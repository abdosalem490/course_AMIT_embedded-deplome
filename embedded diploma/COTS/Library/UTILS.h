#ifndef UTILS_H_
#define UTILS_H_

#define Map(InputMin,InputMax,OutputMin,OutputMax,InputValue)	(sint32)((((f64)(OutputMax - OutputMin) / (InputMax - InputMin)) *(InputValue - InputMin)) + OutputMin)


#endif 