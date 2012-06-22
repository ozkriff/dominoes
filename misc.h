// See LICENSE file for copyright and license details.

#ifndef MISC_H_
#define MISC_H_

void die(const char *errstr, ...);

template <typename ContainerType>
void clean_pointer_container (ContainerType *container) {
   while (container->size() > 0) {
      delete container->back();
      container->pop_back();
   }
}

#endif /* MISC_H_ */
