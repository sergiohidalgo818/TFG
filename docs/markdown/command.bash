pandoc synapsis_hr.md -f markdown-implicit_figures --listings -H config/listings-setup.tex -V geometry:"left=1cm, top=1cm, right=1cm, bottom=2cm" -V fontsize=12pt -V urlcolor='blue' -V block-headings -o synapsis_hr.pdf