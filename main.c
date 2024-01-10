
#include <gtk/gtk.h>
#include <glib-2.0/glib.h>

GtkWidget *window;
GtkWidget *main_box;
GtkWidget *container1;
GtkWidget *container2;
GtkWidget *label;
GtkWidget *minus_button;
GtkWidget *plus_button;
GtkWidget *add_button;

void change2cont1();
void change2cont2();

// signal callback
void button_clicked(GtkWidget *button, gpointer data)
{
  if (data == NULL)
  {
    change2cont1();
    return;
  }
  GtkWidget *label_buff = (GtkWidget *)data;
  const gchar *current_text = gtk_label_get_text(GTK_LABEL(label_buff));

  gint current_value = g_ascii_strtod(current_text, NULL);

  if (button == GTK_WIDGET(g_object_get_data(G_OBJECT(label_buff), "minus_button")))
  {
    current_value--;
    if (current_value <= 0)
    {
      change2cont2();
      return;
    }
  }
  else if (button == GTK_WIDGET(g_object_get_data(G_OBJECT(label_buff), "plus_button")))
  {
    current_value++;
  }

  gchar *new_text = g_strdup_printf("%d", current_value);
  gtk_label_set_text(GTK_LABEL(label_buff), new_text);
  g_free(new_text);
}

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Button Example");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_container_add(GTK_CONTAINER(window), main_box);

  container2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add(GTK_CONTAINER(main_box), container2);

  add_button = gtk_button_new_with_label("Add");
  gtk_box_pack_start(GTK_BOX(container2), add_button, TRUE, TRUE, 0);
  g_signal_connect(add_button, "clicked", G_CALLBACK(button_clicked), NULL);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

void change2cont1()
{
  gtk_container_remove(GTK_CONTAINER(main_box), container2);
  container1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  label = gtk_label_new("1");
  minus_button = gtk_button_new_with_label("-");
  g_signal_connect(minus_button, "clicked", G_CALLBACK(button_clicked), label);
  gtk_box_pack_start(GTK_BOX(container1), minus_button, FALSE, FALSE, 0);
  g_object_set_data(G_OBJECT(label), "minus_button", minus_button);

  gtk_box_pack_start(GTK_BOX(container1), label, TRUE, TRUE, 0);

  plus_button = gtk_button_new_with_label("+");
  g_signal_connect(plus_button, "clicked", G_CALLBACK(button_clicked), label);
  gtk_box_pack_start(GTK_BOX(container1), plus_button, FALSE, FALSE, 0);
  g_object_set_data(G_OBJECT(label), "plus_button", plus_button);
  gtk_container_add(GTK_CONTAINER(main_box), container1);
  gtk_widget_show_all(window);
}

void change2cont2()
{
  gtk_container_remove(GTK_CONTAINER(main_box), container1);
  container2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  add_button = gtk_button_new_with_label("Add");
  gtk_box_pack_start(GTK_BOX(container2), add_button, TRUE, TRUE, 0);
  g_signal_connect(add_button, "clicked", G_CALLBACK(button_clicked), NULL);
  gtk_container_add(GTK_CONTAINER(main_box), container2);
  gtk_widget_show_all(window);
}