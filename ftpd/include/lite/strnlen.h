/* strnlen.h - Re-implementation of GLIBC strnlen()
 *
 * Copyright (c) 2016-2020  Joachim Nilsson <troglobit@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef LITE_STRNLEN_H_
#define LITE_STRNLEN_H_

#if !defined(HAVE_STRNLEN)
#if defined(strnlen)
#define HAVE_STRNLEN	1
#endif
#endif

#if !HAVE_STRNLEN
#include <stddef.h>	/* size_t */

#define strnlen(str, lim) xstrnlen(str, lim)

static inline size_t xstrnlen(const char *str, size_t lim)
{
	size_t i = 0;

	while (str[i] && i < lim)
		i++;

	return i;
}
#endif

#endif /* LITE_STRNLEN_H_ */

#ifdef __cplusplus
}
#endif