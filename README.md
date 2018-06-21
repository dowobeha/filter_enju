# filter_enju

This code takes as input a parallel English-Japanese corpus, with the English side parsed in the [Enju format](https://github.com/mynlp/enju), and returns a filtered version of that corpus. Any sentences with a parse failure are removed. Any sentences that are longer than a specified maximum sentence length are removed.

This repository contains code adapted from:
* https://github.com/tempra28/tree2seq
* https://github.com/hassyGo/N3LP

To compile:
* Install Boost, GNU Make, and a modern C++ compiler
* If Boost is installed somewhere other than /usr/include/boost, modify Makefile to point to the correct location
* Run make

Usage:	
```bash
./filter_enju in.enju in.ja maxSentenceLength out.en out.enju out.ja:
```

Description of files:
* *in.enju* English side of a parallel corpus, one sentence per line, parsed in the [Enju format](https://github.com/mynlp/enju)
* *in.ja* Japanese side of a parallel corpus, one sentence per line
* *maxSentenceLength* The maximum sentence length. Parallel sentences where either side is longer than this will be discarded.
* *out.en* English side of filtered parellel corpus (created by this program)
* *out.en* Parsed English side of filtered parellel corpus (created by this program)
* *out.ja* Japanese side of filtered parellel corpus (created by this program)
