#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "elinks.h"

#include "document/dom/ecmascript/spidermonkey.h"
#include "document/dom/ecmascript/spidermonkey/Node.h"
#include "document/dom/ecmascript/spidermonkey/html/HTMLTableCellElement.h"
#include "dom/node.h"

static JSBool
HTMLTableCellElement_getProperty(JSContext *ctx, JSObject *obj, jsval id, jsval *vp)
{
	struct dom_node *node;
	struct TD_struct *html;

	if (!JSVAL_IS_INT(id))
		return JS_TRUE;

	if (!obj || (!JS_InstanceOf(ctx, obj, (JSClass *)&HTMLTableCellElement_class, NULL)))
		return JS_FALSE;

	node = JS_GetPrivate(ctx, obj);
	if (!node)
		return JS_FALSE;
	html = node->data.element.html_data;
	if (!html)
		return JS_FALSE;

	switch (JSVAL_TO_INT(id)) {
	case JSP_HTML_TABLE_CELL_ELEMENT_CELL_INDEX:
		int_to_jsval(ctx, vp, html->cell_index);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_ABBR:
		string_to_jsval(ctx, vp, html->abbr);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_ALIGN:
		string_to_jsval(ctx, vp, html->align);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_AXIS:
		string_to_jsval(ctx, vp, html->axis);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_BGCOLOR:
		string_to_jsval(ctx, vp, html->bgcolor);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_CH:
		string_to_jsval(ctx, vp, html->ch);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_CH_OFF:
		string_to_jsval(ctx, vp, html->ch_off);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_COL_SPAN:
		int_to_jsval(ctx, vp, html->col_span);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_HEADERS:
		string_to_jsval(ctx, vp, html->headers);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_HEIGHT:
		string_to_jsval(ctx, vp, html->height);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_NO_WRAP:
		boolean_to_jsval(ctx, vp, html->no_wrap);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_ROW_SPAN:
		int_to_jsval(ctx, vp, html->row_span);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_SCOPE:
		string_to_jsval(ctx, vp, html->scope);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_VALIGN:
		string_to_jsval(ctx, vp, html->valign);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_WIDTH:
		string_to_jsval(ctx, vp, html->width);
		break;
	default:
		return HTMLElement_getProperty(ctx, obj, id, vp);
	}
	return JS_TRUE;
}

static JSBool
HTMLTableCellElement_setProperty(JSContext *ctx, JSObject *obj, jsval id, jsval *vp)
{
	struct dom_node *node;
	struct TD_struct *html;

	if (!JSVAL_IS_INT(id))
		return JS_TRUE;

	if (!obj || (!JS_InstanceOf(ctx, obj, (JSClass *)&HTMLTableCellElement_class, NULL)))
		return JS_FALSE;

	node = JS_GetPrivate(ctx, obj);
	if (!node)
		return JS_FALSE;
	html = node->data.element.html_data;
	if (!html)
		return JS_FALSE;

	switch (JSVAL_TO_INT(id)) {
	case JSP_HTML_TABLE_CELL_ELEMENT_ABBR:
		mem_free_set(&html->abbr, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_ALIGN:
		mem_free_set(&html->align, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_AXIS:
		mem_free_set(&html->axis, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_BGCOLOR:
		mem_free_set(&html->bgcolor, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_CH:
		mem_free_set(&html->ch, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_CH_OFF:
		mem_free_set(&html->ch_off, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_COL_SPAN:
		return JS_ValueToInt32(ctx, *vp, &html->col_span);
	case JSP_HTML_TABLE_CELL_ELEMENT_HEADERS:
		mem_free_set(&html->headers, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_HEIGHT:
		mem_free_set(&html->height, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_NO_WRAP:
		html->no_wrap = jsval_to_boolean(ctx, vp);
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_ROW_SPAN:
		return JS_ValueToInt32(ctx, *vp, &html->row_span);
	case JSP_HTML_TABLE_CELL_ELEMENT_SCOPE:
		mem_free_set(&html->scope, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_VALIGN:
		mem_free_set(&html->valign, stracpy(jsval_to_string(ctx, vp)));
		break;
	case JSP_HTML_TABLE_CELL_ELEMENT_WIDTH:
		mem_free_set(&html->width, stracpy(jsval_to_string(ctx, vp)));
		break;
	default:
		return HTMLElement_setProperty(ctx, obj, id, vp);
	}
	return JS_TRUE;
}

const JSPropertySpec HTMLTableCellElement_props[] = {
	{ "cellIndex",	JSP_HTML_TABLE_CELL_ELEMENT_CELL_INDEX,	JSPROP_ENUMERATE | JSPROP_READONLY },
	{ "abbr",	JSP_HTML_TABLE_CELL_ELEMENT_ABBR,	JSPROP_ENUMERATE },
	{ "align",	JSP_HTML_TABLE_CELL_ELEMENT_ALIGN,	JSPROP_ENUMERATE },
	{ "axis",	JSP_HTML_TABLE_CELL_ELEMENT_AXIS,	JSPROP_ENUMERATE },
	{ "bgColor",	JSP_HTML_TABLE_CELL_ELEMENT_BGCOLOR,	JSPROP_ENUMERATE },
	{ "ch",		JSP_HTML_TABLE_CELL_ELEMENT_CH,		JSPROP_ENUMERATE },
	{ "chOff",	JSP_HTML_TABLE_CELL_ELEMENT_CH_OFF,	JSPROP_ENUMERATE },
	{ "colSpan",	JSP_HTML_TABLE_CELL_ELEMENT_COL_SPAN,	JSPROP_ENUMERATE },
	{ "headers",	JSP_HTML_TABLE_CELL_ELEMENT_HEADERS,	JSPROP_ENUMERATE },
	{ "height",	JSP_HTML_TABLE_CELL_ELEMENT_HEIGHT,	JSPROP_ENUMERATE },
	{ "noWrap",	JSP_HTML_TABLE_CELL_ELEMENT_NO_WRAP,	JSPROP_ENUMERATE },
	{ "rowSpan",	JSP_HTML_TABLE_CELL_ELEMENT_ROW_SPAN,	JSPROP_ENUMERATE },
	{ "scope",	JSP_HTML_TABLE_CELL_ELEMENT_SCOPE,	JSPROP_ENUMERATE },
	{ "vAlign",	JSP_HTML_TABLE_CELL_ELEMENT_VALIGN,	JSPROP_ENUMERATE },
	{ "width",	JSP_HTML_TABLE_CELL_ELEMENT_WIDTH,	JSPROP_ENUMERATE },
	{ NULL }
};

const JSFunctionSpec HTMLTableCellElement_funcs[] = {
	{ NULL }
};

const JSClass HTMLTableCellElement_class = {
	"HTMLTableCellElement",
	JSCLASS_HAS_PRIVATE,
	JS_PropertyStub, JS_PropertyStub,
	HTMLTableCellElement_getProperty, HTMLTableCellElement_setProperty,
	JS_EnumerateStub, JS_ResolveStub, JS_ConvertStub, Node_finalize
};

void
make_TD_object(JSContext *ctx, struct dom_node *node)
{
	struct html_objects *o = JS_GetContextPrivate(ctx);

	node->data.element.html_data = mem_calloc(1, sizeof(struct TD_struct));
	if (node->data.element.html_data) {
		node->ecmascript_obj = JS_NewObject(ctx, (JSClass *)&HTMLTableCellElement_class, o->HTMLElement_object, NULL);
	}
}

void
done_TD_object(void *data)
{
	struct TD_struct *d = data;

	mem_free_if(d->abbr);
	mem_free_if(d->align);
	mem_free_if(d->axis);
	mem_free_if(d->bgcolor);
	mem_free_if(d->ch);
	mem_free_if(d->ch_off);
	mem_free_if(d->headers);
	mem_free_if(d->height);
	mem_free_if(d->scope);
	mem_free_if(d->valign);
	mem_free_if(d->width);
}