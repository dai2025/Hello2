In this blog post, I will show you how to create a simple graphical user interface (GUI) in Python using the Tkinter module. Tkinter is a standard library that provides a set of widgets for creating GUIs. Widgets are basic components of a GUI, such as buttons, labels, menus, etc.

To use Tkinter, we need to import it first:

```python
from tkinter import *
from tkinter import messagebox
from tkinter import filedialog
```

Then, we need to create a class that inherits from the `Frame` widget. A `Frame` is a container that can hold other widgets. We can use the `__init__` method to initialize the frame and its attributes. The `master` parameter is the parent widget of the frame, which can be another widget or the root window. The `super().__init__(master)` call invokes the constructor of the `Frame` class and passes the `master` argument to it. We also need to call the `pack` method to make the frame visible and the `_widgets` method to create and add other widgets to the frame.

```python
class App(Frame):
def __init__(self, master=None):
print(master, type(master), type(Tk))
super().__init__(master)
self.master = master
self.pack()
self._widgets()
```

The `_widgets` method is where we define and configure the widgets that we want to display in our GUI. In this example, we will create two buttons: one with the text "title" and another with the text "text". We can use the `Button` widget to create buttons and pass the parent widget (in this case, the frame) as an argument. We can also set various options for the buttons using keyword arguments or dictionary syntax. For example, we can set the `text` option to specify the label of the button, and the `command` option to specify a function that will be executed when the button is clicked. We also need to call the `pack` method to make the buttons visible and arrange them in the frame.

```python
def _widgets(self):
self.title=__name__
self._button(name="title")
self._button()

def _button(self, name='text'):
self.button = Button(self)
self.button['text'] = name
self.button['command'] = self._call_back
self.button.pack()
```

The `_call_back` method is the function that will be executed when either button is clicked. In this example, we will simply display a message box with a title and a message using the `messagebox.showinfo` function. We can pass the title and the message as arguments to this function.

```python
def _call_back(self):
messagebox.showinfo(self.title, 'Thank you')
```

Finally, we need to create an instance of our class and pass it a root window as an argument. The root window is the main window of our GUI and it is created by calling the `Tk` function. We also need to call the `mainloop` method on the root window or on our instance to start the event loop that handles user interactions with our GUI.

```python
def main():
root = Tk()
app = App(master=root)
app.mainloop()
```

To run our program, we can save it as a Python file (e.g., gui.py) and execute it from the command line:

```bash
python gui.py
```

This will open a window with two buttons as shown below:

![GUI example](https://i.imgur.com/pppppppppppppp.png)

If we click on either button, we will see a message box like this:

![Message box example](https://i.imgur.com/aaaaaaaaaaaaa.png)

We can also use other widgets from Tkinter to create more complex GUIs. For example, we can use the `filedialog.askopenfile` function to open a file dialog and let the user select a file from their system. We can pass some options to this function, such as `filetypes` to specify what types of files can be selected, and `initialdir` to specify what directory should be opened by default. The function returns a file object that we can use to read or write data from or to the file.

```python
type1 = [('text file' ,'*.txt'), ('swift file', '*.swift')]
dir1 = 'C:/Path/to'
f = filedialog.askopenfile(filetypes=type1, initialdir=dir1)
print(f)
```

This will open a file dialog like this:

![File dialog example](
