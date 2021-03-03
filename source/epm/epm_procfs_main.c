#include "epm_procfs.h"

#define PROC_PERMISSION 0444

struct ProcStructure_s _Proc[] =
{
	{cProcEntry, "getBrandOEM", PROC_PERMISSION, get_getBrandOEM, NULL, NULL, ""},
	{cProcEntry, "getImageBuild", PROC_PERMISSION, get_getImageBuild, NULL, NULL, ""},
	{cProcEntry, "getLastBuildDate", PROC_PERMISSION, get_getLastBuildDate, NULL, NULL, ""},
	{cProcEntry, "getImageArch", PROC_PERMISSION, get_getImageArch, NULL, NULL, ""},
	{cProcEntry, "getImageDevBuild", PROC_PERMISSION, get_getImageDevBuild, NULL, NULL, ""},
	{cProcEntry, "getDisplayType", PROC_PERMISSION, get_getDisplayType, NULL, NULL, ""},
	{cProcEntry, "getFeedsUrl", PROC_PERMISSION, get_getFeedsUrl, NULL, NULL, ""},
	{cProcEntry, "getImageDistro", PROC_PERMISSION, get_getImageDistro, NULL, NULL, ""},
	{cProcEntry, "getImageType", PROC_PERMISSION, get_getImageType, NULL, NULL, ""},
	{cProcEntry, "getHaveAVJACK", PROC_PERMISSION, get_getHaveAVJACK, NULL, NULL, ""},
	{cProcEntry, "getHaveCI", PROC_PERMISSION, get_getHaveCI, NULL, NULL, ""},
	{cProcEntry, "getHaveDVI", PROC_PERMISSION, get_getHaveDVI, NULL, NULL, ""},
	{cProcEntry, "getHaveHDMI", PROC_PERMISSION, get_getHaveHDMI, NULL, NULL, ""},
	{cProcEntry, "getHaveHDMIinFHD", PROC_PERMISSION, get_getHaveHDMIinFHD, NULL, NULL, ""},
	{cProcEntry, "getHaveHDMIinHD", PROC_PERMISSION, get_getHaveHDMIinHD, NULL, NULL, ""},
	{cProcEntry, "getHaveMiniTV", PROC_PERMISSION, get_getHaveMiniTV, NULL, NULL, ""},
	{cProcEntry, "getHaveRCA", PROC_PERMISSION, get_getHaveRCA, NULL, NULL, ""},
	{cProcEntry, "getHaveSCART", PROC_PERMISSION, get_getHaveSCART, NULL, NULL, ""},
	{cProcEntry, "getHaveSCARTYUV", PROC_PERMISSION, get_getHaveSCARTYUV, NULL, NULL, ""},
	{cProcEntry, "getHaveWOL", PROC_PERMISSION, get_getHaveWOL, NULL, NULL, ""},
	{cProcEntry, "getHaveWWOL", PROC_PERMISSION, get_getHaveWWOL, NULL, NULL, ""},
	{cProcEntry, "getHaveYUV", PROC_PERMISSION, get_getHaveYUV, NULL, NULL, ""},
	{cProcEntry, "getImageFolder", PROC_PERMISSION, get_getImageFolder, NULL, NULL, ""},
	{cProcEntry, "getImageFileSystem", PROC_PERMISSION, get_getImageFileSystem, NULL, NULL, ""},
	{cProcEntry, "getImageName", PROC_PERMISSION, get_getImageName, NULL, NULL, ""},
	{cProcEntry, "getImageVersion", PROC_PERMISSION, get_getImageVersion, NULL, NULL, ""},
	{cProcEntry, "getMachineKernelFile", PROC_PERMISSION, get_getMachineKernelFile, NULL, NULL, ""},
	{cProcEntry, "getModel", PROC_PERMISSION, get_getModel, NULL, NULL, ""},
	{cProcEntry, "getBoxType", PROC_PERMISSION, get_getBoxType, NULL, NULL, ""},
	{cProcEntry, "getMachineBuild", PROC_PERMISSION, get_getMachineBuild, NULL, NULL, ""},
	{cProcEntry, "getMachineBrand", PROC_PERMISSION, get_getMachineBrand, NULL, NULL, ""},
	{cProcEntry, "getMachineName", PROC_PERMISSION, get_getMachineName, NULL, NULL, ""},
	{cProcEntry, "getMachineMKUBIFS", PROC_PERMISSION, get_getMachineMKUBIFS, NULL, NULL, ""},
	{cProcEntry, "getMachineMtdKernel", PROC_PERMISSION, get_getMachineMtdKernel, NULL, NULL, ""},
	{cProcEntry, "getMachineMtdRoot", PROC_PERMISSION, get_getMachineMtdRoot, NULL, NULL, ""},
	{cProcEntry, "getMachineRootFile", PROC_PERMISSION, get_getMachineRootFile, NULL, NULL, ""},
	{cProcEntry, "getSocFamily", PROC_PERMISSION, get_getSocFamily, NULL, NULL, ""},
	{cProcEntry, "getHaveTranscoding1", PROC_PERMISSION, get_getHaveTranscoding1, NULL, NULL, ""},
	{cProcEntry, "getMachineUBINIZE", PROC_PERMISSION, get_getMachineUBINIZE, NULL, NULL, ""},
};

struct proc_dir_entry * find_proc_dir(char * name)
{
	int i;

	for (i = 0; i < sizeof(_Proc) / sizeof(_Proc[0]); i++)
	{
		if ((_Proc[i].type == cProcDir) && (strcmp(name, _Proc[i].name) == 0))
			return _Proc[i].entry;
	}
	return NULL;
}

static int _procfs_show(struct seq_file *m, void* data)
{
	int bytes = 0;
	char bufferfile[MAX_CHAR_LENGTH];
	struct ProcWriteInfo *proc_info = m->private;
	seq_printf(m, "\n");

	bytes = sprintf(bufferfile, "_procfs_show : proc_info->proc_i = %d\n", proc_info->proc_i);

	return 0;
}

static int _procfs_open(struct inode *inode, struct file *file)
{
	struct ProcWriteInfo *proc_info;
	int i;
	char *path, *ptr = NULL, *_Proc_fpath = NULL;

	proc_info = kmalloc(sizeof(struct ProcWriteInfo), GFP_KERNEL);
	if (proc_info == NULL)
		return -ENOMEM;

	path = kmalloc(PAGE_SIZE, GFP_KERNEL);
	_Proc_fpath = kmalloc(PAGE_SIZE, GFP_KERNEL);
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,26)
	ptr = d_path(file->f_dentry, file->f_vfsmnt, path, PAGE_SIZE);
#else
	ptr = d_path(&file->f_path, path, PAGE_SIZE);
#endif
	proc_info->proc_i = -EPERM;

	for (i = 0; i < sizeof(_Proc) / sizeof(_Proc[0]); i++)
	{
		int bytes = 0;
		char buffer[MAX_CHAR_LENGTH];

		sprintf(_Proc_fpath, "/proc/%s", _Proc[i].name);

		bytes = sprintf(buffer, "_Proc : file->f_mode = %d / %s / %s == %s\n", file->f_mode, _Proc[i].name, ptr, _Proc_fpath);

//		if (_Proc[i].type == cProcEntry && strstr(ptr, _Proc[i].name))
		if (_Proc[i].type == cProcEntry && !strcmp(ptr, _Proc_fpath))
		{
			proc_info->proc_i = i;
			proc_info->count = -EPERM;

			if (file->f_mode & FMODE_READ)
			{
				if (_Proc[i].read_proc != NULL)
				{
					if (_Proc[i].proc_info != NULL)
					{
						proc_info = _Proc[i].proc_info;
					}
					return single_open(file, _Proc[i].read_proc, proc_info);
				}
				return single_open(file, _procfs_show, proc_info);
			}
			else if (file->f_mode & FMODE_WRITE)
			{
				if (_Proc[i].write_proc == NULL)
				{
					proc_info->proc_i = -EPERM;
				}
				file->private_data = proc_info;
			}
			break;
		}
	}
	return 0;
}

static ssize_t _procfs_write(struct file *file, const char __user *ubuf,
			       size_t count, loff_t *ppos)
{
	struct ProcWriteInfo *proc_info = file->private_data;
	char *kbuf;

	kbuf = kmalloc(count + 1, GFP_KERNEL);
	if (!kbuf)
		return -ENOMEM;

	if (copy_from_user(kbuf, ubuf, count)) {
		count = -EFAULT;
	}
	else
	{
		kbuf[count] = '\0'; /* Just to make sure... */

		if (proc_info->proc_i >= 0)
		{
			int proc_i = proc_info->proc_i;

			proc_info->ubuf = ubuf;
			proc_info->count = count;
			_Proc[proc_i].write_proc(proc_info, kbuf);
			_Proc[proc_i].proc_info = proc_info;
		}
	}
	return count;
}

static unsigned int _procfs_poll(struct file *file,
				   struct poll_table_struct *wait)
{
	unsigned int mask = 0;
#ifdef DEBUG
	printk(KERN_DEBUG "_procfs: poll called (unimplemented)\n");
#endif
	return mask;
}

static int _procfs_release(struct inode *inode, struct file *file)
{
//	struct ProcWriteInfo *proc_info = file->private_data;
#ifdef DEBUG
	printk(KERN_DEBUG "_procfs: release called\n");
#endif
//	kfree(proc_info);
	return 0;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,6,0)
static const struct proc_ops _procfs_fops = {
	.proc_open	= _procfs_open,
	.proc_read	= seq_read,
	.proc_write	= _procfs_write,
	.proc_lseek	= no_llseek,
	.proc_poll	= _procfs_poll,
	.proc_mmap	= NULL,
	.proc_release	= _procfs_release,
};
#else
static const struct file_operations _procfs_fops = {
	.owner		= THIS_MODULE,
	.open		= _procfs_open,
	.read		= seq_read,
	.write		= _procfs_write,
	.llseek	= no_llseek,
	.poll		= _procfs_poll,
	.mmap		= NULL,
	.release	= _procfs_release,
};
#endif
void _kernel_info(void)
{
	printk(KERN_INFO "getBrandOEM=@BRAND_OEM@\n");
	printk(KERN_INFO "getImageBuild=@BUILD_VERSION@\n");
	printk(KERN_INFO "getLastBuildDate=@DATETIME@\n");
	printk(KERN_INFO "getImageArch=@DEFAULTTUNE@\n");
	printk(KERN_INFO "getImageDevBuild=@DEVELOPER_BUILD_VERSION@\n");
	printk(KERN_INFO "getDisplayType=@DISPLAY_TYPE@\n");
	printk(KERN_INFO "getFeedsUrl=@DISTRO_FEED_URI@\n");
	printk(KERN_INFO "getImageDistro=@DISTRO_NAME@\n");
	printk(KERN_INFO "getImageType=@DISTRO_TYPE@\n");
	printk(KERN_INFO "getHaveAVJACK=@HAVE_AV_JACK@\n");
	printk(KERN_INFO "getHaveCI=@HAVE_CI@\n");
	printk(KERN_INFO "getHaveDVI=@HAVE_DVI@\n");
	printk(KERN_INFO "getHaveHDMI=@HAVE_HDMI@\n");
	printk(KERN_INFO "getHaveHDMIinFHD=@HAVE_HDMI_IN_FHD@\n");
	printk(KERN_INFO "getHaveHDMIinHD=@HAVE_HDMI_IN_HD@\n");
	printk(KERN_INFO "getHaveMiniTV=@HAVE_MINITV@\n");
	printk(KERN_INFO "getHaveRCA=@HAVE_RCA@\n");
	printk(KERN_INFO "getHaveSCART=@HAVE_SCART@\n");
	printk(KERN_INFO "getHaveSCARTYUV=@HAVE_SCART_YUV@\n");
	printk(KERN_INFO "getHaveWOL=@HAVE_WOL@\n");
	printk(KERN_INFO "getHaveWWOL=@HAVE_WWOL@\n");
	printk(KERN_INFO "getHaveYUV=@HAVE_YUV@\n");
	printk(KERN_INFO "getImageFolder=@IMAGEDIR@\n");
	printk(KERN_INFO "getImageFileSystem=@IMAGE_FSTYPES@\n");
	printk(KERN_INFO "getImageName=@IMAGE_NAME@\n");
	printk(KERN_INFO "getImageVersion=@IMAGE_VERSION@\n");
	printk(KERN_INFO "getMachineKernelFile=@KERNEL_FILE@\n");
	printk(KERN_INFO "getModel=@MACHINE@\n");
	printk(KERN_INFO "getBoxType=@MACHINEBUILD@\n");
	printk(KERN_INFO "getMachineBuild=@MACHINEBUILD@\n");
	printk(KERN_INFO "getMachineBrand=@MACHINE_BRAND@\n");
	printk(KERN_INFO "getMachineName=@MACHINE_NAME@\n");
	printk(KERN_INFO "getMachineMKUBIFS=@MKUBIFS_ARGS@\n");
	printk(KERN_INFO "getMachineMtdKernel=@MTD_KERNEL@\n");
	printk(KERN_INFO "getMachineMtdRoot=@MTD_ROOTFS@\n");
	printk(KERN_INFO "getMachineRootFile=@ROOTFS_FILE@\n");
	printk(KERN_INFO "getSocFamily=@SOC_FAMILY@\n");
	printk(KERN_INFO "getHaveTranscoding1=@TRANSCODING@\n");
	printk(KERN_INFO "getMachineUBINIZE=@UBINIZE_ARGS@\n");
}

static int __init _procfs_init_module(void)
{
	int i;
	char *path;
	char *name;

	_kernel_info();

	for (i = 0; i < sizeof(_Proc) / sizeof(_Proc[0]); i++)
	{
		path = dirname(_Proc[i].name);
		name = basename(_Proc[i].name);

		switch (_Proc[i].type)
		{
			case cProcDir:
				_Proc[i].entry = proc_mkdir(name, find_proc_dir(path));

				if (_Proc[i].entry == NULL)
				{
					printk("%s(): could not create entry %s\n", __func__, _Proc[i].name);
				}
				break;

			case cProcEntry:
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,10,0)
				_Proc[i].entry = create_proc_entry(
					(strcmp("bus", path) == 0) ? _Proc[i].name : name,
					PROC_PERMISSION,
					(strcmp("bus", path) == 0) ? NULL : find_proc_dir(path)
				);
#else
				_Proc[i].entry = proc_create(
					(strcmp("bus", path) == 0) ? _Proc[i].name : name,
					PROC_PERMISSION,
					(strcmp("bus", path) == 0) ? NULL : find_proc_dir(path),
					&_procfs_fops
				);
#endif
				break;

			default:
				printk("%s(): invalid type %d\n", __func__, _Proc[i].type);
		}
	}
	return 0;
}

module_init(_procfs_init_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Contains original, open source, material derived from Duckbox-Developers e2_proc module. Contains open source, material from OpenVision developers. Current version OE-Alliance developers");
MODULE_DESCRIPTION("Enigma2 information module\ngetBrandOEM=@BRAND_OEM@\ngetImageBuild=@BUILD_VERSION@\ngetLastBuildDate=@DATETIME@\ngetImageArch=@DEFAULTTUNE@\ngetImageDevBuild=@DEVELOPER_BUILD_VERSION@\ngetDisplayType=@DISPLAY_TYPE@\ngetFeedsUrl=@DISTRO_FEED_URI@\ngetImageDistro=@DISTRO_NAME@\ngetImageType=@DISTRO_TYPE@\ngetHaveAVJACK=@HAVE_AV_JACK@\ngetHaveCI=@HAVE_CI@\ngetHaveDVI=@HAVE_DVI@\ngetHaveHDMI=@HAVE_HDMI@\ngetHaveHDMIinFHD=@HAVE_HDMI_IN_FHD@\ngetHaveHDMIinHD=@HAVE_HDMI_IN_HD@\ngetHaveMiniTV=@HAVE_MINITV@\ngetHaveRCA=@HAVE_RCA@\ngetHaveSCART=@HAVE_SCART@\ngetHaveSCARTYUV=@HAVE_SCART_YUV@\ngetHaveWOL=@HAVE_WOL@\ngetHaveWWOL=@HAVE_WWOL@\ngetHaveYUV=@HAVE_YUV@\ngetImageFolder=@IMAGEDIR@\ngetImageFileSystem=@IMAGE_FSTYPES@\ngetImageName=@IMAGE_NAME@\ngetImageVersion=@IMAGE_VERSION@\ngetMachineKernelFile=@KERNEL_FILE@\ngetModel=@MACHINE@\ngetBoxType=@MACHINEBUILD@\ngetMachineBuild=@MACHINEBUILD@\ngetMachineBrand=@MACHINE_BRAND@\ngetMachineName=@MACHINE_NAME@\ngetMachineMKUBIFS=@MKUBIFS_ARGS@\ngetMachineMtdKernel=@MTD_KERNEL@\ngetMachineMtdRoot=@MTD_ROOTFS@\ngetMachineRootFile=@ROOTFS_FILE@\ngetSocFamily=@SOC_FAMILY@\ngetHaveTranscoding1=@TRANSCODING@\ngetMachineUBINIZE=@UBINIZE_ARGS@");
MODULE_VERSION("@IMAGE_NAME@");
