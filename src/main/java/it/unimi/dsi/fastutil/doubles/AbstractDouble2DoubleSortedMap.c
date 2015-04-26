/* Generic definitions */


#define PACKAGE it.unimi.dsi.fastutil.doubles
#define VALUE_PACKAGE it.unimi.dsi.fastutil.doubles
/* Assertions (useful to generate conditional code) */
#unassert keyclass
#assert keyclass(Double)
#unassert keys
 #assert keys(primitive)
#unassert valueclass
#assert valueclass(Double)
#unassert values
 #assert values(primitive)
/* Current type and class (and size, if applicable) */
#define KEY_TYPE double
#define VALUE_TYPE double
#define KEY_CLASS Double
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
#define KEY_VALUE doubleValue
#define VALUE_VALUE doubleValue
/* Interfaces (keys) */
#define COLLECTION DoubleCollection

#define SET DoubleSet

#define HASH DoubleHash

#define SORTED_SET DoubleSortedSet

#define STD_SORTED_SET DoubleSortedSet

#define FUNCTION Double2DoubleFunction
#define MAP Double2DoubleMap
#define SORTED_MAP Double2DoubleSortedMap
#if #keyclass(Object) || #keyclass(Reference)
#define STD_SORTED_MAP SortedMap

#define STRATEGY Strategy

#else
#define STD_SORTED_MAP Double2DoubleSortedMap

#define STRATEGY PACKAGE.DoubleHash.Strategy

#endif
#define LIST DoubleList

#define BIG_LIST DoubleBigList

#define STACK DoubleStack

#define PRIORITY_QUEUE DoublePriorityQueue

#define INDIRECT_PRIORITY_QUEUE DoubleIndirectPriorityQueue

#define INDIRECT_DOUBLE_PRIORITY_QUEUE DoubleIndirectDoublePriorityQueue

#define KEY_ITERATOR DoubleIterator

#define KEY_ITERABLE DoubleIterable

#define KEY_BIDI_ITERATOR DoubleBidirectionalIterator

#define KEY_LIST_ITERATOR DoubleListIterator

#define KEY_BIG_LIST_ITERATOR DoubleBigListIterator

#define STD_KEY_ITERATOR DoubleIterator

#define KEY_COMPARATOR DoubleComparator

/* Interfaces (values) */
#define VALUE_COLLECTION DoubleCollection

#define VALUE_ARRAY_SET DoubleArraySet

#define VALUE_ITERATOR DoubleIterator

#define VALUE_LIST_ITERATOR DoubleListIterator

/* Abstract implementations (keys) */
#define ABSTRACT_COLLECTION AbstractDoubleCollection

#define ABSTRACT_SET AbstractDoubleSet

#define ABSTRACT_SORTED_SET AbstractDoubleSortedSet
#define ABSTRACT_FUNCTION AbstractDouble2DoubleFunction
#define ABSTRACT_MAP AbstractDouble2DoubleMap
#define ABSTRACT_FUNCTION AbstractDouble2DoubleFunction
#define ABSTRACT_SORTED_MAP AbstractDouble2DoubleSortedMap
#define ABSTRACT_LIST AbstractDoubleList

#define ABSTRACT_BIG_LIST AbstractDoubleBigList

#define SUBLIST DoubleSubList

#define ABSTRACT_PRIORITY_QUEUE AbstractDoublePriorityQueue

#define ABSTRACT_STACK AbstractDoubleStack

#define KEY_ABSTRACT_ITERATOR AbstractDoubleIterator

#define KEY_ABSTRACT_BIDI_ITERATOR AbstractDoubleBidirectionalIterator

#define KEY_ABSTRACT_LIST_ITERATOR AbstractDoubleListIterator

#define KEY_ABSTRACT_BIG_LIST_ITERATOR AbstractDoubleBigListIterator

#if #keyclass(Object)
#define KEY_ABSTRACT_COMPARATOR Comparator

#else
#define KEY_ABSTRACT_COMPARATOR AbstractDoubleComparator

#endif
/* Abstract implementations (values) */
#define VALUE_ABSTRACT_COLLECTION AbstractDoubleCollection

#define VALUE_ABSTRACT_ITERATOR AbstractDoubleIterator

#define VALUE_ABSTRACT_BIDI_ITERATOR AbstractDoubleBidirectionalIterator

/* Static containers (keys) */
#define COLLECTIONS DoubleCollections

#define SETS DoubleSets

#define SORTED_SETS DoubleSortedSets

#define LISTS DoubleLists

#define BIG_LISTS DoubleBigLists

#define MAPS Double2DoubleMaps
#define FUNCTIONS Double2DoubleFunctions
#define SORTED_MAPS Double2DoubleSortedMaps
#define PRIORITY_QUEUES DoublePriorityQueues

#define HEAPS DoubleHeaps

#define SEMI_INDIRECT_HEAPS DoubleSemiIndirectHeaps

#define INDIRECT_HEAPS DoubleIndirectHeaps

#define ARRAYS DoubleArrays

#define BIG_ARRAYS DoubleBigArrays

#define ITERATORS DoubleIterators

#define BIG_LIST_ITERATORS DoubleBigListIterators

#define COMPARATORS DoubleComparators

/* Static containers (values) */
#define VALUE_COLLECTIONS DoubleCollections

#define VALUE_SETS DoubleSets

#define VALUE_ARRAYS DoubleArrays

/* Implementations */
#define OPEN_HASH_SET DoubleOpenHashSet

#define OPEN_HASH_BIG_SET DoubleOpenHashBigSet

#define OPEN_DOUBLE_HASH_SET DoubleOpenDoubleHashSet

#define OPEN_HASH_MAP Double2DoubleOpenHashMap

#define OPEN_HASH_BIG_MAP Double2DoubleOpenHashBigMap

#define STRIPED_OPEN_HASH_MAP StripedDouble2DoubleOpenHashMap

#define OPEN_DOUBLE_HASH_MAP Double2DoubleOpenDoubleHashMap

#define ARRAY_SET DoubleArraySet

#define ARRAY_MAP Double2DoubleArrayMap

#define LINKED_OPEN_HASH_SET DoubleLinkedOpenHashSet

#define AVL_TREE_SET DoubleAVLTreeSet

#define RB_TREE_SET DoubleRBTreeSet

#define AVL_TREE_MAP Double2DoubleAVLTreeMap

#define RB_TREE_MAP Double2DoubleRBTreeMap

#define ARRAY_LIST DoubleArrayList

#define BIG_ARRAY_BIG_LIST DoubleBigArrayBigList

#define ARRAY_FRONT_CODED_LIST DoubleArrayFrontCodedList

#define HEAP_PRIORITY_QUEUE DoubleHeapPriorityQueue

#define HEAP_SEMI_INDIRECT_PRIORITY_QUEUE DoubleHeapSemiIndirectPriorityQueue

#define HEAP_INDIRECT_PRIORITY_QUEUE DoubleHeapIndirectPriorityQueue

#define HEAP_SESQUI_INDIRECT_DOUBLE_PRIORITY_QUEUE DoubleHeapSesquiIndirectDoublePriorityQueue

#define HEAP_INDIRECT_DOUBLE_PRIORITY_QUEUE DoubleHeapIndirectDoublePriorityQueue

#define ARRAY_FIFO_QUEUE DoubleArrayFIFOQueue

#define ARRAY_PRIORITY_QUEUE DoubleArrayPriorityQueue

#define ARRAY_INDIRECT_PRIORITY_QUEUE DoubleArrayIndirectPriorityQueue

#define ARRAY_INDIRECT_DOUBLE_PRIORITY_QUEUE DoubleArrayIndirectDoublePriorityQueue

/* Synchronized wrappers */
#define SYNCHRONIZED_COLLECTION SynchronizedDoubleCollection

#define SYNCHRONIZED_SET SynchronizedDoubleSet

#define SYNCHRONIZED_SORTED_SET SynchronizedDoubleSortedSet

#define SYNCHRONIZED_FUNCTION SynchronizedDouble2DoubleFunction

#define SYNCHRONIZED_MAP SynchronizedDouble2DoubleMap

#define SYNCHRONIZED_LIST SynchronizedDoubleList

/* Unmodifiable wrappers */
#define UNMODIFIABLE_COLLECTION UnmodifiableDoubleCollection

#define UNMODIFIABLE_SET UnmodifiableDoubleSet

#define UNMODIFIABLE_SORTED_SET UnmodifiableDoubleSortedSet

#define UNMODIFIABLE_FUNCTION UnmodifiableDouble2DoubleFunction

#define UNMODIFIABLE_MAP UnmodifiableDouble2DoubleMap

#define UNMODIFIABLE_LIST UnmodifiableDoubleList

#define UNMODIFIABLE_KEY_ITERATOR UnmodifiableDoubleIterator

#define UNMODIFIABLE_KEY_BIDI_ITERATOR UnmodifiableDoubleBidirectionalIterator

#define UNMODIFIABLE_KEY_LIST_ITERATOR UnmodifiableDoubleListIterator

/* Other wrappers */
#define KEY_READER_WRAPPER DoubleReaderWrapper

#define KEY_DATA_INPUT_WRAPPER DoubleDataInputWrapper

/* Methods (keys) */
#define NEXT_KEY nextDouble
#define PREV_KEY previousDouble
#define FIRST_KEY firstDoubleKey
#define LAST_KEY lastDoubleKey
#define GET_KEY getDouble
#define REMOVE_KEY removeDouble
#define READ_KEY readDouble
#define WRITE_KEY writeDouble
#define DEQUEUE dequeueDouble
#define DEQUEUE_LAST dequeueLastDouble
#define SUBLIST_METHOD doubleSubList
#define SINGLETON_METHOD doubleSingleton

#define FIRST firstDouble
#define LAST lastDouble
#define TOP topDouble
#define PEEK peekDouble
#define POP popDouble
#define KEY_ITERATOR_METHOD doubleIterator

#define KEY_LIST_ITERATOR_METHOD doubleListIterator

#define KEY_EMPTY_ITERATOR_METHOD emptyDoubleIterator

#define AS_KEY_ITERATOR asDoubleIterator

#define AS_KEY_ITERABLE asDoubleIterable

#define TO_KEY_ARRAY toDoubleArray
#define ENTRY_GET_KEY getDoubleKey
#define REMOVE_FIRST_KEY removeFirstDouble
#define REMOVE_LAST_KEY removeLastDouble
#define PARSE_KEY parseDouble
#define LOAD_KEYS loadDoubles
#define LOAD_KEYS_BIG loadDoublesBig
#define STORE_KEYS storeDoubles
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
#define ENTRYSET double2DoubleEntrySet
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
#include "drv/AbstractSortedMap.drv"

