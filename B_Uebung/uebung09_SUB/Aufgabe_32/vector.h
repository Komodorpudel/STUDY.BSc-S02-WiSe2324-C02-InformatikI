#ifndef VECTOR_H

/* Anfang */
#define VECTOR_H


/* Konstanten */
#define VALID_INPUT 0
#define INPUT_ERROR 1


/* Protoytpen */
float vector_length(float x, float y);
void vector_norm(float* x, float* y);
float vector_angle(float x1, float y1, float x2, float y2);

#endif
/* Ende */
