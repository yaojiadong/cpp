

/**
 * In order to store the height information, we derive a subclass, called
 * AVL_entry, from the standard entry class
 */
#ifndef AVL_ENTRY_H_
#define AVL_ENTRY_H_

template <typename E> class AVL_tree;

/* E is Entry */
template <typename E> class AVL_entry : public E {

protected:
  using K = typename E::Key;
  using V = typename E::Value;

  int height() { return _height; }

  void set_height(int h) { _height = h; }

public:
  AVL_entry(const K &k = K(), const V &v = V()) : E(k, v), _height{0} {}

  friend class AVL_tree<E>;

private:
  int _height;
};

#endif /* AVL_ENTRY_H_ */
