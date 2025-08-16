
# Markov Chain Word Predictor

A simple C++ program that trains a Markov chain on text data and generates random gibberish sentences.

## Installation (WSL Ubuntu)

1. Install dependencies:

   ```bash
   sudo apt update
   sudo apt install build-essential cmake poppler-utils -y
   ```

2. Convert PDF to text:

   ```bash
   pdftotext input.pdf input.txt
   ```
   For simplicity, ensure input.pdf is in the data folder.

3. Place your text files in the `data/` folder (e.g., `data/input.txt`) (if input.pdf was already placed in the data folder, skip this step)

5. Build the project:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
   Make sure you're in the root directory (Markov). If you aren't, navigate to it via terminal.

## Usage

Run from inside the `build/` folder:

```bash
./markov ../data/<file>.txt <word_count>
```

### Examples

* Generate 100 words from `data/input.txt`:

  ```bash
  ./markov ../data/input.txt 100
  ```

* Use the entire file until a dead end:

  ```bash
  ./markov ../data/input.txt all
  OR
  ./markov ../data/input.txt entire
  ```
