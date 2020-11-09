#include "use.h"

// 支持标准C库的IO函数

// 重载pritnf调用的fputc函数，让它将输出流通过USARTx输出
int fputc(int ch, FILE *f){
	while(!USARTx_TC);
    USARTx->DR = (u16)ch;

	return ch;
}

// 重载scanf调用的fgetc函数，让它将输入流通过USARTx输入
int fgetc(FILE *f){
	while(!USARTx_RXNE);

	return (u16)USARTx->DR;
}