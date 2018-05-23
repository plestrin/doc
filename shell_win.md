# Windows ShellCodes

## Pointeurs vers les bibliothèques systèmes

1. FS (32-bit) ou GS (64-bit) contient l'adresse de la structure ```_TEB``` ;
2. Le champ ```ProcessEnvironmentBlock``` (```+0x30``` 32-bit ou ```+0x60``` 64-bit) contient l'adresse de la structure ```_PEB``` ;
3. Le champ ```Ldr``` (```+0x0c``` 32-bit ou ```+0x18``` 64-bit) contient l'adresse de la structure ```PEB_LDR_DATA``` ;
4. Le champ ```InMemoryOrderModuleList``` (```+0x14``` 32-bit ou ```+0x20``` 64-bit) contient une liste chaînée de structures ```LDR_DATA_TABLE_ENTRY``` ;
5. Le champ ```BaseDllName``` (```+0x24``` 32-bit ou ```+0x48``` 64-bit) peut être utilisé pour filtrer les images chargées ;
6. Le champ ```DllBase``` (```+0x10``` 32-bit ou ```+0x20``` 64-bit) contient l'adresse de la structure ```ÌMAGE_DOS_HEADER``` ;
7. Le champ ```e_lfanew``` (```+0x3c```) contient l'adresse de la structure ```ÌMAGE_NT_HEADER``` ;
8. Le champ ```OptionalHeader.DataDirectory[0].VirtualAddress``` (```+0x78``` 32-bit ou ```+0x88``` 64-bit) contient la RVA de la structure ```IMAGE_EXPORT_DIRECTORY``` ;
9. Le champ ```AdresseOfNames``` contient la RVA du tableau des noms de fonctions exportées (il faut ensuite récupérer l'ordinal associé ```AdddressOfNameOrdinals``` pour enfin accéder à l'adresse de la fonction dans le tableau ```ÀddressOfFunctions``` indexé par l'ordinal)
