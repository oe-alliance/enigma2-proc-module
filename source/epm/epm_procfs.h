#include <linux/version.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/namei.h>
#include <linux/seq_file.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>

#define MAX_CHAR_LENGTH 256
#define cProcDir	1
#define cProcEntry	2

struct ProcWriteInfo
{
	int proc_i;
	int count;
	int ipage;
	char *bpage;
	const char __user *ubuf;
};

typedef int (*proc_read_t) (struct seq_file *m, void* data);
typedef int (*proc_write_t_e2) (struct ProcWriteInfo *proc_info, char *kbuf);

struct ProcStructure_s
{
	int type;
	char* name;
	struct proc_dir_entry* entry;
	proc_read_t read_proc;
	proc_write_t_e2 write_proc;
	struct ProcWriteInfo* proc_info;
	void* identifier; /* needed for cpp stuff */
};

struct file* file_open(const char* path, int flags, int rights);
void file_close(struct file* file);
int file_read(struct file* file, unsigned char* data, unsigned int size);
int file_write(struct file* file, unsigned char* data, unsigned int size);
int remove_file(char *path);
int save_data_to_file(char *path, int flags, char *data, int size);
char * dirname(char * name);
char * basename(char * name);

int get_getBrandOEM(struct seq_file *m, void* data);
int get_getImageBuild(struct seq_file *m, void* data);
int get_getLastBuildDate(struct seq_file *m, void* data);
int get_getImageArch(struct seq_file *m, void* data);
int get_getImageDevBuild(struct seq_file *m, void* data);
int get_getDisplayType(struct seq_file *m, void* data);
int get_getFeedsUrl(struct seq_file *m, void* data);
int get_getImageDistro(struct seq_file *m, void* data);
int get_getImageType(struct seq_file *m, void* data);
int get_getHaveAVJACK(struct seq_file *m, void* data);
int get_getHaveCI(struct seq_file *m, void* data);
int get_getHaveDVI(struct seq_file *m, void* data);
int get_getHaveHDMI(struct seq_file *m, void* data);
int get_getHaveHDMIinFHD(struct seq_file *m, void* data);
int get_getHaveHDMIinHD(struct seq_file *m, void* data);
int get_getHaveMiniTV(struct seq_file *m, void* data);
int get_getHaveRCA(struct seq_file *m, void* data);
int get_getHaveSCART(struct seq_file *m, void* data);
int get_getHaveSCARTYUV(struct seq_file *m, void* data);
int get_getHaveWOL(struct seq_file *m, void* data);
int get_getHaveWWOL(struct seq_file *m, void* data);
int get_getHaveYUV(struct seq_file *m, void* data);
int get_getImageFolder(struct seq_file *m, void* data);
int get_getImageFileSystem(struct seq_file *m, void* data);
int get_getImageName(struct seq_file *m, void* data);
int get_getImageVersion(struct seq_file *m, void* data);
int get_getMachineKernelFile(struct seq_file *m, void* data);
int get_getModel(struct seq_file *m, void* data);
int get_getBoxType(struct seq_file *m, void* data);
int get_getMachineBuild(struct seq_file *m, void* data);
int get_getMachineBrand(struct seq_file *m, void* data);
int get_getMachineName(struct seq_file *m, void* data);
int get_getMachineMKUBIFS(struct seq_file *m, void* data);
int get_getMachineMtdKernel(struct seq_file *m, void* data);
int get_getMachineMtdRoot(struct seq_file *m, void* data);
int get_getMachineRootFile(struct seq_file *m, void* data);
int get_getSocFamily(struct seq_file *m, void* data);
int get_getHaveTranscoding1(struct seq_file *m, void* data);
int get_getMachineUBINIZE(struct seq_file *m, void* data);
