/* Generic definitions */


#define PACKAGE it.unimi.dsi.fastutil.floats
#define VALUE_PACKAGE it.unimi.dsi.fastutil.objects
/* Assertions (useful to generate conditional code) */
#unassert keyclass
#assert keyclass(Float)
#unassert keys
 #assert keys(primitive)
#unassert valueclass
#assert valueclass(Reference)
#unassert values
 #assert values(reference)
/* Current type and class (and size, if applicable) */
#define KEY_TYPE float
#define VALUE_TYPE Object
#define KEY_CLASS Float
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
#define KEY_VALUE floatValue
#define VALUE_VALUE ObjectValue
/* Interfaces (keys) */
#define COLLECTION FloatCollection

#define SET FloatSet

#define HASH FloatHash

#define SORTED_SET FloatSortedSet

#define STD_SORTED_SET FloatSortedSet

#define FUNCTION Float2ReferenceFunction
#define MAP Float2ReferenceMap
#define SORTED_MAP Float2ReferenceSortedMap
#if #keyclass(Object) || #keyclass(Reference)
#define STD_SORTED_MAP SortedMap

#define STRATEGY Strategy

#else
#define STD_SORTED_MAP Float2ReferenceSortedMap

#define STRATEGY PACKAGE.FloatHash.Strategy

#endif
#define LIST FloatList

#define BIG_LIST FloatBigList

#define STACK FloatStack

#define PRIORITY_QUEUE FloatPriorityQueue

#define INDIRECT_PRIORITY_QUEUE FloatIndirectPriorityQueue

#define INDIRECT_DOUBLE_PRIORITY_QUEUE FloatIndirectDoublePriorityQueue

#define KEY_ITERATOR FloatIterator

#define KEY_ITERABLE FloatIterable

#define KEY_BIDI_ITERATOR FloatBidirectionalIterator

#define KEY_LIST_ITERATOR FloatListIterator

#define KEY_BIG_LIST_ITERATOR FloatBigListIterator

#define STD_KEY_ITERATOR FloatIterator

#define KEY_COMPARATOR FloatComparator

/* Interfaces (values) */
#define VALUE_COLLECTION ReferenceCollection

#define VALUE_ARRAY_SET ReferenceArraySet

#define VALUE_ITERATOR ObjectIterator

#define VALUE_LIST_ITERATOR ObjectListIterator

/* Abstract implementations (keys) */
#define ABSTRACT_COLLECTION AbstractFloatCollection

#define ABSTRACT_SET AbstractFloatSet

#define ABSTRACT_SORTED_SET AbstractFloatSortedSet
#define ABSTRACT_FUNCTION AbstractFloat2ReferenceFunction
#define ABSTRACT_MAP AbstractFloat2ReferenceMap
#define ABSTRACT_FUNCTION AbstractFloat2ReferenceFunction
#define ABSTRACT_SORTED_MAP AbstractFloat2ReferenceSortedMap
#define ABSTRACT_LIST AbstractFloatList

#define ABSTRACT_BIG_LIST AbstractFloatBigList

#define SUBLIST FloatSubList

#define ABSTRACT_PRIORITY_QUEUE AbstractFloatPriorityQueue

#define ABSTRACT_STACK AbstractFloatStack

#define KEY_ABSTRACT_ITERATOR AbstractFloatIterator

#define KEY_ABSTRACT_BIDI_ITERATOR AbstractFloatBidirectionalIterator

#define KEY_ABSTRACT_LIST_ITERATOR AbstractFloatListIterator

#define KEY_ABSTRACT_BIG_LIST_ITERATOR AbstractFloatBigListIterator

#if #keyclass(Object)
#define KEY_ABSTRACT_COMPARATOR Comparator

#else
#define KEY_ABSTRACT_COMPARATOR AbstractFloatComparator

#endif
/* Abstract implementations (values) */
#define VALUE_ABSTRACT_COLLECTION AbstractReferenceCollection

#define VALUE_ABSTRACT_ITERATOR AbstractObjectIterator

#define VALUE_ABSTRACT_BIDI_ITERATOR AbstractObjectBidirectionalIterator

/* Static containers (keys) */
#define COLLECTIONS FloatCollections

#define SETS FloatSets

#define SORTED_SETS FloatSortedSets

#define LISTS FloatLists

#define BIG_LISTS FloatBigLists

#define MAPS Float2ReferenceMaps
#define FUNCTIONS Float2ReferenceFunctions
#define SORTED_MAPS Float2ReferenceSortedMaps
#define PRIORITY_QUEUES FloatPriorityQueues

#define HEAPS FloatHeaps

#define SEMI_INDIRECT_HEAPS FloatSemiIndirectHeaps

#define INDIRECT_HEAPS FloatIndirectHeaps

#define ARRAYS FloatArrays

#define BIG_ARRAYS FloatBigArrays

#define ITERATORS FloatIterators

#define BIG_LIST_ITERATORS FloatBigListIterators

#define COMPARATORS FloatComparators

/* Static containers (values) */
#define VALUE_COLLECTIONS ReferenceCollections

#define VALUE_SETS ReferenceSets

#define VALUE_ARRAYS ObjectArrays

/* Implementations */
#define OPEN_HASH_SET FloatOpenHashSet

#define OPEN_HASH_BIG_SET FloatOpenHashBigSet

#define OPEN_DOUBLE_HASH_SET FloatOpenDoubleHashSet

#define OPEN_HASH_MAP Float2ReferenceOpenHashMap

#define OPEN_HASH_BIG_MAP Float2ReferenceOpenHashBigMap

#define STRIPED_OPEN_HASH_MAP StripedFloat2ReferenceOpenHashMap

#define OPEN_DOUBLE_HASH_MAP Float2ReferenceOpenDoubleHashMap

#define ARRAY_SET FloatArraySet

#define ARRAY_MAP Float2ReferenceArrayMap

#define LINKED_OPEN_HASH_SET FloatLinkedOpenHashSet

#define AVL_TREE_SET FloatAVLTreeSet

#define RB_TREE_SET FloatRBTreeSet

#define AVL_TREE_MAP Float2ReferenceAVLTreeMap

#define RB_TREE_MAP Float2ReferenceRBTreeMap

#define ARRAY_LIST FloatArrayList

#define BIG_ARRAY_BIG_LIST FloatBigArrayBigList

#define ARRAY_FRONT_CODED_LIST FloatArrayFrontCodedList

#define HEAP_PRIORITY_QUEUE FloatHeapPriorityQueue

#define HEAP_SEMI_INDIRECT_PRIORITY_QUEUE FloatHeapSemiIndirectPriorityQueue

#define HEAP_INDIRECT_PRIORITY_QUEUE FloatHeapIndirectPriorityQueue

#define HEAP_SESQUI_INDIRECT_DOUBLE_PRIORITY_QUEUE FloatHeapSesquiIndirectDoublePriorityQueue

#define HEAP_INDIRECT_DOUBLE_PRIORITY_QUEUE FloatHeapIndirectDoublePriorityQueue

#define ARRAY_FIFO_QUEUE FloatArrayFIFOQueue

#define ARRAY_PRIORITY_QUEUE FloatArrayPriorityQueue

#define ARRAY_INDIRECT_PRIORITY_QUEUE FloatArrayIndirectPriorityQueue

#define ARRAY_INDIRECT_DOUBLE_PRIORITY_QUEUE FloatArrayIndirectDoublePriorityQueue

/* Synchronized wrappers */
#define SYNCHRONIZED_COLLECTION SynchronizedFloatCollection

#define SYNCHRONIZED_SET SynchronizedFloatSet

#define SYNCHRONIZED_SORTED_SET SynchronizedFloatSortedSet

#define SYNCHRONIZED_FUNCTION SynchronizedFloat2ReferenceFunction

#define SYNCHRONIZED_MAP SynchronizedFloat2ReferenceMap

#define SYNCHRONIZED_LIST SynchronizedFloatList

/* Unmodifiable wrappers */
#define UNMODIFIABLE_COLLECTION UnmodifiableFloatCollection

#define UNMODIFIABLE_SET UnmodifiableFloatSet

#define UNMODIFIABLE_SORTED_SET UnmodifiableFloatSortedSet

#define UNMODIFIABLE_FUNCTION UnmodifiableFloat2ReferenceFunction

#define UNMODIFIABLE_MAP UnmodifiableFloat2ReferenceMap

#define UNMODIFIABLE_LIST UnmodifiableFloatList

#define UNMODIFIABLE_KEY_ITERATOR UnmodifiableFloatIterator

#define UNMODIFIABLE_KEY_BIDI_ITERATOR UnmodifiableFloatBidirectionalIterator

#define UNMODIFIABLE_KEY_LIST_ITERATOR UnmodifiableFloatListIterator

/* Other wrappers */
#define KEY_READER_WRAPPER FloatReaderWrapper

#define KEY_DATA_INPUT_WRAPPER FloatDataInputWrapper

/* Methods (keys) */
#define NEXT_KEY nextFloat
#define PREV_KEY previousFloat
#define FIRST_KEY firstFloatKey
#define LAST_KEY lastFloatKey
#define GET_KEY getFloat
#define REMOVE_KEY removeFloat
#define READ_KEY readFloat
#define WRITE_KEY writeFloat
#define DEQUEUE dequeueFloat
#define DEQUEUE_LAST dequeueLastFloat
#define SUBLIST_METHOD floatSubList
#define SINGLETON_METHOD floatSingleton

#define FIRST firstFloat
#define LAST lastFloat
#define TOP topFloat
#define PEEK peekFloat
#define POP popFloat
#define KEY_ITERATOR_METHOD floatIterator

#define KEY_LIST_ITERATOR_METHOD floatListIterator

#define KEY_EMPTY_ITERATOR_METHOD emptyFloatIterator

#define AS_KEY_ITERATOR asFloatIterator

#define AS_KEY_ITERABLE asFloatIterable

#define TO_KEY_ARRAY toFloatArray
#define ENTRY_GET_KEY getFloatKey
#define REMOVE_FIRST_KEY removeFirstFloat
#define REMOVE_LAST_KEY removeLastFloat
#define PARSE_KEY parseFloat
#define LOAD_KEYS loadFloats
#define LOAD_KEYS_BIG loadFloatsBig
#define STORE_KEYS storeFloats
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
#define ENTRYSET float2ReferenceEntrySet
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
#include "drv/Map.drv"

