

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
package it.unimi.dsi.fastutil.ints;
import it.unimi.dsi.fastutil.objects.ObjectSet;
import it.unimi.dsi.fastutil.objects.ObjectSets;
import it.unimi.dsi.fastutil.booleans.BooleanCollection;
import it.unimi.dsi.fastutil.booleans.BooleanCollections;
import it.unimi.dsi.fastutil.booleans.BooleanSets;
import java.util.Map;
/** A class providing static methods and objects that do useful things with type-specific maps.
 *
 * @see it.unimi.dsi.fastutil.Maps
 * @see java.util.Collections
 */
public class Int2BooleanMaps {
 private Int2BooleanMaps() {}
 /** An immutable class representing an empty type-specific map.
	 *
	 * <P>This class may be useful to implement your own in case you subclass
	 * a type-specific map.
	 */
 public static class EmptyMap extends Int2BooleanFunctions.EmptyFunction implements Int2BooleanMap , java.io.Serializable, Cloneable {
  private static final long serialVersionUID = -7046029254386353129L;
  protected EmptyMap() {}
  public boolean containsValue( final boolean v ) { return false; }
  public void putAll( final Map<? extends Integer, ? extends Boolean> m ) { throw new UnsupportedOperationException(); }
  @SuppressWarnings("unchecked")
  public ObjectSet<Int2BooleanMap.Entry > int2BooleanEntrySet() { return ObjectSets.EMPTY_SET; }
 
  public IntSet keySet() { return IntSets.EMPTY_SET; }
 
  public BooleanCollection values() { return BooleanSets.EMPTY_SET; }
  public boolean containsValue( final Object ov ) { return false; }
        private Object readResolve() { return EMPTY_MAP; }
  public Object clone() { return EMPTY_MAP; }
  public boolean isEmpty() { return true; }
  @SuppressWarnings({ "rawtypes", "unchecked" })
  public ObjectSet<Map.Entry<Integer, Boolean>> entrySet() { return (ObjectSet)int2BooleanEntrySet(); }

  public int hashCode() { return 0; }

  public boolean equals( final Object o ) {
   if ( ! ( o instanceof Map ) ) return false;

   return ((Map<?,?>)o).isEmpty();
  }

  public String toString() { return "{}"; }
 }



 /** An empty type-specific map (immutable). It is serializable and cloneable. */


 public static final EmptyMap EMPTY_MAP = new EmptyMap();


 /** An immutable class representing a type-specific singleton map.	 
	 *
	 * <P>This class may be useful to implement your own in case you subclass
	 * a type-specific map.
	 */

 public static class Singleton extends Int2BooleanFunctions.Singleton implements Int2BooleanMap , java.io.Serializable, Cloneable {

  private static final long serialVersionUID = -7046029254386353129L;

  protected transient volatile ObjectSet<Int2BooleanMap.Entry > entries;
  protected transient volatile IntSet keys;
  protected transient volatile BooleanCollection values;

  protected Singleton( final int key, final boolean value ) {
   super( key, value );
  }

  public boolean containsValue( final boolean v ) { return ( (value) == (v) ); }

  public boolean containsValue( final Object ov ) { return ( (((((Boolean)(ov)).booleanValue()))) == (value) ); }


  public void putAll( final Map<? extends Integer, ? extends Boolean> m ) { throw new UnsupportedOperationException(); }

  public ObjectSet<Int2BooleanMap.Entry > int2BooleanEntrySet() { if ( entries == null ) entries = ObjectSets.singleton( (Int2BooleanMap.Entry )new SingletonEntry() ); return entries; }
  public IntSet keySet() { if ( keys == null ) keys = IntSets.singleton( key ); return keys; }
  public BooleanCollection values() { if ( values == null ) values = BooleanSets.singleton( value ); return values; }

  protected class SingletonEntry implements Int2BooleanMap.Entry , Map.Entry<Integer,Boolean> {
   public Integer getKey() { return (Integer.valueOf(Singleton.this.key)); }
   public Boolean getValue() { return (Boolean.valueOf(Singleton.this.value)); }


   public int getIntKey() { return Singleton.this.key; }



   public boolean getBooleanValue() { return Singleton.this.value; }
   public boolean setValue( final boolean value ) { throw new UnsupportedOperationException(); }


   public Boolean setValue( final Boolean value ) { throw new UnsupportedOperationException(); }

   public boolean equals( final Object o ) {
    if (!(o instanceof Map.Entry)) return false;
    Map.Entry<?,?> e = (Map.Entry<?,?>)o;

    return ( (Singleton.this.key) == (((((Integer)(e.getKey())).intValue()))) ) && ( (Singleton.this.value) == (((((Boolean)(e.getValue())).booleanValue()))) );
   }

   public int hashCode() { return (Singleton.this.key) ^ (Singleton.this.value ? 1231 : 1237); }
   public String toString() { return Singleton.this.key + "->" + Singleton.this.value; }
  }

  public boolean isEmpty() { return false; }

  @SuppressWarnings({ "rawtypes", "unchecked" })
  public ObjectSet<Map.Entry<Integer, Boolean>> entrySet() { return (ObjectSet)int2BooleanEntrySet(); }

  public int hashCode() { return (key) ^ (value ? 1231 : 1237); }

  public boolean equals( final Object o ) {
   if ( o == this ) return true;
   if ( ! ( o instanceof Map ) ) return false;

   Map<?,?> m = (Map<?,?>)o;
   if ( m.size() != 1 ) return false;
   return entrySet().iterator().next().equals( m.entrySet().iterator().next() );
  }

  public String toString() { return "{" + key + "=>" + value + "}"; }
 }

 /** Returns a type-specific immutable map containing only the specified pair. The returned map is serializable and cloneable.
	 *
	 * <P>Note that albeit the returned map is immutable, its default return value may be changed.
	 *
	 * @param key the only key of the returned map.
	 * @param value the only value of the returned map.
	 * @return a type-specific immutable map containing just the pair <code>&lt;key,value&gt;</code>.
	 */

 public static Int2BooleanMap singleton( final int key, boolean value ) {
  return new Singleton ( key, value );
 }



 /** Returns a type-specific immutable map containing only the specified pair. The returned map is serializable and cloneable.
	 *
	 * <P>Note that albeit the returned map is immutable, its default return value may be changed.
	 *
	 * @param key the only key of the returned map.
	 * @param value the only value of the returned map.
	 * @return a type-specific immutable map containing just the pair <code>&lt;key,value&gt;</code>.
	 */

 public static Int2BooleanMap singleton( final Integer key, final Boolean value ) {
  return new Singleton ( ((key).intValue()), ((value).booleanValue()) );
 }




 /** A synchronized wrapper class for maps. */

 public static class SynchronizedMap extends Int2BooleanFunctions.SynchronizedFunction implements Int2BooleanMap , java.io.Serializable {

  private static final long serialVersionUID = -7046029254386353129L;

  protected final Int2BooleanMap map;

  protected transient volatile ObjectSet<Int2BooleanMap.Entry > entries;
  protected transient volatile IntSet keys;
  protected transient volatile BooleanCollection values;

  protected SynchronizedMap( final Int2BooleanMap m, final Object sync ) {
   super( m, sync );
   this.map = m;
  }

  protected SynchronizedMap( final Int2BooleanMap m ) {
   super( m );
   this.map = m;
  }

  public int size() { synchronized( sync ) { return map.size(); } }
  public boolean containsKey( final int k ) { synchronized( sync ) { return map.containsKey( k ); } }
  public boolean containsValue( final boolean v ) { synchronized( sync ) { return map.containsValue( v ); } }

  public boolean defaultReturnValue() { synchronized( sync ) { return map.defaultReturnValue(); } }
  public void defaultReturnValue( final boolean defRetValue ) { synchronized( sync ) { map.defaultReturnValue( defRetValue ); } }

  public boolean put( final int k, final boolean v ) { synchronized( sync ) { return map.put( k, v ); } }

  //public void putAll( final MAP KEY_VALUE_EXTENDS_GENERIC c ) { synchronized( sync ) { map.putAll( c ); } }
  public void putAll( final Map<? extends Integer, ? extends Boolean> m ) { synchronized( sync ) { map.putAll( m ); } }

  public ObjectSet<Int2BooleanMap.Entry > int2BooleanEntrySet() { if ( entries == null ) entries = ObjectSets.synchronize( map.int2BooleanEntrySet(), sync ); return entries; }
  public IntSet keySet() { if ( keys == null ) keys = IntSets.synchronize( map.keySet(), sync ); return keys; }
  public BooleanCollection values() { if ( values == null ) return BooleanCollections.synchronize( map.values(), sync ); return values; }

  public void clear() { synchronized( sync ) { map.clear(); } }
  public String toString() { synchronized( sync ) { return map.toString(); } }


  public Boolean put( final Integer k, final Boolean v ) { synchronized( sync ) { return map.put( k, v ); } }



  public boolean remove( final int k ) { synchronized( sync ) { return map.remove( k ); } }
  public boolean get( final int k ) { synchronized( sync ) { return map.get( k ); } }
  public boolean containsKey( final Object ok ) { synchronized( sync ) { return map.containsKey( ok ); } }



  public boolean containsValue( final Object ov ) { synchronized( sync ) { return map.containsValue( ov ); } }







  public boolean isEmpty() { synchronized( sync ) { return map.isEmpty(); } }
  public ObjectSet<Map.Entry<Integer, Boolean>> entrySet() { synchronized( sync ) { return map.entrySet(); } }

  public int hashCode() { synchronized( sync ) { return map.hashCode(); } }
  public boolean equals( final Object o ) { synchronized( sync ) { return map.equals( o ); } }
 }

 /** Returns a synchronized type-specific map backed by the given type-specific map.
	 *
	 * @param m the map to be wrapped in a synchronized map.
	 * @return a synchronized view of the specified map.
	 * @see java.util.Collections#synchronizedMap(Map)
	 */
 public static Int2BooleanMap synchronize( final Int2BooleanMap m ) { return new SynchronizedMap ( m ); }

 /** Returns a synchronized type-specific map backed by the given type-specific map, using an assigned object to synchronize.
	 *
	 * @param m the map to be wrapped in a synchronized map.
	 * @param sync an object that will be used to synchronize the access to the map.
	 * @return a synchronized view of the specified map.
	 * @see java.util.Collections#synchronizedMap(Map)
	 */

 public static Int2BooleanMap synchronize( final Int2BooleanMap m, final Object sync ) { return new SynchronizedMap ( m, sync ); }



 /** An unmodifiable wrapper class for maps. */

 public static class UnmodifiableMap extends Int2BooleanFunctions.UnmodifiableFunction implements Int2BooleanMap , java.io.Serializable {

  private static final long serialVersionUID = -7046029254386353129L;

  protected final Int2BooleanMap map;

  protected transient volatile ObjectSet<Int2BooleanMap.Entry > entries;
  protected transient volatile IntSet keys;
  protected transient volatile BooleanCollection values;

  protected UnmodifiableMap( final Int2BooleanMap m ) {
   super( m );
   this.map = m;
  }

  public int size() { return map.size(); }
  public boolean containsKey( final int k ) { return map.containsKey( k ); }
  public boolean containsValue( final boolean v ) { return map.containsValue( v ); }

  public boolean defaultReturnValue() { throw new UnsupportedOperationException(); }
  public void defaultReturnValue( final boolean defRetValue ) { throw new UnsupportedOperationException(); }

  public boolean put( final int k, final boolean v ) { throw new UnsupportedOperationException(); }

  //public void putAll( final MAP KEY_VALUE_EXTENDS_GENERIC c ) { throw new UnsupportedOperationException(); }
  public void putAll( final Map<? extends Integer, ? extends Boolean> m ) { throw new UnsupportedOperationException(); }

  public ObjectSet<Int2BooleanMap.Entry > int2BooleanEntrySet() { if ( entries == null ) entries = ObjectSets.unmodifiable( map.int2BooleanEntrySet() ); return entries; }
  public IntSet keySet() { if ( keys == null ) keys = IntSets.unmodifiable( map.keySet() ); return keys; }
  public BooleanCollection values() { if ( values == null ) return BooleanCollections.unmodifiable( map.values() ); return values; }

  public void clear() { throw new UnsupportedOperationException(); }
  public String toString() { return map.toString(); }


  public Boolean put( final Integer k, final Boolean v ) { throw new UnsupportedOperationException(); }



  public boolean remove( final int k ) { throw new UnsupportedOperationException(); }
  public boolean get( final int k ) { return map.get( k ); }
  public boolean containsKey( final Object ok ) { return map.containsKey( ok ); }



  public boolean containsValue( final Object ov ) { return map.containsValue( ov ); }







  public boolean isEmpty() { return map.isEmpty(); }
  public ObjectSet<Map.Entry<Integer, Boolean>> entrySet() { return ObjectSets.unmodifiable( map.entrySet() ); }
 }

 /** Returns an unmodifiable type-specific map backed by the given type-specific map.
	 *
	 * @param m the map to be wrapped in an unmodifiable map.
	 * @return an unmodifiable view of the specified map.
	 * @see java.util.Collections#unmodifiableMap(Map)
	 */
 public static Int2BooleanMap unmodifiable( final Int2BooleanMap m ) { return new UnmodifiableMap ( m ); }

}
