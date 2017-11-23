#include "Package_Info.h"


class container_info
{
	public:
		container_info();
		~container_info();
		int add_item(char * item , char * description);
		int copy_item(const container_info & copy_form);
		int display_item();
		int display_only_item();
	private:
		char * item;
		char * description;
};

