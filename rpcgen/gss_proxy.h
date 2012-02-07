/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _GSS_PROXY_H_RPCGEN
#define _GSS_PROXY_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	u_int utf8string_len;
	char *utf8string_val;
} utf8string;

typedef struct {
	u_int octet_string_len;
	char *octet_string_val;
} octet_string;

typedef u_quad_t gssx_uint64;

typedef u_quad_t gssx_qop;

typedef octet_string gssx_buffer;

typedef octet_string gssx_OID;

typedef struct {
	u_int gssx_OID_set_len;
	gssx_OID *gssx_OID_set_val;
} gssx_OID_set;

enum gssx_cred_usage {
	GSSX_C_INITIATE = 1,
	GSSX_C_ACCEPT = 2,
	GSSX_C_BOTH = 3,
};
typedef enum gssx_cred_usage gssx_cred_usage;

typedef u_quad_t gssx_time;

enum gssx_ext_id {
	GSSX_EXT_NONE = 0,
};
typedef enum gssx_ext_id gssx_ext_id;

struct gssx_typed_hole {
	gssx_ext_id ext_type;
	octet_string ext_data;
};
typedef struct gssx_typed_hole gssx_typed_hole;

struct gssx_mech_attr {
	gssx_OID attr;
	gssx_buffer name;
	gssx_buffer short_desc;
	gssx_buffer long_desc;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_mech_attr gssx_mech_attr;

struct gssx_mech_info {
	gssx_OID mech;
	gssx_OID_set name_types;
	gssx_OID_set mech_attrs;
	gssx_OID_set known_mech_attrs;
	gssx_OID_set cred_options;
	gssx_OID_set sec_ctx_options;
	gssx_buffer saslname_sasl_mech_name;
	gssx_buffer saslname_mech_name;
	gssx_buffer saslname_mech_desc;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_mech_info gssx_mech_info;

struct gssx_name_attr {
	gssx_buffer attr;
	gssx_buffer value;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_name_attr gssx_name_attr;

struct gssx_option {
	gssx_OID option;
	gssx_buffer value;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_option gssx_option;

struct gssx_status {
	gssx_uint64 major_status;
	gssx_OID mech;
	gssx_uint64 minor_status;
	utf8string major_status_string;
	utf8string minor_status_string;
	octet_string server_ctx;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_status gssx_status;

struct gssx_call_ctx {
	utf8string locale;
	octet_string server_ctx;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_call_ctx gssx_call_ctx;

struct gssx_name {
	gssx_buffer display_name;
	gssx_OID name_type;
	gssx_buffer exported_name;
	gssx_buffer exported_composite_name;
	struct {
		u_int name_attributes_len;
		gssx_name_attr *name_attributes_val;
	} name_attributes;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_name gssx_name;

struct gssx_cred_element {
	gssx_name MN;
	gssx_OID mech;
	gssx_cred_usage cred_usage;
	gssx_time initiator_time_rec;
	gssx_time acceptor_time_rec;
	struct {
		u_int cred_options_len;
		gssx_option *cred_options_val;
	} cred_options;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_cred_element gssx_cred_element;

struct gssx_cred {
	gssx_name desired_name;
	struct {
		u_int elements_len;
		gssx_cred_element *elements_val;
	} elements;
	octet_string cred_handle_reference;
	bool_t needs_release;
};
typedef struct gssx_cred gssx_cred;

struct gssx_ctx {
	gssx_buffer *exported_context_token;
	octet_string *state;
	bool_t needs_release;
	gssx_OID mech;
	gssx_name src_name;
	gssx_name targ_name;
	gssx_time lifetime;
	gssx_uint64 ctx_flags;
	bool_t locally_initiated;
	bool_t open;
	struct {
		u_int context_options_len;
		gssx_option *context_options_val;
	} context_options;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_ctx gssx_ctx;

enum gssx_handle_type {
	GSSX_C_HANDLE_SEC_CTX = 0,
	GSSX_C_HANDLE_CRED = 1,
};
typedef enum gssx_handle_type gssx_handle_type;

struct gssx_handle {
	gssx_handle_type handle_type;
	union {
		gssx_cred cred_info;
		gssx_ctx sec_ctx_info;
		octet_string extensions;
	} gssx_handle_u;
};
typedef struct gssx_handle gssx_handle;

struct gssx_cb {
	gssx_uint64 initiator_addrtype;
	gssx_buffer initiator_address;
	gssx_uint64 acceptor_addrtype;
	gssx_buffer acceptor_address;
	gssx_buffer application_data;
};
typedef struct gssx_cb gssx_cb;


struct gssx_arg_release_handle {
	gssx_call_ctx call_ctx;
	gssx_handle cred_handle;
};
typedef struct gssx_arg_release_handle gssx_arg_release_handle;

struct gssx_res_release_handle {
	gssx_status status;
};
typedef struct gssx_res_release_handle gssx_res_release_handle;

struct gssx_arg_indicate_mechs {
	gssx_call_ctx call_ctx;
};
typedef struct gssx_arg_indicate_mechs gssx_arg_indicate_mechs;

struct gssx_res_indicate_mechs {
	gssx_status status;
	struct {
		u_int mechs_len;
		gssx_mech_info *mechs_val;
	} mechs;
	struct {
		u_int mech_attr_descs_len;
		gssx_mech_attr *mech_attr_descs_val;
	} mech_attr_descs;
	struct {
		u_int supported_extensions_len;
		gssx_ext_id *supported_extensions_val;
	} supported_extensions;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_indicate_mechs gssx_res_indicate_mechs;

struct gssx_arg_import_and_canon_name {
	gssx_call_ctx call_ctx;
	gssx_name input_name;
	gssx_OID mech;
	struct {
		u_int name_attributes_len;
		gssx_name_attr *name_attributes_val;
	} name_attributes;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_arg_import_and_canon_name gssx_arg_import_and_canon_name;

struct gssx_res_import_and_canon_name {
	gssx_status status;
	gssx_name *output_name;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_import_and_canon_name gssx_res_import_and_canon_name;

struct gssx_arg_get_call_context {
	gssx_call_ctx call_ctx;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_arg_get_call_context gssx_arg_get_call_context;

struct gssx_res_get_call_context {
	gssx_status status;
	octet_string server_call_ctx;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_get_call_context gssx_res_get_call_context;

struct gssx_arg_acquire_cred {
	gssx_call_ctx call_ctx;
	struct {
		u_int cred_options_len;
		gssx_option *cred_options_val;
	} cred_options;
	gssx_cred *input_cred_handle;
	bool_t add_cred_to_input_handle;
	gssx_name *desired_name;
	gssx_time time_req;
	gssx_OID_set desired_mechs;
	gssx_cred_usage cred_usage;
	gssx_time initiator_time_req;
	gssx_time acceptor_time_req;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_arg_acquire_cred gssx_arg_acquire_cred;

struct gssx_res_acquire_cred {
	gssx_status status;
	gssx_cred *output_cred_handle;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_acquire_cred gssx_res_acquire_cred;

struct gssx_arg_export_cred {
	gssx_call_ctx call_ctx;
	gssx_cred input_cred_handle;
	gssx_cred_usage cred_usage;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_arg_export_cred gssx_arg_export_cred;

struct gssx_res_export_cred {
	gssx_status status;
	gssx_cred_usage usage_exported;
	octet_string *exported_handle;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_export_cred gssx_res_export_cred;

struct gssx_arg_import_cred {
	gssx_call_ctx call_ctx;
	octet_string exported_handle;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_arg_import_cred gssx_arg_import_cred;

struct gssx_res_import_cred {
	gssx_status status;
	gssx_cred *output_cred_handle;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_import_cred gssx_res_import_cred;

struct gssx_arg_store_cred {
	gssx_call_ctx call_ctx;
	gssx_cred input_cred_handle;
	gssx_cred_usage cred_usage;
	gssx_OID desired_mech;
	bool_t overwrite_cred;
	bool_t default_cred;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_arg_store_cred gssx_arg_store_cred;

struct gssx_res_store_cred {
	gssx_status status;
	gssx_OID_set elements_stored;
	gssx_cred_usage cred_usage_stored;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_store_cred gssx_res_store_cred;

struct gssx_arg_init_sec_context {
	gssx_call_ctx call_ctx;
	struct {
		u_int context_options_len;
		gssx_option *context_options_val;
	} context_options;
	gssx_ctx *context_handle;
	gssx_cred *cred_handle;
	gssx_name *target_name;
	gssx_OID mech_type;
	gssx_uint64 req_flags;
	gssx_time time_req;
	gssx_cb *input_cb;
	gssx_buffer *input_token;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_arg_init_sec_context gssx_arg_init_sec_context;

struct gssx_res_init_sec_context {
	gssx_status status;
	gssx_ctx *context_handle;
	gssx_buffer *output_token;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_init_sec_context gssx_res_init_sec_context;

struct gssx_arg_accept_sec_context {
	gssx_call_ctx call_ctx;
	struct {
		u_int context_options_len;
		gssx_option *context_options_val;
	} context_options;
	gssx_ctx *context_handle;
	gssx_cred *cred_handle;
	gssx_buffer input_token;
	gssx_cb *input_cb;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_arg_accept_sec_context gssx_arg_accept_sec_context;

struct gssx_res_accept_sec_context {
	gssx_status status;
	gssx_ctx *context_handle;
	gssx_buffer *output_token;
	gssx_cred *delegated_cred_handle;
	struct {
		u_int extensions_len;
		gssx_typed_hole *extensions_val;
	} extensions;
};
typedef struct gssx_res_accept_sec_context gssx_res_accept_sec_context;

struct gssx_arg_get_mic {
	gssx_call_ctx call_ctx;
	gssx_ctx context_handle;
	gssx_qop qop_req;
	gssx_buffer message_buffer;
};
typedef struct gssx_arg_get_mic gssx_arg_get_mic;

struct gssx_res_get_mic {
	gssx_status status;
	gssx_ctx *context_handle;
	gssx_buffer token_buffer;
	gssx_qop *qop_state;
};
typedef struct gssx_res_get_mic gssx_res_get_mic;

struct gssx_arg_verify_mic {
	gssx_call_ctx call_ctx;
	gssx_ctx context_handle;
	gssx_buffer message_buffer;
	gssx_buffer token_buffer;
};
typedef struct gssx_arg_verify_mic gssx_arg_verify_mic;

struct gssx_res_verify_mic {
	gssx_status status;
	gssx_ctx *context_handle;
	gssx_qop *qop_state;
};
typedef struct gssx_res_verify_mic gssx_res_verify_mic;

struct gssx_arg_wrap {
	gssx_call_ctx call_ctx;
	gssx_ctx context_handle;
	bool_t conf_req;
	struct {
		u_int message_buffer_len;
		gssx_buffer *message_buffer_val;
	} message_buffer;
	gssx_qop qop_state;
};
typedef struct gssx_arg_wrap gssx_arg_wrap;

struct gssx_res_wrap {
	gssx_status status;
	gssx_ctx *context_handle;
	struct {
		u_int token_buffer_len;
		gssx_buffer *token_buffer_val;
	} token_buffer;
	bool_t *conf_state;
	gssx_qop *qop_state;
};
typedef struct gssx_res_wrap gssx_res_wrap;

struct gssx_arg_unwrap {
	gssx_call_ctx call_ctx;
	gssx_ctx context_handle;
	struct {
		u_int token_buffer_len;
		gssx_buffer *token_buffer_val;
	} token_buffer;
	gssx_qop qop_state;
};
typedef struct gssx_arg_unwrap gssx_arg_unwrap;

struct gssx_res_unwrap {
	gssx_status status;
	gssx_ctx *context_handle;
	struct {
		u_int message_buffer_len;
		gssx_buffer *message_buffer_val;
	} message_buffer;
	bool_t *conf_state;
	gssx_qop *qop_state;
};
typedef struct gssx_res_unwrap gssx_res_unwrap;

struct gssx_arg_wrap_size_limit {
	gssx_call_ctx call_ctx;
	gssx_ctx context_handle;
	bool_t conf_req;
	gssx_qop qop_state;
	gssx_uint64 req_output_size;
};
typedef struct gssx_arg_wrap_size_limit gssx_arg_wrap_size_limit;

struct gssx_res_wrap_size_limit {
	gssx_status status;
	gssx_uint64 max_input_size;
};
typedef struct gssx_res_wrap_size_limit gssx_res_wrap_size_limit;

#define GSSPROXY 412345
#define GSSPROXYVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define GSSX_INDICATE_MECHS 1
extern  gssx_res_indicate_mechs * gssx_indicate_mechs_1(gssx_arg_indicate_mechs *, CLIENT *);
extern  gssx_res_indicate_mechs * gssx_indicate_mechs_1_svc(gssx_arg_indicate_mechs *, struct svc_req *);
#define GSSX_GET_CALL_CONTEXT 2
extern  gssx_res_get_call_context * gssx_get_call_context_1(gssx_arg_get_call_context *, CLIENT *);
extern  gssx_res_get_call_context * gssx_get_call_context_1_svc(gssx_arg_get_call_context *, struct svc_req *);
#define GSSX_IMPORT_AND_CANON_NAME 3
extern  gssx_res_import_and_canon_name * gssx_import_and_canon_name_1(gssx_arg_import_and_canon_name *, CLIENT *);
extern  gssx_res_import_and_canon_name * gssx_import_and_canon_name_1_svc(gssx_arg_import_and_canon_name *, struct svc_req *);
#define GSSX_EXPORT_CRED 4
extern  gssx_res_export_cred * gssx_export_cred_1(gssx_arg_export_cred *, CLIENT *);
extern  gssx_res_export_cred * gssx_export_cred_1_svc(gssx_arg_export_cred *, struct svc_req *);
#define GSSX_IMPORT_CRED 5
extern  gssx_res_import_cred * gssx_import_cred_1(gssx_arg_import_cred *, CLIENT *);
extern  gssx_res_import_cred * gssx_import_cred_1_svc(gssx_arg_import_cred *, struct svc_req *);
#define GSSX_ACQUIRE_CRED 6
extern  gssx_res_acquire_cred * gssx_acquire_cred_1(gssx_arg_acquire_cred *, CLIENT *);
extern  gssx_res_acquire_cred * gssx_acquire_cred_1_svc(gssx_arg_acquire_cred *, struct svc_req *);
#define GSSX_STORE_CRED 7
extern  gssx_res_store_cred * gssx_store_cred_1(gssx_arg_store_cred *, CLIENT *);
extern  gssx_res_store_cred * gssx_store_cred_1_svc(gssx_arg_store_cred *, struct svc_req *);
#define GSSX_INIT_SEC_CONTEXT 8
extern  gssx_res_init_sec_context * gssx_init_sec_context_1(gssx_arg_init_sec_context *, CLIENT *);
extern  gssx_res_init_sec_context * gssx_init_sec_context_1_svc(gssx_arg_init_sec_context *, struct svc_req *);
#define GSSX_ACCEPT_SEC_CONTEXT 9
extern  gssx_res_accept_sec_context * gssx_accept_sec_context_1(gssx_arg_accept_sec_context *, CLIENT *);
extern  gssx_res_accept_sec_context * gssx_accept_sec_context_1_svc(gssx_arg_accept_sec_context *, struct svc_req *);
#define GSSX_RELEASE_HANDLE 10
extern  gssx_res_release_handle * gssx_release_handle_1(gssx_arg_release_handle *, CLIENT *);
extern  gssx_res_release_handle * gssx_release_handle_1_svc(gssx_arg_release_handle *, struct svc_req *);
#define GSSX_GET_MIC 11
extern  gssx_res_get_mic * gssx_get_mic_1(gssx_arg_get_mic *, CLIENT *);
extern  gssx_res_get_mic * gssx_get_mic_1_svc(gssx_arg_get_mic *, struct svc_req *);
#define GSSX_VERIFY 12
extern  gssx_res_verify_mic * gssx_verify_1(gssx_arg_verify_mic *, CLIENT *);
extern  gssx_res_verify_mic * gssx_verify_1_svc(gssx_arg_verify_mic *, struct svc_req *);
#define GSSX_WRAP 13
extern  gssx_res_wrap * gssx_wrap_1(gssx_arg_wrap *, CLIENT *);
extern  gssx_res_wrap * gssx_wrap_1_svc(gssx_arg_wrap *, struct svc_req *);
#define GSSX_UNWRAP 14
extern  gssx_res_unwrap * gssx_unwrap_1(gssx_arg_unwrap *, CLIENT *);
extern  gssx_res_unwrap * gssx_unwrap_1_svc(gssx_arg_unwrap *, struct svc_req *);
#define GSSX_WRAP_SIZE_LIMIT 15
extern  gssx_res_wrap_size_limit * gssx_wrap_size_limit_1(gssx_arg_wrap_size_limit *, CLIENT *);
extern  gssx_res_wrap_size_limit * gssx_wrap_size_limit_1_svc(gssx_arg_wrap_size_limit *, struct svc_req *);
extern int gssproxy_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define GSSX_INDICATE_MECHS 1
extern  gssx_res_indicate_mechs * gssx_indicate_mechs_1();
extern  gssx_res_indicate_mechs * gssx_indicate_mechs_1_svc();
#define GSSX_GET_CALL_CONTEXT 2
extern  gssx_res_get_call_context * gssx_get_call_context_1();
extern  gssx_res_get_call_context * gssx_get_call_context_1_svc();
#define GSSX_IMPORT_AND_CANON_NAME 3
extern  gssx_res_import_and_canon_name * gssx_import_and_canon_name_1();
extern  gssx_res_import_and_canon_name * gssx_import_and_canon_name_1_svc();
#define GSSX_EXPORT_CRED 4
extern  gssx_res_export_cred * gssx_export_cred_1();
extern  gssx_res_export_cred * gssx_export_cred_1_svc();
#define GSSX_IMPORT_CRED 5
extern  gssx_res_import_cred * gssx_import_cred_1();
extern  gssx_res_import_cred * gssx_import_cred_1_svc();
#define GSSX_ACQUIRE_CRED 6
extern  gssx_res_acquire_cred * gssx_acquire_cred_1();
extern  gssx_res_acquire_cred * gssx_acquire_cred_1_svc();
#define GSSX_STORE_CRED 7
extern  gssx_res_store_cred * gssx_store_cred_1();
extern  gssx_res_store_cred * gssx_store_cred_1_svc();
#define GSSX_INIT_SEC_CONTEXT 8
extern  gssx_res_init_sec_context * gssx_init_sec_context_1();
extern  gssx_res_init_sec_context * gssx_init_sec_context_1_svc();
#define GSSX_ACCEPT_SEC_CONTEXT 9
extern  gssx_res_accept_sec_context * gssx_accept_sec_context_1();
extern  gssx_res_accept_sec_context * gssx_accept_sec_context_1_svc();
#define GSSX_RELEASE_HANDLE 10
extern  gssx_res_release_handle * gssx_release_handle_1();
extern  gssx_res_release_handle * gssx_release_handle_1_svc();
#define GSSX_GET_MIC 11
extern  gssx_res_get_mic * gssx_get_mic_1();
extern  gssx_res_get_mic * gssx_get_mic_1_svc();
#define GSSX_VERIFY 12
extern  gssx_res_verify_mic * gssx_verify_1();
extern  gssx_res_verify_mic * gssx_verify_1_svc();
#define GSSX_WRAP 13
extern  gssx_res_wrap * gssx_wrap_1();
extern  gssx_res_wrap * gssx_wrap_1_svc();
#define GSSX_UNWRAP 14
extern  gssx_res_unwrap * gssx_unwrap_1();
extern  gssx_res_unwrap * gssx_unwrap_1_svc();
#define GSSX_WRAP_SIZE_LIMIT 15
extern  gssx_res_wrap_size_limit * gssx_wrap_size_limit_1();
extern  gssx_res_wrap_size_limit * gssx_wrap_size_limit_1_svc();
extern int gssproxy_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_utf8string (XDR *, utf8string*);
extern  bool_t xdr_octet_string (XDR *, octet_string*);
extern  bool_t xdr_gssx_uint64 (XDR *, gssx_uint64*);
extern  bool_t xdr_gssx_qop (XDR *, gssx_qop*);
extern  bool_t xdr_gssx_buffer (XDR *, gssx_buffer*);
extern  bool_t xdr_gssx_OID (XDR *, gssx_OID*);
extern  bool_t xdr_gssx_OID_set (XDR *, gssx_OID_set*);
extern  bool_t xdr_gssx_cred_usage (XDR *, gssx_cred_usage*);
extern  bool_t xdr_gssx_time (XDR *, gssx_time*);
extern  bool_t xdr_gssx_ext_id (XDR *, gssx_ext_id*);
extern  bool_t xdr_gssx_typed_hole (XDR *, gssx_typed_hole*);
extern  bool_t xdr_gssx_mech_attr (XDR *, gssx_mech_attr*);
extern  bool_t xdr_gssx_mech_info (XDR *, gssx_mech_info*);
extern  bool_t xdr_gssx_name_attr (XDR *, gssx_name_attr*);
extern  bool_t xdr_gssx_option (XDR *, gssx_option*);
extern  bool_t xdr_gssx_status (XDR *, gssx_status*);
extern  bool_t xdr_gssx_call_ctx (XDR *, gssx_call_ctx*);
extern  bool_t xdr_gssx_name (XDR *, gssx_name*);
extern  bool_t xdr_gssx_cred_element (XDR *, gssx_cred_element*);
extern  bool_t xdr_gssx_cred (XDR *, gssx_cred*);
extern  bool_t xdr_gssx_ctx (XDR *, gssx_ctx*);
extern  bool_t xdr_gssx_handle_type (XDR *, gssx_handle_type*);
extern  bool_t xdr_gssx_handle (XDR *, gssx_handle*);
extern  bool_t xdr_gssx_cb (XDR *, gssx_cb*);
extern  bool_t xdr_gssx_cb (XDR *, gssx_cb*);
extern  bool_t xdr_gssx_arg_release_handle (XDR *, gssx_arg_release_handle*);
extern  bool_t xdr_gssx_res_release_handle (XDR *, gssx_res_release_handle*);
extern  bool_t xdr_gssx_arg_indicate_mechs (XDR *, gssx_arg_indicate_mechs*);
extern  bool_t xdr_gssx_res_indicate_mechs (XDR *, gssx_res_indicate_mechs*);
extern  bool_t xdr_gssx_arg_import_and_canon_name (XDR *, gssx_arg_import_and_canon_name*);
extern  bool_t xdr_gssx_res_import_and_canon_name (XDR *, gssx_res_import_and_canon_name*);
extern  bool_t xdr_gssx_arg_get_call_context (XDR *, gssx_arg_get_call_context*);
extern  bool_t xdr_gssx_res_get_call_context (XDR *, gssx_res_get_call_context*);
extern  bool_t xdr_gssx_arg_acquire_cred (XDR *, gssx_arg_acquire_cred*);
extern  bool_t xdr_gssx_res_acquire_cred (XDR *, gssx_res_acquire_cred*);
extern  bool_t xdr_gssx_arg_export_cred (XDR *, gssx_arg_export_cred*);
extern  bool_t xdr_gssx_res_export_cred (XDR *, gssx_res_export_cred*);
extern  bool_t xdr_gssx_arg_import_cred (XDR *, gssx_arg_import_cred*);
extern  bool_t xdr_gssx_res_import_cred (XDR *, gssx_res_import_cred*);
extern  bool_t xdr_gssx_arg_store_cred (XDR *, gssx_arg_store_cred*);
extern  bool_t xdr_gssx_res_store_cred (XDR *, gssx_res_store_cred*);
extern  bool_t xdr_gssx_arg_init_sec_context (XDR *, gssx_arg_init_sec_context*);
extern  bool_t xdr_gssx_res_init_sec_context (XDR *, gssx_res_init_sec_context*);
extern  bool_t xdr_gssx_arg_accept_sec_context (XDR *, gssx_arg_accept_sec_context*);
extern  bool_t xdr_gssx_res_accept_sec_context (XDR *, gssx_res_accept_sec_context*);
extern  bool_t xdr_gssx_arg_get_mic (XDR *, gssx_arg_get_mic*);
extern  bool_t xdr_gssx_res_get_mic (XDR *, gssx_res_get_mic*);
extern  bool_t xdr_gssx_arg_verify_mic (XDR *, gssx_arg_verify_mic*);
extern  bool_t xdr_gssx_res_verify_mic (XDR *, gssx_res_verify_mic*);
extern  bool_t xdr_gssx_arg_wrap (XDR *, gssx_arg_wrap*);
extern  bool_t xdr_gssx_res_wrap (XDR *, gssx_res_wrap*);
extern  bool_t xdr_gssx_arg_unwrap (XDR *, gssx_arg_unwrap*);
extern  bool_t xdr_gssx_res_unwrap (XDR *, gssx_res_unwrap*);
extern  bool_t xdr_gssx_arg_wrap_size_limit (XDR *, gssx_arg_wrap_size_limit*);
extern  bool_t xdr_gssx_res_wrap_size_limit (XDR *, gssx_res_wrap_size_limit*);

#else /* K&R C */
extern bool_t xdr_utf8string ();
extern bool_t xdr_octet_string ();
extern bool_t xdr_gssx_uint64 ();
extern bool_t xdr_gssx_qop ();
extern bool_t xdr_gssx_buffer ();
extern bool_t xdr_gssx_OID ();
extern bool_t xdr_gssx_OID_set ();
extern bool_t xdr_gssx_cred_usage ();
extern bool_t xdr_gssx_time ();
extern bool_t xdr_gssx_ext_id ();
extern bool_t xdr_gssx_typed_hole ();
extern bool_t xdr_gssx_mech_attr ();
extern bool_t xdr_gssx_mech_info ();
extern bool_t xdr_gssx_name_attr ();
extern bool_t xdr_gssx_option ();
extern bool_t xdr_gssx_status ();
extern bool_t xdr_gssx_call_ctx ();
extern bool_t xdr_gssx_name ();
extern bool_t xdr_gssx_cred_element ();
extern bool_t xdr_gssx_cred ();
extern bool_t xdr_gssx_ctx ();
extern bool_t xdr_gssx_handle_type ();
extern bool_t xdr_gssx_handle ();
extern bool_t xdr_gssx_cb ();
extern bool_t xdr_gssx_cb ();
extern bool_t xdr_gssx_arg_release_handle ();
extern bool_t xdr_gssx_res_release_handle ();
extern bool_t xdr_gssx_arg_indicate_mechs ();
extern bool_t xdr_gssx_res_indicate_mechs ();
extern bool_t xdr_gssx_arg_import_and_canon_name ();
extern bool_t xdr_gssx_res_import_and_canon_name ();
extern bool_t xdr_gssx_arg_get_call_context ();
extern bool_t xdr_gssx_res_get_call_context ();
extern bool_t xdr_gssx_arg_acquire_cred ();
extern bool_t xdr_gssx_res_acquire_cred ();
extern bool_t xdr_gssx_arg_export_cred ();
extern bool_t xdr_gssx_res_export_cred ();
extern bool_t xdr_gssx_arg_import_cred ();
extern bool_t xdr_gssx_res_import_cred ();
extern bool_t xdr_gssx_arg_store_cred ();
extern bool_t xdr_gssx_res_store_cred ();
extern bool_t xdr_gssx_arg_init_sec_context ();
extern bool_t xdr_gssx_res_init_sec_context ();
extern bool_t xdr_gssx_arg_accept_sec_context ();
extern bool_t xdr_gssx_res_accept_sec_context ();
extern bool_t xdr_gssx_arg_get_mic ();
extern bool_t xdr_gssx_res_get_mic ();
extern bool_t xdr_gssx_arg_verify_mic ();
extern bool_t xdr_gssx_res_verify_mic ();
extern bool_t xdr_gssx_arg_wrap ();
extern bool_t xdr_gssx_res_wrap ();
extern bool_t xdr_gssx_arg_unwrap ();
extern bool_t xdr_gssx_res_unwrap ();
extern bool_t xdr_gssx_arg_wrap_size_limit ();
extern bool_t xdr_gssx_res_wrap_size_limit ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_GSS_PROXY_H_RPCGEN */
