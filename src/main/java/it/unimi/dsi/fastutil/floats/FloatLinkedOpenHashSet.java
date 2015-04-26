/* Generic definitions */
/* Assertions (useful to generate conditional code) */
/* Current type and class (and size, if applicable) */
/* Value methods */
/* Interfaces (keys) */
/* Interfaces (values) */
/* Abstract implementations (keys) */
/* Abstract implementations (values) */
/* Static containers (keys) */
/* Static containers (values) */
/* Implementations */
/* Synchronized wrappers */
/* Unmodifiable wrappers */
/* Other wrappers */
/* Methods (keys) */
/* Methods (values) */
/* Methods (keys/values) */
/* Methods that have special names depending on keys (but the special names depend on values) */
/* Equality */
/* Object/Reference-only definitions (keys) */
/* Primitive-type-only definitions (keys) */
/* Object/Reference-only definitions (values) */
/*		 
 * Copyright (C) 2002-2014 Sebastiano Vigna 
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. 
 */
package it.unimi.dsi.fastutil.floats;
import it.unimi.dsi.fastutil.Hash;
import it.unimi.dsi.fastutil.HashCommon;
import static it.unimi.dsi.fastutil.HashCommon.arraySize;
import static it.unimi.dsi.fastutil.HashCommon.maxFill;
import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.NoSuchElementException;
/**  A type-specific linked hash set with with a fast, small-footprint implementation.
 *
 * <P>Instances of this class use a hash table to represent a set. The table is
 * filled up to a specified <em>load factor</em>, and then doubled in size to
 * accommodate new entries. If the table is emptied below <em>one fourth</em>
 * of the load factor, it is halved in size. However, halving is
 * not performed when deleting entries from an iterator, as it would interfere
 * with the iteration process.
 *
 * <p>Note that {@link #clear()} does not modify the hash table size. 
 * Rather, a family of {@linkplain #trim() trimming
 * methods} lets you control the size of the table; this is particularly useful
 * if you reuse instances of this class.
 *
 * <P>Iterators generated by this set will enumerate elements in the same order in which they
 * have been added to the set (addition of elements already present 
 * in the set does not change the iteration order). Note that this order has nothing in common with the natural
 * order of the keys. The order is kept by means of a doubly linked list, represented
 * <i>via</i> an array of longs parallel to the table.
 *
 * <P>This class implements the interface of a sorted set, so to allow easy
 * access of the iteration order: for instance, you can get the first element
 * in iteration order with {@link #first()} without having to create an
 * iterator; however, this class partially violates the {@link java.util.SortedSet}
 * contract because all subset methods throw an exception and {@link
 * #comparator()} returns always <code>null</code>.
 *
 * <p>Additional methods, such as <code>addAndMoveToFirst()</code>, make it easy
 * to use instances of this class as a cache (e.g., with LRU policy).
 *
 * <P>The iterators provided by this class are type-specific {@linkplain
 * java.util.ListIterator list iterators}, and can be started at any
 * element <em>which is in the set</em> (if the provided element 
 * is not in the set, a {@link NoSuchElementException} exception will be thrown).
 * If, however, the provided element is not the first or last element in the
 * set, the first access to the list index will require linear time, as in the worst case
 * the entire set must be scanned in iteration order to retrieve the positional
 * index of the starting element. If you use just the methods of a type-specific {@link it.unimi.dsi.fastutil.BidirectionalIterator},
 * however, all operations will be performed in constant time.
 *
 * @see Hash
 * @see HashCommon
 */
public class FloatLinkedOpenHashSet extends AbstractFloatSortedSet implements java.io.Serializable, Cloneable, Hash {
    private static final long serialVersionUID = 0L;
 private static final boolean ASSERTS = false;
 /** The array of keys. */
 protected transient float[] key;
 /** The mask for wrapping a position counter. */
 protected transient int mask;
 /** Whether this set contains the null key. */
 protected transient boolean containsNull;
 /** The index of the first entry in iteration order. It is valid iff {@link #size} is nonzero; otherwise, it contains -1. */
 protected transient int first = -1;
 /** The index of the last entry in iteration order. It is valid iff {@link #size} is nonzero; otherwise, it contains -1. */
 protected transient int last = -1;
 /** For each entry, the next and the previous entry in iteration order,
     * stored as <code>((prev & 0xFFFFFFFFL) << 32) | (next & 0xFFFFFFFFL)</code>.
     * The first entry contains predecessor -1, and the last entry 
     * contains successor -1. */
 protected transient long[] link;
 /** The current table size. */
 protected transient int n;
 /** Threshold after which we rehash. It must be the table size times {@link #f}. */
 protected transient int maxFill;
 /** Number of entries in the set (including the null key, if present). */
 protected int size;
 /** The acceptable load factor. */
 protected final float f;
 /** Creates a new hash set.
	 *
	 * <p>The actual table size will be the least power of two greater than <code>expected</code>/<code>f</code>.
	 *
	 * @param expected the expected number of elements in the hash set. 
	 * @param f the load factor.
	 */

 public FloatLinkedOpenHashSet( final int expected, final float f ) {
  if ( f <= 0 || f > 1 ) throw new IllegalArgumentException( "Load factor must be greater than 0 and smaller than or equal to 1" );
  if ( expected < 0 ) throw new IllegalArgumentException( "The expected number of elements must be nonnegative" );
  this.f = f;
  n = arraySize( expected, f );
  mask = n - 1;
  maxFill = maxFill( n, f );
  key = new float[ n + 1 ];
  link = new long[ n + 1 ];
 }
 /** Creates a new hash set with {@link Hash#DEFAULT_LOAD_FACTOR} as load factor.
	 *
	 * @param expected the expected number of elements in the hash set. 
	 */
 public FloatLinkedOpenHashSet( final int expected ) {
  this( expected, DEFAULT_LOAD_FACTOR );
 }
 /** Creates a new hash set with initial expected {@link Hash#DEFAULT_INITIAL_SIZE} elements
	 * and {@link Hash#DEFAULT_LOAD_FACTOR} as load factor.
	 */
 public FloatLinkedOpenHashSet() {
  this( DEFAULT_INITIAL_SIZE, DEFAULT_LOAD_FACTOR );
 }
 /** Creates a new hash set copying a given collection.
	 *
	 * @param c a {@link Collection} to be copied into the new hash set. 
	 * @param f the load factor.
	 */
 public FloatLinkedOpenHashSet( final Collection<? extends Float> c, final float f ) {
  this( c.size(), f );
  addAll( c );
 }
 /** Creates a new hash set  with {@link Hash#DEFAULT_LOAD_FACTOR} as load factor 
	 * copying a given collection.
	 *
	 * @param c a {@link Collection} to be copied into the new hash set. 
	 */
 public FloatLinkedOpenHashSet( final Collection<? extends Float> c ) {
  this( c, DEFAULT_LOAD_FACTOR );
 }
 /** Creates a new hash set copying a given type-specific collection.
	 *
	 * @param c a type-specific collection to be copied into the new hash set. 
	 * @param f the load factor.
	 */
 public FloatLinkedOpenHashSet( final FloatCollection c, final float f ) {
  this( c.size(), f );
  addAll( c );
 }
 /** Creates a new hash set  with {@link Hash#DEFAULT_LOAD_FACTOR} as load factor 
	 * copying a given type-specific collection.
	 *
	 * @param c a type-specific collection to be copied into the new hash set. 
	 */
 public FloatLinkedOpenHashSet( final FloatCollection c ) {
  this( c, DEFAULT_LOAD_FACTOR );
 }
 /** Creates a new hash set using elements provided by a type-specific iterator.
	 *
	 * @param i a type-specific iterator whose elements will fill the set.
	 * @param f the load factor.
	 */
 public FloatLinkedOpenHashSet( final FloatIterator i, final float f ) {
  this( DEFAULT_INITIAL_SIZE, f );
  while( i.hasNext() ) add( i.nextFloat() );
 }
 /** Creates a new hash set with {@link Hash#DEFAULT_LOAD_FACTOR} as load factor using elements provided by a type-specific iterator.
	 *
	 * @param i a type-specific iterator whose elements will fill the set.
	 */
 public FloatLinkedOpenHashSet( final FloatIterator i ) {
  this( i, DEFAULT_LOAD_FACTOR );
 }
 /** Creates a new hash set using elements provided by an iterator.
	 *
	 * @param i an iterator whose elements will fill the set.
	 * @param f the load factor.
	 */
 public FloatLinkedOpenHashSet( final Iterator<?> i, final float f ) {
  this( FloatIterators.asFloatIterator( i ), f );
 }
 /** Creates a new hash set with {@link Hash#DEFAULT_LOAD_FACTOR} as load factor using elements provided by an iterator.
	 *
	 * @param i an iterator whose elements will fill the set.
	 */
 public FloatLinkedOpenHashSet( final Iterator<?> i ) {
  this( FloatIterators.asFloatIterator( i ) );
 }
 /** Creates a new hash set and fills it with the elements of a given array.
	 *
	 * @param a an array whose elements will be used to fill the set.
	 * @param offset the first element to use.
	 * @param length the number of elements to use.
	 * @param f the load factor.
	 */
 public FloatLinkedOpenHashSet( final float[] a, final int offset, final int length, final float f ) {
  this( length < 0 ? 0 : length, f );
  FloatArrays.ensureOffsetLength( a, offset, length );
  for( int i = 0; i < length; i++ ) add( a[ offset + i ] );
 }
 /** Creates a new hash set with {@link Hash#DEFAULT_LOAD_FACTOR} as load factor and fills it with the elements of a given array.
	 *
	 * @param a an array whose elements will be used to fill the set.
	 * @param offset the first element to use.
	 * @param length the number of elements to use.
	 */
 public FloatLinkedOpenHashSet( final float[] a, final int offset, final int length ) {
  this( a, offset, length, DEFAULT_LOAD_FACTOR );
 }
 /** Creates a new hash set copying the elements of an array.
	 *
	 * @param a an array to be copied into the new hash set. 
	 * @param f the load factor.
	 */
 public FloatLinkedOpenHashSet( final float[] a, final float f ) {
  this( a, 0, a.length, f );
 }
 /** Creates a new hash set with {@link Hash#DEFAULT_LOAD_FACTOR} as load factor 
	 * copying the elements of an array.
	 *
	 * @param a an array to be copied into the new hash set. 
	 */
 public FloatLinkedOpenHashSet( final float[] a ) {
  this( a, DEFAULT_LOAD_FACTOR );
 }
 private int realSize() {
  return containsNull ? size - 1 : size;
 }
 private void ensureCapacity( final int capacity ) {
  final int needed = arraySize( capacity, f );
  if ( needed > n ) rehash( needed );
 }
 private void tryCapacity( final long capacity ) {
  final int needed = (int)Math.min( 1 << 30, Math.max( 2, HashCommon.nextPowerOfTwo( (long)Math.ceil( capacity / f ) ) ) );
  if ( needed > n ) rehash( needed );
 }
 /** {@inheritDoc} */
 public boolean addAll( FloatCollection c ) {
  if ( f <= .5 ) ensureCapacity( c.size() ); // The resulting collection will be sized for c.size() elements
  else tryCapacity( size() + c.size() ); // The resulting collection will be tentatively sized for size() + c.size() elements
  return super.addAll( c );
 }
 /** {@inheritDoc} */
 public boolean addAll( Collection<? extends Float> c ) {
  // The resulting collection will be at least c.size() big
  if ( f <= .5 ) ensureCapacity( c.size() ); // The resulting collection will be sized for c.size() elements
  else tryCapacity( size() + c.size() ); // The resulting collection will be tentatively sized for size() + c.size() elements
  return super.addAll( c );
 }
 public boolean add( final float k ) {
  int pos;
  if ( ( Float.floatToIntBits(k) == 0 ) ) {
   if ( containsNull ) return false;
   pos = n;
   containsNull = true;
  }
  else {
   float curr;
   final float[] key = this.key;
   // The starting point.
   if ( ! ( Float.floatToIntBits(curr = key[ pos = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(k) ) & mask ]) == 0 ) ) {
    if ( ( Float.floatToIntBits(curr) == Float.floatToIntBits(k) ) ) return false;
    while( ! ( Float.floatToIntBits(curr = key[ pos = ( pos + 1 ) & mask ]) == 0 ) )
     if ( ( Float.floatToIntBits(curr) == Float.floatToIntBits(k) ) ) return false;
   }
   key[ pos ] = k;
  }
  if ( size == 0 ) {
   first = last = pos;
   // Special case of SET_UPPER_LOWER(link[ pos ], -1, -1);
   link[ pos ] = -1L;
  }
  else {
   link[ last ] ^= ( ( link[ last ] ^ ( pos & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
   link[ pos ] = ( ( last & 0xFFFFFFFFL ) << 32 ) | ( -1 & 0xFFFFFFFFL );
   last = pos;
  }
  if ( size++ >= maxFill ) rehash( arraySize( size + 1, f ) );
  if ( ASSERTS ) checkTable();
  return true;
 }
 /** Shifts left entries with the specified hash code, starting at the specified position,
	 * and empties the resulting free entry.
	 *
	 * @param pos a starting position.
	 */
 protected final void shiftKeys( int pos ) {
  // Shift entries with the same hash.
  int last, slot;
  float curr;
  final float[] key = this.key;
  for(;;) {
   pos = ( ( last = pos ) + 1 ) & mask;
   for(;;) {
    if ( ( Float.floatToIntBits(curr = key[ pos ]) == 0 ) ) {
     key[ last ] = (0);
     return;
    }
    slot = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(curr) ) & mask;
    if ( last <= pos ? last >= slot || slot > pos : last >= slot && slot > pos ) break;
    pos = ( pos + 1 ) & mask;
   }
   key[ last ] = curr;
   fixPointers( pos, last );
  }
 }
 private boolean removeEntry( final int pos ) {
  size--;
  fixPointers( pos );
  shiftKeys( pos );
  if ( size < maxFill / 4 && n > DEFAULT_INITIAL_SIZE ) rehash( n / 2 );
  return true;
 }
 private boolean removeNullEntry() {
  containsNull = false;
  size--;
  fixPointers( n );
  if ( size < maxFill / 4 && n > DEFAULT_INITIAL_SIZE ) rehash( n / 2 );
  return true;
 }

 public boolean remove( final float k ) {
  if ( ( Float.floatToIntBits(k) == 0 ) ) {
   if ( containsNull ) return removeNullEntry();
   return false;
  }
  float curr;
  final float[] key = this.key;
  int pos;
  // The starting point.
  if ( ( Float.floatToIntBits(curr = key[ pos = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(k) ) & mask ]) == 0 ) ) return false;
  if ( ( Float.floatToIntBits(k) == Float.floatToIntBits(curr) ) ) return removeEntry( pos );
  while( true ) {
   if ( ( Float.floatToIntBits(curr = key[ pos = ( pos + 1 ) & mask ]) == 0 ) ) return false;
   if ( ( Float.floatToIntBits(k) == Float.floatToIntBits(curr) ) ) return removeEntry( pos );
  }
 }

 public boolean contains( final float k ) {
  if ( ( Float.floatToIntBits(k) == 0 ) ) return containsNull;
  float curr;
  final float[] key = this.key;
  int pos;
  // The starting point.
  if ( ( Float.floatToIntBits(curr = key[ pos = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(k) ) & mask ]) == 0 ) ) return false;
  if ( ( Float.floatToIntBits(k) == Float.floatToIntBits(curr) ) ) return true;
  while( true ) {
   if ( ( Float.floatToIntBits(curr = key[ pos = ( pos + 1 ) & mask ]) == 0 ) ) return false;
   if ( ( Float.floatToIntBits(k) == Float.floatToIntBits(curr) ) ) return true;
  }
 }
 /** Removes the first key in iteration order.
	 * @return the first key.
	 * @throws NoSuchElementException is this set is empty.
	 */
 public float removeFirstFloat() {
  if ( size == 0 ) throw new NoSuchElementException();
  final int pos = first;
  // Abbreviated version of fixPointers(pos)
  first = (int) link[ pos ];
  if ( 0 <= first ) {
   // Special case of SET_PREV( link[ first ], -1 )
   link[ first ] |= (-1 & 0xFFFFFFFFL) << 32;
  }
  final float k = key[ pos ];
  size--;
  if ( ( Float.floatToIntBits(k) == 0 ) ) containsNull = false;
  else shiftKeys( pos );
  if ( size < maxFill / 4 && n > DEFAULT_INITIAL_SIZE ) rehash( n / 2 );
  return k;
 }
 /** Removes the the last key in iteration order.
	 * @return the last key.
	 * @throws NoSuchElementException is this set is empty.
	 */
 public float removeLastFloat() {
  if ( size == 0 ) throw new NoSuchElementException();
  final int pos = last;
  // Abbreviated version of fixPointers(pos)
  last = (int) ( link[ pos ] >>> 32 );
  if ( 0 <= last ) {
   // Special case of SET_NEXT( link[ last ], -1 )
   link[ last ] |= -1 & 0xFFFFFFFFL;
  }
  final float k = key[ pos ];
  size--;
  if ( ( Float.floatToIntBits(k) == 0 ) ) containsNull = false;
  else shiftKeys( pos );
  if ( size < maxFill / 4 && n > DEFAULT_INITIAL_SIZE ) rehash( n / 2 );
  return k;
 }
 private void moveIndexToFirst( final int i ) {
  if ( size == 1 || first == i ) return;
  if ( last == i ) {
   last = (int) ( link[ i ] >>> 32 );
   // Special case of SET_NEXT( link[ last ], -1 );
   link[ last ] |= -1 & 0xFFFFFFFFL;
  }
  else {
   final long linki = link[ i ];
   final int prev = (int) ( linki >>> 32 );
   final int next = (int) linki;
   link[ prev ] ^= ( ( link[ prev ] ^ ( linki & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
   link[ next ] ^= ( ( link[ next ] ^ ( linki & 0xFFFFFFFF00000000L ) ) & 0xFFFFFFFF00000000L );
  }
  link[ first ] ^= ( ( link[ first ] ^ ( ( i & 0xFFFFFFFFL ) << 32 ) ) & 0xFFFFFFFF00000000L );
  link[ i ] = ( ( -1 & 0xFFFFFFFFL ) << 32 ) | ( first & 0xFFFFFFFFL );
  first = i;
 }
 private void moveIndexToLast( final int i ) {
  if ( size == 1 || last == i ) return;
  if ( first == i ) {
   first = (int) link[ i ];
   // Special case of SET_PREV( link[ first ], -1 );
   link[ first ] |= (-1 & 0xFFFFFFFFL) << 32;
  }
  else {
   final long linki = link[ i ];
   final int prev = (int) ( linki >>> 32 );
   final int next = (int) linki;
   link[ prev ] ^= ( ( link[ prev ] ^ ( linki & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
   link[ next ] ^= ( ( link[ next ] ^ ( linki & 0xFFFFFFFF00000000L ) ) & 0xFFFFFFFF00000000L );
  }
  link[ last ] ^= ( ( link[ last ] ^ ( i & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
  link[ i ] = ( ( last & 0xFFFFFFFFL ) << 32 ) | ( -1 & 0xFFFFFFFFL );
  last = i;
 }
 /** Adds a key to the set; if the key is already present, it is moved to the first position of the iteration order.
	 *
	 * @param k the key.
	 * @return true if the key was not present.
	 */
 public boolean addAndMoveToFirst( final float k ) {
  int pos;
  if ( ( Float.floatToIntBits(k) == 0 ) ) {
   if ( containsNull ) {
    moveIndexToFirst( n );
    return false;
   }
   containsNull = true;
   pos = n;
  }
  else {
   // The starting point.
   final float key[] = this.key;
   pos = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(k) ) & mask;
   // There's always an unused entry. TODO
   while( ! ( Float.floatToIntBits(key[ pos ]) == 0 ) ) {
    if ( ( Float.floatToIntBits(k) == Float.floatToIntBits(key[ pos ]) ) ) {
     moveIndexToFirst( pos );
     return false;
    }
    pos = ( pos + 1 ) & mask;
   }
   key[ pos ] = k;
  }
  if ( size == 0 ) {
   first = last = pos;
   // Special case of SET_UPPER_LOWER( link[ pos ], -1, -1 );
   link[ pos ] = -1L;
  }
  else {
   link[ first ] ^= ( ( link[ first ] ^ ( ( pos & 0xFFFFFFFFL ) << 32 ) ) & 0xFFFFFFFF00000000L );
   link[ pos ] = ( ( -1 & 0xFFFFFFFFL ) << 32 ) | ( first & 0xFFFFFFFFL );
   first = pos;
  }
  if ( size++ >= maxFill ) rehash( arraySize( size, f ) );
  if ( ASSERTS ) checkTable();
  return true;
 }
 /** Adds a key to the set; if the key is already present, it is moved to the last position of the iteration order.
	 *
	 * @param k the key.
	 * @return true if the key was not present.
	 */
 public boolean addAndMoveToLast( final float k ) {
  int pos;
  if ( ( Float.floatToIntBits(k) == 0 ) ) {
   if ( containsNull ) {
    moveIndexToLast( n );
    return false;
   }
   containsNull = true;
   pos = n;
  }
  else {
   // The starting point.
   final float key[] = this.key;
   pos = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(k) ) & mask;
   // There's always an unused entry.
   while( ! ( Float.floatToIntBits(key[ pos ]) == 0 ) ) {
    if ( ( Float.floatToIntBits(k) == Float.floatToIntBits(key[ pos ]) ) ) {
     moveIndexToLast( pos );
     return false;
    }
    pos = ( pos + 1 ) & mask;
   }
   key[ pos ] = k;
  }
  if ( size == 0 ) {
   first = last = pos;
   // Special case of SET_UPPER_LOWER( link[ pos ], -1, -1 );
   link[ pos ] = -1L;
  }
  else {
   link[ last ] ^= ( ( link[ last ] ^ ( pos & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
   link[ pos ] = ( ( last & 0xFFFFFFFFL ) << 32 ) | ( -1 & 0xFFFFFFFFL );
   last = pos;
  }
  if ( size++ >= maxFill ) rehash( arraySize( size, f ) );
  if ( ASSERTS ) checkTable();
  return true;
 }
 /* Removes all elements from this set.
	 *
	 * <P>To increase object reuse, this method does not change the table size.
	 * If you want to reduce the table size, you must use {@link #trim()}.
	 *
	 */
 public void clear() {
  if ( size == 0 ) return;
  size = 0;
  containsNull = false;
  Arrays.fill( key, (0) );
  first = last = -1;
 }
 public int size() {
  return size;
 }
 public boolean isEmpty() {
  return size == 0;
 }
 /** A no-op for backward compatibility.
	 * 
	 * @param growthFactor unused.
	 * @deprecated Since <code>fastutil</code> 6.1.0, hash tables are doubled when they are too full.
	 */
 @Deprecated
 public void growthFactor( int growthFactor ) {}
 /** Gets the growth factor (2).
	 *
	 * @return the growth factor of this set, which is fixed (2).
	 * @see #growthFactor(int)
	 * @deprecated Since <code>fastutil</code> 6.1.0, hash tables are doubled when they are too full.
	 */
 @Deprecated
 public int growthFactor() {
  return 16;
 }
 /** Modifies the {@link #link} vector so that the given entry is removed.
	 * This method will complete in constant time.
	 *
	 * @param i the index of an entry. 
	 */
 protected void fixPointers( final int i ) {
  if ( size == 0 ) {
   first = last = -1;
   return;
  }
  if ( first == i ) {
   first = (int) link[ i ];
   if (0 <= first) {
    // Special case of SET_PREV( link[ first ], -1 )
    link[ first ] |= (-1 & 0xFFFFFFFFL) << 32;
   }
   return;
  }
  if ( last == i ) {
   last = (int) ( link[ i ] >>> 32 );
   if (0 <= last) {
    // Special case of SET_NEXT( link[ last ], -1 )
    link[ last ] |= -1 & 0xFFFFFFFFL;
   }
   return;
  }
  final long linki = link[ i ];
  final int prev = (int) ( linki >>> 32 );
  final int next = (int) linki;
  link[ prev ] ^= ( ( link[ prev ] ^ ( linki & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
  link[ next ] ^= ( ( link[ next ] ^ ( linki & 0xFFFFFFFF00000000L ) ) & 0xFFFFFFFF00000000L );
 }
 /** Modifies the {@link #link} vector for a shift from s to d.
	 * This method will complete in constant time.
	 *
	 * @param s the source position.
	 * @param d the destination position.
	 */
 protected void fixPointers( int s, int d ) {
  if ( size == 1 ) {
   first = last = d;
   // Special case of SET(link[ d ], -1, -1)
   link[ d ] = -1L;
   return;
  }
  if ( first == s ) {
   first = d;
   link[ (int) link[ s ] ] ^= ( ( link[ (int) link[ s ] ] ^ ( ( d & 0xFFFFFFFFL ) << 32 ) ) & 0xFFFFFFFF00000000L );
   link[ d ] = link[ s ];
   return;
  }
  if ( last == s ) {
   last = d;
   link[ (int) ( link[ s ] >>> 32 )] ^= ( ( link[ (int) ( link[ s ] >>> 32 )] ^ ( d & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
   link[ d ] = link[ s ];
   return;
  }
  final long links = link[ s ];
  final int prev = (int) ( links >>> 32 );
  final int next = (int) links;
  link[ prev ] ^= ( ( link[ prev ] ^ ( d & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
  link[ next ] ^= ( ( link[ next ] ^ ( ( d & 0xFFFFFFFFL ) << 32 ) ) & 0xFFFFFFFF00000000L );
  link[ d ] = links;
 }
 /** Returns the first element of this set in iteration order.
	 *
	 * @return the first element in iteration order.
	 */
 public float firstFloat() {
  if ( size == 0 ) throw new NoSuchElementException();
  return key[ first ];
 }
 /** Returns the last element of this set in iteration order.
	 *
	 * @return the last element in iteration order.
	 */
 public float lastFloat() {
  if ( size == 0 ) throw new NoSuchElementException();
  return key[ last ];
 }
 public FloatSortedSet tailSet( float from ) { throw new UnsupportedOperationException(); }
 public FloatSortedSet headSet( float to ) { throw new UnsupportedOperationException(); }
 public FloatSortedSet subSet( float from, float to ) { throw new UnsupportedOperationException(); }
 public FloatComparator comparator() { return null; }
 /** A list iterator over a linked set.
	 *
	 * <P>This class provides a list iterator over a linked hash set. The constructor runs in constant time. 
	 */
 private class SetIterator extends AbstractFloatListIterator {
  /** The entry that will be returned by the next call to {@link java.util.ListIterator#previous()} (or <code>null</code> if no previous entry exists). */
  int prev = -1;
  /** The entry that will be returned by the next call to {@link java.util.ListIterator#next()} (or <code>null</code> if no next entry exists). */
  int next = -1;
  /** The last entry that was returned (or -1 if we did not iterate or used {@link #remove()}). */
  int curr = -1;
  /** The current index (in the sense of a {@link java.util.ListIterator}). When -1, we do not know the current index.*/
  int index = -1;
  SetIterator() {
   next = first;
   index = 0;
  }
  SetIterator( float from ) {
   if ( ( Float.floatToIntBits(from) == 0 ) ) {
    if ( FloatLinkedOpenHashSet.this.containsNull ) {
     next = (int) link[ n ];
     prev = n;
     return;
    }
    else throw new NoSuchElementException( "The key " + from + " does not belong to this set." );
   }
   if ( ( Float.floatToIntBits(key[ last ]) == Float.floatToIntBits(from) ) ) {
    prev = last;
    index = size;
    return;
   }
   // The starting point.
   final float key[] = FloatLinkedOpenHashSet.this.key;
   int pos = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(from) ) & mask;
   // There's always an unused entry.
   while( ! ( Float.floatToIntBits(key[ pos ]) == 0 ) ) {
    if ( ( Float.floatToIntBits(key[ pos ]) == Float.floatToIntBits(from) ) ) {
     // Note: no valid index known.
     next = (int) link[ pos ];
     prev = pos;
     return;
    }
    pos = ( pos + 1 ) & mask;
   }
   throw new NoSuchElementException( "The key " + from + " does not belong to this set." );
  }
  public boolean hasNext() { return next != -1; }
  public boolean hasPrevious() { return prev != -1; }
  public float nextFloat() {
   if ( ! hasNext() ) throw new NoSuchElementException();
   curr = next;
   next = (int) link[ curr ];
   prev = curr;
   if ( index >= 0 ) index++;
   if ( ASSERTS ) assert curr == n || ! ( Float.floatToIntBits(key[ curr ]) == 0 ) : "Position " + curr + " is not used";
   return key[ curr ];
  }
  public float previousFloat() {
   if ( ! hasPrevious() ) throw new NoSuchElementException();
   curr = prev;
   prev = (int) ( link[ curr ] >>> 32 );
   next = curr;
   if ( index >= 0 ) index--;
   return key[ curr ];
  }
  private final void ensureIndexKnown() {
   if ( index >= 0 ) return;
   if ( prev == -1 ) {
    index = 0;
    return;
   }
   if ( next == -1 ) {
    index = size;
    return;
   }
   int pos = first;
   index = 1;
   while( pos != prev ) {
    pos = (int) link[ pos ];
    index++;
   }
  }
  public int nextIndex() {
   ensureIndexKnown();
   return index;
  }
  public int previousIndex() {
   ensureIndexKnown();
   return index - 1;
  }
  public void remove() {
   ensureIndexKnown();
   if ( curr == -1 ) throw new IllegalStateException();
   if ( curr == prev ) {
    /* If the last operation was a next(), we are removing an entry that preceeds
				   the current index, and thus we must decrement it. */
    index--;
    prev = (int) ( link[ curr ] >>> 32 );
   }
   else
    next = (int) link[ curr ];
   size--;
   /* Now we manually fix the pointers. Because of our knowledge of next
			   and prev, this is going to be faster than calling fixPointers(). */
   if ( prev == -1 ) first = next;
   else
    link[ prev ] ^= ( ( link[ prev ] ^ ( next & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
   if ( next == -1 ) last = prev;
   else
    link[ next ] ^= ( ( link[ next ] ^ ( ( prev & 0xFFFFFFFFL ) << 32 ) ) & 0xFFFFFFFF00000000L );
   int last, slot, pos = curr;
   curr = -1;
   if ( pos == n ) FloatLinkedOpenHashSet.this.containsNull = false;
   else {
    float curr;
    final float[] key = FloatLinkedOpenHashSet.this.key;
    // We have to horribly duplicate the shiftKeys() code because we need to update next/prev.			
    for(;;) {
     pos = ( ( last = pos ) + 1 ) & mask;
     for(;;) {
      if ( ( Float.floatToIntBits(curr = key[ pos ]) == 0 ) ) {
       key[ last ] = (0);
       return;
      }
      slot = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(curr) ) & mask;
      if ( last <= pos ? last >= slot || slot > pos : last >= slot && slot > pos ) break;
      pos = ( pos + 1 ) & mask;
     }
     key[ last ] = curr;
     if ( next == pos ) next = last;
     if ( prev == pos ) prev = last;
     fixPointers( pos, last );
    }
   }
  }
 }
 /** Returns a type-specific list iterator on the elements in this set, starting from a given element of the set.
	 * Please see the class documentation for implementation details.
	 *
	 * @param from an element to start from.
	 * @return a type-specific list iterator starting at the given element.
	 * @throws IllegalArgumentException if <code>from</code> does not belong to the set.
	 */
 public FloatListIterator iterator( float from ) {
  return new SetIterator( from );
 }
 public FloatListIterator iterator() {
  return new SetIterator();
 }
 /** A no-op for backward compatibility. The kind of tables implemented by
	 * this class never need rehashing.
	 *
	 * <P>If you need to reduce the table size to fit exactly
	 * this set, use {@link #trim()}.
	 *
	 * @return true.
	 * @see #trim()
	 * @deprecated A no-op.
	 */
 @Deprecated
 public boolean rehash() {
  return true;
 }
 /** Rehashes this set, making the table as small as possible.
	 * 
	 * <P>This method rehashes the table to the smallest size satisfying the
	 * load factor. It can be used when the set will not be changed anymore, so
	 * to optimize access speed and size.
	 *
	 * <P>If the table size is already the minimum possible, this method
	 * does nothing.
	 *
	 * @return true if there was enough memory to trim the set.
	 * @see #trim(int)
	 */
 public boolean trim() {
  final int l = arraySize( size, f );
  if ( l >= n ) return true;
  try {
   rehash( l );
  }
  catch(OutOfMemoryError cantDoIt) { return false; }
  return true;
 }
 /** Rehashes this set if the table is too large.
	 * 
	 * <P>Let <var>N</var> be the smallest table size that can hold
	 * <code>max(n,{@link #size()})</code> entries, still satisfying the load factor. If the current
	 * table size is smaller than or equal to <var>N</var>, this method does
	 * nothing. Otherwise, it rehashes this set in a table of size
	 * <var>N</var>.
	 *
	 * <P>This method is useful when reusing sets.  {@linkplain #clear() Clearing a
	 * set} leaves the table size untouched. If you are reusing a set
	 * many times, you can call this method with a typical
	 * size to avoid keeping around a very large table just
	 * because of a few large transient sets.
	 *
	 * @param n the threshold for the trimming.
	 * @return true if there was enough memory to trim the set.
	 * @see #trim()
	 */
 public boolean trim( final int n ) {
  final int l = HashCommon.nextPowerOfTwo( (int)Math.ceil( n / f ) );
  if ( this.n <= l ) return true;
  try {
   rehash( l );
  }
  catch( OutOfMemoryError cantDoIt ) { return false; }
  return true;
 }
 /** Rehashes the set.
	 *
	 * <P>This method implements the basic rehashing strategy, and may be
	 * overriden by subclasses implementing different rehashing strategies (e.g.,
	 * disk-based rehashing). However, you should not override this method
	 * unless you understand the internal workings of this class.
	 *
	 * @param newN the new size
	 */

 protected void rehash( final int newN ) {
  final float key[] = this.key;
  final int mask = newN - 1; // Note that this is used by the hashing macro
  final float newKey[] = new float[ newN + 1 ];
  int i = first, prev = -1, newPrev = -1, t, pos;
  final long link[] = this.link;
  final long newLink[] = new long[ newN + 1 ];
  first = -1;
  for( int j = size; j-- != 0; ) {
   if ( ( Float.floatToIntBits(key[ i ]) == 0 ) ) pos = newN;
   else {
    pos = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(key[ i ]) ) & mask;
    while ( ! ( Float.floatToIntBits(newKey[ pos ]) == 0 ) ) pos = ( pos + 1 ) & mask;
    newKey[ pos ] = key[ i ];
   }
   if ( prev != -1 ) {
    newLink[ newPrev ] ^= ( ( newLink[ newPrev ] ^ ( pos & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
    newLink[ pos ] ^= ( ( newLink[ pos ] ^ ( ( newPrev & 0xFFFFFFFFL ) << 32 ) ) & 0xFFFFFFFF00000000L );
    newPrev = pos;
   }
   else {
    newPrev = first = pos;
    // Special case of SET(newLink[ pos ], -1, -1);
    newLink[ pos ] = -1L;
   }
   t = i;
   i = (int) link[ i ];
   prev = t;
  }
  this.link = newLink;
  this.last = newPrev;
  if ( newPrev != -1 )
   // Special case of SET_NEXT( newLink[ newPrev ], -1 );
   newLink[ newPrev ] |= -1 & 0xFFFFFFFFL;
  n = newN;
  this.mask = mask;
  maxFill = maxFill( n, f );
  this.key = newKey;
 }
 /** Returns a deep copy of this set. 
	 *
	 * <P>This method performs a deep copy of this hash set; the data stored in the
	 * set, however, is not cloned. Note that this makes a difference only for object keys.
	 *
	 *  @return a deep copy of this set.
	 */

 public FloatLinkedOpenHashSet clone() {
  FloatLinkedOpenHashSet c;
  try {
   c = (FloatLinkedOpenHashSet )super.clone();
  }
  catch(CloneNotSupportedException cantHappen) {
   throw new InternalError();
  }
  c.key = key.clone();
  c.containsNull = containsNull;
  c.link = link.clone();
  return c;
 }
 /** Returns a hash code for this set.
	 *
	 * This method overrides the generic method provided by the superclass. 
	 * Since <code>equals()</code> is not overriden, it is important
	 * that the value returned by this method is the same value as
	 * the one returned by the overriden method.
	 *
	 * @return a hash code for this set.
	 */
 public int hashCode() {
  int h = 0;
  for( int j = realSize(), i = 0; j-- != 0; ) {
   while( ( Float.floatToIntBits(key[ i ]) == 0 ) ) i++;
    h += it.unimi.dsi.fastutil.HashCommon.float2int(key[ i ]);
   i++;
  }
  // Zero / null have hash zero.		
  return h;
 }
 private void writeObject(java.io.ObjectOutputStream s) throws java.io.IOException {
  final FloatIterator i = iterator();
  s.defaultWriteObject();
  for( int j = size; j-- != 0; ) s.writeFloat( i.nextFloat() );
 }

 private void readObject(java.io.ObjectInputStream s) throws java.io.IOException, ClassNotFoundException {
  s.defaultReadObject();
  n = arraySize( size, f );
  maxFill = maxFill( n, f );
  mask = n - 1;
  final float key[] = this.key = new float[ n + 1 ];
  final long link[] = this.link = new long[ n + 1 ];
  int prev = -1;
  first = last = -1;
  float k;
  for( int i = size, pos; i-- != 0; ) {
   k = s.readFloat();
   if ( ( Float.floatToIntBits(k) == 0 ) ) {
    pos = n;
    containsNull = true;
   }
   else {
    if ( ! ( Float.floatToIntBits(key[ pos = it.unimi.dsi.fastutil.HashCommon.mix( it.unimi.dsi.fastutil.HashCommon.float2int(k) ) & mask ]) == 0 ) )
     while ( ! ( Float.floatToIntBits(key[ pos = ( pos + 1 ) & mask ]) == 0 ) );
    key[ pos ] = k;
   }
   if ( first != -1 ) {
    link[ prev ] ^= ( ( link[ prev ] ^ ( pos & 0xFFFFFFFFL ) ) & 0xFFFFFFFFL );
    link[ pos ] ^= ( ( link[ pos ] ^ ( ( prev & 0xFFFFFFFFL ) << 32 ) ) & 0xFFFFFFFF00000000L );
    prev = pos;
   }
   else {
    prev = first = pos;
    // Special case of SET_PREV( newLink[ pos ], -1 );
    link[ pos ] |= (-1L & 0xFFFFFFFFL) << 32;
   }
  }
  last = prev;
  if ( prev != -1 )
   // Special case of SET_NEXT( link[ prev ], -1 );
   link[ prev ] |= -1 & 0xFFFFFFFFL;
  if ( ASSERTS ) checkTable();
 }
 private void checkTable() {}
}
