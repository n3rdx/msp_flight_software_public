#ifndef SRC_MESSAGES_SERIALISED_MESSAGE_H_
#define SRC_MESSAGES_SERIALISED_MESSAGE_H_

#include <src/util/data_types.h>
#include <stdint.h>

class SerialisedMessage {
   public:
    static constexpr uint16_t kMaxSerialisedSize = 300;
    SerialisedMessage(uint16_t size, byte* message);
    byte* GetBuffer() const;
    uint16_t GetSize() const;

   private:
    uint16_t size;
    // TODO (dingbenjamin): Investigate need for destructor of VLA allocation
    byte* buffer;
};

#endif  // SRC_MESSAGES_SERIALISED_MESSAGE_H_
