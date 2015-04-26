

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
/* Primitive-type-only definitions (values) */
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
package it.unimi.dsi.fastutil.bytes;
import it.unimi.dsi.fastutil.floats.FloatCollection;
import it.unimi.dsi.fastutil.floats.AbstractFloatCollection;
import it.unimi.dsi.fastutil.floats.FloatIterator;
import it.unimi.dsi.fastutil.floats.AbstractFloatIterator;
import it.unimi.dsi.fastutil.objects.ObjectSet;
import it.unimi.dsi.fastutil.objects.ObjectIterator;
import java.util.Iterator;
import java.util.Map;
/** An abstract class providing basic methods for maps implementing a type-specific interface.
 *
 * <P>Optional operations just throw an {@link
 * UnsupportedOperationException}. Generic versions of accessors delegate to
 * the corresponding type-specific counterparts following the interface rules
 * (they take care of returning <code>null</code> on a missing key).
 *
 * <P>As a further help, this class provides a {@link BasicEntry BasicEntry} inner class
 * that implements a type-specific version of {@link java.util.Map.Entry}; it
 * is particularly useful for those classes that do not implement their own
 * entries (e.g., most immutable maps).
 */
public abstract class AbstractByte2FloatMap extends AbstractByte2FloatFunction implements Byte2FloatMap , java.io.Serializable {
 private static final long serialVersionUID = -4940583368468432370L;
 protected AbstractByte2FloatMap() {}
 public boolean containsValue( Object ov ) {
  return containsValue( ((((Float)(ov)).floatValue())) );
 }
 /** Checks whether the given value is contained in {@link #values()}. */
 public boolean containsValue( float v ) {
  return values().contains( v );
 }
 /** Checks whether the given value is contained in {@link #keySet()}. */
 public boolean containsKey( byte k ) {
  return keySet().contains( k );
 }
 /** Puts all pairs in the given map.
	 * If the map implements the interface of this map,
	 * it uses the faster iterators.
	 *
	 * @param m a map.
	 */
 public void putAll(Map<? extends Byte,? extends Float> m) {
  int n = m.size();
  final Iterator<? extends Map.Entry<? extends Byte,? extends Float>> i = m.entrySet().iterator();
  if (m instanceof Byte2FloatMap) {
   Byte2FloatMap.Entry e;
   while(n-- != 0) {
    e = (Byte2FloatMap.Entry )i.next();
    put(e.getByteKey(), e.getFloatValue());
   }
  }
  else {
   Map.Entry<? extends Byte,? extends Float> e;
   while(n-- != 0) {
    e = i.next();
    put(e.getKey(), e.getValue());
   }
  }
 }
 public boolean isEmpty() {
  return size() == 0;
 }
 /** This class provides a basic but complete type-specific entry class for all those maps implementations
	 * that do not have entries on their own (e.g., most immutable maps). 
	 *
	 * <P>This class does not implement {@link java.util.Map.Entry#setValue(Object) setValue()}, as the modification
	 * would not be reflected in the base map.
	 */
 public static class BasicEntry implements Byte2FloatMap.Entry {
  protected byte key;
  protected float value;
  public BasicEntry( final Byte key, final Float value ) {
   this.key = ((key).byteValue());
   this.value = ((value).floatValue());
  }


  public BasicEntry( final byte key, final float value ) {
   this.key = key;
   this.value = value;
  }



  public Byte getKey() {
   return (Byte.valueOf(key));
  }


  public byte getByteKey() {
   return key;
  }


  public Float getValue() {
   return (Float.valueOf(value));
  }


  public float getFloatValue() {
   return value;
  }


  public float setValue( final float value ) {
   throw new UnsupportedOperationException();
  }



  public Float setValue( final Float value ) {
   return Float.valueOf(setValue(value.floatValue()));
  }



  public boolean equals( final Object o ) {
   if (!(o instanceof Map.Entry)) return false;
   Map.Entry<?,?> e = (Map.Entry<?,?>)o;

   return ( (key) == (((((Byte)(e.getKey())).byteValue()))) ) && ( (value) == (((((Float)(e.getValue())).floatValue()))) );
  }

  public int hashCode() {
   return (key) ^ it.unimi.dsi.fastutil.HashCommon.float2int(value);
  }


  public String toString() {
   return key + "->" + value;
  }
 }


 /** Returns a type-specific-set view of the keys of this map.
	 *
	 * <P>The view is backed by the set returned by {@link #entrySet()}. Note that
	 * <em>no attempt is made at caching the result of this method</em>, as this would
	 * require adding some attributes that lightweight implementations would
	 * not need. Subclasses may easily override this policy by calling
	 * this method and caching the result, but implementors are encouraged to
	 * write more efficient ad-hoc implementations.
	 *
	 * @return a set view of the keys of this map; it may be safely cast to a type-specific interface.
	 */


 public ByteSet keySet() {
  return new AbstractByteSet () {

    public boolean contains( final byte k ) { return containsKey( k ); }

    public int size() { return AbstractByte2FloatMap.this.size(); }
    public void clear() { AbstractByte2FloatMap.this.clear(); }

    public ByteIterator iterator() {
     return new AbstractByteIterator () {
       final ObjectIterator<Map.Entry<Byte,Float>> i = entrySet().iterator();

       public byte nextByte() { return ((Byte2FloatMap.Entry )i.next()).getByteKey(); };

       public boolean hasNext() { return i.hasNext(); }
      };
    }
   };
 }

 /** Returns a type-specific-set view of the values of this map.
	 *
	 * <P>The view is backed by the set returned by {@link #entrySet()}. Note that
	 * <em>no attempt is made at caching the result of this method</em>, as this would
	 * require adding some attributes that lightweight implementations would
	 * not need. Subclasses may easily override this policy by calling
	 * this method and caching the result, but implementors are encouraged to
	 * write more efficient ad-hoc implementations.
	 *
	 * @return a set view of the values of this map; it may be safely cast to a type-specific interface.
	 */


 public FloatCollection values() {
  return new AbstractFloatCollection () {

    public boolean contains( final float k ) { return containsValue( k ); }

    public int size() { return AbstractByte2FloatMap.this.size(); }
    public void clear() { AbstractByte2FloatMap.this.clear(); }

    public FloatIterator iterator() {
     return new AbstractFloatIterator () {
       final ObjectIterator<Map.Entry<Byte,Float>> i = entrySet().iterator();

       public float nextFloat() { return ((Byte2FloatMap.Entry )i.next()).getFloatValue(); };

       public boolean hasNext() { return i.hasNext(); }
      };
    }
   };
 }


 @SuppressWarnings({ "unchecked", "rawtypes" })
 public ObjectSet<Map.Entry<Byte, Float>> entrySet() {
  return (ObjectSet)byte2FloatEntrySet();
 }



 /** Returns a hash code for this map.
	 *
	 * The hash code of a map is computed by summing the hash codes of its entries.
	 *
	 * @return a hash code for this map.
	 */

 public int hashCode() {
  int h = 0, n = size();
  final ObjectIterator<? extends Map.Entry<Byte,Float>> i = entrySet().iterator();

  while( n-- != 0 ) h += i.next().hashCode();
  return h;
 }

 public boolean equals(Object o) {
  if ( o == this ) return true;
  if ( ! ( o instanceof Map ) ) return false;

  Map<?,?> m = (Map<?,?>)o;
  if ( m.size() != size() ) return false;
  return entrySet().containsAll( m.entrySet() );
 }


 public String toString() {
  final StringBuilder s = new StringBuilder();
  final ObjectIterator<? extends Map.Entry<Byte,Float>> i = entrySet().iterator();
  int n = size();
  Byte2FloatMap.Entry e;
  boolean first = true;

  s.append("{");

  while(n-- != 0) {
   if (first) first = false;
   else s.append(", ");

   e = (Byte2FloatMap.Entry )i.next();




    s.append(String.valueOf(e.getByteKey()));
   s.append("=>");



    s.append(String.valueOf(e.getFloatValue()));
  }

  s.append("}");
  return s.toString();
 }


}
