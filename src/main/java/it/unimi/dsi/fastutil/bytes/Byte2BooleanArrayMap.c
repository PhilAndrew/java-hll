/* Generic definitions */


#define PACKAGE it.unimi.dsi.fastutil.bytes
#define VALUE_PACKAGE it.unimi.dsi.fastutil.booleans
/* Assertions (useful to generate conditional code) */
#unassert keyclass
#assert keyclass(Byte)
#unassert keys
 #assert keys(primitive)
#unassert valueclass
#assert valueclass(Boolean)
#unassert values
 #assert values(primitive)
/* Current type and class (and size, if applicable) */
#define KEY_TYPE byte
#define VALUE_TYPE boolean
#define KEY_CLASS Byte
#define VALUE_CLASS Boolean
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
#define KEY_VALUE byteValue
#define VALUE_VALUE booleanValue
/* Interfaces (keys) */
#define COLLECTION ByteCollection

#define SET ByteSet

#define HASH ByteHash

#define SORTED_SET ByteSortedSet

#define STD_SORTED_SET ByteSortedSet

#define FUNCTION Byte2BooleanFunction
#define MAP Byte2BooleanMap
#define SORTED_MAP Byte2BooleanSortedMap
#if #keyclass(Object) || #keyclass(Reference)
#define STD_SORTED_MAP SortedMap

#define STRATEGY Strategy

#else
#define STD_SORTED_MAP Byte2BooleanSortedMap

#define STRATEGY PACKAGE.ByteHash.Strategy

#endif
#define LIST ByteList

#define BIG_LIST ByteBigList

#define STACK ByteStack

#define PRIORITY_QUEUE BytePriorityQueue

#define INDIRECT_PRIORITY_QUEUE ByteIndirectPriorityQueue

#define INDIRECT_DOUBLE_PRIORITY_QUEUE ByteIndirectDoublePriorityQueue

#define KEY_ITERATOR ByteIterator

#define KEY_ITERABLE ByteIterable

#define KEY_BIDI_ITERATOR ByteBidirectionalIterator

#define KEY_LIST_ITERATOR ByteListIterator

#define KEY_BIG_LIST_ITERATOR ByteBigListIterator

#define STD_KEY_ITERATOR ByteIterator

#define KEY_COMPARATOR ByteComparator

/* Interfaces (values) */
#define VALUE_COLLECTION BooleanCollection

#define VALUE_ARRAY_SET BooleanArraySet

#define VALUE_ITERATOR BooleanIterator

#define VALUE_LIST_ITERATOR BooleanListIterator

/* Abstract implementations (keys) */
#define ABSTRACT_COLLECTION AbstractByteCollection

#define ABSTRACT_SET AbstractByteSet

#define ABSTRACT_SORTED_SET AbstractByteSortedSet
#define ABSTRACT_FUNCTION AbstractByte2BooleanFunction
#define ABSTRACT_MAP AbstractByte2BooleanMap
#define ABSTRACT_FUNCTION AbstractByte2BooleanFunction
#define ABSTRACT_SORTED_MAP AbstractByte2BooleanSortedMap
#define ABSTRACT_LIST AbstractByteList

#define ABSTRACT_BIG_LIST AbstractByteBigList

#define SUBLIST ByteSubList

#define ABSTRACT_PRIORITY_QUEUE AbstractBytePriorityQueue

#define ABSTRACT_STACK AbstractByteStack

#define KEY_ABSTRACT_ITERATOR AbstractByteIterator

#define KEY_ABSTRACT_BIDI_ITERATOR AbstractByteBidirectionalIterator

#define KEY_ABSTRACT_LIST_ITERATOR AbstractByteListIterator

#define KEY_ABSTRACT_BIG_LIST_ITERATOR AbstractByteBigListIterator

#if #keyclass(Object)
#define KEY_ABSTRACT_COMPARATOR Comparator

#else
#define KEY_ABSTRACT_COMPARATOR AbstractByteComparator

#endif
/* Abstract implementations (values) */
#define VALUE_ABSTRACT_COLLECTION AbstractBooleanCollection

#define VALUE_ABSTRACT_ITERATOR AbstractBooleanIterator

#define VALUE_ABSTRACT_BIDI_ITERATOR AbstractBooleanBidirectionalIterator

/* Static containers (keys) */
#define COLLECTIONS ByteCollections

#define SETS ByteSets

#define SORTED_SETS ByteSortedSets

#define LISTS ByteLists

#define BIG_LISTS ByteBigLists

#define MAPS Byte2BooleanMaps
#define FUNCTIONS Byte2BooleanFunctions
#define SORTED_MAPS Byte2BooleanSortedMaps
#define PRIORITY_QUEUES BytePriorityQueues

#define HEAPS ByteHeaps

#define SEMI_INDIRECT_HEAPS ByteSemiIndirectHeaps

#define INDIRECT_HEAPS ByteIndirectHeaps

#define ARRAYS ByteArrays

#define BIG_ARRAYS ByteBigArrays

#define ITERATORS ByteIterators

#define BIG_LIST_ITERATORS ByteBigListIterators

#define COMPARATORS ByteComparators

/* Static containers (values) */
#define VALUE_COLLECTIONS BooleanCollections

#define VALUE_SETS BooleanSets

#define VALUE_ARRAYS BooleanArrays

/* Implementations */
#define OPEN_HASH_SET ByteOpenHashSet

#define OPEN_HASH_BIG_SET ByteOpenHashBigSet

#define OPEN_DOUBLE_HASH_SET ByteOpenDoubleHashSet

#define OPEN_HASH_MAP Byte2BooleanOpenHashMap

#define OPEN_HASH_BIG_MAP Byte2BooleanOpenHashBigMap

#define STRIPED_OPEN_HASH_MAP StripedByte2BooleanOpenHashMap

#define OPEN_DOUBLE_HASH_MAP Byte2BooleanOpenDoubleHashMap

#define ARRAY_SET ByteArraySet

#define ARRAY_MAP Byte2BooleanArrayMap

#define LINKED_OPEN_HASH_SET ByteLinkedOpenHashSet

#define AVL_TREE_SET ByteAVLTreeSet

#define RB_TREE_SET ByteRBTreeSet

#define AVL_TREE_MAP Byte2BooleanAVLTreeMap

#define RB_TREE_MAP Byte2BooleanRBTreeMap

#define ARRAY_LIST ByteArrayList

#define BIG_ARRAY_BIG_LIST ByteBigArrayBigList

#define ARRAY_FRONT_CODED_LIST ByteArrayFrontCodedList

#define HEAP_PRIORITY_QUEUE ByteHeapPriorityQueue

#define HEAP_SEMI_INDIRECT_PRIORITY_QUEUE ByteHeapSemiIndirectPriorityQueue

#define HEAP_INDIRECT_PRIORITY_QUEUE ByteHeapIndirectPriorityQueue

#define HEAP_SESQUI_INDIRECT_DOUBLE_PRIORITY_QUEUE ByteHeapSesquiIndirectDoublePriorityQueue

#define HEAP_INDIRECT_DOUBLE_PRIORITY_QUEUE ByteHeapIndirectDoublePriorityQueue

#define ARRAY_FIFO_QUEUE ByteArrayFIFOQueue

#define ARRAY_PRIORITY_QUEUE ByteArrayPriorityQueue

#define ARRAY_INDIRECT_PRIORITY_QUEUE ByteArrayIndirectPriorityQueue

#define ARRAY_INDIRECT_DOUBLE_PRIORITY_QUEUE ByteArrayIndirectDoublePriorityQueue

/* Synchronized wrappers */
#define SYNCHRONIZED_COLLECTION SynchronizedByteCollection

#define SYNCHRONIZED_SET SynchronizedByteSet

#define SYNCHRONIZED_SORTED_SET SynchronizedByteSortedSet

#define SYNCHRONIZED_FUNCTION SynchronizedByte2BooleanFunction

#define SYNCHRONIZED_MAP SynchronizedByte2BooleanMap

#define SYNCHRONIZED_LIST SynchronizedByteList

/* Unmodifiable wrappers */
#define UNMODIFIABLE_COLLECTION UnmodifiableByteCollection

#define UNMODIFIABLE_SET UnmodifiableByteSet

#define UNMODIFIABLE_SORTED_SET UnmodifiableByteSortedSet

#define UNMODIFIABLE_FUNCTION UnmodifiableByte2BooleanFunction

#define UNMODIFIABLE_MAP UnmodifiableByte2BooleanMap

#define UNMODIFIABLE_LIST UnmodifiableByteList

#define UNMODIFIABLE_KEY_ITERATOR UnmodifiableByteIterator

#define UNMODIFIABLE_KEY_BIDI_ITERATOR UnmodifiableByteBidirectionalIterator

#define UNMODIFIABLE_KEY_LIST_ITERATOR UnmodifiableByteListIterator

/* Other wrappers */
#define KEY_READER_WRAPPER ByteReaderWrapper

#define KEY_DATA_INPUT_WRAPPER ByteDataInputWrapper

/* Methods (keys) */
#define NEXT_KEY nextByte
#define PREV_KEY previousByte
#define FIRST_KEY firstByteKey
#define LAST_KEY lastByteKey
#define GET_KEY getByte
#define REMOVE_KEY removeByte
#define READ_KEY readByte
#define WRITE_KEY writeByte
#define DEQUEUE dequeueByte
#define DEQUEUE_LAST dequeueLastByte
#define SUBLIST_METHOD byteSubList
#define SINGLETON_METHOD byteSingleton

#define FIRST firstByte
#define LAST lastByte
#define TOP topByte
#define PEEK peekByte
#define POP popByte
#define KEY_ITERATOR_METHOD byteIterator

#define KEY_LIST_ITERATOR_METHOD byteListIterator

#define KEY_EMPTY_ITERATOR_METHOD emptyByteIterator

#define AS_KEY_ITERATOR asByteIterator

#define AS_KEY_ITERABLE asByteIterable

#define TO_KEY_ARRAY toByteArray
#define ENTRY_GET_KEY getByteKey
#define REMOVE_FIRST_KEY removeFirstByte
#define REMOVE_LAST_KEY removeLastByte
#define PARSE_KEY parseByte
#define LOAD_KEYS loadBytes
#define LOAD_KEYS_BIG loadBytesBig
#define STORE_KEYS storeBytes
/* Methods (values) */
#define NEXT_VALUE nextBoolean
#define PREV_VALUE previousBoolean
#define READ_VALUE readBoolean
#define WRITE_VALUE writeBoolean
#define VALUE_ITERATOR_METHOD booleanIterator

#define ENTRY_GET_VALUE getBooleanValue
#define REMOVE_FIRST_VALUE removeFirstBoolean
#define REMOVE_LAST_VALUE removeLastBoolean
/* Methods (keys/values) */
#define ENTRYSET byte2BooleanEntrySet
/* Methods that have special names depending on keys (but the special names depend on values) */
#if #keyclass(Object) || #keyclass(Reference)
#define GET_VALUE getBoolean
#define REMOVE_VALUE removeBoolean
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
#define VALUE2JAVAHASH(x) it.unimi.dsi.fastutil.HashCommon.boolean2int(x)
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
#include "drv/ArrayMap.drv"

