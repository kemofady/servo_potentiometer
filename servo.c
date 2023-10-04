#include"STD_TYPES.h"
#include"servo.h"

s32 map(s32 cpy_inputmini,s32 cpy_inputmax,s32 cpy_outmini,s32 cpy_outmax, s32 cpy_val)
{
	s32 local_hoder =cpy_val - cpy_inputmax;
	local_hoder *=(cpy_outmini - cpy_outmax);
	local_hoder /=(cpy_inputmini - cpy_inputmax);
	local_hoder +=cpy_outmax;
	return local_hoder;
}
