

#define all_print(f,args...) \
do{\
	{\
		  printf("[%s (%d)] ",__FUNCTION__,__LINE__);\
		  printf(f,##args);\
	}\
}while(0)
