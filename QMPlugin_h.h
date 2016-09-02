

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Aug 31 14:00:06 2016
 */
/* Compiler settings for QMPlugin.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __QMPlugin_h_h__
#define __QMPlugin_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IQMPlugin_FWD_DEFINED__
#define __IQMPlugin_FWD_DEFINED__
typedef interface IQMPlugin IQMPlugin;

#endif 	/* __IQMPlugin_FWD_DEFINED__ */


#ifndef __IQMPluginStandard_FWD_DEFINED__
#define __IQMPluginStandard_FWD_DEFINED__
typedef interface IQMPluginStandard IQMPluginStandard;

#endif 	/* __IQMPluginStandard_FWD_DEFINED__ */


#ifndef __QMPlugin_FWD_DEFINED__
#define __QMPlugin_FWD_DEFINED__

#ifdef __cplusplus
typedef class QMPlugin QMPlugin;
#else
typedef struct QMPlugin QMPlugin;
#endif /* __cplusplus */

#endif 	/* __QMPlugin_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __QMPlugin_LIBRARY_DEFINED__
#define __QMPlugin_LIBRARY_DEFINED__

/* library QMPlugin */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_QMPlugin;

#ifndef __IQMPlugin_DISPINTERFACE_DEFINED__
#define __IQMPlugin_DISPINTERFACE_DEFINED__

/* dispinterface IQMPlugin */
/* [uuid] */ 


EXTERN_C const IID DIID_IQMPlugin;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EB62CBA9-5F62-44DF-9154-D33BF5DF213B")
    IQMPlugin : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IQMPluginVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IQMPlugin * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IQMPlugin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IQMPlugin * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IQMPlugin * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IQMPlugin * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IQMPlugin * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IQMPlugin * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IQMPluginVtbl;

    interface IQMPlugin
    {
        CONST_VTBL struct IQMPluginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQMPlugin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IQMPlugin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IQMPlugin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IQMPlugin_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IQMPlugin_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IQMPlugin_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IQMPlugin_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IQMPlugin_DISPINTERFACE_DEFINED__ */


#ifndef __IQMPluginStandard_DISPINTERFACE_DEFINED__
#define __IQMPluginStandard_DISPINTERFACE_DEFINED__

/* dispinterface IQMPluginStandard */
/* [uuid] */ 


EXTERN_C const IID DIID_IQMPluginStandard;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EE1035BA-1025-4cde-AD4C-A04B3878BF00")
    IQMPluginStandard : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IQMPluginStandardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IQMPluginStandard * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IQMPluginStandard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IQMPluginStandard * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IQMPluginStandard * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IQMPluginStandard * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IQMPluginStandard * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IQMPluginStandard * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IQMPluginStandardVtbl;

    interface IQMPluginStandard
    {
        CONST_VTBL struct IQMPluginStandardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQMPluginStandard_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IQMPluginStandard_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IQMPluginStandard_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IQMPluginStandard_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IQMPluginStandard_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IQMPluginStandard_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IQMPluginStandard_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IQMPluginStandard_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_QMPlugin;

#ifdef __cplusplus

class DECLSPEC_UUID("B0103678-8D56-4946-9C47-59B02AA4D91C")
QMPlugin;
#endif
#endif /* __QMPlugin_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


