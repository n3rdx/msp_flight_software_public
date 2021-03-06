#include <src/tasks/runnable.h>
#include <src/util/msp_exception.h>
#include <src/util/runnable_memory_logger.h>
#include <src/util/tirtos_utils.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/std.h>

RunnableMemoryLogger::RunnableMemoryLogger() {}

fnptr RunnableMemoryLogger::GetRunnablePointer() {
    return &RunnableMemoryLogger::LogMemoryStats;
}

void RunnableMemoryLogger::LogMemoryStats() {
    Memory_Stats mem_stats;
    Task_Object* task;
    while (1) {
        try {
            HeapMem_getStats(
                HeapMem_Handle_downCast(Memory_defaultHeapInstance),
                &mem_stats);
            Log_info3("Heap memory: %d free, %d total, %d largest free (bytes)",
                      mem_stats.totalFreeSize, mem_stats.totalSize,
                      mem_stats.largestFreeSize);

            // Now report on stacks
            // https://e2e.ti.com/support/embedded/tirtos/f/355/t/259653#pi317008=2
            // Statically created tasks
            for (int i = 0; i < Task_Object_count(); i++) {
                task = Task_Object_get(NULL, i);
                PrintTaskInfo(task);
            }

            // Dynamically created tasks
            task = Task_Object_first();
            while (task) {
                PrintTaskInfo(task);
                task = Task_Object_next(task);
            }

            Task_sleep(TirtosUtils::MilliToCycles(kMemoryLoggerRunPeriod));
        } catch (MspException& e) {
            MspException::LogTopLevelException(e, kRunnableMemoryLoggerCatch);
        }
    }
}

void RunnableMemoryLogger::PrintTaskInfo(Task_Handle task) {
    Task_Stat stat;

    Task_stat(task, &stat);
    // TODO(akremor): If we set task names, print them here as well
    Log_info3("Task 0x%x: %d of %d stack bytes used", (xdc_IArg)task, stat.used,
              stat.stackSize);

    if (stat.used > 0.9 * stat.stackSize) {
        Log_warning1(
            "Task 0x%x: >90%% of task stack used, stack overflow possible!",
            (xdc_IArg)task);
    }
}
