/* Page Map Entry (Genric) */
#define PME_get_present(pme) 		(((pme) >> 0 ) & 0x00000001) /* P */
#define PME_get_writable(pme) 		(((pme) >> 1 ) & 0x00000001) /* P/W */
#define PME_get_user(pme) 			(((pme) >> 2 ) & 0x00000001) /* U/S */
#define PME_get_write_through(pme) 	(((pme) >> 3 ) & 0x00000001) /* PWT */
#define PME_get_cache_disabled(pme) (((pme) >> 4 ) & 0x00000001) /* PCD */
#define PME_get_accessed(pme) 		(((pme) >> 5 ) & 0x00000001) /* A */
#define PME_get_dirty(pme) 			(((pme) >> 6 ) & 0x00000001) /* D (ignored if PS = 0)*/
#define PME_get_page_size(pme) 		(((pme) >> 7 ) & 0x00000001) /* PS */
#define PME_get_global(pme) 		(((pme) >> 8 ) & 0x00000001) /* G (ignored if PS = 0) */
#define PME_get_type(pme) 			(((pme) >> 12) & 0x00000001) /* PAT (valid if PS = 1) */
#define PME_get_tbl_phy_addr(pme) 	((pme) & 0xffffffffff000)
#define PME_get_key(pme) 			(((pme) >> 59) & 0x0000000f) /* (ignored if PS = 0) */
#define PME_get_not_executable(pme) (((pme) >> 63) & 0x00000001) /* XD */

#define PDPTE_get_1gpg_phy_addr(pdpte) 	((pdpte) & 0xfffffc0000000) /* 1-GByte page physical address (valid for PDPTE) */
#define PDE_get_2mpg_phy_addr(pde) 		((pde  ) & 0xfffffffe00000) /* 2-Mbyte page physical address (valid for PDE) */
#define PTE_get_4kpg_phy_addr(pte) 		((pte  ) & 0xffffffffff000) /* 4-KByte page physical address (valid for PTE) */
