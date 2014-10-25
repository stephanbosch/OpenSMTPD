/*	$OpenBSD: rfc822.h,v 1.2 2014/10/15 08:04:41 gilles Exp $	*/

/*
 * Copyright (c) 2014 Gilles Chehade <gilles@poolp.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
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

#ifndef _RFC822_H_
#define	_RFC822_H_

#define	RFC822_MAX_LINE_SIZE	998
#define	RFC822_MAX_BUFFERS	1000

struct rfc822_address {
	TAILQ_ENTRY(rfc822_address)	next;
	char				name[RFC822_MAX_LINE_SIZE+1];
	char				address[RFC822_MAX_LINE_SIZE+1];
};

struct rfc822_parser {
	size_t					count;
	TAILQ_HEAD(addresses, rfc822_address)	addresses;

	struct rfc822_address		*ra;

	uint8_t				quote;
	uint8_t				comment;
	uint8_t				escape;
	uint8_t				bracket;
};

void	rfc822_parser_init(struct rfc822_parser *);
void	rfc822_parser_reset(struct rfc822_parser *);
void	rfc822_parser_finish(struct rfc822_parser *);
int	rfc822_parser_feed(struct rfc822_parser *, const char *);

#endif