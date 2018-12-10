struct segAddr {
	uint16_t offset;
	uint16_t segment;
};

struct header {
	char magic[8]; // AMIBIOSC
	char core_version[4];
	uint16_t length;
	uint32_t checksum;
	struct segAddr first_module_address;
};

struct ext_header {
	char reserved[4];
	uint8_t fill_value_complement;
	uint8_t image_version;
	uint8_t rom_image_attribute;
	uint8_t flash_utility_signature;
	uint8_t module_ext_header_length; 	// 0x08 is expected (see below the ext_module_header definition)
	uint8_t ext_header_length; 			// 0xa is expected (sizeof(struct ext_header))
};

struct module_header {
	struct segAddr next_module_address;
	uint16_t size_word;
	uint8_t identifier;
	uint8_t attribute;
	struct segAddr destination_address;
};

/*
	Module header attribute field:
	0 : ??
	1 : ??
	2 : ??
	3 : ??
	4 : may be split
	5 : is split piece
	6 : is link
	7 : is compressed
*/

/*
	Module identifier signification:
	6   - DMI Data module
	21  - External memory detection module
	27  - Main peel module
	128 - Image information module
*/

struct ext_module_header {
	uint32_t size_dword;
	uint32_t checksum;
};

struct section_header {
	uint16_t next_section_address;
	uint8_t identifier;
	uint8_t entry_size;
	uint8_t nb_entry;
};

/*
	Section identifier signification:
	16 - Version section
	32 - Init section
	33 - Boot block gap section
	47 - Date time section
	48 - Peel section
	64 - Module section
	80 - Hole section
	96 - ROMBuild section
 */

struct segment_header {
	uint32_t segment_address;
	uint32_t segment_length;
};

struct ext_segment_header {
	uint8_t type;
	uint16_t offset;
	char name[];
};
