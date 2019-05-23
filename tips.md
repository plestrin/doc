# Miscellaneous Tips

## Windows

* Download and install updates manually: http://www.catalog.update.microsoft.com/Home.aspx
* Log on automatically on Windows 7: user account dialogue box named `netplwiz`
* Disable Windows 10 lock screen: create the registry key `HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows\Personalization` and add to it the value `NoLockScreen = 0` (DWORD 32-bit)

## Linux

* Add an existing user to an existing group: `usermod -a -G groupName userName`. The user needs to log out and on afterwards.
* Update Virtualbox extension pack:
	* `VBV=$(vboxmanage -v | cut -d r -f 1)`
	* `wget https://download.virtualbox.org/virtualbox/$VBV/Oracle_VM_VirtualBox_Extension_Pack-$VBV.vbox-extpack`
	* `vboxmanage extpack install --replace Oracle_VM_VirtualBox_Extension_Pack-$VBV.vbox-extpack`
* Kernel header packages: `linux-headers-$(uname -r)`
* Test Snort rule(s) against a pcap file: `snort -A console -q -c /etc/snort/snort.conf -r file.pcap` (don't forget to disable offloading: `ethtool -K interface rx off tx off`)

## Debug

* Dump raw memory to file: 
	* GDB: `dump binary memory file_name start_address stop_address`
	* WinDbg: `.writemem file_name start_address range`
* Break at entrypoint:
	* GDB: `info files` then `b *0x...` or simply `b *0` then `r`

* Windows kernel debugging Serial :
	* Windows Vista and sup:
		* `bcdedit /copy {current} /d 'New boot loader entry name'` this command returns a UUID
		* `bcdedit /enum` list boot loader entries
		* `bcdedit /set {UUID} debugtype serial`
		* `bcdedit /set {UUID} debugport 1`
		* `bcdedit /set {UUID} baudrate 115200`
	* Windows Server 2003 and inf:
		* edit the file `c:/boot.ini` and duplicate the first line in `[operating systems]`. Modify the entry name and append the following options: `/debug /debugport=COM1 /baudrate=115200`
If performance issues are encountered with VirtualBox and serial ports try the following : `vboxmanage setextradata {VM-UUID} "VBoxInternal/Devices/serial/0/Config/YieldOnLSRRead" 1`. To obtain VM UUID : `vboxmanage list vms`
