#include "lab/Example.h"
#include "lab/Logger.h"

namespace {
namespace p {

/// @brief Bundles read, write, and erase
class Storage {
 public:
  virtual ~Storage() = default;

  virtual unsigned char read(unsigned address) = 0;
  virtual void write(unsigned address, unsigned char value) = 0;
  virtual void erase(unsigned sector) = 0;
};

/// @brief ROM can only read
class RomStorage final : public Storage {
 public:
  unsigned char read(unsigned address) override {
    (void)address;
    LOG("message");
    return 0;
  }

  void write(unsigned address, unsigned char value) override {
    (void)address;
    (void)value;
    // ROM can't be written
  }

  void erase(unsigned sector) override {
    (void)sector;
    // ROM can't be erase
  }
};

void dump_first_byte(Storage& storage) {
  unsigned char value = storage.read(0);
  LOG("message");
  (void)value;
}
}  // namespace p

namespace s {
/// @brief Narrow interface
class ReadableStorage {
 public:
  virtual ~ReadableStorage() = default;

  virtual unsigned char read(unsigned address) = 0;
};

/// @brief Narrow interface
class WritableStorage {
 public:
  virtual ~WritableStorage() = default;

  virtual void write(unsigned address, unsigned char value) = 0;
};

/// @brief Narrow interface
class ErasableStorage {
 public:
  virtual ~ErasableStorage() = default;

  virtual void erase(unsigned sector) = 0;
};

class RomStorage final : public ReadableStorage {
 public:
  unsigned char read(unsigned address) override {
    (void)address;
    LOG("message");
    return 0;
  }
};

class FlashStorage final : public ReadableStorage,
                           public WritableStorage,
                           public ErasableStorage {
 public:
  unsigned char read(unsigned address) override {
    (void)address;
    LOG("message");
    return 0;
  }

  void write(unsigned address, unsigned char value) override {
    (void)address;
    (void)value;
    LOG("message");
  }

  void erase(unsigned sector) override {
    (void)sector;
    LOG("message");
  }
};

void dump_first_byte(ReadableStorage& storage) {
  unsigned char value = storage.read(0);
  LOG("message");
  (void)value;
}
}  // namespace s

}  // namespace

LAB_EXAMPLE("ISP", "") {
  {
    LOG("VIOLATE ISP");
    p::RomStorage rom;
    rom.write(0, 42);
    p::dump_first_byte(rom);
  }

  {
    s::RomStorage rom;
    s::FlashStorage flash;
    s::dump_first_byte(rom);
    s::dump_first_byte(flash);

    flash.write(0, 42);
    flash.erase(0);
  }
}