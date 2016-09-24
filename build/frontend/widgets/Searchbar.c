/* Searchbar.c generated by valac 0.32.1, the Vala compiler
 * generated from Searchbar.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>
#include <pango/pango.h>
#include <cairo.h>
#include <float.h>
#include <math.h>


#define SLINGSHOT_FRONTEND_TYPE_SEARCHBAR (slingshot_frontend_searchbar_get_type ())
#define SLINGSHOT_FRONTEND_SEARCHBAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, SlingshotFrontendSearchbar))
#define SLINGSHOT_FRONTEND_SEARCHBAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, SlingshotFrontendSearchbarClass))
#define SLINGSHOT_FRONTEND_IS_SEARCHBAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SLINGSHOT_FRONTEND_TYPE_SEARCHBAR))
#define SLINGSHOT_FRONTEND_IS_SEARCHBAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SLINGSHOT_FRONTEND_TYPE_SEARCHBAR))
#define SLINGSHOT_FRONTEND_SEARCHBAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, SlingshotFrontendSearchbarClass))

typedef struct _SlingshotFrontendSearchbar SlingshotFrontendSearchbar;
typedef struct _SlingshotFrontendSearchbarClass SlingshotFrontendSearchbarClass;
typedef struct _SlingshotFrontendSearchbarPrivate SlingshotFrontendSearchbarPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _gtk_icon_source_free0(var) ((var == NULL) ? NULL : (var = (gtk_icon_source_free (var), NULL)))
#define _gtk_icon_set_unref0(var) ((var == NULL) ? NULL : (var = (gtk_icon_set_unref (var), NULL)))
#define __vala_PangoFontDescription_free0(var) ((var == NULL) ? NULL : (var = (_vala_PangoFontDescription_free (var), NULL)))
#define _cairo_pattern_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_pattern_destroy (var), NULL)))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))

struct _SlingshotFrontendSearchbar {
	GtkHBox parent_instance;
	SlingshotFrontendSearchbarPrivate * priv;
	GtkLabel* label;
	GtkImage* search_icon;
	gchar* hint_string;
};

struct _SlingshotFrontendSearchbarClass {
	GtkHBoxClass parent_class;
};

struct _SlingshotFrontendSearchbarPrivate {
	GtkTextBuffer* buffer;
	GtkImage* clear_icon;
	gboolean is_hinted;
};


static gpointer slingshot_frontend_searchbar_parent_class = NULL;

GType slingshot_frontend_searchbar_get_type (void) G_GNUC_CONST;
#define SLINGSHOT_FRONTEND_SEARCHBAR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, SlingshotFrontendSearchbarPrivate))
enum  {
	SLINGSHOT_FRONTEND_SEARCHBAR_DUMMY_PROPERTY,
	SLINGSHOT_FRONTEND_SEARCHBAR_TEXT
};
#define SLINGSHOT_FRONTEND_SEARCHBAR_WIDTH 240
#define SLINGSHOT_FRONTEND_SEARCHBAR_HEIGHT 34
SlingshotFrontendSearchbar* slingshot_frontend_searchbar_new (const gchar* hint);
SlingshotFrontendSearchbar* slingshot_frontend_searchbar_construct (GType object_type, const gchar* hint);
static gboolean __lambda9_ (SlingshotFrontendSearchbar* self);
static gboolean ___lambda9__gtk_widget_button_release_event (GtkWidget* _sender, GdkEventButton* event, gpointer self);
static gboolean __lambda10_ (SlingshotFrontendSearchbar* self);
void slingshot_frontend_searchbar_hint (SlingshotFrontendSearchbar* self);
static gboolean ___lambda10__gtk_widget_button_release_event (GtkWidget* _sender, GdkEventButton* event, gpointer self);
static void slingshot_frontend_searchbar_on_changed (SlingshotFrontendSearchbar* self);
static void _slingshot_frontend_searchbar_on_changed_gtk_text_buffer_changed (GtkTextBuffer* _sender, gpointer self);
static gboolean slingshot_frontend_searchbar_draw_background (SlingshotFrontendSearchbar* self, GtkWidget* widget, GdkEventExpose* event);
static gboolean _slingshot_frontend_searchbar_draw_background_gtk_widget_expose_event (GtkWidget* _sender, GdkEventExpose* event, gpointer self);
static void __lambda11_ (SlingshotFrontendSearchbar* self);
static void ___lambda11__gtk_widget_realize (GtkWidget* _sender, gpointer self);
static void slingshot_frontend_searchbar_grey_out (SlingshotFrontendSearchbar* self);
void slingshot_frontend_searchbar_unhint (SlingshotFrontendSearchbar* self);
void slingshot_frontend_searchbar_set_text (SlingshotFrontendSearchbar* self, const gchar* value);
static void slingshot_frontend_searchbar_reset_font (SlingshotFrontendSearchbar* self);
static void _vala_PangoFontDescription_free (PangoFontDescription* self);
void slingshot_frontend_utilities_draw_rounded_rectangle (cairo_t* context, gdouble radius, gdouble offset, GtkAllocation* size);
gchar* slingshot_frontend_searchbar_get_text (SlingshotFrontendSearchbar* self);
static void slingshot_frontend_searchbar_finalize (GObject* obj);
static void _vala_slingshot_frontend_searchbar_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_slingshot_frontend_searchbar_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gboolean __lambda9_ (SlingshotFrontendSearchbar* self) {
	gboolean result = FALSE;
	result = TRUE;
	return result;
}


static gboolean ___lambda9__gtk_widget_button_release_event (GtkWidget* _sender, GdkEventButton* event, gpointer self) {
	gboolean result;
	result = __lambda9_ ((SlingshotFrontendSearchbar*) self);
	return result;
}


static gboolean __lambda10_ (SlingshotFrontendSearchbar* self) {
	gboolean result = FALSE;
	slingshot_frontend_searchbar_hint (self);
	result = TRUE;
	return result;
}


static gboolean ___lambda10__gtk_widget_button_release_event (GtkWidget* _sender, GdkEventButton* event, gpointer self) {
	gboolean result;
	result = __lambda10_ ((SlingshotFrontendSearchbar*) self);
	return result;
}


static void _slingshot_frontend_searchbar_on_changed_gtk_text_buffer_changed (GtkTextBuffer* _sender, gpointer self) {
	slingshot_frontend_searchbar_on_changed ((SlingshotFrontendSearchbar*) self);
}


static gboolean _slingshot_frontend_searchbar_draw_background_gtk_widget_expose_event (GtkWidget* _sender, GdkEventExpose* event, gpointer self) {
	gboolean result;
	result = slingshot_frontend_searchbar_draw_background ((SlingshotFrontendSearchbar*) self, _sender, event);
	return result;
}


static void __lambda11_ (SlingshotFrontendSearchbar* self) {
	slingshot_frontend_searchbar_hint (self);
}


static void ___lambda11__gtk_widget_realize (GtkWidget* _sender, gpointer self) {
	__lambda11_ ((SlingshotFrontendSearchbar*) self);
}


SlingshotFrontendSearchbar* slingshot_frontend_searchbar_construct (GType object_type, const gchar* hint) {
	SlingshotFrontendSearchbar * self = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	GtkTextBuffer* _tmp2_ = NULL;
	GtkTextBuffer* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	GtkHBox* wrapper = NULL;
	GtkHBox* _tmp5_ = NULL;
	GtkEventBox* search_icon_wrapper = NULL;
	GtkEventBox* _tmp6_ = NULL;
	GtkImage* _tmp7_ = NULL;
	GtkImage* _tmp8_ = NULL;
	GtkTextBuffer* _tmp9_ = NULL;
	gchar* _tmp10_ = NULL;
	gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	GtkLabel* _tmp13_ = NULL;
	GtkLabel* _tmp14_ = NULL;
	GtkLabel* _tmp15_ = NULL;
	GtkLabel* _tmp16_ = NULL;
	GtkLabel* _tmp17_ = NULL;
	GtkLabel* _tmp18_ = NULL;
	GtkLabel* _tmp19_ = NULL;
	GtkEventBox* clear_icon_wrapper = NULL;
	GtkEventBox* _tmp20_ = NULL;
	GtkStockItem stock_item = {0};
	GtkIconFactory* factory = NULL;
	GtkIconFactory* _tmp21_ = NULL;
	GtkIconSet* icon_set = NULL;
	GtkIconSet* _tmp22_ = NULL;
	GtkIconSource* icon_source = NULL;
	GtkIconSource* _tmp23_ = NULL;
	GtkStockItem _tmp24_ = {0};
	GtkStockItem* _tmp25_ = NULL;
	GtkStockItem* _tmp26_ = NULL;
	gint _tmp26__length1 = 0;
	GtkImage* _tmp27_ = NULL;
	GtkImage* _tmp28_ = NULL;
	GtkTextBuffer* _tmp29_ = NULL;
	g_return_val_if_fail (hint != NULL, NULL);
	self = (SlingshotFrontendSearchbar*) g_object_new (object_type, NULL);
	_tmp0_ = hint;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->hint_string);
	self->hint_string = _tmp1_;
	_tmp2_ = gtk_text_buffer_new (NULL);
	_g_object_unref0 (self->priv->buffer);
	self->priv->buffer = _tmp2_;
	_tmp3_ = self->priv->buffer;
	_tmp4_ = self->hint_string;
	g_object_set (_tmp3_, "text", _tmp4_, NULL);
	gtk_box_set_homogeneous ((GtkBox*) self, FALSE);
	g_object_set ((GtkWidget*) self, "can-focus", FALSE, NULL);
	gtk_widget_set_size_request ((GtkWidget*) self, SLINGSHOT_FRONTEND_SEARCHBAR_WIDTH, SLINGSHOT_FRONTEND_SEARCHBAR_HEIGHT);
	_tmp5_ = (GtkHBox*) gtk_hbox_new (FALSE, 3);
	g_object_ref_sink (_tmp5_);
	wrapper = _tmp5_;
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) wrapper);
	_tmp6_ = (GtkEventBox*) gtk_event_box_new ();
	g_object_ref_sink (_tmp6_);
	search_icon_wrapper = _tmp6_;
	gtk_event_box_set_visible_window (search_icon_wrapper, FALSE);
	_tmp7_ = (GtkImage*) gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_MENU);
	g_object_ref_sink (_tmp7_);
	_g_object_unref0 (self->search_icon);
	self->search_icon = _tmp7_;
	_tmp8_ = self->search_icon;
	gtk_container_add ((GtkContainer*) search_icon_wrapper, (GtkWidget*) _tmp8_);
	g_signal_connect_object ((GtkWidget*) search_icon_wrapper, "button-release-event", (GCallback) ___lambda9__gtk_widget_button_release_event, self, 0);
	gtk_box_pack_start ((GtkBox*) wrapper, (GtkWidget*) search_icon_wrapper, FALSE, TRUE, (guint) 3);
	_tmp9_ = self->priv->buffer;
	g_object_get (_tmp9_, "text", &_tmp10_, NULL);
	_tmp11_ = _tmp10_;
	_tmp12_ = _tmp11_;
	_tmp13_ = (GtkLabel*) gtk_label_new (_tmp12_);
	g_object_ref_sink (_tmp13_);
	_g_object_unref0 (self->label);
	self->label = _tmp13_;
	_g_free0 (_tmp12_);
	_tmp14_ = self->label;
	gtk_label_set_ellipsize (_tmp14_, PANGO_ELLIPSIZE_START);
	_tmp15_ = self->label;
	gtk_misc_set_alignment ((GtkMisc*) _tmp15_, 0.0f, 0.5f);
	_tmp16_ = self->label;
	gtk_label_set_selectable (_tmp16_, TRUE);
	_tmp17_ = self->label;
	g_object_set ((GtkWidget*) _tmp17_, "can-focus", FALSE, NULL);
	_tmp18_ = self->label;
	gtk_label_set_single_line_mode (_tmp18_, TRUE);
	_tmp19_ = self->label;
	gtk_box_pack_start ((GtkBox*) wrapper, (GtkWidget*) _tmp19_, TRUE, TRUE, (guint) 0);
	_tmp20_ = (GtkEventBox*) gtk_event_box_new ();
	g_object_ref_sink (_tmp20_);
	clear_icon_wrapper = _tmp20_;
	gtk_event_box_set_visible_window (clear_icon_wrapper, FALSE);
	memset (&stock_item, 0, sizeof (GtkStockItem));
	stock_item.stock_id = "edit-clear-symbolic";
	stock_item.label = NULL;
	stock_item.modifier = 0;
	stock_item.keyval = (guint) 0;
	stock_item.translation_domain = GTK_STOCK_CLEAR;
	_tmp21_ = gtk_icon_factory_new ();
	factory = _tmp21_;
	_tmp22_ = gtk_icon_set_new ();
	icon_set = _tmp22_;
	_tmp23_ = gtk_icon_source_new ();
	icon_source = _tmp23_;
	gtk_icon_source_set_icon_name (icon_source, GTK_STOCK_CLEAR);
	gtk_icon_set_add_source (icon_set, icon_source);
	gtk_icon_source_set_icon_name (icon_source, "edit-clear-symbolic");
	gtk_icon_set_add_source (icon_set, icon_source);
	gtk_icon_factory_add (factory, "edit-clear-symbolic", icon_set);
	_tmp24_ = stock_item;
	_tmp25_ = g_new0 (GtkStockItem, 1);
	_tmp25_[0] = _tmp24_;
	_tmp26_ = _tmp25_;
	_tmp26__length1 = 1;
	gtk_stock_add (_tmp26_, 1);
	_tmp26_ = (g_free (_tmp26_), NULL);
	gtk_icon_factory_add_default (factory);
	_tmp27_ = (GtkImage*) gtk_image_new_from_stock ("edit-clear-symbolic", GTK_ICON_SIZE_MENU);
	g_object_ref_sink (_tmp27_);
	_g_object_unref0 (self->priv->clear_icon);
	self->priv->clear_icon = _tmp27_;
	_tmp28_ = self->priv->clear_icon;
	gtk_container_add ((GtkContainer*) clear_icon_wrapper, (GtkWidget*) _tmp28_);
	g_signal_connect_object ((GtkWidget*) clear_icon_wrapper, "button-release-event", (GCallback) ___lambda10__gtk_widget_button_release_event, self, 0);
	gtk_box_pack_end ((GtkBox*) wrapper, (GtkWidget*) clear_icon_wrapper, FALSE, TRUE, (guint) 3);
	_tmp29_ = self->priv->buffer;
	g_signal_connect_object (_tmp29_, "changed", (GCallback) _slingshot_frontend_searchbar_on_changed_gtk_text_buffer_changed, self, 0);
	g_signal_connect_object ((GtkWidget*) self, "expose-event", (GCallback) _slingshot_frontend_searchbar_draw_background_gtk_widget_expose_event, self, 0);
	g_signal_connect_object ((GtkWidget*) self, "realize", (GCallback) ___lambda11__gtk_widget_realize, self, 0);
	_gtk_icon_source_free0 (icon_source);
	_gtk_icon_set_unref0 (icon_set);
	_g_object_unref0 (factory);
	_g_object_unref0 (clear_icon_wrapper);
	_g_object_unref0 (search_icon_wrapper);
	_g_object_unref0 (wrapper);
	return self;
}


SlingshotFrontendSearchbar* slingshot_frontend_searchbar_new (const gchar* hint) {
	return slingshot_frontend_searchbar_construct (SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, hint);
}


void slingshot_frontend_searchbar_hint (SlingshotFrontendSearchbar* self) {
	GtkTextBuffer* _tmp0_ = NULL;
	GtkLabel* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	GtkImage* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->buffer;
	g_object_set (_tmp0_, "text", "", NULL);
	_tmp1_ = self->label;
	_tmp2_ = self->hint_string;
	gtk_label_set_label (_tmp1_, _tmp2_);
	slingshot_frontend_searchbar_grey_out (self);
	_tmp3_ = self->priv->clear_icon;
	gtk_widget_set_visible ((GtkWidget*) _tmp3_, FALSE);
}


void slingshot_frontend_searchbar_unhint (SlingshotFrontendSearchbar* self) {
	g_return_if_fail (self != NULL);
	slingshot_frontend_searchbar_set_text (self, "");
	slingshot_frontend_searchbar_reset_font (self);
}


static void _vala_PangoFontDescription_free (PangoFontDescription* self) {
	g_boxed_free (pango_font_description_get_type (), self);
}


static void slingshot_frontend_searchbar_grey_out (SlingshotFrontendSearchbar* self) {
	GdkColor color = {0};
	GdkColor _tmp0_ = {0};
	GtkLabel* _tmp1_ = NULL;
	GdkColor _tmp2_ = {0};
	GtkLabel* _tmp3_ = NULL;
	PangoFontDescription* _tmp4_ = NULL;
	PangoFontDescription* _tmp5_ = NULL;
	g_return_if_fail (self != NULL);
	memset (&color, 0, sizeof (GdkColor));
	gdk_color_parse ("#a0a0a0", &_tmp0_);
	color = _tmp0_;
	_tmp1_ = self->label;
	_tmp2_ = color;
	gtk_widget_modify_fg ((GtkWidget*) _tmp1_, GTK_STATE_NORMAL, &_tmp2_);
	_tmp3_ = self->label;
	_tmp4_ = pango_font_description_from_string ("italic");
	_tmp5_ = _tmp4_;
	gtk_widget_modify_font ((GtkWidget*) _tmp3_, _tmp5_);
	__vala_PangoFontDescription_free0 (_tmp5_);
	self->priv->is_hinted = TRUE;
}


static void slingshot_frontend_searchbar_reset_font (SlingshotFrontendSearchbar* self) {
	GdkColor color = {0};
	GdkColor _tmp0_ = {0};
	GtkLabel* _tmp1_ = NULL;
	GdkColor _tmp2_ = {0};
	GtkLabel* _tmp3_ = NULL;
	PangoFontDescription* _tmp4_ = NULL;
	PangoFontDescription* _tmp5_ = NULL;
	g_return_if_fail (self != NULL);
	memset (&color, 0, sizeof (GdkColor));
	gdk_color_parse ("#444", &_tmp0_);
	color = _tmp0_;
	_tmp1_ = self->label;
	_tmp2_ = color;
	gtk_widget_modify_fg ((GtkWidget*) _tmp1_, GTK_STATE_NORMAL, &_tmp2_);
	_tmp3_ = self->label;
	_tmp4_ = pango_font_description_from_string ("normal");
	_tmp5_ = _tmp4_;
	gtk_widget_modify_font ((GtkWidget*) _tmp3_, _tmp5_);
	__vala_PangoFontDescription_free0 (_tmp5_);
	self->priv->is_hinted = FALSE;
}


static void slingshot_frontend_searchbar_on_changed (SlingshotFrontendSearchbar* self) {
	g_return_if_fail (self != NULL);
	g_signal_emit_by_name (self, "changed");
}


static gboolean slingshot_frontend_searchbar_draw_background (SlingshotFrontendSearchbar* self, GtkWidget* widget, GdkEventExpose* event) {
	gboolean result = FALSE;
	GtkAllocation size = {0};
	GtkWidget* _tmp0_ = NULL;
	GtkAllocation _tmp1_ = {0};
	cairo_t* context = NULL;
	GtkWidget* _tmp2_ = NULL;
	GdkWindow* _tmp3_ = NULL;
	cairo_t* _tmp4_ = NULL;
	GtkAllocation _tmp5_ = {0};
	cairo_pattern_t* linear_fill = NULL;
	GtkAllocation _tmp6_ = {0};
	gint _tmp7_ = 0;
	GtkAllocation _tmp8_ = {0};
	gint _tmp9_ = 0;
	GtkAllocation _tmp10_ = {0};
	gint _tmp11_ = 0;
	GtkAllocation _tmp12_ = {0};
	gint _tmp13_ = 0;
	GtkAllocation _tmp14_ = {0};
	gint _tmp15_ = 0;
	cairo_pattern_t* _tmp16_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (widget != NULL, FALSE);
	g_return_val_if_fail (event != NULL, FALSE);
	_tmp0_ = widget;
	gtk_widget_get_allocation (_tmp0_, &_tmp1_);
	size = _tmp1_;
	_tmp2_ = widget;
	_tmp3_ = _tmp2_->window;
	_tmp4_ = gdk_cairo_create ((GdkDrawable*) _tmp3_);
	context = _tmp4_;
	_tmp5_ = size;
	slingshot_frontend_utilities_draw_rounded_rectangle (context, (gdouble) 3, 0.5, &_tmp5_);
	_tmp6_ = size;
	_tmp7_ = _tmp6_.x;
	_tmp8_ = size;
	_tmp9_ = _tmp8_.y;
	_tmp10_ = size;
	_tmp11_ = _tmp10_.x;
	_tmp12_ = size;
	_tmp13_ = _tmp12_.y;
	_tmp14_ = size;
	_tmp15_ = _tmp14_.height;
	_tmp16_ = cairo_pattern_create_linear ((gdouble) _tmp7_, (gdouble) _tmp9_, (gdouble) _tmp11_, (gdouble) (_tmp13_ + _tmp15_));
	linear_fill = _tmp16_;
	cairo_pattern_add_color_stop_rgb (linear_fill, 0.0, 0.85, 0.85, 0.85);
	cairo_pattern_add_color_stop_rgb (linear_fill, 0.25, 1.0, 1.0, 0.0);
	cairo_pattern_add_color_stop_rgb (linear_fill, 1.0, 1.0, 1.0, 0.0);
	cairo_set_source_rgba (context, (gdouble) 0, (gdouble) 0, (gdouble) 0, 0.5);
	cairo_fill_preserve (context);
	cairo_set_source_rgba (context, (gdouble) 0, (gdouble) 0, (gdouble) 0, 0.7);
	cairo_set_line_width (context, 1.0);
	cairo_stroke (context);
	result = FALSE;
	_cairo_pattern_destroy0 (linear_fill);
	_cairo_destroy0 (context);
	return result;
}


gchar* slingshot_frontend_searchbar_get_text (SlingshotFrontendSearchbar* self) {
	gchar* result;
	gchar* current_text = NULL;
	GtkTextBuffer* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	gboolean _tmp4_ = FALSE;
	const gchar* _tmp5_ = NULL;
	const gchar* _tmp6_ = NULL;
	gchar* _tmp9_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->buffer;
	g_object_get (_tmp0_, "text", &_tmp1_, NULL);
	_tmp2_ = _tmp1_;
	current_text = _tmp2_;
	_tmp5_ = current_text;
	_tmp6_ = self->hint_string;
	if (g_strcmp0 (_tmp5_, _tmp6_) == 0) {
		gboolean _tmp7_ = FALSE;
		_tmp7_ = self->priv->is_hinted;
		_tmp4_ = _tmp7_;
	} else {
		_tmp4_ = FALSE;
	}
	if (_tmp4_) {
		_tmp3_ = "";
	} else {
		const gchar* _tmp8_ = NULL;
		_tmp8_ = current_text;
		_tmp3_ = _tmp8_;
	}
	_tmp9_ = g_strdup (_tmp3_);
	result = _tmp9_;
	_g_free0 (current_text);
	return result;
}


void slingshot_frontend_searchbar_set_text (SlingshotFrontendSearchbar* self, const gchar* value) {
	GtkTextBuffer* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GtkTextBuffer* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gboolean _tmp6_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->buffer;
	_tmp1_ = value;
	g_object_set (_tmp0_, "text", _tmp1_, NULL);
	_tmp2_ = self->priv->buffer;
	g_object_get (_tmp2_, "text", &_tmp3_, NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = _tmp4_;
	_tmp6_ = g_strcmp0 (_tmp5_, "") == 0;
	_g_free0 (_tmp5_);
	if (_tmp6_) {
		slingshot_frontend_searchbar_hint (self);
	} else {
		GtkLabel* _tmp7_ = NULL;
		GtkTextBuffer* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		GtkLabel* _tmp12_ = NULL;
		GtkImage* _tmp13_ = NULL;
		slingshot_frontend_searchbar_reset_font (self);
		_tmp7_ = self->label;
		_tmp8_ = self->priv->buffer;
		g_object_get (_tmp8_, "text", &_tmp9_, NULL);
		_tmp10_ = _tmp9_;
		_tmp11_ = _tmp10_;
		gtk_label_set_label (_tmp7_, _tmp11_);
		_g_free0 (_tmp11_);
		_tmp12_ = self->label;
		gtk_label_select_region (_tmp12_, -1, -1);
		_tmp13_ = self->priv->clear_icon;
		gtk_widget_set_visible ((GtkWidget*) _tmp13_, TRUE);
	}
	g_object_notify ((GObject *) self, "text");
}


static void slingshot_frontend_searchbar_class_init (SlingshotFrontendSearchbarClass * klass) {
	slingshot_frontend_searchbar_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SlingshotFrontendSearchbarPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_slingshot_frontend_searchbar_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_slingshot_frontend_searchbar_set_property;
	G_OBJECT_CLASS (klass)->finalize = slingshot_frontend_searchbar_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SLINGSHOT_FRONTEND_SEARCHBAR_TEXT, g_param_spec_string ("text", "text", "text", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_signal_new ("changed", SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void slingshot_frontend_searchbar_instance_init (SlingshotFrontendSearchbar * self) {
	self->priv = SLINGSHOT_FRONTEND_SEARCHBAR_GET_PRIVATE (self);
	self->priv->is_hinted = TRUE;
}


static void slingshot_frontend_searchbar_finalize (GObject* obj) {
	SlingshotFrontendSearchbar * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, SlingshotFrontendSearchbar);
	_g_object_unref0 (self->priv->buffer);
	_g_object_unref0 (self->label);
	_g_object_unref0 (self->search_icon);
	_g_object_unref0 (self->priv->clear_icon);
	_g_free0 (self->hint_string);
	G_OBJECT_CLASS (slingshot_frontend_searchbar_parent_class)->finalize (obj);
}


GType slingshot_frontend_searchbar_get_type (void) {
	static volatile gsize slingshot_frontend_searchbar_type_id__volatile = 0;
	if (g_once_init_enter (&slingshot_frontend_searchbar_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SlingshotFrontendSearchbarClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) slingshot_frontend_searchbar_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SlingshotFrontendSearchbar), 0, (GInstanceInitFunc) slingshot_frontend_searchbar_instance_init, NULL };
		GType slingshot_frontend_searchbar_type_id;
		slingshot_frontend_searchbar_type_id = g_type_register_static (GTK_TYPE_HBOX, "SlingshotFrontendSearchbar", &g_define_type_info, 0);
		g_once_init_leave (&slingshot_frontend_searchbar_type_id__volatile, slingshot_frontend_searchbar_type_id);
	}
	return slingshot_frontend_searchbar_type_id__volatile;
}


static void _vala_slingshot_frontend_searchbar_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SlingshotFrontendSearchbar * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, SlingshotFrontendSearchbar);
	switch (property_id) {
		case SLINGSHOT_FRONTEND_SEARCHBAR_TEXT:
		g_value_take_string (value, slingshot_frontend_searchbar_get_text (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_slingshot_frontend_searchbar_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	SlingshotFrontendSearchbar * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SLINGSHOT_FRONTEND_TYPE_SEARCHBAR, SlingshotFrontendSearchbar);
	switch (property_id) {
		case SLINGSHOT_FRONTEND_SEARCHBAR_TEXT:
		slingshot_frontend_searchbar_set_text (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



