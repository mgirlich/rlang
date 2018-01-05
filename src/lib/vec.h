#ifndef RLANG_VECTOR_H
#define RLANG_VECTOR_H


r_size_t r_vec_length(sexp* x);


static inline int* r_lgl_deref(sexp* x) {
  return LOGICAL(x);
}
static inline int* r_int_deref(sexp* x) {
  return INTEGER(x);
}
static inline double* r_dbl_deref(sexp* x) {
  return REAL(x);
}
static inline r_complex_t* r_cpl_deref(sexp* x) {
  return COMPLEX(x);
}
static inline r_byte_t* r_raw_deref(sexp* x) {
  return RAW(x);
}

static inline int r_lgl_get(sexp* x, r_size_t i) {
  return LOGICAL(x)[i];
}
static inline int r_int_get(sexp* x, r_size_t i) {
  return INTEGER(x)[i];
}
static inline double r_dbl_get(sexp* x, r_size_t i) {
  return REAL(x)[i];
}
static inline r_complex_t r_cpl_get(sexp* x, r_size_t i) {
  return COMPLEX(x)[i];
}
static inline r_byte_t r_raw_get(sexp* x, r_size_t i) {
  return RAW(x)[i];
}


bool r_is_list(sexp* x);
bool r_is_vector(sexp* x);
bool r_is_scalar_atomic(sexp* x);
bool r_is_atomic(sexp* x);
bool r_is_integerish(sexp* x);

static inline bool r_is_scalar_character(sexp* x) {
  return r_typeof(x) == r_type_character && r_length(x) == 1;
}
static inline bool r_is_scalar_logical(sexp* x) {
  return r_typeof(x) == r_type_logical && r_length(x) == 1;
}

static inline sexp* r_scalar_lgl(bool x) {
  return Rf_ScalarLogical(x);
}
static inline sexp* r_scalar_int(int x) {
  return Rf_ScalarInteger(x);
}

static inline int r_c_int(sexp* x) {
  return INTEGER(x)[0];
}

static inline sexp* r_new_vector(enum r_type type, r_size_t n) {
  return Rf_allocVector(type, n);
}
static inline sexp* r_vec_coerce(sexp* x, enum r_type to) {
  return Rf_coerceVector(x, to);
}

void r_vec_poke_n(sexp* x, r_size_t offset,
                  sexp* y, r_size_t from, r_size_t n);
void r_vec_poke_range(sexp* x, r_size_t offset,
                      sexp* y, r_size_t from, r_size_t to);

void r_vec_poke_coerce_n(sexp* x, r_size_t offset,
                         sexp* y, r_size_t from, r_size_t n);
void r_vec_poke_coerce_range(sexp* x, r_size_t offset,
                             sexp* y, r_size_t from, r_size_t to);


#endif
