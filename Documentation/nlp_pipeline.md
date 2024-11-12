
### **Documentation/nlp_pipeline.md**

```markdown
# NLP Pipeline

The NLP pipeline in NeuroCore consists of the following stages:

1. **Text Cleaning**
    - **Component**: `TextCleaner`
    - **Functionality**: Converts text to lowercase and removes punctuation.

2. **Tokenization**
    - **Component**: `Tokenizer`
    - **Functionality**: Splits cleaned text into individual tokens (words).

3. **Stop Words Removal**
    - **Component**: `StopWordsRemover`
    - **Functionality**: Removes common stop words that do not contribute to the semantic meaning.

4. **Lemmatization**
    - **Component**: `Lemmatiser`
    - **Functionality**: Reduces words to their base or dictionary form.

5. **Embeddings**
    - **Component**: `WordEmbeddings`
    - **Functionality**: Converts tokens into numerical vectors using pre-trained embeddings.

6. **Named Entity Recognition (NER)**
    - **Component**: `NamedEntityRecognition`
    - **Functionality**: Identifies and classifies named entities within the text.

7. **Sentiment Analysis**
    - **Component**: `SentimentAnalysis`
    - **Functionality**: Determines the sentiment polarity of the text.

8. **Part-of-Speech (POS) Tagging**
    - **Component**: `PartOfSpeechTagger`
    - **Functionality**: Assigns grammatical categories to each token.

## Workflow

1. **Input Text**: Raw text input is received for processing.
2. **Cleaning**: `TextCleaner` processes the text to standardize it.
3. **Tokenization**: `Tokenizer` splits the text into tokens.
4. **Stop Words Removal**: `StopWordsRemover` filters out non-essential words.
5. **Lemmatization**: `Lemmatiser` converts tokens to their base forms.
6. **Embeddings**: `WordEmbeddings` transforms tokens into numerical vectors.
7. **NER**: `NamedEntityRecognition` identifies entities like names, dates, etc.
8. **Sentiment Analysis**: `SentimentAnalysis` assesses the emotional tone.
9. **POS Tagging**: `PartOfSpeechTagger` labels each token with its grammatical role.
10. **Output**: Processed data is forwarded to the neural network for training or inference.

## Integration with Neural Network

The processed embeddings are used as input features for the neural network. NLP tasks like NER and Sentiment Analysis provide additional contextual information that enhances the model's understanding and reasoning capabilities.

## Customization

- **Embedding Models**: You can switch between different embedding models (e.g., Word2Vec, GloVe) by adjusting the `EmbeddingLoader`.
- **NLP Models**: Replace or extend NLP components with more advanced models as needed.
- **Pipeline Stages**: Modify or reorder pipeline stages to experiment with different preprocessing strategies.
