// in-core file system types

struct inode {
  uint dev;           // Device number
  uint inum;          // Inode number
  int ref;            // Reference count
  int flags;          // I_BUSY, I_VALID

  short type;         // copy of disk inode
  short major;
  short minor;
  short nlink;
  uint size;
  // keep the inode structure exactly as it
  // is except for those data block points.
  // Use 3 of the 4 bytes for pointer and
  // the remaining byte for length.
  // Do we need to modify this the same way
  // we modified dinode in fs.h?
  uint addrs[NDIRECT+1];
};

#define I_BUSY 0x1
#define I_VALID 0x2
