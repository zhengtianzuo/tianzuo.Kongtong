/*!
 *@file tianzuo.Kongtong.h
 *@brief 天佐.崆峒印(tianzuo.Kongtong)
 *@version 1.0.0.0
 *@author 郑天佐（zhengtianzuo）
 *@date 2014-5-17
*/
#pragma once
#include <Windows.h>

//!@brief 导出函数定义(define dllexport)
#ifdef tianzuo_Kongtong_dllexport
#define tianzuo_Kongtong_lib __declspec(dllexport)
#else
#define tianzuo_Kongtong_lib __declspec(dllimport)
typedef int (*tianzuo_Kongtong_get_exception)(PEXCEPTION_POINTERS const pExceptPtrs, WORD const create_param, int const language);
#endif

//!@enum 生成方式(generation type)
enum Kongtong_create {
    Kongtong_create_normal = 0x00000001,         ///< 创建minidmp和日志 (generate minidmp and logs)
    Kongtong_create_nodump = 0x00000002,         ///< 不创建minidmp (not generate minidmp)
    Kongtong_create_nolog  = 0x00000003,         ///< 不创建logs (not generate logs)
    Kongtong_create_none   = 0x00000004          ///< 不创建minidmp和logs (not generate minidmp and logs)
};

/*!
 *@name Kongtong_get_exception
 *@brief 获取异常信息 (Get exception information)
 *@param[in] except_ptrs 异常信息指针 (Exception message pointer)
 *@param[in] create_param 生成方式 (generation type)
 *@see ::Kongtong_create
 *@return int
 *@author 郑天佐
 *@date 2014-5-17
*/
extern "C" tianzuo_Kongtong_lib int Kongtong_get_exception(PEXCEPTION_POINTERS const except_ptrs, int const create_param, int const language = 0);

#undef tianzuo_Kongtong_lib
