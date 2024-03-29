#ifndef __VKI_XEN_SYSCTL_H
#define __VKI_XEN_SYSCTL_H

/*
 * The sysctl interface is versioned via the interface_version
 * field. The structures in this header supports sysctl interfaces:
 *
 * - 0x00000002: Xen 3.0.3 (unhandled)
 * - 0x00000003: Xen 3.1.0 (unhandled)
 * - 0x00000006: Xen 3.2 (unhandled)
 * - 0x00000007: Xen 4.0 (unhandled)
 * - 0x00000008: Xen 4.1
 * - 0x00000009: Xen 4.2
 * - 0x0000000a: Xen 4.3 & 4.4
 * - 0x0000000b: Xen 4.5
 * - 0x0000000c: Xen 4.6
 * - 0x0000000d: Xen 4.7
 * - 0x0000000e: Xen 4.8
 * - 0x0000000f: Xen 4.9
 * - 0x00000010: Xen 4.10
 * - 0x00000011: Xen 4.11
 * - 0x00000012: Xen 4.12 & 4.13
 * - 0x00000013: Xen 4.14
 *
 * When adding a new subop be sure to include the variants used by all
 * of the above, both here and in syswrap-xen.c
 *
 * Structs which are identical in all supported versions have no
 * version suffix. Structs which do differ are defined multiple times
 * and use the suffix of the earliest version to contain that particular
 * variant.
 */

#define VKI_XEN_SYSCTL_readconsole                    1
#define VKI_XEN_SYSCTL_tbuf_op                        2
#define VKI_XEN_SYSCTL_physinfo                       3
#define VKI_XEN_SYSCTL_sched_id                       4
#define VKI_XEN_SYSCTL_perfc_op                       5
#define VKI_XEN_SYSCTL_getdomaininfolist              6
#define VKI_XEN_SYSCTL_debug_keys                     7
#define VKI_XEN_SYSCTL_getcpuinfo                     8
#define VKI_XEN_SYSCTL_availheap                      9
#define VKI_XEN_SYSCTL_get_pmstat                    10
#define VKI_XEN_SYSCTL_cpu_hotplug                   11
#define VKI_XEN_SYSCTL_pm_op                         12
#define VKI_XEN_SYSCTL_page_offline_op               14
#define VKI_XEN_SYSCTL_lockprof_op                   15
#define VKI_XEN_SYSCTL_topologyinfo                  16
#define VKI_XEN_SYSCTL_cputopoinfo                   16 /* Since xen-4.6 */
#define VKI_XEN_SYSCTL_numainfo                      17
#define VKI_XEN_SYSCTL_cpupool_op                    18
#define VKI_XEN_SYSCTL_scheduler_op                  19
#define VKI_XEN_SYSCTL_coverage_op                   20
#define VKI_XEN_SYSCTL_gcov_op                       20 /* Since xen-4.9 */
#define VKI_XEN_SYSCTL_psr_cmt_op                    21
#define VKI_XEN_SYSCTL_pcitopoinfo                   22
#define VKI_XEN_SYSCTL_psr_cat_op                    23
#define VKI_XEN_SYSCTL_tmem_op                       24
#define VKI_XEN_SYSCTL_get_cpu_levelling_caps        25
#define VKI_XEN_SYSCTL_get_cpu_featureset            26
#define VKI_XEN_SYSCTL_livepatch_op                  27
#define VKI_XEN_SYSCTL_set_parameter                 28
#define VKI_XEN_SYSCTL_get_cpu_policy                29

struct vki_xen_sysctl_readconsole {
    /* IN */
    vki_uint8_t clear;
    vki_uint8_t incremental;

    vki_uint8_t pad0, pad1;

    /*
     * IN:  Start index for consumption if @incremental.
     * OUT: End index after consuming from the console.
     */
    vki_uint32_t index;
    VKI_XEN_GUEST_HANDLE_64(char) buffer; /* IN */

    /*
     * IN:  size of buffer.
     * OUT: bytes written into buffer.
     */
    vki_uint32_t count;
};

struct vki_xen_sysctl_getdomaininfolist_00000007 {
    /* IN variables. */
    vki_xen_domid_t           first_domain;
    vki_uint32_t              max_domains;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_domctl_getdomaininfo_00000007_t) buffer;
    /* OUT variables. */
    vki_uint32_t              num_domains;
};
struct vki_xen_sysctl_getdomaininfolist_00000008 {
    /* IN variables. */
    vki_xen_domid_t           first_domain;
    vki_uint32_t              max_domains;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_domctl_getdomaininfo_00000008_t) buffer;
    /* OUT variables. */
    vki_uint32_t              num_domains;
};

struct vki_xen_sysctl_getdomaininfolist_00000009 {
    /* IN variables. */
    vki_xen_domid_t           first_domain;
    vki_uint32_t              max_domains;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_domctl_getdomaininfo_00000009_t) buffer;
    /* OUT variables. */
    vki_uint32_t              num_domains;
};

struct vki_xen_sysctl_getdomaininfolist_0000000f {
    /* IN variables. */
    vki_xen_domid_t           first_domain;
    vki_uint32_t              max_domains;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_domctl_getdomaininfo_0000000f_t) buffer;
    /* OUT variables. */
    vki_uint32_t              num_domains;
};

struct vki_xen_sysctl_getdomaininfolist_00000012 {
    /* IN variables. */
    vki_xen_domid_t           first_domain;
    vki_uint32_t              max_domains;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_domctl_getdomaininfo_00000012_t) buffer;
    /* OUT variables. */
    vki_uint32_t              num_domains;
};

#define VKI_XEN_SYSCTL_CPUPOOL_OP_CREATE                1  /* C */
#define VKI_XEN_SYSCTL_CPUPOOL_OP_DESTROY               2  /* D */
#define VKI_XEN_SYSCTL_CPUPOOL_OP_INFO                  3  /* I */
#define VKI_XEN_SYSCTL_CPUPOOL_OP_ADDCPU                4  /* A */
#define VKI_XEN_SYSCTL_CPUPOOL_OP_RMCPU                 5  /* R */
#define VKI_XEN_SYSCTL_CPUPOOL_OP_MOVEDOMAIN            6  /* M */
#define VKI_XEN_SYSCTL_CPUPOOL_OP_FREEINFO              7  /* F */
#define VKI_XEN_SYSCTL_CPUPOOL_PAR_ANY     0xFFFFFFFF
struct vki_xen_sysctl_cpupool_op {
    vki_uint32_t op;          /* IN */
    vki_uint32_t cpupool_id;  /* IN: CDIARM OUT: CI */
    vki_uint32_t sched_id;    /* IN: C      OUT: I  */
    vki_uint32_t domid;       /* IN: M              */
    vki_uint32_t cpu;         /* IN: AR             */
    vki_uint32_t n_dom;       /*            OUT: I  */
    struct vki_xenctl_bitmap cpumap; /*     OUT: IF */
};

struct vki_xen_sysctl_debug_keys {
    /* IN variables. */
    VKI_XEN_GUEST_HANDLE_64(char) keys;
    vki_uint32_t nr_keys;
};

struct vki_xen_sysctl_topologyinfo {
    vki_uint32_t max_cpu_index;
    VKI_XEN_GUEST_HANDLE_64(vki_uint32) cpu_to_core;
    VKI_XEN_GUEST_HANDLE_64(vki_uint32) cpu_to_socket;
    VKI_XEN_GUEST_HANDLE_64(vki_uint32) cpu_to_node;
};

struct vki_xen_sysctl_cputopo_0000000c {
    vki_uint32_t core;
    vki_uint32_t socket;
    vki_uint32_t node;
};
typedef struct vki_xen_sysctl_cputopo_0000000c vki_xen_sysctl_cputopo_0000000c_t;
DEFINE_VKI_XEN_GUEST_HANDLE(vki_xen_sysctl_cputopo_0000000c_t);

struct vki_xen_sysctl_cputopoinfo_0000000c {
    vki_uint32_t num_cpus;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_sysctl_cputopo_0000000c_t) cputopo;
};

struct vki_xen_sysctl_pcitopoinfo_0000000c {
    vki_uint32_t num_devs;
    VKI_XEN_GUEST_HANDLE_64(vki_physdev_pci_device_t) devs;
    VKI_XEN_GUEST_HANDLE_64(vki_uint32) nodes;
};

struct vki_xen_sysctl_numainfo_00000008 {
    vki_uint32_t max_node_index;
    VKI_XEN_GUEST_HANDLE_64(vki_uint64) node_to_memsize;
    VKI_XEN_GUEST_HANDLE_64(vki_uint64) node_to_memfree;
    VKI_XEN_GUEST_HANDLE_64(vki_uint32) node_to_node_distance;
};

struct vki_xen_xen_sysctl_meminfo_0000000c {
    vki_uint64_t memsize;
    vki_uint64_t memfree;
};
typedef struct vki_xen_xen_sysctl_meminfo_0000000c vki_xen_xen_sysctl_meminfo_0000000c_t;
DEFINE_VKI_XEN_GUEST_HANDLE(vki_xen_xen_sysctl_meminfo_0000000c_t);

struct vki_xen_sysctl_numainfo_0000000c {
    vki_uint32_t num_nodes;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_xen_sysctl_meminfo_0000000c_t) meminfo;
    VKI_XEN_GUEST_HANDLE_64(vki_uint32) distance;
};

struct vki_xen_sysctl_physinfo_00000008 {
    vki_uint32_t threads_per_core;
    vki_uint32_t cores_per_socket;
    vki_uint32_t nr_cpus;     /* # CPUs currently online */
    vki_uint32_t max_cpu_id;  /* Largest possible CPU ID on this host */
    vki_uint32_t nr_nodes;    /* # nodes currently online */
    vki_uint32_t max_node_id; /* Largest possible node ID on this host */
    vki_uint32_t cpu_khz;
    vki_xen_uint64_aligned_t total_pages;
    vki_xen_uint64_aligned_t free_pages;
    vki_xen_uint64_aligned_t scrub_pages;
    vki_uint32_t hw_cap[8];

    vki_uint32_t capabilities;
};

struct vki_xen_sysctl_physinfo_0000000a {
    vki_uint32_t threads_per_core;
    vki_uint32_t cores_per_socket;
    vki_uint32_t nr_cpus;     /* # CPUs currently online */
    vki_uint32_t max_cpu_id;  /* Largest possible CPU ID on this host */
    vki_uint32_t nr_nodes;    /* # nodes currently online */
    vki_uint32_t max_node_id; /* Largest possible node ID on this host */
    vki_uint32_t cpu_khz;
    vki_xen_uint64_aligned_t total_pages;
    vki_xen_uint64_aligned_t free_pages;
    vki_xen_uint64_aligned_t scrub_pages;
    vki_xen_uint64_aligned_t outstanding_pages;
    vki_uint32_t hw_cap[8];

    vki_uint32_t capabilities;
};

struct vki_xen_sysctl_physinfo_00000010 {
    vki_uint32_t threads_per_core;
    vki_uint32_t cores_per_socket;
    vki_uint32_t nr_cpus;     /* # CPUs currently online */
    vki_uint32_t max_cpu_id;  /* Largest possible CPU ID on this host */
    vki_uint32_t nr_nodes;    /* # nodes currently online */
    vki_uint32_t max_node_id; /* Largest possible node ID on this host */
    vki_uint32_t cpu_khz;
    vki_uint32_t capabilities;
    vki_xen_uint64_aligned_t total_pages;
    vki_xen_uint64_aligned_t free_pages;
    vki_xen_uint64_aligned_t scrub_pages;
    vki_xen_uint64_aligned_t outstanding_pages;
    vki_xen_uint64_aligned_t max_mfn;
    vki_uint32_t hw_cap[8];

};

struct vki_xen_sysctl_sched_id {
    /* OUT variable. */
    vki_uint32_t              sched_id;
};

struct vki_xen_sysctl_cpu_featureset_0000000d {
    vki_uint32_t index;
    vki_uint32_t nr_features;
    VKI_XEN_GUEST_HANDLE_64(vki_uint32) features;
};

struct vki_xen_sysctl_get_cpu_policy_00000012 {
    vki_uint32_t index;
    vki_uint32_t nr_leaves;
    vki_uint64_t nr_msrs;
    vki_uint64_t _rsvd;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_cpuid_leaf_00000012_t) cpuid_policy;
    VKI_XEN_GUEST_HANDLE_64(vki_xen_msr_entry_00000012_t) msr_policy;
};

struct vki_xen_sysctl {
    vki_uint32_t cmd;
    vki_uint32_t interface_version; /* XEN_SYSCTL_INTERFACE_VERSION */
    union {
        struct vki_xen_sysctl_readconsole       readconsole;
        //struct vki_xen_sysctl_tbuf_op           tbuf_op;
        struct vki_xen_sysctl_physinfo_00000008 physinfo_00000008;
        struct vki_xen_sysctl_physinfo_0000000a physinfo_0000000a;
        struct vki_xen_sysctl_physinfo_00000010 physinfo_00000010;
        struct vki_xen_sysctl_topologyinfo      topologyinfo;
        struct vki_xen_sysctl_cputopoinfo_0000000c cputopoinfo_0000000c;
        struct vki_xen_sysctl_pcitopoinfo_0000000c pcitopoinfo_0000000c;
        struct vki_xen_sysctl_numainfo_00000008 numainfo_00000008;
        struct vki_xen_sysctl_numainfo_0000000c numainfo_0000000c;
        struct vki_xen_sysctl_sched_id          sched_id;
        //struct vki_xen_sysctl_perfc_op          perfc_op;
        /* getdomaininfolist (sysctl) suffix is the getdomaininfo (domctl) suffix */
        struct vki_xen_sysctl_getdomaininfolist_00000007 getdomaininfolist_00000007;
        struct vki_xen_sysctl_getdomaininfolist_00000008 getdomaininfolist_00000008;
        struct vki_xen_sysctl_getdomaininfolist_00000009 getdomaininfolist_00000009;
        struct vki_xen_sysctl_getdomaininfolist_0000000f getdomaininfolist_0000000f;
        struct vki_xen_sysctl_getdomaininfolist_00000012 getdomaininfolist_00000012;
        struct vki_xen_sysctl_debug_keys        debug_keys;
        //struct vki_xen_sysctl_getcpuinfo        getcpuinfo;
        //struct vki_xen_sysctl_availheap         availheap;
        //struct vki_xen_sysctl_get_pmstat        get_pmstat;
        //struct vki_xen_sysctl_cpu_hotplug       cpu_hotplug;
        //struct vki_xen_sysctl_pm_op             pm_op;
        //struct vki_xen_sysctl_page_offline_op   page_offline;
        //struct vki_xen_sysctl_lockprof_op       lockprof_op;
        struct vki_xen_sysctl_cpupool_op        cpupool_op;
        //struct vki_xen_sysctl_scheduler_op      scheduler_op;
        //struct vki_xen_sysctl_coverage_op       coverage_op;
        //struct vki_xen_sysctl_gcov_op           gcov_op;
        //struct vki_xen_sysctl_psr_cmt_op        psr_cmt_op;
        //struct vki_xen_sysctl_psr_cat_op        psr_cat_op;
        //struct vki_xen_sysctl_tmem_op           tmem_op;
        //struct vki_xen_sysctl_cpu_levelling_caps cpu_levelling_caps;
        struct vki_xen_sysctl_cpu_featureset_0000000d cpu_featureset_0000000d;
        //struct vki_xen_sysctl_livepatch_op      livepatch;
        //struct vki_xen_sysctl_set_parameter     set_parameter;
        struct vki_xen_sysctl_get_cpu_policy_00000012 get_cpu_policy_00000012;

        vki_uint8_t                             pad[128];
    } u;
};

#endif // __VKI_XEN_SYSCTL_H

/*--------------------------------------------------------------------*/
/*--- end                                                          ---*/
/*--------------------------------------------------------------------*/
