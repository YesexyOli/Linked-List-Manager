#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ktime.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/time.h>
#include <linux/random.h>

struct node {
  struct list_head list;
  int data;
};

void list_insert_1000(void)
{
  struct list_head *list_1000 = kmalloc(sizeof(struct list_head), GFP_KERNEL);
  INIT_LIST_HEAD(list_1000);
  
  ktime_t start, end;
  long long time;
  int i = 0;
  int quantity = 1000;
  start = ktime_get();

  for (i = 0; i < quantity; i++)
    {
      struct node *new = kmalloc(sizeof(struct node), GFP_KERNEL);
      new->data = i;
      list_add(&new->list, list_1000);
    }
  end = ktime_get();
  time = ktime_to_ns(ktime_sub(end, start));
  printk("Insert duration %lldns for amount of %d items\n", time, quantity);
}

void list_insert_10000(void)
{
  struct list_head *list_10000 = kmalloc(sizeof(struct list_head), GFP_KERNEL);
  INIT_LIST_HEAD(list_10000);

  ktime_t start, end;
  long long time;
  int i = 0;
  int quantity = 10000;
  start = ktime_get();

  for (i = 0; i < quantity; i++)
    {
      struct node *new = kmalloc(sizeof(struct node), GFP_KERNEL);
      new->data = i;
      list_add(&new->list, list_10000);
    }
  end = ktime_get();
  time = ktime_to_ns(ktime_sub(end, start));
  printk("Insert duration %lldns for amount of %d items\n", time, quantity);
}

void list_insert_100000(void)
{
  struct list_head *list_100000 = kmalloc(sizeof(struct list_head), GFP_KERNEL);
  INIT_LIST_HEAD(list_100000);

  ktime_t start, end;
  long long time;
  int i = 0;
  int quantity = 100000;
  start = ktime_get();

  for (i = 0; i < quantity; i++)
    {
      struct node *new = kmalloc(sizeof(struct node), GFP_KERNEL);
      new->data = i;
      list_add(&new->list, list_100000);
    }
  end = ktime_get();
  time = ktime_to_ns(ktime_sub(end, start));
  printk("Insert duration %lldns for amount of %d items\n", time, quantity);
}

void list_delete_1000(void)
{
  struct list_head *list_1000 = kmalloc(sizeof(struct list_head), GFP_KERNEL);
  INIT_LIST_HEAD(list_1000);

  ktime_t start, end;
  long long time;
  int i = 0;
  int quantity = 1000;
  struct node *old, *new;

  for (i = 0; i < quantity; i++)
   {
     struct node *new = kmalloc(sizeof(struct node), GFP_KERNEL);
     new->data = i;
     list_add(&new->list, list_1000);
   }
  start = ktime_get();
  i = 0;
  list_for_each_entry_safe(old, new, list_1000, list) {
    if (i <= quantity) {
      list_del(&old->list);
      kfree(old);
      i = i + 1;
    }
    else
      {
       	break;
      }
  }
  end = ktime_get();
  time = ktime_to_ns(ktime_sub(end, start));
  printk("Delete duration %lldns for amount of %d items\n", time, quantity);
}

void list_delete_10000(void)
{
  struct list_head *list_10000 = kmalloc(sizeof(struct list_head), GFP_KERNEL);
  INIT_LIST_HEAD(list_10000);

  ktime_t start, end;
  long long time;
  int i = 0;
  int quantity = 10000;
  struct node *old, *new;

  for (i = 0; i < quantity; i++)
   {
     struct node *new = kmalloc(sizeof(struct node), GFP_KERNEL);
     new->data = i;
     list_add(&new->list, list_10000);
   }
  start = ktime_get();
  i = 0;
  list_for_each_entry_safe(old, new, list_10000, list) {
    if (i <= quantity) {
      list_del(&old->list);
      kfree(old);
      i = i + 1;
    }
    else
      {
       	break;
      }
  }
  end = ktime_get();
  time = ktime_to_ns(ktime_sub(end, start));
  printk("Delete duration %lldns for amount of %d items\n", time, quantity);
}

void list_delete_100000(void)
{
  struct list_head *list_100000 = kmalloc(sizeof(struct list_head), GFP_KERNEL);
  INIT_LIST_HEAD(list_100000);
 
  ktime_t start, end;
  long long time;
  int i = 0;
  int quantity = 100000;
  struct node *old, *new;

  for (i = 0; i < quantity; i++)
   {
     struct node *new = kmalloc(sizeof(struct node), GFP_KERNEL);
     new->data = i;
     list_add(&new->list, list_100000);
   }
  start = ktime_get();
  i = 0;
  list_for_each_entry_safe(old, new, list_100000, list) {
    if (i <= quantity) {
      list_del(&old->list);
      kfree(old);
      i = i + 1;
    }
    else
      {
	break;
      }
  }
  end = ktime_get();
  time = ktime_to_ns(ktime_sub(end, start));
  printk("Delete duration %lldns for amount of %d items\n", time, quantity);
}


int __init test_module_init(void)
{
  list_insert_1000();
  list_insert_10000();
  list_insert_100000();
  list_delete_1000();
  list_delete_10000();
  list_delete_100000();
  return 0;
}

void __exit test_module_cleanup(void)
{
  printk(KERN_INFO "cleanup_module() called\n");
}

module_init(test_module_init);
module_exit(test_module_cleanup);
MODULE_LICENSE("GPL");
