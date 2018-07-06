# Miscellaneous Tips

## Windows

* Download and install updates manually: http://www.catalog.update.microsoft.com/Home.aspx
* Log on automatically on Windows 7: user account dialogue box named ```netplwiz```
* Disable Windows 10 lock screen: create the registry key ```HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows\Personalization``` and add to it the value ```NoLockScreen = 0``` (DWORD 32-bit)

## Linux

* Add an existing user to an existing group: ```usermod -a -G groupName userName```. The user needs to log out and on afterwards.
* Update Virtualbox extension pack:
	* ```VBV=$(vboxmanage -v | cut -d r -f 1)```
	* ```wget https://download.virtualbox.org/virtualbox/$VBV/Oracle_VM_VirtualBox_Extension_Pack-$VBV.vbox-extpack```
	* ```vboxmanage extpack install --replace Oracle_VM_VirtualBox_Extension_Pack-$VBV.vbox-extpack```
* Test Snort rule(s) against a pcap file: ```snort -A console -q -c /etc/snort/snort.conf -r file.pcap``` (don't forget to disable offloading: ```ethtool -K interface rx off tx off```)

### Debug

* Dump raw memory to file: 
	* GDB: ```dump binary memory file_name start_address stop_address```
	* WinDbg: ```.writemem file_name start_address range```
