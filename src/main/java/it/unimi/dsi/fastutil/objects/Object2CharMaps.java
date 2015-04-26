

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
package it.unimi.dsi.fastutil.objects;
import it.unimi.dsi.fastutil.objects.ObjectSet;
import it.unimi.dsi.fastutil.objects.ObjectSets;
import it.unimi.dsi.fastutil.chars.CharCollection;
import it.unimi.dsi.fastutil.chars.CharCollections;
import it.unimi.dsi.fastutil.chars.CharSets;
import java.util.Map;
/** A class providing static methods and objects that do useful things with type-specific maps.
 *
 * @see it.unimi.dsi.fastutil.Maps
 * @see java.util.Collections
 */
public class Object2CharMaps {
 private Object2CharMaps() {}
 /** An immutable class representing an empty type-specific map.
	 *
	 * <P>This class may be useful to implement your own in case you subclass
	 * a type-specific map.
	 */
 public static class EmptyMap <K> extends Object2CharFunctions.EmptyFunction <K> implements Object2CharMap <K>, java.io.Serializable, Cloneable {
  private static final long serialVersionUID = -7046029254386353129L;
  protected EmptyMap() {}
  public boolean containsValue( final char v ) { return false; }
  public void putAll( final Map<? extends K, ? extends Character> m ) { throw new UnsupportedOperationException(); }
  @SuppressWarnings("unchecked")
  public ObjectSet<Object2CharMap.Entry <K> > object2CharEntrySet() { return ObjectSets.EMPTY_SET; }
  @SuppressWarnings("unchecked")
  public ObjectSet <K> keySet() { return ObjectSets.EMPTY_SET; }
 
  public CharCollection values() { return CharSets.EMPTY_SET; }
  public boolean containsValue( final Object ov ) { return false; }
        private Object readResolve() { return EMPTY_MAP; }
  public Object clone() { return EMPTY_MAP; }
  public boolean isEmpty() { return true; }

  @SuppressWarnings({ "rawtypes", "unchecked" })
  public ObjectSet<Map.Entry<K, Character>> entrySet() { return (ObjectSet)object2CharEntrySet(); }

  public int hashCode() { return 0; }

  public boolean equals( final Object o ) {
   if ( ! ( o instanceof Map ) ) return false;

   return ((Map<?,?>)o).isEmpty();
  }

  public String toString() { return "{}"; }
 }



 /** An empty type-specific map (immutable). It is serializable and cloneable. */

 @SuppressWarnings("rawtypes")
 public static final EmptyMap EMPTY_MAP = new EmptyMap();


 /** An immutable class representing a type-specific singleton map.	 
	 *
	 * <P>This class may be useful to implement your own in case you subclass
	 * a type-specific map.
	 */

 public static class Singleton <K> extends Object2CharFunctions.Singleton <K> implements Object2CharMap <K>, java.io.Serializable, Cloneable {

  private static final long serialVersionUID = -7046029254386353129L;

  protected transient volatile ObjectSet<Object2CharMap.Entry <K> > entries;
  protected transient volatile ObjectSet <K> keys;
  protected transient volatile CharCollection values;

  protected Singleton( final K key, final char value ) {
   super( key, value );
  }

  public boolean containsValue( final char v ) { return ( (value) == (v) ); }

  public boolean containsValue( final Object ov ) { return ( (((((Character)(ov)).charValue()))) == (value) ); }


  public void putAll( final Map<? extends K, ? extends Character> m ) { throw new UnsupportedOperationException(); }

  public ObjectSet<Object2CharMap.Entry <K> > object2CharEntrySet() { if ( entries == null ) entries = ObjectSets.singleton( (Object2CharMap.Entry <K>)new SingletonEntry() ); return entries; }
  public ObjectSet <K> keySet() { if ( keys == null ) keys = ObjectSets.singleton( key ); return keys; }
  public CharCollection values() { if ( values == null ) values = CharSets.singleton( value ); return values; }

  protected class SingletonEntry implements Object2CharMap.Entry <K>, Map.Entry<K,Character> {
   public K getKey() { return (Singleton.this.key); }
   public Character getValue() { return (Character.valueOf(Singleton.this.value)); }






   public char getCharValue() { return Singleton.this.value; }
   public char setValue( final char value ) { throw new UnsupportedOperationException(); }


   public Character setValue( final Character value ) { throw new UnsupportedOperationException(); }

   public boolean equals( final Object o ) {
    if (!(o instanceof Map.Entry)) return false;
    Map.Entry<?,?> e = (Map.Entry<?,?>)o;

    return ( (Singleton.this.key) == null ? ((e.getKey())) == null : (Singleton.this.key).equals((e.getKey())) ) && ( (Singleton.this.value) == (((((Character)(e.getValue())).charValue()))) );
   }

   public int hashCode() { return ( (Singleton.this.key) == null ? 0 : (Singleton.this.key).hashCode() ) ^ (Singleton.this.value); }
   public String toString() { return Singleton.this.key + "->" + Singleton.this.value; }
  }

  public boolean isEmpty() { return false; }

  @SuppressWarnings({ "rawtypes", "unchecked" })
  public ObjectSet<Map.Entry<K, Character>> entrySet() { return (ObjectSet)object2CharEntrySet(); }

  public int hashCode() { return ( (key) == null ? 0 : (key).hashCode() ) ^ (value); }

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

 public static <K> Object2CharMap <K> singleton( final K key, char value ) {
  return new Singleton <K>( key, value );
 }



 /** Returns a type-specific immutable map containing only the specified pair. The returned map is serializable and cloneable.
	 *
	 * <P>Note that albeit the returned map is immutable, its default return value may be changed.
	 *
	 * @param key the only key of the returned map.
	 * @param value the only value of the returned map.
	 * @return a type-specific immutable map containing just the pair <code>&lt;key,value&gt;</code>.
	 */

 public static <K> Object2CharMap <K> singleton( final K key, final Character value ) {
  return new Singleton <K>( (key), ((value).charValue()) );
 }




 /** A synchronized wrapper class for maps. */

 public static class SynchronizedMap <K> extends Object2CharFunctions.SynchronizedFunction <K> implements Object2CharMap <K>, java.io.Serializable {

  private static final long serialVersionUID = -7046029254386353129L;

  protected final Object2CharMap <K> map;

  protected transient volatile ObjectSet<Object2CharMap.Entry <K> > entries;
  protected transient volatile ObjectSet <K> keys;
  protected transient volatile CharCollection values;

  protected SynchronizedMap( final Object2CharMap <K> m, final Object sync ) {
   super( m, sync );
   this.map = m;
  }

  protected SynchronizedMap( final Object2CharMap <K> m ) {
   super( m );
   this.map = m;
  }

  public int size() { synchronized( sync ) { return map.size(); } }
  public boolean containsKey( final Object k ) { synchronized( sync ) { return map.containsKey( k ); } }
  public boolean containsValue( final char v ) { synchronized( sync ) { return map.containsValue( v ); } }

  public char defaultReturnValue() { synchronized( sync ) { return map.defaultReturnValue(); } }
  public void defaultReturnValue( final char defRetValue ) { synchronized( sync ) { map.defaultReturnValue( defRetValue ); } }

  public char put( final K k, final char v ) { synchronized( sync ) { return map.put( k, v ); } }

  //public void putAll( final MAP KEY_VALUE_EXTENDS_GENERIC c ) { synchronized( sync ) { map.putAll( c ); } }
  public void putAll( final Map<? extends K, ? extends Character> m ) { synchronized( sync ) { map.putAll( m ); } }

  public ObjectSet<Object2CharMap.Entry <K> > object2CharEntrySet() { if ( entries == null ) entries = ObjectSets.synchronize( map.object2CharEntrySet(), sync ); return entries; }
  public ObjectSet <K> keySet() { if ( keys == null ) keys = ObjectSets.synchronize( map.keySet(), sync ); return keys; }
  public CharCollection values() { if ( values == null ) return CharCollections.synchronize( map.values(), sync ); return values; }

  public void clear() { synchronized( sync ) { map.clear(); } }
  public String toString() { synchronized( sync ) { return map.toString(); } }


  public Character put( final K k, final Character v ) { synchronized( sync ) { return map.put( k, v ); } }
  public boolean containsValue( final Object ov ) { synchronized( sync ) { return map.containsValue( ov ); } }
  public char removeChar( final Object k ) { synchronized( sync ) { return map.removeChar( k ); } }
  public char getChar( final Object k ) { synchronized( sync ) { return map.getChar( k ); } }
  public boolean isEmpty() { synchronized( sync ) { return map.isEmpty(); } }
  public ObjectSet<Map.Entry<K, Character>> entrySet() { synchronized( sync ) { return map.entrySet(); } }
  public int hashCode() { synchronized( sync ) { return map.hashCode(); } }
  public boolean equals( final Object o ) { synchronized( sync ) { return map.equals( o ); } }
 }
 /** Returns a synchronized type-specific map backed by the given type-specific map.
	 *
	 * @param m the map to be wrapped in a synchronized map.
	 * @return a synchronized view of the specified map.
	 * @see java.util.Collections#synchronizedMap(Map)
	 */
 public static <K> Object2CharMap <K> synchronize( final Object2CharMap <K> m ) { return new SynchronizedMap <K>( m ); }
 /** Returns a synchronized type-specific map backed by the given type-specific map, using an assigned object to synchronize.
	 *
	 * @param m the map to be wrapped in a synchronized map.
	 * @param sync an object that will be used to synchronize the access to the map.
	 * @return a synchronized view of the specified map.
	 * @see java.util.Collections#synchronizedMap(Map)
	 */
 public static <K> Object2CharMap <K> synchronize( final Object2CharMap <K> m, final Object sync ) { return new SynchronizedMap <K>( m, sync ); }
 /** An unmodifiable wrapper class for maps. */
 public static class UnmodifiableMap <K> extends Object2CharFunctions.UnmodifiableFunction <K> implements Object2CharMap <K>, java.io.Serializable {
  private static final long serialVersionUID = -7046029254386353129L;
  protected final Object2CharMap <K> map;
  protected transient volatile ObjectSet<Object2CharMap.Entry <K> > entries;
  protected transient volatile ObjectSet <K> keys;
  protected transient volatile CharCollection values;
  protected UnmodifiableMap( final Object2CharMap <K> m ) {
   super( m );
   this.map = m;
  }
  public int size() { return map.size(); }
  public boolean containsKey( final Object k ) { return map.containsKey( k ); }
  public boolean containsValue( final char v ) { return map.containsValue( v ); }
  public char defaultReturnValue() { throw new UnsupportedOperationException(); }
  public void defaultReturnValue( final char defRetValue ) { throw new UnsupportedOperationException(); }
  public char put( final K k, final char v ) { throw new UnsupportedOperationException(); }
  //public void putAll( final MAP KEY_VALUE_EXTENDS_GENERIC c ) { throw new UnsupportedOperationException(); }
  public void putAll( final Map<? extends K, ? extends Character> m ) { throw new UnsupportedOperationException(); }
  public ObjectSet<Object2CharMap.Entry <K> > object2CharEntrySet() { if ( entries == null ) entries = ObjectSets.unmodifiable( map.object2CharEntrySet() ); return entries; }
  public ObjectSet <K> keySet() { if ( keys == null ) keys = ObjectSets.unmodifiable( map.keySet() ); return keys; }
  public CharCollection values() { if ( values == null ) return CharCollections.unmodifiable( map.values() ); return values; }
  public void clear() { throw new UnsupportedOperationException(); }
  public String toString() { return map.toString(); }
  public boolean containsValue( final Object ov ) { return map.containsValue( ov ); }
  public char removeChar( final Object k ) { throw new UnsupportedOperationException(); }
  public char getChar( final Object k ) { return map.getChar( k ); }
  public boolean isEmpty() { return map.isEmpty(); }
  public ObjectSet<Map.Entry<K, Character>> entrySet() { return ObjectSets.unmodifiable( map.entrySet() ); }
 }
 /** Returns an unmodifiable type-specific map backed by the given type-specific map.
	 *
	 * @param m the map to be wrapped in an unmodifiable map.
	 * @return an unmodifiable view of the specified map.
	 * @see java.util.Collections#unmodifiableMap(Map)
	 */
 public static <K> Object2CharMap <K> unmodifiable( final Object2CharMap <K> m ) { return new UnmodifiableMap <K>( m ); }
}
