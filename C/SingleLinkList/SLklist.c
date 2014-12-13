/******************************************************************************
 * 版权所有 (C)2012, 九江学院软件工程研究所3G培训班
 *
 * 文件名称： // lklist.c
 * 文件标识： // 见配置管理计划书
 * 内容摘要： // 实现单链表的创建、清空、初始化、查找、插入、删除等操作
 * 其它说明： // 其它内容的说明
 * 当前版本： // 输入当前版本
 * 作    者： //
 * 完成日期： // 2012年5月1日
 *
 * 修改记录1：// 修改历史记录，包括修改日期、修改者及修改内容
 *    修改日期：
 *    版 本 号：
 *    修 改 人：
 *    修改内容：
 * 修改记录2：…
 ******************************************************************************/

#include "SLklist.h"

/*****************************************************************************
 *                            常量                                           *
 *****************************************************************************/


/*****************************************************************************
 *                            宏                                             *
 *****************************************************************************/



/*****************************************************************************
 *                          数据类型                                         *
 *****************************************************************************/



/*****************************************************************************
 *                           全局变量                                        *
 *****************************************************************************/



/*****************************************************************************
 *                           局部函数原型                                    *
 *****************************************************************************/


/*****************************************************************************
 *                     函数实现--公有部分                                    *
 *****************************************************************************/

/*****************************************************************************
 * 函数名称： ListInit()
 * 功能描述： 初始化单链表
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示成功，OVERFLOW 表示溢出
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 ******************************************************************************/

WORD ListInit(T_LinkList **ptL)
{
    // 给链表分配空间
    *ptL = (T_LinkList *) malloc (sizeof(T_LinkList));
    // 判断是否合法
    if (NULL == ptL)
    {
        return(OVERFLOW);
    }
    // 初始化链表
    (*ptL)->ptHead = NULL;
    (*ptL)->ptCur  = NULL;
    (*ptL)->iNum   = 0;
    
    return(OK);
}

/*****************************************************************************
 * 函数名称： ListClear()
 * 功能描述： 清空单链表
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示成功
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 ******************************************************************************/

WORD ListClear(T_LinkList *ptL)
{
    T_ListNode *ptTemp;
    
    // 保存头结点
    ptL->ptCur = ptL->ptHead;
    // 断链清空单链表
    while (NULL != ptL->ptCur)
    {
        ptTemp     = ptL->ptCur;
        ptL->ptCur = ptL->ptCur->ptNext;
        free(ptTemp);
    }
    // 初始化链表
    ptL->ptHead = NULL;
    ptL->iNum   = 0;
    
    return(OK);
}

/*****************************************************************************
 * 函数名称： ListptHeadCreate()
 * 功能描述： 头插法创建单链表
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示成功，OVERFLOW表示溢出
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 ******************************************************************************/

WORD ListHeadCreate(T_LinkList *ptL, int iInSize, void (*InputElem)(elemTypeLkL *))
{
    T_ListNode *ptListNodeTemp;
    elemTypeLkL eDatatmp;
    
    int i;
    for (i = 0; i < iInSize; i++)
    {
        printf("\n请输入第 %d 个值：",i+1);
        // 输入Elemtype类型的数据
        InputElem(&eDatatmp);
        // 给动态节点申请空间
        ptListNodeTemp = (T_ListNode *)malloc(sizeof(T_ListNode));
        // 判断是否申请成功
        if (NULL == ptListNodeTemp)
        {
            return(OVERFLOW);
        }
        // 给该节点赋值
        ptListNodeTemp->eData  = eDatatmp;
        // 断链并插入节点
        ptListNodeTemp->ptNext = ptL->ptHead;
        ptL->ptHead = ptListNodeTemp;
        // 链表长度加一
        ptL->iNum++;
    }
    
    return (OK);
}

/*****************************************************************************
 * 函数名称： ListTailCreate()
 * 功能描述： 尾插法建立单链表
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示成功，OVERFLOW表示溢出
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 ******************************************************************************/

WORD ListTailCreate(T_LinkList *ptL, int iInSize, void (*InputElem)(elemTypeLkL *))
{
    T_ListNode * ptListNodeTemp;
    elemTypeLkL eDataTemp;
    int i;
    
    ptL->ptCur = ptL->ptHead;
    for (i = 0; i < iInSize; i++)
    {
        printf("\n请输入第 %d 个值：", i+1);
        // 输入Elemtype类型的数据
        InputElem(&eDataTemp);
        // 给节点申请一个动态空间
        ptListNodeTemp = (T_ListNode *) malloc (sizeof(T_ListNode));
        // 判断申请节点是否成功
        if(NULL == ptListNodeTemp)
        {
            return(OVERFLOW);
        }
        // 初始化该节点
        ptListNodeTemp->eData  = eDataTemp;
        ptListNodeTemp->ptNext = NULL;
        // 第一个结点
        if (0 == i)
        {
            ptL->ptHead = ptListNodeTemp;
        }
        // 其他结点
        else
        {
            ptL->ptCur->ptNext = ptListNodeTemp;
        }
        
        ptL->ptCur = ptListNodeTemp;
        // 链表长度加一
        ptL->iNum++;
    }
    
    return(OK);
}

/*****************************************************************************
 * 函数名称： ListDisplay()
 * 功能描述： 遍历单链表
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示成功，ERROR表示链表为空
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 ******************************************************************************/

WORD ListDisplay(T_LinkList *ptL, void (*Visit)(elemTypeLkL *))
{
    int iCount = 0;
    // 判断单链表是否为空
    if(0 == ptL->iNum)
    {
        return(ERROR);
    }
    
    ptL->ptCur = ptL->ptHead;
    // 遍历该单链表
    while(NULL != ptL->ptCur)
    {
        iCount ++;
        printf("\n\n第 %d 个值为:", iCount);
        // 读取该单链表每个节点的值
        Visit(&ptL->ptCur->eData);
        // 移动单链表
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    
    return(OK);
}

/*****************************************************************************
 * 函数名称： ListLength()
 * 功能描述： 求单链表长度
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： 返回链表的长度
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 ******************************************************************************/

WORD ListLength(T_LinkList *ptL)
{
    int iLength;
    iLength = ptL->iNum;
    return (iLength);
}

/*****************************************************************************
 * 函数名称： ListEmpty()
 * 功能描述： 判空单链表
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示链表为空，ERROR表示链表不空
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 ******************************************************************************/

WORD ListEmpty(T_LinkList *ptL)
{
    // 判断该单链表是否为空
    if(0 == ptL->iNum)
    {
        return (OK);
    }
    else
    {
        return (ERROR);
    }
}

/*****************************************************************************
 * 函数名称： ListOrderFind()
 * 功能描述： 按序号查找单链表
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示成功，ERROR表示查找位置不合法
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 ******************************************************************************/

WORD ListOrderFind(T_LinkList *ptL, const int iInPosition, elemTypeLkL *peOutValue)
{
    int i;
    // 判断是否合法
    if ( iInPosition <1 || iInPosition >ptL->iNum)
    {
        return(ERROR);
    }
    
    ptL->ptCur = ptL->ptHead;
    // 按顺序查找目标位置
    for (i = iInPosition-1; i > 0 ; i--)
    {
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    // 将查找到的值返回出去
    *peOutValue = ptL->ptCur->eData;
    
    return(OK);
}

/*****************************************************************************
 * 函数名称： ListValueFind()
 * 功能描述： 按查找内容单链表并返回查找到的位置
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示成功，ERROR表示没找到
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 // ******************************************************************************/

WORD ListValueFind(T_LinkList *ptL,  elemTypeLkL *peInValue, int *piOutPosition, T_ListNode **peOutValuePoint, WORD (*EqualElem)(elemTypeLkL *, elemTypeLkL *))
{
    int iCount = 1;
    
    ptL->ptCur = ptL->ptHead;
    // 按单链表内容进行查找
    while (NULL != ptL->ptCur)
    {
        int flag;
        // 将输入的值和单链的值进行比较
        flag = EqualElem(peInValue, &ptL->ptCur->eData);
        // 找到后返回当前值和其所在的位置
        if ( TRUE == flag )
        {
            *piOutPosition      = iCount;
            *peOutValuePoint    = ptL->ptCur;
            return(OK);
        }
        
        iCount ++;
        // 移动单链表
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    
    return(ERROR);
}

/*****************************************************************************
 * 函数名称： ListUpdate()
 * 功能描述： 更新单链表
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示更新成功，ERROR表示位置不合法
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 // ******************************************************************************/

WORD ListUpdate(T_LinkList *ptL, int iInPosition, elemTypeLkL *peInValue)
{
    int iCount = 0;
    // 判断查找位置是否合法
    if ((iInPosition < 1) || (iInPosition > ptL->iNum))
    {
        return(ERROR);
    }
    
    ptL->ptCur = ptL->ptHead;
    // 按位置查找到要修改的单链表并对其进行修改
    while (NULL != ptL->ptCur)
    {
        iCount ++;
        
        if (iCount == iInPosition)
        {
            // 修改单链表
            ptL->ptCur->eData = *peInValue;
            return(OK);
        }
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    
    return(OK);
}

/*****************************************************************************
 * 函数名称： ListInsert()
 * 功能描述： 插入元素到单链表指定位置之后
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示更新成功，ERROR表示位置不合法，OVERFLOW表示空间溢出
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 // ******************************************************************************/

WORD ListInsert(T_LinkList *ptL, int iInPosition, elemTypeLkL *peInValue)
{
    T_ListNode * ptListNodeTmp;
    int iCount = 0;
    
    // 判断插入的位置是否合法
    if ((iInPosition < 0) || (iInPosition > ptL->iNum))
    {
        return(ERROR);
    }
    
    // 给待插入的节点申请一个动态空间
    ptListNodeTmp = (T_ListNode *) malloc (sizeof(T_ListNode));
    // 判断是否申请成功
    if (NULL == ptListNodeTmp)
    {
        return(OVERFLOW);
    }
    // 初始化待插入节点
    ptListNodeTmp->eData  = *peInValue;
    ptListNodeTmp->ptNext = NULL;
    // 待插入的节点插入的位置为第0个节点的位置
    if (0 == iInPosition)
    {
        ptListNodeTmp->ptNext = ptL->ptHead;
        ptL->ptHead = ptListNodeTmp;
        
        ptL->iNum ++;
        return(OK);
    }
    
    ptL->ptCur = ptL->ptHead;
    // 其它节点的位置
    while (NULL != ptL->ptCur)
    {
        iCount ++;
        // 找到该位置并插入到该位置
        if (iCount == iInPosition)
        {
            ptListNodeTmp->ptNext = ptL->ptCur->ptNext;
            ptL->ptCur->ptNext = ptListNodeTmp;
            
            ptL->iNum ++;
            return(OK);
        }
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    return(OK);
}

/*****************************************************************************
 * 函数名称： ListDelete()
 * 功能描述： 删除元素在单链表指定位置
 * 访问的表：
 * 修改的表：
 * 输入参数： 指向单链表的指针
 * 输出参数： 无
 * 返 回 值： OK 表示更新成功，ERROR表示位置不合法
 * 其它说明：
 * 修改日期    版本号     修改人	     修改内容
 * -----------------------------------------------
 * 12/05/01	   V1.0	      XXXX	      XXXX
 // ******************************************************************************/

WORD ListDelete(T_LinkList *ptL, int iInPosition, elemTypeLkL *peOutValue)
{
    int i;
    
    // 检查删除位置是否合法
    if ((iInPosition < 1) || (iInPosition > ptL->iNum))
    {
        return(ERROR);
    }
    
    // 删除结点为第一个结点
    if (1 == iInPosition)
    {
        ptL->ptCur  = ptL->ptHead;
        ptL->ptHead = ptL->ptHead->ptNext;
        ptL->iNum --;
        
        *peOutValue = ptL->ptCur->eData;
        free(ptL->ptCur);
    }
    // 删除结点为其他合法结点
    else
    {
        T_ListNode *ptTemp;
        
        ptL->ptCur = ptL->ptHead;
        for (i = iInPosition-1; i > 0; i--)
        {
            ptL->ptCur = ptL->ptCur->ptNext;
        }
        // 断链并删除节点
        ptTemp = ptL->ptCur->ptNext;
        ptL->ptCur->ptNext = ptTemp->ptNext;
        // 链表长度减一
        ptL->iNum --;
        // 返回删除节点的值 
        *peOutValue = ptTemp->eData;
        free(ptTemp);
    }
    
    return(OK);      // 只要位置合法，一定能找到  
}

/*****************************************************************************
 *                     函数实现--局部部分                                    *
 *****************************************************************************/


