# CS8 File Tokenizer

This is a programming exercise on implementing a file tokenizer via state
machines. It uses the STokenizer class created in the previous assignment but
which has been modified to close certain bugs, such as hanging on multibyte
characters.

## Documentation

Documentation can be built using Doxygen and pdflatex.

### OS X installation of Doxygen and pdflatex

```bash
$ brew install doxygen
$ brew cask install mactex
```
For bash to find pdflatex, you must then restart the terminal.

### Building documentation with Doxygen

To build the documentation, simply run the following from the project's root
folder:

```bash
$ doxygen Doxyfile
```

This creates the HTML and LaTeX documentation in `/docs/html/` and
`/docs/latex/`. For a PDF version of the docs, simply go into the `/docs/latex/`
directory and run `make`. The PDF will be named `/docs/latex/refman.pdf`.
