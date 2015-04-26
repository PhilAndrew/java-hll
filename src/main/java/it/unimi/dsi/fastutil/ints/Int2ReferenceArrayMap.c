/* Generic definitions */


#define PACKAGE it.unimi.dsi.fastutil.ints
#define VALUE_PACKAGE it.unimi.dsi.fastutil.objects
/* Assertions (useful to generate conditional code) */
#unassert keyclass
#assert keyclass(Integer)
#unassert keys
 #assert keys(primitive)
#unassert valueclass
#assert valueclass(Reference)
#unassert values
 #assert values(reference)
/* Current type and class (and size, if applicable) */
#define KEY_TYPE int
#define VALUE_TYPE Object
#define KEY_CLASS Integer
#define VALUE_CLASS Reference
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
#define KEY_VALUE intValue
#define VALUE_VALUE ObjectValue
/* Interfaces (keys) */
#define COLLECTION IntCollection

#define SET IntSet

#define HASH IntHash

#define SORTED_SET IntSortedSet

#define STD_SORTED_SET IntSortedSet

#define FUNCTION Int2ReferenceFunction
#define MAP Int2ReferenceMap
#define SORTED_MAP Int2ReferenceSortedMap
#if #keyclass(Object) || #keyclass(Reference)
#define STD_SORTED_MAP SortedMap

#define STRATEGY Strategy

#else
#define STD_SORTED_MAP Int2ReferenceSortedMap

#define STRATEGY PACKAGE.IntHash.Strategy

#endif
#define LIST IntList

#define BIG_LIST IntBigList

#define STACK IntStack

#define PRIORITY_QUEUE IntPriorityQueue

#define INDIRECT_PRIORITY_QUEUE IntIndirectPriorityQueue

#define INDIRECT_DOUBLE_PRIORITY_QUEUE IntIndirectDoublePriorityQueue

#define KEY_ITERATOR IntIterator

#define KEY_ITERABLE IntIterable

#define KEY_BIDI_ITERATOR IntBidirectionalIterator

#define KEY_LIST_ITERATOR IntListIterator

#define KEY_BIG_LIST_ITERATOR IntBigListIterator

#define STD_KEY_ITERATOR IntIterator

#define KEY_COMPARATOR IntComparator

/* Interfaces (values) */
#define VALUE_COLLECTION ReferenceCollection

#define VALUE_ARRAY_SET ReferenceArraySet

#define VALUE_ITERATOR ObjectIterator

#define VALUE_LIST_ITERATOR ObjectListIterator

/* Abstract implementations (keys) */
#define ABSTRACT_COLLECTION AbstractIntCollection

#define ABSTRACT_SET AbstractIntSet

#define ABSTRACT_SORTED_SET AbstractIntSortedSet
#define ABSTRACT_FUNCTION AbstractInt2ReferenceFunction
#define ABSTRACT_MAP AbstractInt2ReferenceMap
#define ABSTRACT_FUNCTION AbstractInt2ReferenceFunction
#define ABSTRACT_SORTED_MAP AbstractInt2ReferenceSortedMap
#define ABSTRACT_LIST AbstractIntList

#define ABSTRACT_BIG_LIST AbstractIntBigList

#define SUBLIST IntSubList

#define ABSTRACT_PRIORITY_QUEUE AbstractIntPriorityQueue

#define ABSTRACT_STACK AbstractIntStack

#define KEY_ABSTRACT_ITERATOR AbstractIntIterator

#define KEY_ABSTRACT_BIDI_ITERATOR AbstractIntBidirectionalIterator

#define KEY_ABSTRACT_LIST_ITERATOR AbstractIntListIterator

#define KEY_ABSTRACT_BIG_LIST_ITERATOR AbstractIntBigListIterator

#if #keyclass(Object)
#define KEY_ABSTRACT_COMPARATOR Comparator

#else
#define KEY_ABSTRACT_COMPARATOR AbstractIntComparator

#endif
/* Abstract implementations (values) */
#define VALUE_ABSTRACT_COLLECTION AbstractReferenceCollection

#define VALUE_ABSTRACT_ITERATOR AbstractObjectIterator

#define VALUE_ABSTRACT_BIDI_ITERATOR AbstractObjectBidirectionalIterator

/* Static containers (keys) */
#define COLLECTIONS IntCollections

#define SETS IntSets

#define SORTED_SETS IntSortedSets

#define LISTS IntLists

#define BIG_LISTS IntBigLists

#define MAPS Int2ReferenceMaps
#define FUNCTIONS Int2ReferenceFunctions
#define SORTED_MAPS Int2ReferenceSortedMaps
#define PRIORITY_QUEUES IntPriorityQueues

#define HEAPS IntHeaps

#define SEMI_INDIRECT_HEAPS IntSemiIndirectHeaps

#define INDIRECT_HEAPS IntIndirectHeaps

#define ARRAYS IntArrays

#define BIG_ARRAYS IntBigArrays

#define ITERATORS IntIterators

#define BIG_LIST_ITERATORS IntBigListIterators

#define COMPARATORS IntComparators

/* Static containers (values) */
#define VALUE_COLLECTIONS ReferenceCollections

#define VALUE_SETS ReferenceSets

#define VALUE_ARRAYS ObjectArrays

/* Implementations */
#define OPEN_HASH_SET IntOpenHashSet

#define OPEN_HASH_BIG_SET IntOpenHashBigSet

#define OPEN_DOUBLE_HASH_SET IntOpenDoubleHashSet

#define OPEN_HASH_MAP Int2ReferenceOpenHashMap

#define OPEN_HASH_BIG_MAP Int2ReferenceOpenHashBigMap

#define STRIPED_OPEN_HASH_MAP StripedInt2ReferenceOpenHashMap

#define OPEN_DOUBLE_HASH_MAP Int2ReferenceOpenDoubleHashMap

#define ARRAY_SET IntArraySet

#define ARRAY_MAP Int2ReferenceArrayMap

#define LINKED_OPEN_HASH_SET IntLinkedOpenHashSet

#define AVL_TREE_SET IntAVLTreeSet

#define RB_TREE_SET IntRBTreeSet

#define AVL_TREE_MAP Int2ReferenceAVLTreeMap

#define RB_TREE_MAP Int2ReferenceRBTreeMap

#define ARRAY_LIST IntArrayList

#define BIG_ARRAY_BIG_LIST IntBigArrayBigList

#define ARRAY_FRONT_CODED_LIST IntArrayFrontCodedList

#define HEAP_PRIORITY_QUEUE IntHeapPriorityQueue

#define HEAP_SEMI_INDIRECT_PRIORITY_QUEUE IntHeapSemiIndirectPriorityQueue

#define HEAP_INDIRECT_PRIORITY_QUEUE IntHeapIndirectPriorityQueue

#define HEAP_SESQUI_INDIRECT_DOUBLE_PRIORITY_QUEUE IntHeapSesquiIndirectDoublePriorityQueue

#define HEAP_INDIRECT_DOUBLE_PRIORITY_QUEUE IntHeapIndirectDoublePriorityQueue

#define ARRAY_FIFO_QUEUE IntArrayFIFOQueue

#define ARRAY_PRIORITY_QUEUE IntArrayPriorityQueue

#define ARRAY_INDIRECT_PRIORITY_QUEUE IntArrayIndirectPriorityQueue

#define ARRAY_INDIRECT_DOUBLE_PRIORITY_QUEUE IntArrayIndirectDoublePriorityQueue

/* Synchronized wrappers */
#define SYNCHRONIZED_COLLECTION SynchronizedIntCollection

#define SYNCHRONIZED_SET SynchronizedIntSet

#define SYNCHRONIZED_SORTED_SET SynchronizedIntSortedSet

#define SYNCHRONIZED_FUNCTION SynchronizedInt2ReferenceFunction

#define SYNCHRONIZED_MAP SynchronizedInt2ReferenceMap

#define SYNCHRONIZED_LIST SynchronizedIntList

/* Unmodifiable wrappers */
#define UNMODIFIABLE_COLLECTION UnmodifiableIntCollection

#define UNMODIFIABLE_SET UnmodifiableIntSet

#define UNMODIFIABLE_SORTED_SET UnmodifiableIntSortedSet

#define UNMODIFIABLE_FUNCTION UnmodifiableInt2ReferenceFunction

#define UNMODIFIABLE_MAP UnmodifiableInt2ReferenceMap

#define UNMODIFIABLE_LIST UnmodifiableIntList

#define UNMODIFIABLE_KEY_ITERATOR UnmodifiableIntIterator

#define UNMODIFIABLE_KEY_BIDI_ITERATOR UnmodifiableIntBidirectionalIterator

#define UNMODIFIABLE_KEY_LIST_ITERATOR UnmodifiableIntListIterator

/* Other wrappers */
#define KEY_READER_WRAPPER IntReaderWrapper

#define KEY_DATA_INPUT_WRAPPER IntDataInputWrapper

/* Methods (keys) */
#define NEXT_KEY nextInt
#define PREV_KEY previousInt
#define FIRST_KEY firstIntKey
#define LAST_KEY lastIntKey
#define GET_KEY getInt
#define REMOVE_KEY removeInt
#define READ_KEY readInt
#define WRITE_KEY writeInt
#define DEQUEUE dequeueInt
#define DEQUEUE_LAST dequeueLastInt
#define SUBLIST_METHOD intSubList
#define SINGLETON_METHOD intSingleton

#define FIRST firstInt
#define LAST lastInt
#define TOP topInt
#define PEEK peekInt
#define POP popInt
#define KEY_ITERATOR_METHOD intIterator

#define KEY_LIST_ITERATOR_METHOD intListIterator

#define KEY_EMPTY_ITERATOR_METHOD emptyIntIterator

#define AS_KEY_ITERATOR asIntIterator

#define AS_KEY_ITERABLE asIntIterable

#define TO_KEY_ARRAY toIntArray
#define ENTRY_GET_KEY getIntKey
#define REMOVE_FIRST_KEY removeFirstInt
#define REMOVE_LAST_KEY removeLastInt
#define PARSE_KEY parseInt
#define LOAD_KEYS loadInts
#define LOAD_KEYS_BIG loadIntsBig
#define STORE_KEYS storeInts
/* Methods (values) */
#define NEXT_VALUE next
#define PREV_VALUE previous
#define READ_VALUE readObject
#define WRITE_VALUE writeObject
#define VALUE_ITERATOR_METHOD objectIterator

#define ENTRY_GET_VALUE getValue
#define REMOVE_FIRST_VALUE removeFirst
#define REMOVE_LAST_VALUE removeLast
/* Methods (keys/values) */
#define ENTRYSET int2ReferenceEntrySet
/* Methods that have special names depending on keys (but the special names depend on values) */
#if #keyclass(Object) || #keyclass(Reference)
#define GET_VALUE get
#define REMOVE_VALUE remove
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
#define VALUE2JAVAHASH(x) it.unimi.dsi.fastutil.HashCommon.Object2int(x)
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

