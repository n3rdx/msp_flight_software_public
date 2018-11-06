#include <src/payload_processor/uplinks/clear_exceptions_uplink.h>
#include <src/util/msp_exception.h>

ClearExceptionsUplink::ClearExceptionsUplink(byte* payload)
    : Uplink(kClearExceptionsUplinkArgumentLength), error_id(*payload) {}

bool ClearExceptionsUplink::ExecuteUplink() {
    try {
        if (error_id == kClearAll) {
            MspException::ClearAll();
        } else {
            MspException::ClearType(error_id);
        }
        return true;
    } catch (etl::exception& e) {
        MspException::LogException(e);
        return false;
    }
}
