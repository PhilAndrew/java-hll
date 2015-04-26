

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
package it.unimi.dsi.fastutil.doubles;
/**  An abstract class facilitating the creation of type-specific iterators.
 *
 * <P>To create a type-specific iterator you need both a method returning the
 * next element as primitive type and a method returning the next element as an
 * object. However, if you inherit from this class you need just one (anyone).
 *
 * <P>This class implements also a trivial version of {@link #skip(int)} that uses
 * type-specific methods; moreover, {@link #remove()} will throw an {@link
 * UnsupportedOperationException}.
 *
 * @see java.util.Iterator
 */
public abstract class AbstractDoubleIterator implements DoubleIterator {
 protected AbstractDoubleIterator() {}
 /** Delegates to the corresponding generic method. */
 public double nextDouble() { return next().doubleValue(); }
 /** Delegates to the corresponding type-specific method. */
 public Double next() { return Double.valueOf( nextDouble() ); }
 /** This method just throws an  {@link UnsupportedOperationException}. */
 public void remove() { throw new UnsupportedOperationException(); }
 /** This method just iterates the type-specific version of {@link #next()} for at most
	 * <code>n</code> times, stopping if {@link #hasNext()} becomes false.*/
 public int skip( final int n ) {
  int i = n;
  while( i-- != 0 && hasNext() ) nextDouble();
  return n - i - 1;
 }
}
