#ifndef _HOBJECT_H
#define _HOBJECT_H

class Nocopyable {
 public:
  Nocopyable() {
  }
  virtual ~Nocopyable() {
  }

 protected:
  Nocopyable(const Nocopyable&) = delete;
  Nocopyable& operator=(const Nocopyable&) = delete;
};

template <typename T>
class Singleton {
 public:
  static T* GetInstance() {
    if (m_ins == nullptr) {
      m_ins = new T();
    }
    return m_ins;
  }

 protected:
  Singleton() {
  }
  ~Singleton() {
    m_ins = nullptr;
  }
  static T* m_ins;

 private:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};

template <typename T>
T* Singleton<T>::m_ins;

#endif