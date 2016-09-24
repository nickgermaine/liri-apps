/* GMenuEntries.c generated by valac 0.32.1, the Vala compiler
 * generated from GMenuEntries.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <gnome-menus/gmenu-tree.h>
#include <stdlib.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdio.h>


#define SLINGSHOT_BACKEND_TYPE_GMENU_ENTRIES (slingshot_backend_gmenu_entries_get_type ())
#define SLINGSHOT_BACKEND_GMENU_ENTRIES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SLINGSHOT_BACKEND_TYPE_GMENU_ENTRIES, SlingshotBackendGMenuEntries))
#define SLINGSHOT_BACKEND_GMENU_ENTRIES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SLINGSHOT_BACKEND_TYPE_GMENU_ENTRIES, SlingshotBackendGMenuEntriesClass))
#define SLINGSHOT_BACKEND_IS_GMENU_ENTRIES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SLINGSHOT_BACKEND_TYPE_GMENU_ENTRIES))
#define SLINGSHOT_BACKEND_IS_GMENU_ENTRIES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SLINGSHOT_BACKEND_TYPE_GMENU_ENTRIES))
#define SLINGSHOT_BACKEND_GMENU_ENTRIES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SLINGSHOT_BACKEND_TYPE_GMENU_ENTRIES, SlingshotBackendGMenuEntriesClass))

typedef struct _SlingshotBackendGMenuEntries SlingshotBackendGMenuEntries;
typedef struct _SlingshotBackendGMenuEntriesClass SlingshotBackendGMenuEntriesClass;
typedef struct _SlingshotBackendGMenuEntriesPrivate SlingshotBackendGMenuEntriesPrivate;
#define _gmenu_tree_item_unref0(var) ((var == NULL) ? NULL : (var = (gmenu_tree_item_unref (var), NULL)))
#define _gmenu_tree_unref0(var) ((var == NULL) ? NULL : (var = (gmenu_tree_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _gtk_icon_info_free0(var) ((var == NULL) ? NULL : (var = (gtk_icon_info_free (var), NULL)))

struct _SlingshotBackendGMenuEntries {
	GObject parent_instance;
	SlingshotBackendGMenuEntriesPrivate * priv;
};

struct _SlingshotBackendGMenuEntriesClass {
	GObjectClass parent_class;
};


static gpointer slingshot_backend_gmenu_entries_parent_class = NULL;

GType slingshot_backend_gmenu_entries_get_type (void) G_GNUC_CONST;
enum  {
	SLINGSHOT_BACKEND_GMENU_ENTRIES_DUMMY_PROPERTY
};
GeeArrayList* slingshot_backend_gmenu_entries_get_categories (void);
GeeArrayList* slingshot_backend_gmenu_entries_get_applications_for_category (GMenuTreeDirectory* category);
GeeArrayList* slingshot_backend_gmenu_entries_get_all (void);
void slingshot_backend_gmenu_entries_enumerate_apps (GeeArrayList* source, GeeHashMap* icons, gint icon_size, GeeArrayList** list);
SlingshotBackendGMenuEntries* slingshot_backend_gmenu_entries_new (void);
SlingshotBackendGMenuEntries* slingshot_backend_gmenu_entries_construct (GType object_type);


static gpointer _gmenu_tree_ref0 (gpointer self) {
	return self ? gmenu_tree_ref (self) : NULL;
}


static gpointer _gmenu_tree_item_ref0 (gpointer self) {
	return self ? gmenu_tree_item_ref (self) : NULL;
}


GeeArrayList* slingshot_backend_gmenu_entries_get_categories (void) {
	GeeArrayList* result = NULL;
	GMenuTree* tree = NULL;
	GMenuTree* _tmp0_ = NULL;
	GMenuTree* _tmp1_ = NULL;
	GMenuTreeDirectory* root = NULL;
	GMenuTree* _tmp2_ = NULL;
	GMenuTreeDirectory* _tmp3_ = NULL;
	GMenuTreeDirectory* _tmp4_ = NULL;
	GeeArrayList* main_directory_entries = NULL;
	GeeArrayList* _tmp5_ = NULL;
	GMenuTreeDirectory* _tmp6_ = NULL;
	GSList* _tmp7_ = NULL;
	_tmp0_ = gmenu_tree_lookup ("applications.menu", GMENU_TREE_FLAGS_INCLUDE_EXCLUDED);
	_tmp1_ = _gmenu_tree_ref0 (_tmp0_);
	tree = _tmp1_;
	_tmp2_ = tree;
	_tmp3_ = gmenu_tree_get_root_directory (_tmp2_);
	_tmp4_ = _gmenu_tree_item_ref0 (_tmp3_);
	root = _tmp4_;
	_tmp5_ = gee_array_list_new (G_TYPE_POINTER, (GBoxedCopyFunc) gmenu_tree_item_ref, gmenu_tree_item_unref, NULL);
	main_directory_entries = _tmp5_;
	_tmp6_ = root;
	_tmp7_ = gmenu_tree_directory_get_contents (_tmp6_);
	{
		GSList* item_collection = NULL;
		GSList* item_it = NULL;
		item_collection = _tmp7_;
		for (item_it = item_collection; item_it != NULL; item_it = item_it->next) {
			GMenuTreeItem* _tmp8_ = NULL;
			GMenuTreeItem* item = NULL;
			_tmp8_ = _gmenu_tree_item_ref0 ((GMenuTreeItem*) item_it->data);
			item = _tmp8_;
			{
				GMenuTreeItem* _tmp9_ = NULL;
				GMenuTreeItemType _tmp10_ = 0;
				_tmp9_ = item;
				_tmp10_ = gmenu_tree_item_get_type (_tmp9_);
				if (_tmp10_ == GMENU_TREE_ITEM_DIRECTORY) {
					GeeArrayList* _tmp11_ = NULL;
					GMenuTreeItem* _tmp12_ = NULL;
					_tmp11_ = main_directory_entries;
					_tmp12_ = item;
					gee_abstract_collection_add ((GeeAbstractCollection*) _tmp11_, (GMenuTreeDirectory*) _tmp12_);
				}
				_gmenu_tree_item_unref0 (item);
			}
		}
	}
	result = main_directory_entries;
	_gmenu_tree_item_unref0 (root);
	_gmenu_tree_unref0 (tree);
	return result;
}


GeeArrayList* slingshot_backend_gmenu_entries_get_applications_for_category (GMenuTreeDirectory* category) {
	GeeArrayList* result = NULL;
	GeeArrayList* entries = NULL;
	GeeArrayList* _tmp0_ = NULL;
	GMenuTreeDirectory* _tmp1_ = NULL;
	GSList* _tmp2_ = NULL;
	g_return_val_if_fail (category != NULL, NULL);
	_tmp0_ = gee_array_list_new (G_TYPE_POINTER, (GBoxedCopyFunc) gmenu_tree_item_ref, gmenu_tree_item_unref, NULL);
	entries = _tmp0_;
	_tmp1_ = category;
	_tmp2_ = gmenu_tree_directory_get_contents (_tmp1_);
	{
		GSList* item_collection = NULL;
		GSList* item_it = NULL;
		item_collection = _tmp2_;
		for (item_it = item_collection; item_it != NULL; item_it = item_it->next) {
			GMenuTreeItem* _tmp3_ = NULL;
			GMenuTreeItem* item = NULL;
			_tmp3_ = _gmenu_tree_item_ref0 ((GMenuTreeItem*) item_it->data);
			item = _tmp3_;
			{
				GMenuTreeItem* _tmp4_ = NULL;
				GMenuTreeItemType _tmp5_ = 0;
				_tmp4_ = item;
				_tmp5_ = gmenu_tree_item_get_type (_tmp4_);
				switch (_tmp5_) {
					case GMENU_TREE_ITEM_DIRECTORY:
					{
						GeeArrayList* _tmp6_ = NULL;
						GMenuTreeItem* _tmp7_ = NULL;
						GeeArrayList* _tmp8_ = NULL;
						GeeArrayList* _tmp9_ = NULL;
						_tmp6_ = entries;
						_tmp7_ = item;
						_tmp8_ = slingshot_backend_gmenu_entries_get_applications_for_category ((GMenuTreeDirectory*) _tmp7_);
						_tmp9_ = _tmp8_;
						gee_abstract_collection_add_all ((GeeAbstractCollection*) _tmp6_, (GeeCollection*) _tmp9_);
						_g_object_unref0 (_tmp9_);
						break;
					}
					case GMENU_TREE_ITEM_ENTRY:
					{
						GeeArrayList* _tmp10_ = NULL;
						GMenuTreeItem* _tmp11_ = NULL;
						_tmp10_ = entries;
						_tmp11_ = item;
						gee_abstract_collection_add ((GeeAbstractCollection*) _tmp10_, (GMenuTreeEntry*) _tmp11_);
						break;
					}
					default:
					break;
				}
				_gmenu_tree_item_unref0 (item);
			}
		}
	}
	result = entries;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


GeeArrayList* slingshot_backend_gmenu_entries_get_all (void) {
	GeeArrayList* result = NULL;
	GeeArrayList* the_apps = NULL;
	GeeArrayList* _tmp0_ = NULL;
	GeeArrayList* all_categories = NULL;
	GeeArrayList* _tmp1_ = NULL;
	_tmp0_ = gee_array_list_new (G_TYPE_POINTER, (GBoxedCopyFunc) gmenu_tree_item_ref, gmenu_tree_item_unref, NULL);
	the_apps = _tmp0_;
	_tmp1_ = slingshot_backend_gmenu_entries_get_categories ();
	all_categories = _tmp1_;
	{
		GeeArrayList* _directory_list = NULL;
		GeeArrayList* _tmp2_ = NULL;
		GeeArrayList* _tmp3_ = NULL;
		gint _directory_size = 0;
		GeeArrayList* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		gint _tmp6_ = 0;
		gint _directory_index = 0;
		_tmp2_ = all_categories;
		_tmp3_ = _g_object_ref0 (_tmp2_);
		_directory_list = _tmp3_;
		_tmp4_ = _directory_list;
		_tmp5_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp4_);
		_tmp6_ = _tmp5_;
		_directory_size = _tmp6_;
		_directory_index = -1;
		while (TRUE) {
			gint _tmp7_ = 0;
			gint _tmp8_ = 0;
			gint _tmp9_ = 0;
			GMenuTreeDirectory* directory = NULL;
			GeeArrayList* _tmp10_ = NULL;
			gint _tmp11_ = 0;
			gpointer _tmp12_ = NULL;
			GeeArrayList* this_category_apps = NULL;
			GMenuTreeDirectory* _tmp13_ = NULL;
			GeeArrayList* _tmp14_ = NULL;
			_tmp7_ = _directory_index;
			_directory_index = _tmp7_ + 1;
			_tmp8_ = _directory_index;
			_tmp9_ = _directory_size;
			if (!(_tmp8_ < _tmp9_)) {
				break;
			}
			_tmp10_ = _directory_list;
			_tmp11_ = _directory_index;
			_tmp12_ = gee_abstract_list_get ((GeeAbstractList*) _tmp10_, _tmp11_);
			directory = (GMenuTreeDirectory*) _tmp12_;
			_tmp13_ = directory;
			_tmp14_ = slingshot_backend_gmenu_entries_get_applications_for_category (_tmp13_);
			this_category_apps = _tmp14_;
			{
				GeeArrayList* _this_app_list = NULL;
				GeeArrayList* _tmp15_ = NULL;
				GeeArrayList* _tmp16_ = NULL;
				gint _this_app_size = 0;
				GeeArrayList* _tmp17_ = NULL;
				gint _tmp18_ = 0;
				gint _tmp19_ = 0;
				gint _this_app_index = 0;
				_tmp15_ = this_category_apps;
				_tmp16_ = _g_object_ref0 (_tmp15_);
				_this_app_list = _tmp16_;
				_tmp17_ = _this_app_list;
				_tmp18_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp17_);
				_tmp19_ = _tmp18_;
				_this_app_size = _tmp19_;
				_this_app_index = -1;
				while (TRUE) {
					gint _tmp20_ = 0;
					gint _tmp21_ = 0;
					gint _tmp22_ = 0;
					GMenuTreeEntry* this_app = NULL;
					GeeArrayList* _tmp23_ = NULL;
					gint _tmp24_ = 0;
					gpointer _tmp25_ = NULL;
					GeeArrayList* _tmp26_ = NULL;
					GMenuTreeEntry* _tmp27_ = NULL;
					_tmp20_ = _this_app_index;
					_this_app_index = _tmp20_ + 1;
					_tmp21_ = _this_app_index;
					_tmp22_ = _this_app_size;
					if (!(_tmp21_ < _tmp22_)) {
						break;
					}
					_tmp23_ = _this_app_list;
					_tmp24_ = _this_app_index;
					_tmp25_ = gee_abstract_list_get ((GeeAbstractList*) _tmp23_, _tmp24_);
					this_app = (GMenuTreeEntry*) _tmp25_;
					_tmp26_ = the_apps;
					_tmp27_ = this_app;
					gee_abstract_collection_add ((GeeAbstractCollection*) _tmp26_, _tmp27_);
					_gmenu_tree_item_unref0 (this_app);
				}
				_g_object_unref0 (_this_app_list);
			}
			_g_object_unref0 (this_category_apps);
			_gmenu_tree_item_unref0 (directory);
		}
		_g_object_unref0 (_directory_list);
	}
	result = the_apps;
	_g_object_unref0 (all_categories);
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


void slingshot_backend_gmenu_entries_enumerate_apps (GeeArrayList* source, GeeHashMap* icons, gint icon_size, GeeArrayList** list) {
	GeeArrayList* _vala_list = NULL;
	GtkIconTheme* icon_theme = NULL;
	GtkIconTheme* _tmp0_ = NULL;
	GtkIconTheme* _tmp1_ = NULL;
	GeeArrayList* _tmp2_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_if_fail (source != NULL);
	g_return_if_fail (icons != NULL);
	_tmp0_ = gtk_icon_theme_get_default ();
	_tmp1_ = _g_object_ref0 (_tmp0_);
	icon_theme = _tmp1_;
	_tmp2_ = gee_array_list_new (GEE_TYPE_HASH_MAP, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL);
	_g_object_unref0 (_vala_list);
	_vala_list = _tmp2_;
	{
		GeeArrayList* _app_list = NULL;
		GeeArrayList* _tmp3_ = NULL;
		GeeArrayList* _tmp4_ = NULL;
		gint _app_size = 0;
		GeeArrayList* _tmp5_ = NULL;
		gint _tmp6_ = 0;
		gint _tmp7_ = 0;
		gint _app_index = 0;
		_tmp3_ = source;
		_tmp4_ = _g_object_ref0 (_tmp3_);
		_app_list = _tmp4_;
		_tmp5_ = _app_list;
		_tmp6_ = gee_abstract_collection_get_size ((GeeCollection*) _tmp5_);
		_tmp7_ = _tmp6_;
		_app_size = _tmp7_;
		_app_index = -1;
		while (TRUE) {
			gint _tmp8_ = 0;
			gint _tmp9_ = 0;
			gint _tmp10_ = 0;
			GMenuTreeEntry* app = NULL;
			GeeArrayList* _tmp11_ = NULL;
			gint _tmp12_ = 0;
			gpointer _tmp13_ = NULL;
			gboolean _tmp14_ = FALSE;
			gboolean _tmp15_ = FALSE;
			GMenuTreeEntry* _tmp16_ = NULL;
			gboolean _tmp17_ = FALSE;
			_tmp8_ = _app_index;
			_app_index = _tmp8_ + 1;
			_tmp9_ = _app_index;
			_tmp10_ = _app_size;
			if (!(_tmp9_ < _tmp10_)) {
				break;
			}
			_tmp11_ = _app_list;
			_tmp12_ = _app_index;
			_tmp13_ = gee_abstract_list_get ((GeeAbstractList*) _tmp11_, _tmp12_);
			app = (GMenuTreeEntry*) _tmp13_;
			_tmp16_ = app;
			_tmp17_ = gmenu_tree_entry_get_is_nodisplay (_tmp16_);
			if (_tmp17_ == FALSE) {
				GMenuTreeEntry* _tmp18_ = NULL;
				gboolean _tmp19_ = FALSE;
				_tmp18_ = app;
				_tmp19_ = gmenu_tree_entry_get_is_excluded (_tmp18_);
				_tmp15_ = _tmp19_ == FALSE;
			} else {
				_tmp15_ = FALSE;
			}
			if (_tmp15_) {
				GMenuTreeEntry* _tmp20_ = NULL;
				const gchar* _tmp21_ = NULL;
				_tmp20_ = app;
				_tmp21_ = gmenu_tree_entry_get_icon (_tmp20_);
				_tmp14_ = _tmp21_ != NULL;
			} else {
				_tmp14_ = FALSE;
			}
			if (_tmp14_) {
				GeeHashMap* app_to_add = NULL;
				GeeHashMap* _tmp22_ = NULL;
				GeeHashMap* _tmp23_ = NULL;
				GMenuTreeEntry* _tmp24_ = NULL;
				const gchar* _tmp25_ = NULL;
				GeeHashMap* _tmp26_ = NULL;
				GMenuTreeEntry* _tmp27_ = NULL;
				const gchar* _tmp28_ = NULL;
				GeeHashMap* _tmp29_ = NULL;
				GMenuTreeEntry* _tmp30_ = NULL;
				const gchar* _tmp31_ = NULL;
				GeeHashMap* _tmp32_ = NULL;
				GMenuTreeEntry* _tmp33_ = NULL;
				const gchar* _tmp34_ = NULL;
				GeeHashMap* _tmp35_ = NULL;
				GeeHashMap* _tmp36_ = NULL;
				gpointer _tmp37_ = NULL;
				gchar* _tmp38_ = NULL;
				gboolean _tmp39_ = FALSE;
				gboolean _tmp40_ = FALSE;
				GeeArrayList* _tmp96_ = NULL;
				GeeHashMap* _tmp97_ = NULL;
				_tmp22_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL, NULL);
				app_to_add = _tmp22_;
				_tmp23_ = app_to_add;
				_tmp24_ = app;
				_tmp25_ = gmenu_tree_entry_get_comment (_tmp24_);
				gee_abstract_map_set ((GeeAbstractMap*) _tmp23_, "description", _tmp25_);
				_tmp26_ = app_to_add;
				_tmp27_ = app;
				_tmp28_ = gmenu_tree_entry_get_name (_tmp27_);
				gee_abstract_map_set ((GeeAbstractMap*) _tmp26_, "name", _tmp28_);
				_tmp29_ = app_to_add;
				_tmp30_ = app;
				_tmp31_ = gmenu_tree_entry_get_exec (_tmp30_);
				gee_abstract_map_set ((GeeAbstractMap*) _tmp29_, "command", _tmp31_);
				_tmp32_ = app_to_add;
				_tmp33_ = app;
				_tmp34_ = gmenu_tree_entry_get_desktop_file_path (_tmp33_);
				gee_abstract_map_set ((GeeAbstractMap*) _tmp32_, "desktop_file", _tmp34_);
				_tmp35_ = icons;
				_tmp36_ = app_to_add;
				_tmp37_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp36_, "command");
				_tmp38_ = (gchar*) _tmp37_;
				_tmp39_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp35_, _tmp38_);
				_tmp40_ = !_tmp39_;
				_g_free0 (_tmp38_);
				if (_tmp40_) {
					gchar* app_icon = NULL;
					GMenuTreeEntry* _tmp41_ = NULL;
					const gchar* _tmp42_ = NULL;
					gchar* _tmp43_ = NULL;
					GtkIconTheme* _tmp44_ = NULL;
					const gchar* _tmp45_ = NULL;
					gboolean _tmp46_ = FALSE;
					_tmp41_ = app;
					_tmp42_ = gmenu_tree_entry_get_icon (_tmp41_);
					_tmp43_ = g_strdup (_tmp42_);
					app_icon = _tmp43_;
					_tmp44_ = icon_theme;
					_tmp45_ = app_icon;
					_tmp46_ = gtk_icon_theme_has_icon (_tmp44_, _tmp45_);
					if (_tmp46_) {
						GdkPixbuf* _tmp47_ = NULL;
						GtkIconTheme* _tmp48_ = NULL;
						const gchar* _tmp49_ = NULL;
						gint _tmp50_ = 0;
						GtkIconInfo* _tmp51_ = NULL;
						GtkIconInfo* _tmp52_ = NULL;
						GdkPixbuf* _tmp53_ = NULL;
						GdkPixbuf* _tmp54_ = NULL;
						GeeHashMap* _tmp55_ = NULL;
						GeeHashMap* _tmp56_ = NULL;
						gpointer _tmp57_ = NULL;
						gchar* _tmp58_ = NULL;
						_tmp48_ = icon_theme;
						_tmp49_ = app_icon;
						_tmp50_ = icon_size;
						_tmp51_ = gtk_icon_theme_lookup_icon (_tmp48_, _tmp49_, _tmp50_, 0);
						_tmp52_ = _tmp51_;
						_tmp53_ = gtk_icon_info_load_icon (_tmp52_, &_inner_error_);
						_tmp54_ = _tmp53_;
						_gtk_icon_info_free0 (_tmp52_);
						_tmp47_ = _tmp54_;
						if (G_UNLIKELY (_inner_error_ != NULL)) {
							_g_free0 (app_icon);
							_g_object_unref0 (app_to_add);
							_gmenu_tree_item_unref0 (app);
							_g_object_unref0 (_app_list);
							_g_object_unref0 (icon_theme);
							g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
							g_clear_error (&_inner_error_);
							return;
						}
						_tmp55_ = icons;
						_tmp56_ = app_to_add;
						_tmp57_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp56_, "command");
						_tmp58_ = (gchar*) _tmp57_;
						gee_abstract_map_set ((GeeAbstractMap*) _tmp55_, _tmp58_, _tmp47_);
						_g_free0 (_tmp58_);
						_g_object_unref0 (_tmp47_);
					} else {
						const gchar* _tmp59_ = NULL;
						GFile* _tmp60_ = NULL;
						GFile* _tmp61_ = NULL;
						gboolean _tmp62_ = FALSE;
						gboolean _tmp63_ = FALSE;
						_tmp59_ = app_icon;
						_tmp60_ = g_file_new_for_path (_tmp59_);
						_tmp61_ = _tmp60_;
						_tmp62_ = g_file_query_exists (_tmp61_, NULL);
						_tmp63_ = _tmp62_;
						_g_object_unref0 (_tmp61_);
						if (_tmp63_) {
							{
								GdkPixbuf* _tmp64_ = NULL;
								const gchar* _tmp65_ = NULL;
								const gchar* _tmp66_ = NULL;
								gint _tmp67_ = 0;
								GdkPixbuf* _tmp68_ = NULL;
								GeeHashMap* _tmp69_ = NULL;
								GeeHashMap* _tmp70_ = NULL;
								gpointer _tmp71_ = NULL;
								gchar* _tmp72_ = NULL;
								_tmp65_ = app_icon;
								_tmp66_ = string_to_string (_tmp65_);
								_tmp67_ = icon_size;
								_tmp68_ = gdk_pixbuf_new_from_file_at_scale (_tmp66_, -1, _tmp67_, TRUE, &_inner_error_);
								_tmp64_ = _tmp68_;
								if (G_UNLIKELY (_inner_error_ != NULL)) {
									goto __catch1_g_error;
								}
								_tmp69_ = icons;
								_tmp70_ = app_to_add;
								_tmp71_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp70_, "command");
								_tmp72_ = (gchar*) _tmp71_;
								gee_abstract_map_set ((GeeAbstractMap*) _tmp69_, _tmp72_, _tmp64_);
								_g_free0 (_tmp72_);
								_g_object_unref0 (_tmp64_);
							}
							goto __finally1;
							__catch1_g_error:
							{
								GdkPixbuf* _tmp73_ = NULL;
								GtkIconTheme* _tmp74_ = NULL;
								gint _tmp75_ = 0;
								GtkIconInfo* _tmp76_ = NULL;
								GtkIconInfo* _tmp77_ = NULL;
								GdkPixbuf* _tmp78_ = NULL;
								GdkPixbuf* _tmp79_ = NULL;
								GeeHashMap* _tmp80_ = NULL;
								GeeHashMap* _tmp81_ = NULL;
								gpointer _tmp82_ = NULL;
								gchar* _tmp83_ = NULL;
								FILE* _tmp84_ = NULL;
								g_clear_error (&_inner_error_);
								_inner_error_ = NULL;
								_tmp74_ = icon_theme;
								_tmp75_ = icon_size;
								_tmp76_ = gtk_icon_theme_lookup_icon (_tmp74_, "application-default-icon", _tmp75_, 0);
								_tmp77_ = _tmp76_;
								_tmp78_ = gtk_icon_info_load_icon (_tmp77_, &_inner_error_);
								_tmp79_ = _tmp78_;
								_gtk_icon_info_free0 (_tmp77_);
								_tmp73_ = _tmp79_;
								if (G_UNLIKELY (_inner_error_ != NULL)) {
									goto __finally1;
								}
								_tmp80_ = icons;
								_tmp81_ = app_to_add;
								_tmp82_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp81_, "command");
								_tmp83_ = (gchar*) _tmp82_;
								gee_abstract_map_set ((GeeAbstractMap*) _tmp80_, _tmp83_, _tmp73_);
								_g_free0 (_tmp83_);
								_tmp84_ = stdout;
								fprintf (_tmp84_, "Failed to load icon from file.\n");
								_g_object_unref0 (_tmp73_);
							}
							__finally1:
							if (G_UNLIKELY (_inner_error_ != NULL)) {
								_g_free0 (app_icon);
								_g_object_unref0 (app_to_add);
								_gmenu_tree_item_unref0 (app);
								_g_object_unref0 (_app_list);
								_g_object_unref0 (icon_theme);
								g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
								g_clear_error (&_inner_error_);
								return;
							}
						} else {
							GdkPixbuf* _tmp85_ = NULL;
							GtkIconTheme* _tmp86_ = NULL;
							gint _tmp87_ = 0;
							GtkIconInfo* _tmp88_ = NULL;
							GtkIconInfo* _tmp89_ = NULL;
							GdkPixbuf* _tmp90_ = NULL;
							GdkPixbuf* _tmp91_ = NULL;
							GeeHashMap* _tmp92_ = NULL;
							GeeHashMap* _tmp93_ = NULL;
							gpointer _tmp94_ = NULL;
							gchar* _tmp95_ = NULL;
							_tmp86_ = icon_theme;
							_tmp87_ = icon_size;
							_tmp88_ = gtk_icon_theme_lookup_icon (_tmp86_, "application-default-icon", _tmp87_, 0);
							_tmp89_ = _tmp88_;
							_tmp90_ = gtk_icon_info_load_icon (_tmp89_, &_inner_error_);
							_tmp91_ = _tmp90_;
							_gtk_icon_info_free0 (_tmp89_);
							_tmp85_ = _tmp91_;
							if (G_UNLIKELY (_inner_error_ != NULL)) {
								_g_free0 (app_icon);
								_g_object_unref0 (app_to_add);
								_gmenu_tree_item_unref0 (app);
								_g_object_unref0 (_app_list);
								_g_object_unref0 (icon_theme);
								g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
								g_clear_error (&_inner_error_);
								return;
							}
							_tmp92_ = icons;
							_tmp93_ = app_to_add;
							_tmp94_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp93_, "command");
							_tmp95_ = (gchar*) _tmp94_;
							gee_abstract_map_set ((GeeAbstractMap*) _tmp92_, _tmp95_, _tmp85_);
							_g_free0 (_tmp95_);
							_g_object_unref0 (_tmp85_);
						}
					}
					_g_free0 (app_icon);
				}
				_tmp96_ = _vala_list;
				_tmp97_ = app_to_add;
				gee_abstract_collection_add ((GeeAbstractCollection*) _tmp96_, _tmp97_);
				_g_object_unref0 (app_to_add);
			}
			_gmenu_tree_item_unref0 (app);
		}
		_g_object_unref0 (_app_list);
	}
	_g_object_unref0 (icon_theme);
	if (list) {
		*list = _vala_list;
	} else {
		_g_object_unref0 (_vala_list);
	}
}


SlingshotBackendGMenuEntries* slingshot_backend_gmenu_entries_construct (GType object_type) {
	SlingshotBackendGMenuEntries * self = NULL;
	self = (SlingshotBackendGMenuEntries*) g_object_new (object_type, NULL);
	return self;
}


SlingshotBackendGMenuEntries* slingshot_backend_gmenu_entries_new (void) {
	return slingshot_backend_gmenu_entries_construct (SLINGSHOT_BACKEND_TYPE_GMENU_ENTRIES);
}


static void slingshot_backend_gmenu_entries_class_init (SlingshotBackendGMenuEntriesClass * klass) {
	slingshot_backend_gmenu_entries_parent_class = g_type_class_peek_parent (klass);
}


static void slingshot_backend_gmenu_entries_instance_init (SlingshotBackendGMenuEntries * self) {
}


GType slingshot_backend_gmenu_entries_get_type (void) {
	static volatile gsize slingshot_backend_gmenu_entries_type_id__volatile = 0;
	if (g_once_init_enter (&slingshot_backend_gmenu_entries_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SlingshotBackendGMenuEntriesClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) slingshot_backend_gmenu_entries_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SlingshotBackendGMenuEntries), 0, (GInstanceInitFunc) slingshot_backend_gmenu_entries_instance_init, NULL };
		GType slingshot_backend_gmenu_entries_type_id;
		slingshot_backend_gmenu_entries_type_id = g_type_register_static (G_TYPE_OBJECT, "SlingshotBackendGMenuEntries", &g_define_type_info, 0);
		g_once_init_leave (&slingshot_backend_gmenu_entries_type_id__volatile, slingshot_backend_gmenu_entries_type_id);
	}
	return slingshot_backend_gmenu_entries_type_id__volatile;
}



