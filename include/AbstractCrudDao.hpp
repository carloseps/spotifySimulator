#if !defined(ABSTRACT_CRUD_DAO_HPP)
#define ABSTRACT_CRUD_DAO_HPP

template <typename T>
class AbstractCrudDao
{
private:
  AbstractCrudDao();
  ~AbstractCrudDao();
  T findByAttributes(T obj);
  T update(T obj);
  T insert(T obj);
  void remove(T obj);
};

template <typename T>
AbstractCrudDao<T>::AbstractCrudDao() {}

template <typename T>
AbstractCrudDao<T>::~AbstractCrudDao() {}

template <typename T>
T AbstractCrudDao<T>::findByAttributes(T obj)
{
}
template <typename T>
T AbstractCrudDao<T>::update(T obj)
{
}

template <typename T>
T AbstractCrudDao<T>::insert(T obj)
{
}

template <typename T>
void AbstractCrudDao<T>::remove(T obj)
{
}

#endif // ABSTRACT_CRUD_DAO_HPP
