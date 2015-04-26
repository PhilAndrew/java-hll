/* Generic definitions */


#define PACKAGE it.unimi.dsi.fastutil.chars
#define VALUE_PACKAGE it.unimi.dsi.fastutil.doubles
/* Assertions (useful to generate conditional code) */
#unassert keyclass
#assert keyclass(Character)
#unassert keys
 #assert keys(primitive)
#unassert valueclass
#assert valueclass(Double)
#unassert values
 #assert values(primitive)
/* Current type and class (and size, if applicable) */
#define KEY_TYPE char
#define VALUE_TYPE double
#define KEY_CLASS Character
#define VALUE_CLASS Double
#if #keyclass(Object) || #keyclass(Reference)
#define KEY_GENERIC_CLASS K
#define KEY_GENERIC_TYPE K
#define KEY_GENERIC <K>
#define KEY_GENERIC_WILDCARD <?>
#define KEY_EXTENDS_GENERIC <? extends K>
#define KEY_SUPER_GENERIC <? super K>
#define KEY_GENERIC_CAST (K)
#define KEY_GENERIC_ARRAY_CAST (K[])
#define KEY_GENERIC_BIG_ARRAY_CAST (K[][])
#define SUPPRESS_WARNINGS_KEY_UNCHECKED @SuppressWarnings("unchecked")
#define SUPPRESS_WARNINGS_KEY_RAWTYPES @SuppressWarnings("rawtypes")
#define SUPPRESS_WARNINGS_KEY_UNCHECKED_RAWTYPES @SuppressWarnings({"unchecked","rawtypes"})
#if defined(Custom) && #keyclass(Object)
#define SUPPRESS_WARNINGS_CUSTOM_KEY_UNCHECKED @SuppressWarnings("unchecked")
#else
#define SUPPRESS_WARNINGS_CUSTOM_KEY_UNCHECKED
#endif
#else
#define KEY_GENERIC_CLASS KEY_CLASS
#define KEY_GENERIC_TYPE KEY_TYPE
#define KEY_GENERIC
#define KEY_GENERIC_WILDCARD
#define KEY_EXTENDS_GENERIC
#define KEY_SUPER_GENERIC
#define KEY_GENERIC_CAST
#define KEY_GENERIC_ARRAY_CAST
#define KEY_GENERIC_BIG_ARRAY_CAST
#define SUPPRESS_WARNINGS_KEY_UNCHECKED
#define SUPPRESS_WARNINGS_KEY_RAWTYPES
#define SUPPRESS_WARNINGS_KEY_UNCHECKED_RAWTYPES
#define SUPPRESS_WARNINGS_CUSTOM_KEY_UNCHECKED
#endif
#if #valueclass(Object) || #valueclass(Reference)
#define VALUE_GENERIC_CLASS V
#define VALUE_GENERIC_TYPE V
#define VALUE_GENERIC <V>
#define VALUE_EXTENDS_GENERIC <? extends V>
#define VALUE_GENERIC_CAST (V)
#define VALUE_GENERIC_ARRAY_CAST (V[])
#define SUPPRESS_WARNINGS_VALUE_UNCHECKED @SuppressWarnings("unchecked")
#define SUPPRESS_WARNINGS_VALUE_RAWTYPES @SuppressWarnings("rawtypes")
#else
#define VALUE_GENERIC_CLASS VALUE_CLASS
#define VALUE_GENERIC_TYPE VALUE_TYPE
#define VALUE_GENERIC
#define VALUE_EXTENDS_GENERIC
#define VALUE_GENERIC_CAST
#define VALUE_GENERIC_ARRAY_CAST
#define SUPPRESS_WARNINGS_VALUE_UNCHECKED
#define SUPPRESS_WARNINGS_VALUE_RAWTYPES
#endif
#if #keyclass(Object) || #keyclass(Reference)
#if #valueclass(Object) || #valueclass(Reference)
#define KEY_VALUE_GENERIC <K,V>
#define KEY_VALUE_EXTENDS_GENERIC <? extends K, ? extends V>
#else
#define KEY_VALUE_GENERIC <K>
#define KEY_VALUE_EXTENDS_GENERIC <? extends K>
#endif
#else
#if #valueclass(Object) || #valueclass(Reference)
#define KEY_VALUE_GENERIC <V>
#define KEY_VALUE_EXTENDS_GENERIC <? extends V>
#else
#define KEY_VALUE_GENERIC
#define KEY_VALUE_EXTENDS_GENERIC
#endif
#endif
#if #keyclass(Object) || #keyclass(Reference) || #valueclass(Object) || #valueclass(Reference)
#define SUPPRESS_WARNINGS_KEY_VALUE_UNCHECKED @SuppressWarnings("unchecked")
#define SUPPRESS_WARNINGS_KEY_VALUE_RAWTYPES @SuppressWarnings("rawtypes")
#else
#define SUPPRESS_WARNINGS_KEY_VALUE_UNCHECKED
#define SUPPRESS_WARNINGS_KEY_VALUE_RAWTYPES
#endif
/* Value methods */
#define KEY_VALUE charValue
#define VALUE_VALUE doubleValue
/* Interfaces (keys) */
#define COLLECTION CharCollection

#define SET CharSet

#define HASH CharHash

#define SORTED_SET CharSortedSet

#define STD_SORTED_SET CharSortedSet

#define FUNCTION Char2DoubleFunction
#define MAP Char2DoubleMap
#define SORTED_MAP Char2DoubleSortedMap
#if #keyclass(Object) || #keyclass(Reference)
#define STD_SORTED_MAP SortedMap

#define STRATEGY Strategy

#else
#define STD_SORTED_MAP Char2DoubleSortedMap

#define STRATEGY PACKAGE.CharHash.Strategy

#endif
#define LIST CharList

#define BIG_LIST CharBigList

#define STACK CharStack

#define PRIORITY_QUEUE CharPriorityQueue

#define INDIRECT_PRIORITY_QUEUE CharIndirectPriorityQueue

#define INDIRECT_DOUBLE_PRIORITY_QUEUE CharIndirectDoublePriorityQueue

#define KEY_ITERATOR CharIterator

#define KEY_ITERABLE CharIterable

#define KEY_BIDI_ITERATOR CharBidirectionalIterator

#define KEY_LIST_ITERATOR CharListIterator

#define KEY_BIG_LIST_ITERATOR CharBigListIterator

#define STD_KEY_ITERATOR CharIterator

#define KEY_COMPARATOR CharComparator

/* Interfaces (values) */
#define VALUE_COLLECTION DoubleCollection

#define VALUE_ARRAY_SET DoubleArraySet

#define VALUE_ITERATOR DoubleIterator

#define VALUE_LIST_ITERATOR DoubleListIterator

/* Abstract implementations (keys) */
#define ABSTRACT_COLLECTION AbstractCharCollection

#define ABSTRACT_SET AbstractCharSet

#define ABSTRACT_SORTED_SET AbstractCharSortedSet
#define ABSTRACT_FUNCTION AbstractChar2DoubleFunction
#define ABSTRACT_MAP AbstractChar2DoubleMap
#define ABSTRACT_FUNCTION AbstractChar2DoubleFunction
#define ABSTRACT_SORTED_MAP AbstractChar2DoubleSortedMap
#define ABSTRACT_LIST AbstractCharList

#define ABSTRACT_BIG_LIST AbstractCharBigList

#define SUBLIST CharSubList

#define ABSTRACT_PRIORITY_QUEUE AbstractCharPriorityQueue

#define ABSTRACT_STACK AbstractCharStack

#define KEY_ABSTRACT_ITERATOR AbstractCharIterator

#define KEY_ABSTRACT_BIDI_ITERATOR AbstractCharBidirectionalIterator

#define KEY_ABSTRACT_LIST_ITERATOR AbstractCharListIterator

#define KEY_ABSTRACT_BIG_LIST_ITERATOR AbstractCharBigListIterator

#if #keyclass(Object)
#define KEY_ABSTRACT_COMPARATOR Comparator

#else
#define KEY_ABSTRACT_COMPARATOR AbstractCharComparator

#endif
/* Abstract implementations (values) */
#define VALUE_ABSTRACT_COLLECTION AbstractDoubleCollection

#define VALUE_ABSTRACT_ITERATOR AbstractDoubleIterator

#define VALUE_ABSTRACT_BIDI_ITERATOR AbstractDoubleBidirectionalIterator

/* Static containers (keys) */
#define COLLECTIONS CharCollections

#define SETS CharSets

#define SORTED_SETS CharSortedSets

#define LISTS CharLists

#define BIG_LISTS CharBigLists

#define MAPS Char2DoubleMaps
#define FUNCTIONS Char2DoubleFunctions
#define SORTED_MAPS Char2DoubleSortedMaps
#define PRIORITY_QUEUES CharPriorityQueues

#define HEAPS CharHeaps

#define SEMI_INDIRECT_HEAPS CharSemiIndirectHeaps

#define INDIRECT_HEAPS CharIndirectHeaps

#define ARRAYS CharArrays

#define BIG_ARRAYS CharBigArrays

#define ITERATORS CharIterators

#define BIG_LIST_ITERATORS CharBigListIterators

#define COMPARATORS CharComparators

/* Static containers (values) */
#define VALUE_COLLECTIONS DoubleCollections

#define VALUE_SETS DoubleSets

#define VALUE_ARRAYS DoubleArrays

/* Implementations */
#define OPEN_HASH_SET CharOpenHashSet

#define OPEN_HASH_BIG_SET CharOpenHashBigSet

#define OPEN_DOUBLE_HASH_SET CharOpenDoubleHashSet

#define OPEN_HASH_MAP Char2DoubleOpenHashMap

#define OPEN_HASH_BIG_MAP Char2DoubleOpenHashBigMap

#define STRIPED_OPEN_HASH_MAP StripedChar2DoubleOpenHashMap

#define OPEN_DOUBLE_HASH_MAP Char2DoubleOpenDoubleHashMap

#define ARRAY_SET CharArraySet

#define ARRAY_MAP Char2DoubleArrayMap

#define LINKED_OPEN_HASH_SET CharLinkedOpenHashSet

#define AVL_TREE_SET CharAVLTreeSet

#define RB_TREE_SET CharRBTreeSet

#define AVL_TREE_MAP Char2DoubleAVLTreeMap

#define RB_TREE_MAP Char2DoubleRBTreeMap

#define ARRAY_LIST CharArrayList

#define BIG_ARRAY_BIG_LIST CharBigArrayBigList

#define ARRAY_FRONT_CODED_LIST CharArrayFrontCodedList

#define HEAP_PRIORITY_QUEUE CharHeapPriorityQueue

#define HEAP_SEMI_INDIRECT_PRIORITY_QUEUE CharHeapSemiIndirectPriorityQueue

#define HEAP_INDIRECT_PRIORITY_QUEUE CharHeapIndirectPriorityQueue

#define HEAP_SESQUI_INDIRECT_DOUBLE_PRIORITY_QUEUE CharHeapSesquiIndirectDoublePriorityQueue

#define HEAP_INDIRECT_DOUBLE_PRIORITY_QUEUE CharHeapIndirectDoublePriorityQueue

#define ARRAY_FIFO_QUEUE CharArrayFIFOQueue

#define ARRAY_PRIORITY_QUEUE CharArrayPriorityQueue

#define ARRAY_INDIRECT_PRIORITY_QUEUE CharArrayIndirectPriorityQueue

#define ARRAY_INDIRECT_DOUBLE_PRIORITY_QUEUE CharArrayIndirectDoublePriorityQueue

/* Synchronized wrappers */
#define SYNCHRONIZED_COLLECTION SynchronizedCharCollection

#define SYNCHRONIZED_SET SynchronizedCharSet

#define SYNCHRONIZED_SORTED_SET SynchronizedCharSortedSet

#define SYNCHRONIZED_FUNCTION SynchronizedChar2DoubleFunction

#define SYNCHRONIZED_MAP SynchronizedChar2DoubleMap

#define SYNCHRONIZED_LIST SynchronizedCharList

/* Unmodifiable wrappers */
#define UNMODIFIABLE_COLLECTION UnmodifiableCharCollection

#define UNMODIFIABLE_SET UnmodifiableCharSet

#define UNMODIFIABLE_SORTED_SET UnmodifiableCharSortedSet

#define UNMODIFIABLE_FUNCTION UnmodifiableChar2DoubleFunction

#define UNMODIFIABLE_MAP UnmodifiableChar2DoubleMap

#define UNMODIFIABLE_LIST UnmodifiableCharList

#define UNMODIFIABLE_KEY_ITERATOR UnmodifiableCharIterator

#define UNMODIFIABLE_KEY_BIDI_ITERATOR UnmodifiableCharBidirectionalIterator

#define UNMODIFIABLE_KEY_LIST_ITERATOR UnmodifiableCharListIterator

/* Other wrappers */
#define KEY_READER_WRAPPER CharReaderWrapper

#define KEY_DATA_INPUT_WRAPPER CharDataInputWrapper

/* Methods (keys) */
#define NEXT_KEY nextChar
#define PREV_KEY previousChar
#define FIRST_KEY firstCharKey
#define LAST_KEY lastCharKey
#define GET_KEY getChar
#define REMOVE_KEY removeChar
#define READ_KEY readChar
#define WRITE_KEY writeChar
#define DEQUEUE dequeueChar
#define DEQUEUE_LAST dequeueLastChar
#define SUBLIST_METHOD charSubList
#define SINGLETON_METHOD charSingleton

#define FIRST firstChar
#define LAST lastChar
#define TOP topChar
#define PEEK peekChar
#define POP popChar
#define KEY_ITERATOR_METHOD charIterator

#define KEY_LIST_ITERATOR_METHOD charListIterator

#define KEY_EMPTY_ITERATOR_METHOD emptyCharIterator

#define AS_KEY_ITERATOR asCharIterator

#define AS_KEY_ITERABLE asCharIterable

#define TO_KEY_ARRAY toCharArray
#define ENTRY_GET_KEY getCharKey
#define REMOVE_FIRST_KEY removeFirstChar
#define REMOVE_LAST_KEY removeLastChar
#define PARSE_KEY parseChar
#define LOAD_KEYS loadChars
#define LOAD_KEYS_BIG loadCharsBig
#define STORE_KEYS storeChars
/* Methods (values) */
#define NEXT_VALUE nextDouble
#define PREV_VALUE previousDouble
#define READ_VALUE readDouble
#define WRITE_VALUE writeDouble
#define VALUE_ITERATOR_METHOD doubleIterator

#define ENTRY_GET_VALUE getDoubleValue
#define REMOVE_FIRST_VALUE removeFirstDouble
#define REMOVE_LAST_VALUE removeLastDouble
/* Methods (keys/values) */
#define ENTRYSET char2DoubleEntrySet
/* Methods that have special names depending on keys (but the special names depend on values) */
#if #keyclass(Object) || #keyclass(Reference)
#define GET_VALUE getDouble
#define REMOVE_VALUE removeDouble
#else
#define GET_VALUE get
#define REMOVE_VALUE remove
#endif
/* Equality */
#define KEY_EQUALS_NOT_NULL_CAST(x,y) KEY_EQUALS_NOT_NULL(x,y)
#define KEY2INTHASH_CAST(x) KEY2INTHASH(x)
#if #keyclass(Object)
#ifdef Custom
#define KEY_EQUALS(x,y) ( strategy.equals( (x), (y) ) )
#define KEY_EQUALS_NOT_NULL(x,y) ( strategy.equals( (x), (y) ) )
#undef KEY_EQUALS_NOT_NULL_CAST
#define KEY_EQUALS_NOT_NULL_CAST(x,y) ( strategy.equals(  KEY_GENERIC_CAST (x), (y) ) )
#else
#define KEY_EQUALS(x,y) ( (x) == null ? (y) == null : (x).equals(y) )
#define KEY_EQUALS_NOT_NULL(x,y) ( (x).equals(y) )
#endif
#define KEY_IS_NULL(x) ( (x) == null )
#elif #keyclass(Float)
#define KEY_EQUALS(x,y) ( Float.floatToIntBits(x) == Float.floatToIntBits(y) )
#define KEY_EQUALS_NOT_NULL(x,y) ( Float.floatToIntBits(x) == Float.floatToIntBits(y) )
#define KEY_IS_NULL(x) ( Float.floatToIntBits(x) == 0 )
#elif #keyclass(Double)
#define KEY_EQUALS(x,y) ( Double.doubleToLongBits(x) == Double.doubleToLongBits(y) )
#define KEY_EQUALS_NOT_NULL(x,y) ( Double.doubleToLongBits(x) == Double.doubleToLongBits(y) )
#define KEY_IS_NULL(x) ( Double.doubleToLongBits(x) == 0 )
#else
#define KEY_EQUALS(x,y) ( (x) == (y) )
#define KEY_EQUALS_NOT_NULL(x,y) ( (x) == (y) )
#define KEY_IS_NULL(x) ( (x) == KEY_NULL )
#endif

#if #valueclass(Object)
#define VALUE_EQUALS(x,y) ( (x) == null ? (y) == null : (x).equals(y) )
#else
#define VALUE_EQUALS(x,y) ( (x) == (y) )
#endif

/* Object/Reference-only definitions (keys) */
#if #keyclass(Object) || #keyclass(Reference)
#define REMOVE remove
#define KEY_OBJ2TYPE(x) (x)
#define KEY_CLASS2TYPE(x) (x)
#define KEY2OBJ(x) (x)
#if #keyclass(Object)
#ifdef Custom
#define KEY2JAVAHASH_NOT_NULL(x) ( strategy.hashCode(x) )
#define KEY2INTHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( strategy.hashCode(x) ) )
#undef KEY2INTHASH_CAST
#define KEY2INTHASH_CAST(x) ( it.unimi.dsi.fastutil.HashCommon.mix( strategy.hashCode(  KEY_GENERIC_CAST  x) ) )
#define KEY2LONGHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( (long)( strategy.hashCode(x)) ) ) )
#else
#define KEY2JAVAHASH_NOT_NULL(x) ( (x).hashCode() )
#define KEY2JAVAHASH(x) ( (x) == null ? 0 : (x).hashCode() )
#define KEY2INTHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( (x).hashCode() ) )
#define KEY2LONGHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( (long)( (x).hashCode() ) ) )
#endif
#else
#define KEY2JAVAHASH_NOT_NULL(x) ( System.identityHashCode(x) )
#define KEY2INTHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( System.identityHashCode(x) ) )
#define KEY2LONGHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( (long)( System.identityHashCode(x) ) ) )
#endif
#define KEY_CMP(x,y) ( ((Comparable<KEY_GENERIC_CLASS>)(x)).compareTo(y) )
#define KEY_CMP_EQ(x,y) ( ((Comparable<KEY_GENERIC_CLASS>)(x)).compareTo(y) == 0 )
#define KEY_LESS(x,y) ( ((Comparable<KEY_GENERIC_CLASS>)(x)).compareTo(y) < 0 )
#define KEY_LESSEQ(x,y) ( ((Comparable<KEY_GENERIC_CLASS>)(x)).compareTo(y) <= 0 )
#define KEY_NULL (null)
#else
/* Primitive-type-only definitions (keys) */
#define REMOVE rem
#define KEY_CLASS2TYPE(x) ((x).KEY_VALUE())
#define KEY_OBJ2TYPE(x) (KEY_CLASS2TYPE((KEY_CLASS)(x)))
#define KEY2OBJ(x) (KEY_CLASS.valueOf(x))
#if #keyclass(Boolean)
#define KEY_CMP_EQ(x,y) ( (x) == (y) )
#define KEY_NULL (false)
#define KEY_CMP(x,y) ( KEY_CLASS.compare((x),(y)) )
#define KEY_LESS(x,y) ( !(x) && (y) )
#define KEY_LESSEQ(x,y) ( !(x) || (y) )
#else
#if #keyclass(Byte) || #keyclass(Short) || #keyclass(Character)
#define KEY_NULL ((KEY_TYPE)0)
#else
#define KEY_NULL (0)
#endif
#if #keyclass(Float) || #keyclass(Double)
#define KEY_CMP_EQ(x,y) ( KEY_CLASS.compare((x),(y)) == 0 )
#define KEY_CMP(x,y) ( KEY_CLASS.compare((x),(y)) )
#define KEY_LESS(x,y) ( KEY_CLASS.compare((x),(y)) < 0 )
#define KEY_LESSEQ(x,y) ( KEY_CLASS.compare((x),(y)) <= 0 )
#else
#define KEY_CMP_EQ(x,y) ( (x) == (y) )
#define KEY_CMP(x,y) ( KEY_CLASS.compare((x),(y)) )
#define KEY_LESS(x,y) ( (x) < (y) )
#define KEY_LESSEQ(x,y) ( (x) <= (y) )
#endif
#if #keyclass(Float)
#define KEY2LEXINT(x) fixFloat(x)
#elif #keyclass(Double)
#define KEY2LEXINT(x) fixDouble(x)
#else
#define KEY2LEXINT(x) (x)
#endif
#endif
#ifdef Custom
#define KEY2JAVAHASH_NOT_NULL(x) ( strategy.hashCode(x) )
#define KEY2INTHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( strategy.hashCode(x) ) )
#define KEY2LONGHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( (long)( strategy.hashCode(x) ) ) )
#else
#if #keyclass(Float)
#define KEY2JAVAHASH_NOT_NULL(x) it.unimi.dsi.fastutil.HashCommon.float2int(x)
#define KEY2INTHASH(x) it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(x) )
#define KEY2LONGHASH(x) it.unimi.dsi.fastutil.HashCommon.mix( (long)( it.unimi.dsi.fastutil.HashCommon.float2int(x) ) )
#define INT(x) (x)
#elif #keyclass(Double)
#define KEY2JAVAHASH_NOT_NULL(x) it.unimi.dsi.fastutil.HashCommon.double2int(x)
#define KEY2INTHASH(x) (int)it.unimi.dsi.fastutil.HashCommon.mix( Double.doubleToRawLongBits(x) )
#define KEY2LONGHASH(x) it.unimi.dsi.fastutil.HashCommon.mix( Double.doubleToRawLongBits(x) )
#define INT(x) (int)(x)
#elif #keyclass(Long)
#define KEY2JAVAHASH_NOT_NULL(x) it.unimi.dsi.fastutil.HashCommon.long2int(x)
#define KEY2INTHASH(x) (int)it.unimi.dsi.fastutil.HashCommon.mix( (x) )
#define KEY2LONGHASH(x) it.unimi.dsi.fastutil.HashCommon.mix( (x) )
#define INT(x) (int)(x)
#elif #keyclass(Boolean)
#define KEY2JAVAHASH_NOT_NULL(x) ((x) ? 1231 : 1237)
#define KEY2INTHASH(x) ((x) ? 0xfab5368 : 0xcba05e7b)
#define KEY2LONGHASH(x) ((x) ? 0x74a19fc8b6428188L : 0xbaeca2031a4fd9ecL)
#else
#define KEY2JAVAHASH_NOT_NULL(x) (x)
#define KEY2INTHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( (x) ) )
#define KEY2LONGHASH(x) ( it.unimi.dsi.fastutil.HashCommon.mix( (long)( (x) ) ) )
#define INT(x) (x)
#endif
#endif
#endif
#ifndef KEY2JAVAHASH
#define KEY2JAVAHASH(x) KEY2JAVAHASH_NOT_NULL(x)
#endif
/* Object/Reference-only definitions (values) */
#if #valueclass(Object) || #valueclass(Reference)
#define VALUE_OBJ2TYPE(x) (x)
#define VALUE_CLASS2TYPE(x) (x)
#define VALUE2OBJ(x) (x)
#if #valueclass(Object)
#define VALUE2JAVAHASH(x) ( (x) == null ? 0 : (x).hashCode() )
#else
#define VALUE2JAVAHASH(x) ( (x) == null ? 0 : System.identityHashCode(x) )
#endif
#define VALUE_NULL (null)
#define OBJECT_DEFAULT_RETURN_VALUE (this.defRetValue)
#else
/* Primitive-type-only definitions (values) */
#define VALUE_CLASS2TYPE(x) ((x).VALUE_VALUE())
#define VALUE_OBJ2TYPE(x) (VALUE_CLASS2TYPE((VALUE_CLASS)(x)))
#define VALUE2OBJ(x) (VALUE_CLASS.valueOf(x))
#if #valueclass(Float) || #valueclass(Double) || #valueclass(Long)
#define VALUE_NULL (0)
#define VALUE2JAVAHASH(x) it.unimi.dsi.fastutil.HashCommon.double2int(x)
#elif #valueclass(Boolean)
#define VALUE_NULL (false)
#define VALUE2JAVAHASH(x) (x ? 1231 : 1237)
#else
#if #valueclass(Integer)
#define VALUE_NULL (0)
#else
#define VALUE_NULL ((VALUE_TYPE)0)
#endif
#define VALUE2JAVAHASH(x) (x)
#endif
#define OBJECT_DEFAULT_RETURN_VALUE (null)
#endif
#include "drv/AbstractFunction.drv"

