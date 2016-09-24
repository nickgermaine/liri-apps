
namespace Slingshot.Frontend {

    public class AppItem : Gtk.EventBox {

        private Gdk.Pixbuf icon;
        private Slingshot.Frontend.Color prominent;
        private string label;
        private Gtk.VBox wrapper;
        private int icon_size;

        const int FPS = 24;
        const int DURATION = 200;
        const int RUN_LENGTH = (int)(DURATION/FPS); // total number of frames
        private int current_frame = 1; // run length, in frames

        public AppItem (int size) {
            this.icon_size = size;

            // EventBox Properties
            this.set_visible_window(false);
            this.can_focus = true;
            this.set_size_request (icon_size * 2, icon_size + 30); // 30 is the padding between icon and label and label's height

            // VBox properties
            this.wrapper = new Gtk.VBox (false, 0);
            this.wrapper.expose_event.connect (this.draw_icon);
            this.add (this.wrapper);


		    // Focused signals
		    this.expose_event.connect (this.draw_background);
		    this.focus_in_event.connect ( () => { this.focus_in (); return true;} );
		    this.focus_out_event.connect ( () => { this.focus_out (); return true;} );

        }

        public void change_app (Gdk.Pixbuf new_icon, string new_name, string new_tooltip) {
            this.current_frame = 1;

            // Icon
            this.icon = new_icon;
            this.prominent = Slingshot.Frontend.Utilities.average_color (this.icon);

            // Label
            this.label = new_name;

            // Tooltip
            this.set_tooltip_text (new_tooltip);

            // Redraw
            this.wrapper.queue_draw ();
        }

        public new void focus_in () {

            GLib.Timeout.add (((int)(1000/this.FPS)), () => {
				if (this.current_frame >= this.RUN_LENGTH || !this.has_focus) {
				    current_frame = 1;
					return false; // stop animation
				}
				queue_draw ();
				this.current_frame++;
				return true;
			});

        }

        public new void focus_out () {

            GLib.Timeout.add (((int)(1000/this.FPS)), () => {
				if (this.current_frame >= this.RUN_LENGTH || this.has_focus) {
				    current_frame = 1;
					return false; // stop animation
				}
				queue_draw ();
				this.current_frame++;
				return true;
			});

        }

        private bool draw_icon (Gtk.Widget widget, Gdk.EventExpose event) {
            Gtk.Allocation size;
            widget.get_allocation (out size);
            var context = Gdk.cairo_create (widget.window);

            // Draw icon
            Gdk.cairo_set_source_pixbuf (context, this.icon, size.x + ((this.icon.width - size.width) / -2.0), size.y);
            context.paint ();

            // Truncate text
            Cairo.TextExtents extents;
            context.select_font_face ("Sans", Cairo.FontSlant.NORMAL, Cairo.FontWeight.NORMAL);
            context.set_font_size (11.5);
            Slingshot.Frontend.Utilities.truncate_text (context, size, 10, this.label, out this.label, out extents); // truncate text

            // Draw text shadow
            context.move_to ((size.x + size.width/2 - extents.width/2) + 1, (size.y + size.height - 10) + 1);
            context.set_source_rgba (0.0, 0.0, 0.0, 0.8);
            context.show_text (this.label);

            // Draw normal text
            context.set_source_rgba (1.0, 1.0, 1.0, 1.0);
            context.move_to (size.x + size.width/2 - extents.width/2, size.y + size.height - 10);
            context.show_text (this.label);

            return false;
        }

        private bool draw_background (Gtk.Widget widget, Gdk.EventExpose event) {
            Gtk.Allocation size;
            widget.get_allocation (out size);
            var context = Gdk.cairo_create (widget.window);

            double progress;
            if (this.current_frame > 1) {
                progress = (double)this.RUN_LENGTH/(double)this.current_frame;
            } else {
                progress = 1;
            }


            return false;
        }


    }
}
