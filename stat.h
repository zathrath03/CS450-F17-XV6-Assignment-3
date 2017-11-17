#define T_DIR  1   // Directory
#define T_FILE 2   // File
#define T_DEV  3   // Special device
// create a new type of file to support
// inodes with pointers and length
#define T_EXTENT 4 // Extent based file

struct stat {
  short type;  // Type of file
  int dev;     // Device number
  uint ino;    // Inode number on device
  short nlink; // Number of links to file
  uint size;   // Size of file in bytes
  // add information for the extent based file type
};
