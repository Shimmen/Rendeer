#ifndef __glad_gl_h_
#define __glad_gl_h_

#ifdef __gl_h_
    #error OpenGL header already included (API: gl), remove previous include!
#endif
#define __gl_h_


#define GLAD_GL

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif
#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifdef __cplusplus
extern "C" {
#endif

#ifndef GLAPI
# if defined(GLAD_GLAPI_EXPORT)
#  if defined(WIN32) || defined(__CYGWIN__)
#   if defined(GLAD_GLAPI_EXPORT_BUILD)
#    if defined(__GNUC__)
#     define GLAPI __attribute__ ((dllexport)) extern
#    else
#     define GLAPI __declspec(dllexport) extern
#    endif
#   else
#    if defined(__GNUC__)
#     define GLAPI __attribute__ ((dllimport)) extern
#    else
#     define GLAPI __declspec(dllimport) extern
#    endif
#   endif
#  elif defined(__GNUC__) && defined(GLAD_GLAPI_EXPORT_BUILD)
#   define GLAPI __attribute__ ((visibility ("default"))) extern
#  else
#   define GLAPI extern
#  endif
# else
#  define GLAPI extern
# endif
#endif

#define GL_VERSION_1_0 1
GLAPI int GLAD_GL_VERSION_1_0;
#define GL_VERSION_1_1 1
GLAPI int GLAD_GL_VERSION_1_1;
#define GL_VERSION_1_2 1
GLAPI int GLAD_GL_VERSION_1_2;
#define GL_VERSION_1_3 1
GLAPI int GLAD_GL_VERSION_1_3;
#define GL_VERSION_1_4 1
GLAPI int GLAD_GL_VERSION_1_4;
#define GL_VERSION_1_5 1
GLAPI int GLAD_GL_VERSION_1_5;
#define GL_VERSION_2_0 1
GLAPI int GLAD_GL_VERSION_2_0;
#define GL_VERSION_2_1 1
GLAPI int GLAD_GL_VERSION_2_1;
#define GL_VERSION_3_0 1
GLAPI int GLAD_GL_VERSION_3_0;
#define GL_VERSION_3_1 1
GLAPI int GLAD_GL_VERSION_3_1;
#define GL_VERSION_3_2 1
GLAPI int GLAD_GL_VERSION_3_2;
#define GL_VERSION_3_3 1
GLAPI int GLAD_GL_VERSION_3_3;
#define GL_SGIX_pixel_tiles 1
GLAPI int GLAD_GL_SGIX_pixel_tiles;
#define GL_EXT_post_depth_coverage 1
GLAPI int GLAD_GL_EXT_post_depth_coverage;
#define GL_APPLE_element_array 1
GLAPI int GLAD_GL_APPLE_element_array;
#define GL_AMD_multi_draw_indirect 1
GLAPI int GLAD_GL_AMD_multi_draw_indirect;
#define GL_EXT_blend_subtract 1
GLAPI int GLAD_GL_EXT_blend_subtract;
#define GL_SGIX_tag_sample_buffer 1
GLAPI int GLAD_GL_SGIX_tag_sample_buffer;
#define GL_NV_point_sprite 1
GLAPI int GLAD_GL_NV_point_sprite;
#define GL_IBM_texture_mirrored_repeat 1
GLAPI int GLAD_GL_IBM_texture_mirrored_repeat;
#define GL_APPLE_transform_hint 1
GLAPI int GLAD_GL_APPLE_transform_hint;
#define GL_ATI_separate_stencil 1
GLAPI int GLAD_GL_ATI_separate_stencil;
#define GL_NV_shader_atomic_int64 1
GLAPI int GLAD_GL_NV_shader_atomic_int64;
#define GL_NV_vertex_program2_option 1
GLAPI int GLAD_GL_NV_vertex_program2_option;
#define GL_EXT_texture_buffer_object 1
GLAPI int GLAD_GL_EXT_texture_buffer_object;
#define GL_ARB_vertex_blend 1
GLAPI int GLAD_GL_ARB_vertex_blend;
#define GL_OVR_multiview 1
GLAPI int GLAD_GL_OVR_multiview;
#define GL_NV_vertex_program2 1
GLAPI int GLAD_GL_NV_vertex_program2;
#define GL_ARB_program_interface_query 1
GLAPI int GLAD_GL_ARB_program_interface_query;
#define GL_EXT_misc_attribute 1
GLAPI int GLAD_GL_EXT_misc_attribute;
#define GL_NV_multisample_coverage 1
GLAPI int GLAD_GL_NV_multisample_coverage;
#define GL_ARB_shading_language_packing 1
GLAPI int GLAD_GL_ARB_shading_language_packing;
#define GL_EXT_texture_cube_map 1
GLAPI int GLAD_GL_EXT_texture_cube_map;
#define GL_NV_viewport_array2 1
GLAPI int GLAD_GL_NV_viewport_array2;
#define GL_ARB_texture_stencil8 1
GLAPI int GLAD_GL_ARB_texture_stencil8;
#define GL_EXT_index_func 1
GLAPI int GLAD_GL_EXT_index_func;
#define GL_OES_compressed_paletted_texture 1
GLAPI int GLAD_GL_OES_compressed_paletted_texture;
#define GL_NV_depth_clamp 1
GLAPI int GLAD_GL_NV_depth_clamp;
#define GL_NV_shader_buffer_load 1
GLAPI int GLAD_GL_NV_shader_buffer_load;
#define GL_EXT_color_subtable 1
GLAPI int GLAD_GL_EXT_color_subtable;
#define GL_SUNX_constant_data 1
GLAPI int GLAD_GL_SUNX_constant_data;
#define GL_EXT_texture_compression_s3tc 1
GLAPI int GLAD_GL_EXT_texture_compression_s3tc;
#define GL_EXT_multi_draw_arrays 1
GLAPI int GLAD_GL_EXT_multi_draw_arrays;
#define GL_ARB_shader_atomic_counters 1
GLAPI int GLAD_GL_ARB_shader_atomic_counters;
#define GL_ARB_arrays_of_arrays 1
GLAPI int GLAD_GL_ARB_arrays_of_arrays;
#define GL_NV_conditional_render 1
GLAPI int GLAD_GL_NV_conditional_render;
#define GL_EXT_texture_env_combine 1
GLAPI int GLAD_GL_EXT_texture_env_combine;
#define GL_NV_fog_distance 1
GLAPI int GLAD_GL_NV_fog_distance;
#define GL_SGIX_async_histogram 1
GLAPI int GLAD_GL_SGIX_async_histogram;
#define GL_MESA_resize_buffers 1
GLAPI int GLAD_GL_MESA_resize_buffers;
#define GL_NV_light_max_exponent 1
GLAPI int GLAD_GL_NV_light_max_exponent;
#define GL_NV_texture_env_combine4 1
GLAPI int GLAD_GL_NV_texture_env_combine4;
#define GL_ARB_texture_view 1
GLAPI int GLAD_GL_ARB_texture_view;
#define GL_ARB_texture_env_combine 1
GLAPI int GLAD_GL_ARB_texture_env_combine;
#define GL_ARB_map_buffer_range 1
GLAPI int GLAD_GL_ARB_map_buffer_range;
#define GL_EXT_convolution 1
GLAPI int GLAD_GL_EXT_convolution;
#define GL_NV_compute_program5 1
GLAPI int GLAD_GL_NV_compute_program5;
#define GL_NV_vertex_attrib_integer_64bit 1
GLAPI int GLAD_GL_NV_vertex_attrib_integer_64bit;
#define GL_EXT_paletted_texture 1
GLAPI int GLAD_GL_EXT_paletted_texture;
#define GL_ARB_texture_buffer_object 1
GLAPI int GLAD_GL_ARB_texture_buffer_object;
#define GL_ATI_pn_triangles 1
GLAPI int GLAD_GL_ATI_pn_triangles;
#define GL_SGIX_resample 1
GLAPI int GLAD_GL_SGIX_resample;
#define GL_SGIX_flush_raster 1
GLAPI int GLAD_GL_SGIX_flush_raster;
#define GL_EXT_light_texture 1
GLAPI int GLAD_GL_EXT_light_texture;
#define GL_ARB_point_sprite 1
GLAPI int GLAD_GL_ARB_point_sprite;
#define GL_SUN_convolution_border_modes 1
GLAPI int GLAD_GL_SUN_convolution_border_modes;
#define GL_NV_parameter_buffer_object2 1
GLAPI int GLAD_GL_NV_parameter_buffer_object2;
#define GL_ARB_half_float_pixel 1
GLAPI int GLAD_GL_ARB_half_float_pixel;
#define GL_NV_tessellation_program5 1
GLAPI int GLAD_GL_NV_tessellation_program5;
#define GL_REND_screen_coordinates 1
GLAPI int GLAD_GL_REND_screen_coordinates;
#define GL_EXT_shared_texture_palette 1
GLAPI int GLAD_GL_EXT_shared_texture_palette;
#define GL_EXT_packed_float 1
GLAPI int GLAD_GL_EXT_packed_float;
#define GL_OML_subsample 1
GLAPI int GLAD_GL_OML_subsample;
#define GL_SGIX_vertex_preclip 1
GLAPI int GLAD_GL_SGIX_vertex_preclip;
#define GL_SGIX_texture_scale_bias 1
GLAPI int GLAD_GL_SGIX_texture_scale_bias;
#define GL_AMD_draw_buffers_blend 1
GLAPI int GLAD_GL_AMD_draw_buffers_blend;
#define GL_APPLE_texture_range 1
GLAPI int GLAD_GL_APPLE_texture_range;
#define GL_EXT_texture_array 1
GLAPI int GLAD_GL_EXT_texture_array;
#define GL_NV_texture_barrier 1
GLAPI int GLAD_GL_NV_texture_barrier;
#define GL_ARB_texture_query_levels 1
GLAPI int GLAD_GL_ARB_texture_query_levels;
#define GL_NV_texgen_emboss 1
GLAPI int GLAD_GL_NV_texgen_emboss;
#define GL_EXT_texture_swizzle 1
GLAPI int GLAD_GL_EXT_texture_swizzle;
#define GL_ARB_texture_rg 1
GLAPI int GLAD_GL_ARB_texture_rg;
#define GL_ARB_vertex_type_2_10_10_10_rev 1
GLAPI int GLAD_GL_ARB_vertex_type_2_10_10_10_rev;
#define GL_ARB_fragment_shader 1
GLAPI int GLAD_GL_ARB_fragment_shader;
#define GL_3DFX_tbuffer 1
GLAPI int GLAD_GL_3DFX_tbuffer;
#define GL_GREMEDY_frame_terminator 1
GLAPI int GLAD_GL_GREMEDY_frame_terminator;
#define GL_ARB_blend_func_extended 1
GLAPI int GLAD_GL_ARB_blend_func_extended;
#define GL_EXT_separate_shader_objects 1
GLAPI int GLAD_GL_EXT_separate_shader_objects;
#define GL_NV_texture_multisample 1
GLAPI int GLAD_GL_NV_texture_multisample;
#define GL_ARB_shader_objects 1
GLAPI int GLAD_GL_ARB_shader_objects;
#define GL_ARB_framebuffer_object 1
GLAPI int GLAD_GL_ARB_framebuffer_object;
#define GL_ATI_envmap_bumpmap 1
GLAPI int GLAD_GL_ATI_envmap_bumpmap;
#define GL_AMD_shader_explicit_vertex_parameter 1
GLAPI int GLAD_GL_AMD_shader_explicit_vertex_parameter;
#define GL_ARB_robust_buffer_access_behavior 1
GLAPI int GLAD_GL_ARB_robust_buffer_access_behavior;
#define GL_ARB_shader_stencil_export 1
GLAPI int GLAD_GL_ARB_shader_stencil_export;
#define GL_NV_texture_rectangle 1
GLAPI int GLAD_GL_NV_texture_rectangle;
#define GL_ARB_enhanced_layouts 1
GLAPI int GLAD_GL_ARB_enhanced_layouts;
#define GL_ARB_texture_rectangle 1
GLAPI int GLAD_GL_ARB_texture_rectangle;
#define GL_SGI_texture_color_table 1
GLAPI int GLAD_GL_SGI_texture_color_table;
#define GL_NV_viewport_swizzle 1
GLAPI int GLAD_GL_NV_viewport_swizzle;
#define GL_ATI_map_object_buffer 1
GLAPI int GLAD_GL_ATI_map_object_buffer;
#define GL_ARB_robustness 1
GLAPI int GLAD_GL_ARB_robustness;
#define GL_NV_pixel_data_range 1
GLAPI int GLAD_GL_NV_pixel_data_range;
#define GL_EXT_framebuffer_blit 1
GLAPI int GLAD_GL_EXT_framebuffer_blit;
#define GL_ARB_gpu_shader_fp64 1
GLAPI int GLAD_GL_ARB_gpu_shader_fp64;
#define GL_NV_command_list 1
GLAPI int GLAD_GL_NV_command_list;
#define GL_SGIX_depth_texture 1
GLAPI int GLAD_GL_SGIX_depth_texture;
#define GL_EXT_vertex_weighting 1
GLAPI int GLAD_GL_EXT_vertex_weighting;
#define GL_GREMEDY_string_marker 1
GLAPI int GLAD_GL_GREMEDY_string_marker;
#define GL_ARB_texture_compression_bptc 1
GLAPI int GLAD_GL_ARB_texture_compression_bptc;
#define GL_EXT_subtexture 1
GLAPI int GLAD_GL_EXT_subtexture;
#define GL_EXT_pixel_transform_color_table 1
GLAPI int GLAD_GL_EXT_pixel_transform_color_table;
#define GL_EXT_texture_compression_rgtc 1
GLAPI int GLAD_GL_EXT_texture_compression_rgtc;
#define GL_ARB_shader_atomic_counter_ops 1
GLAPI int GLAD_GL_ARB_shader_atomic_counter_ops;
#define GL_SGIX_depth_pass_instrument 1
GLAPI int GLAD_GL_SGIX_depth_pass_instrument;
#define GL_EXT_gpu_program_parameters 1
GLAPI int GLAD_GL_EXT_gpu_program_parameters;
#define GL_NV_evaluators 1
GLAPI int GLAD_GL_NV_evaluators;
#define GL_SGIS_texture_filter4 1
GLAPI int GLAD_GL_SGIS_texture_filter4;
#define GL_AMD_performance_monitor 1
GLAPI int GLAD_GL_AMD_performance_monitor;
#define GL_NV_geometry_shader4 1
GLAPI int GLAD_GL_NV_geometry_shader4;
#define GL_EXT_stencil_clear_tag 1
GLAPI int GLAD_GL_EXT_stencil_clear_tag;
#define GL_NV_vertex_program1_1 1
GLAPI int GLAD_GL_NV_vertex_program1_1;
#define GL_NV_present_video 1
GLAPI int GLAD_GL_NV_present_video;
#define GL_ARB_texture_compression_rgtc 1
GLAPI int GLAD_GL_ARB_texture_compression_rgtc;
#define GL_HP_convolution_border_modes 1
GLAPI int GLAD_GL_HP_convolution_border_modes;
#define GL_EXT_shader_integer_mix 1
GLAPI int GLAD_GL_EXT_shader_integer_mix;
#define GL_SGIX_framezoom 1
GLAPI int GLAD_GL_SGIX_framezoom;
#define GL_ARB_stencil_texturing 1
GLAPI int GLAD_GL_ARB_stencil_texturing;
#define GL_ARB_shader_clock 1
GLAPI int GLAD_GL_ARB_shader_clock;
#define GL_NV_shader_atomic_fp16_vector 1
GLAPI int GLAD_GL_NV_shader_atomic_fp16_vector;
#define GL_SGIX_fog_offset 1
GLAPI int GLAD_GL_SGIX_fog_offset;
#define GL_ARB_draw_elements_base_vertex 1
GLAPI int GLAD_GL_ARB_draw_elements_base_vertex;
#define GL_INGR_interlace_read 1
GLAPI int GLAD_GL_INGR_interlace_read;
#define GL_NV_transform_feedback 1
GLAPI int GLAD_GL_NV_transform_feedback;
#define GL_NV_fragment_program 1
GLAPI int GLAD_GL_NV_fragment_program;
#define GL_AMD_stencil_operation_extended 1
GLAPI int GLAD_GL_AMD_stencil_operation_extended;
#define GL_ARB_seamless_cubemap_per_texture 1
GLAPI int GLAD_GL_ARB_seamless_cubemap_per_texture;
#define GL_ARB_instanced_arrays 1
GLAPI int GLAD_GL_ARB_instanced_arrays;
#define GL_ARB_get_texture_sub_image 1
GLAPI int GLAD_GL_ARB_get_texture_sub_image;
#define GL_NV_vertex_array_range2 1
GLAPI int GLAD_GL_NV_vertex_array_range2;
#define GL_KHR_robustness 1
GLAPI int GLAD_GL_KHR_robustness;
#define GL_AMD_sparse_texture 1
GLAPI int GLAD_GL_AMD_sparse_texture;
#define GL_ARB_clip_control 1
GLAPI int GLAD_GL_ARB_clip_control;
#define GL_NV_fragment_coverage_to_color 1
GLAPI int GLAD_GL_NV_fragment_coverage_to_color;
#define GL_NV_fence 1
GLAPI int GLAD_GL_NV_fence;
#define GL_ARB_texture_buffer_range 1
GLAPI int GLAD_GL_ARB_texture_buffer_range;
#define GL_SUN_mesh_array 1
GLAPI int GLAD_GL_SUN_mesh_array;
#define GL_ARB_vertex_attrib_binding 1
GLAPI int GLAD_GL_ARB_vertex_attrib_binding;
#define GL_ARB_framebuffer_no_attachments 1
GLAPI int GLAD_GL_ARB_framebuffer_no_attachments;
#define GL_ARB_cl_event 1
GLAPI int GLAD_GL_ARB_cl_event;
#define GL_ARB_derivative_control 1
GLAPI int GLAD_GL_ARB_derivative_control;
#define GL_NV_packed_depth_stencil 1
GLAPI int GLAD_GL_NV_packed_depth_stencil;
#define GL_OES_single_precision 1
GLAPI int GLAD_GL_OES_single_precision;
#define GL_NV_primitive_restart 1
GLAPI int GLAD_GL_NV_primitive_restart;
#define GL_SUN_global_alpha 1
GLAPI int GLAD_GL_SUN_global_alpha;
#define GL_ARB_fragment_shader_interlock 1
GLAPI int GLAD_GL_ARB_fragment_shader_interlock;
#define GL_EXT_texture_object 1
GLAPI int GLAD_GL_EXT_texture_object;
#define GL_AMD_name_gen_delete 1
GLAPI int GLAD_GL_AMD_name_gen_delete;
#define GL_NV_texture_compression_vtc 1
GLAPI int GLAD_GL_NV_texture_compression_vtc;
#define GL_NV_sample_mask_override_coverage 1
GLAPI int GLAD_GL_NV_sample_mask_override_coverage;
#define GL_NV_texture_shader3 1
GLAPI int GLAD_GL_NV_texture_shader3;
#define GL_NV_texture_shader2 1
GLAPI int GLAD_GL_NV_texture_shader2;
#define GL_EXT_texture 1
GLAPI int GLAD_GL_EXT_texture;
#define GL_ARB_buffer_storage 1
GLAPI int GLAD_GL_ARB_buffer_storage;
#define GL_AMD_shader_atomic_counter_ops 1
GLAPI int GLAD_GL_AMD_shader_atomic_counter_ops;
#define GL_APPLE_vertex_program_evaluators 1
GLAPI int GLAD_GL_APPLE_vertex_program_evaluators;
#define GL_ARB_multi_bind 1
GLAPI int GLAD_GL_ARB_multi_bind;
#define GL_ARB_explicit_uniform_location 1
GLAPI int GLAD_GL_ARB_explicit_uniform_location;
#define GL_ARB_depth_buffer_float 1
GLAPI int GLAD_GL_ARB_depth_buffer_float;
#define GL_NV_path_rendering_shared_edge 1
GLAPI int GLAD_GL_NV_path_rendering_shared_edge;
#define GL_SGIX_shadow_ambient 1
GLAPI int GLAD_GL_SGIX_shadow_ambient;
#define GL_ARB_texture_cube_map 1
GLAPI int GLAD_GL_ARB_texture_cube_map;
#define GL_AMD_vertex_shader_viewport_index 1
GLAPI int GLAD_GL_AMD_vertex_shader_viewport_index;
#define GL_SGIX_list_priority 1
GLAPI int GLAD_GL_SGIX_list_priority;
#define GL_NV_vertex_buffer_unified_memory 1
GLAPI int GLAD_GL_NV_vertex_buffer_unified_memory;
#define GL_NV_uniform_buffer_unified_memory 1
GLAPI int GLAD_GL_NV_uniform_buffer_unified_memory;
#define GL_ARB_clear_texture 1
GLAPI int GLAD_GL_ARB_clear_texture;
#define GL_ATI_texture_env_combine3 1
GLAPI int GLAD_GL_ATI_texture_env_combine3;
#define GL_ARB_map_buffer_alignment 1
GLAPI int GLAD_GL_ARB_map_buffer_alignment;
#define GL_NV_blend_equation_advanced 1
GLAPI int GLAD_GL_NV_blend_equation_advanced;
#define GL_SGIS_sharpen_texture 1
GLAPI int GLAD_GL_SGIS_sharpen_texture;
#define GL_KHR_robust_buffer_access_behavior 1
GLAPI int GLAD_GL_KHR_robust_buffer_access_behavior;
#define GL_ARB_pipeline_statistics_query 1
GLAPI int GLAD_GL_ARB_pipeline_statistics_query;
#define GL_ARB_vertex_program 1
GLAPI int GLAD_GL_ARB_vertex_program;
#define GL_ARB_texture_rgb10_a2ui 1
GLAPI int GLAD_GL_ARB_texture_rgb10_a2ui;
#define GL_OML_interlace 1
GLAPI int GLAD_GL_OML_interlace;
#define GL_ATI_pixel_format_float 1
GLAPI int GLAD_GL_ATI_pixel_format_float;
#define GL_NV_clip_space_w_scaling 1
GLAPI int GLAD_GL_NV_clip_space_w_scaling;
#define GL_ARB_vertex_buffer_object 1
GLAPI int GLAD_GL_ARB_vertex_buffer_object;
#define GL_EXT_shadow_funcs 1
GLAPI int GLAD_GL_EXT_shadow_funcs;
#define GL_ATI_text_fragment_shader 1
GLAPI int GLAD_GL_ATI_text_fragment_shader;
#define GL_NV_vertex_array_range 1
GLAPI int GLAD_GL_NV_vertex_array_range;
#define GL_SGIX_fragment_lighting 1
GLAPI int GLAD_GL_SGIX_fragment_lighting;
#define GL_AMD_shader_ballot 1
GLAPI int GLAD_GL_AMD_shader_ballot;
#define GL_NV_texture_expand_normal 1
GLAPI int GLAD_GL_NV_texture_expand_normal;
#define GL_NV_framebuffer_multisample_coverage 1
GLAPI int GLAD_GL_NV_framebuffer_multisample_coverage;
#define GL_EXT_timer_query 1
GLAPI int GLAD_GL_EXT_timer_query;
#define GL_EXT_vertex_array_bgra 1
GLAPI int GLAD_GL_EXT_vertex_array_bgra;
#define GL_NV_bindless_texture 1
GLAPI int GLAD_GL_NV_bindless_texture;
#define GL_KHR_debug 1
GLAPI int GLAD_GL_KHR_debug;
#define GL_SGIS_texture_border_clamp 1
GLAPI int GLAD_GL_SGIS_texture_border_clamp;
#define GL_ATI_vertex_attrib_array_object 1
GLAPI int GLAD_GL_ATI_vertex_attrib_array_object;
#define GL_SGIX_clipmap 1
GLAPI int GLAD_GL_SGIX_clipmap;
#define GL_EXT_geometry_shader4 1
GLAPI int GLAD_GL_EXT_geometry_shader4;
#define GL_ARB_shader_texture_image_samples 1
GLAPI int GLAD_GL_ARB_shader_texture_image_samples;
#define GL_MESA_ycbcr_texture 1
GLAPI int GLAD_GL_MESA_ycbcr_texture;
#define GL_MESAX_texture_stack 1
GLAPI int GLAD_GL_MESAX_texture_stack;
#define GL_AMD_seamless_cubemap_per_texture 1
GLAPI int GLAD_GL_AMD_seamless_cubemap_per_texture;
#define GL_EXT_bindable_uniform 1
GLAPI int GLAD_GL_EXT_bindable_uniform;
#define GL_KHR_texture_compression_astc_hdr 1
GLAPI int GLAD_GL_KHR_texture_compression_astc_hdr;
#define GL_ARB_shader_ballot 1
GLAPI int GLAD_GL_ARB_shader_ballot;
#define GL_KHR_blend_equation_advanced 1
GLAPI int GLAD_GL_KHR_blend_equation_advanced;
#define GL_ARB_fragment_program_shadow 1
GLAPI int GLAD_GL_ARB_fragment_program_shadow;
#define GL_ATI_element_array 1
GLAPI int GLAD_GL_ATI_element_array;
#define GL_AMD_texture_texture4 1
GLAPI int GLAD_GL_AMD_texture_texture4;
#define GL_SGIX_reference_plane 1
GLAPI int GLAD_GL_SGIX_reference_plane;
#define GL_EXT_stencil_two_side 1
GLAPI int GLAD_GL_EXT_stencil_two_side;
#define GL_ARB_transform_feedback_overflow_query 1
GLAPI int GLAD_GL_ARB_transform_feedback_overflow_query;
#define GL_SGIX_texture_lod_bias 1
GLAPI int GLAD_GL_SGIX_texture_lod_bias;
#define GL_KHR_no_error 1
GLAPI int GLAD_GL_KHR_no_error;
#define GL_NV_explicit_multisample 1
GLAPI int GLAD_GL_NV_explicit_multisample;
#define GL_NV_stereo_view_rendering 1
GLAPI int GLAD_GL_NV_stereo_view_rendering;
#define GL_IBM_static_data 1
GLAPI int GLAD_GL_IBM_static_data;
#define GL_EXT_clip_volume_hint 1
GLAPI int GLAD_GL_EXT_clip_volume_hint;
#define GL_EXT_texture_perturb_normal 1
GLAPI int GLAD_GL_EXT_texture_perturb_normal;
#define GL_NV_fragment_program2 1
GLAPI int GLAD_GL_NV_fragment_program2;
#define GL_NV_fragment_program4 1
GLAPI int GLAD_GL_NV_fragment_program4;
#define GL_EXT_point_parameters 1
GLAPI int GLAD_GL_EXT_point_parameters;
#define GL_PGI_misc_hints 1
GLAPI int GLAD_GL_PGI_misc_hints;
#define GL_SGIX_subsample 1
GLAPI int GLAD_GL_SGIX_subsample;
#define GL_AMD_shader_stencil_export 1
GLAPI int GLAD_GL_AMD_shader_stencil_export;
#define GL_ARB_shader_texture_lod 1
GLAPI int GLAD_GL_ARB_shader_texture_lod;
#define GL_ARB_vertex_shader 1
GLAPI int GLAD_GL_ARB_vertex_shader;
#define GL_ARB_depth_clamp 1
GLAPI int GLAD_GL_ARB_depth_clamp;
#define GL_SGIS_texture_select 1
GLAPI int GLAD_GL_SGIS_texture_select;
#define GL_NV_texture_shader 1
GLAPI int GLAD_GL_NV_texture_shader;
#define GL_ARB_tessellation_shader 1
GLAPI int GLAD_GL_ARB_tessellation_shader;
#define GL_EXT_draw_buffers2 1
GLAPI int GLAD_GL_EXT_draw_buffers2;
#define GL_ARB_vertex_attrib_64bit 1
GLAPI int GLAD_GL_ARB_vertex_attrib_64bit;
#define GL_EXT_texture_filter_minmax 1
GLAPI int GLAD_GL_EXT_texture_filter_minmax;
#define GL_WIN_specular_fog 1
GLAPI int GLAD_GL_WIN_specular_fog;
#define GL_AMD_interleaved_elements 1
GLAPI int GLAD_GL_AMD_interleaved_elements;
#define GL_ARB_fragment_program 1
GLAPI int GLAD_GL_ARB_fragment_program;
#define GL_OML_resample 1
GLAPI int GLAD_GL_OML_resample;
#define GL_APPLE_ycbcr_422 1
GLAPI int GLAD_GL_APPLE_ycbcr_422;
#define GL_SGIX_texture_add_env 1
GLAPI int GLAD_GL_SGIX_texture_add_env;
#define GL_ARB_shadow_ambient 1
GLAPI int GLAD_GL_ARB_shadow_ambient;
#define GL_ARB_texture_storage 1
GLAPI int GLAD_GL_ARB_texture_storage;
#define GL_EXT_pixel_buffer_object 1
GLAPI int GLAD_GL_EXT_pixel_buffer_object;
#define GL_ARB_copy_image 1
GLAPI int GLAD_GL_ARB_copy_image;
#define GL_SGIS_pixel_texture 1
GLAPI int GLAD_GL_SGIS_pixel_texture;
#define GL_SGIS_generate_mipmap 1
GLAPI int GLAD_GL_SGIS_generate_mipmap;
#define GL_SGIX_instruments 1
GLAPI int GLAD_GL_SGIX_instruments;
#define GL_HP_texture_lighting 1
GLAPI int GLAD_GL_HP_texture_lighting;
#define GL_ARB_shader_storage_buffer_object 1
GLAPI int GLAD_GL_ARB_shader_storage_buffer_object;
#define GL_EXT_sparse_texture2 1
GLAPI int GLAD_GL_EXT_sparse_texture2;
#define GL_EXT_blend_minmax 1
GLAPI int GLAD_GL_EXT_blend_minmax;
#define GL_MESA_pack_invert 1
GLAPI int GLAD_GL_MESA_pack_invert;
#define GL_ARB_base_instance 1
GLAPI int GLAD_GL_ARB_base_instance;
#define GL_SGIX_convolution_accuracy 1
GLAPI int GLAD_GL_SGIX_convolution_accuracy;
#define GL_PGI_vertex_hints 1
GLAPI int GLAD_GL_PGI_vertex_hints;
#define GL_AMD_transform_feedback4 1
GLAPI int GLAD_GL_AMD_transform_feedback4;
#define GL_ARB_ES3_1_compatibility 1
GLAPI int GLAD_GL_ARB_ES3_1_compatibility;
#define GL_EXT_texture_integer 1
GLAPI int GLAD_GL_EXT_texture_integer;
#define GL_ARB_texture_multisample 1
GLAPI int GLAD_GL_ARB_texture_multisample;
#define GL_ATI_vertex_streams 1
GLAPI int GLAD_GL_ATI_vertex_streams;
#define GL_AMD_gpu_shader_int64 1
GLAPI int GLAD_GL_AMD_gpu_shader_int64;
#define GL_S3_s3tc 1
GLAPI int GLAD_GL_S3_s3tc;
#define GL_ARB_query_buffer_object 1
GLAPI int GLAD_GL_ARB_query_buffer_object;
#define GL_AMD_vertex_shader_tessellator 1
GLAPI int GLAD_GL_AMD_vertex_shader_tessellator;
#define GL_ARB_invalidate_subdata 1
GLAPI int GLAD_GL_ARB_invalidate_subdata;
#define GL_EXT_index_material 1
GLAPI int GLAD_GL_EXT_index_material;
#define GL_NV_blend_equation_advanced_coherent 1
GLAPI int GLAD_GL_NV_blend_equation_advanced_coherent;
#define GL_KHR_texture_compression_astc_sliced_3d 1
GLAPI int GLAD_GL_KHR_texture_compression_astc_sliced_3d;
#define GL_INTEL_parallel_arrays 1
GLAPI int GLAD_GL_INTEL_parallel_arrays;
#define GL_ATI_draw_buffers 1
GLAPI int GLAD_GL_ATI_draw_buffers;
#define GL_EXT_cmyka 1
GLAPI int GLAD_GL_EXT_cmyka;
#define GL_SGIX_pixel_texture 1
GLAPI int GLAD_GL_SGIX_pixel_texture;
#define GL_APPLE_specular_vector 1
GLAPI int GLAD_GL_APPLE_specular_vector;
#define GL_ARB_compatibility 1
GLAPI int GLAD_GL_ARB_compatibility;
#define GL_ARB_timer_query 1
GLAPI int GLAD_GL_ARB_timer_query;
#define GL_SGIX_interlace 1
GLAPI int GLAD_GL_SGIX_interlace;
#define GL_NV_parameter_buffer_object 1
GLAPI int GLAD_GL_NV_parameter_buffer_object;
#define GL_AMD_shader_trinary_minmax 1
GLAPI int GLAD_GL_AMD_shader_trinary_minmax;
#define GL_ARB_direct_state_access 1
GLAPI int GLAD_GL_ARB_direct_state_access;
#define GL_EXT_rescale_normal 1
GLAPI int GLAD_GL_EXT_rescale_normal;
#define GL_ARB_pixel_buffer_object 1
GLAPI int GLAD_GL_ARB_pixel_buffer_object;
#define GL_ARB_uniform_buffer_object 1
GLAPI int GLAD_GL_ARB_uniform_buffer_object;
#define GL_ARB_vertex_type_10f_11f_11f_rev 1
GLAPI int GLAD_GL_ARB_vertex_type_10f_11f_11f_rev;
#define GL_ARB_texture_swizzle 1
GLAPI int GLAD_GL_ARB_texture_swizzle;
#define GL_NV_transform_feedback2 1
GLAPI int GLAD_GL_NV_transform_feedback2;
#define GL_SGIX_async_pixel 1
GLAPI int GLAD_GL_SGIX_async_pixel;
#define GL_NV_fragment_program_option 1
GLAPI int GLAD_GL_NV_fragment_program_option;
#define GL_ARB_explicit_attrib_location 1
GLAPI int GLAD_GL_ARB_explicit_attrib_location;
#define GL_EXT_blend_color 1
GLAPI int GLAD_GL_EXT_blend_color;
#define GL_NV_shader_thread_group 1
GLAPI int GLAD_GL_NV_shader_thread_group;
#define GL_EXT_stencil_wrap 1
GLAPI int GLAD_GL_EXT_stencil_wrap;
#define GL_EXT_index_array_formats 1
GLAPI int GLAD_GL_EXT_index_array_formats;
#define GL_OVR_multiview2 1
GLAPI int GLAD_GL_OVR_multiview2;
#define GL_EXT_histogram 1
GLAPI int GLAD_GL_EXT_histogram;
#define GL_EXT_polygon_offset 1
GLAPI int GLAD_GL_EXT_polygon_offset;
#define GL_SGIS_point_parameters 1
GLAPI int GLAD_GL_SGIS_point_parameters;
#define GL_SGIX_ycrcb 1
GLAPI int GLAD_GL_SGIX_ycrcb;
#define GL_EXT_direct_state_access 1
GLAPI int GLAD_GL_EXT_direct_state_access;
#define GL_ARB_cull_distance 1
GLAPI int GLAD_GL_ARB_cull_distance;
#define GL_AMD_sample_positions 1
GLAPI int GLAD_GL_AMD_sample_positions;
#define GL_NV_vertex_program 1
GLAPI int GLAD_GL_NV_vertex_program;
#define GL_NV_shader_thread_shuffle 1
GLAPI int GLAD_GL_NV_shader_thread_shuffle;
#define GL_ARB_shader_precision 1
GLAPI int GLAD_GL_ARB_shader_precision;
#define GL_EXT_vertex_shader 1
GLAPI int GLAD_GL_EXT_vertex_shader;
#define GL_EXT_blend_func_separate 1
GLAPI int GLAD_GL_EXT_blend_func_separate;
#define GL_APPLE_fence 1
GLAPI int GLAD_GL_APPLE_fence;
#define GL_OES_byte_coordinates 1
GLAPI int GLAD_GL_OES_byte_coordinates;
#define GL_ARB_transpose_matrix 1
GLAPI int GLAD_GL_ARB_transpose_matrix;
#define GL_ARB_provoking_vertex 1
GLAPI int GLAD_GL_ARB_provoking_vertex;
#define GL_EXT_fog_coord 1
GLAPI int GLAD_GL_EXT_fog_coord;
#define GL_EXT_vertex_array 1
GLAPI int GLAD_GL_EXT_vertex_array;
#define GL_ARB_half_float_vertex 1
GLAPI int GLAD_GL_ARB_half_float_vertex;
#define GL_EXT_blend_equation_separate 1
GLAPI int GLAD_GL_EXT_blend_equation_separate;
#define GL_NV_framebuffer_mixed_samples 1
GLAPI int GLAD_GL_NV_framebuffer_mixed_samples;
#define GL_NVX_conditional_render 1
GLAPI int GLAD_GL_NVX_conditional_render;
#define GL_ARB_multi_draw_indirect 1
GLAPI int GLAD_GL_ARB_multi_draw_indirect;
#define GL_EXT_raster_multisample 1
GLAPI int GLAD_GL_EXT_raster_multisample;
#define GL_NV_copy_image 1
GLAPI int GLAD_GL_NV_copy_image;
#define GL_ARB_fragment_layer_viewport 1
GLAPI int GLAD_GL_ARB_fragment_layer_viewport;
#define GL_INTEL_framebuffer_CMAA 1
GLAPI int GLAD_GL_INTEL_framebuffer_CMAA;
#define GL_ARB_transform_feedback2 1
GLAPI int GLAD_GL_ARB_transform_feedback2;
#define GL_ARB_transform_feedback3 1
GLAPI int GLAD_GL_ARB_transform_feedback3;
#define GL_SGIX_ycrcba 1
GLAPI int GLAD_GL_SGIX_ycrcba;
#define GL_EXT_debug_marker 1
GLAPI int GLAD_GL_EXT_debug_marker;
#define GL_EXT_bgra 1
GLAPI int GLAD_GL_EXT_bgra;
#define GL_ARB_sparse_texture_clamp 1
GLAPI int GLAD_GL_ARB_sparse_texture_clamp;
#define GL_EXT_pixel_transform 1
GLAPI int GLAD_GL_EXT_pixel_transform;
#define GL_ARB_conservative_depth 1
GLAPI int GLAD_GL_ARB_conservative_depth;
#define GL_ATI_fragment_shader 1
GLAPI int GLAD_GL_ATI_fragment_shader;
#define GL_ARB_vertex_array_object 1
GLAPI int GLAD_GL_ARB_vertex_array_object;
#define GL_SUN_triangle_list 1
GLAPI int GLAD_GL_SUN_triangle_list;
#define GL_EXT_texture_env_add 1
GLAPI int GLAD_GL_EXT_texture_env_add;
#define GL_EXT_packed_depth_stencil 1
GLAPI int GLAD_GL_EXT_packed_depth_stencil;
#define GL_EXT_texture_mirror_clamp 1
GLAPI int GLAD_GL_EXT_texture_mirror_clamp;
#define GL_NV_multisample_filter_hint 1
GLAPI int GLAD_GL_NV_multisample_filter_hint;
#define GL_APPLE_float_pixels 1
GLAPI int GLAD_GL_APPLE_float_pixels;
#define GL_ARB_transform_feedback_instanced 1
GLAPI int GLAD_GL_ARB_transform_feedback_instanced;
#define GL_SGIX_async 1
GLAPI int GLAD_GL_SGIX_async;
#define GL_EXT_texture_compression_latc 1
GLAPI int GLAD_GL_EXT_texture_compression_latc;
#define GL_NV_robustness_video_memory_purge 1
GLAPI int GLAD_GL_NV_robustness_video_memory_purge;
#define GL_ARB_shading_language_100 1
GLAPI int GLAD_GL_ARB_shading_language_100;
#define GL_INTEL_performance_query 1
GLAPI int GLAD_GL_INTEL_performance_query;
#define GL_ARB_texture_mirror_clamp_to_edge 1
GLAPI int GLAD_GL_ARB_texture_mirror_clamp_to_edge;
#define GL_NV_gpu_shader5 1
GLAPI int GLAD_GL_NV_gpu_shader5;
#define GL_NV_bindless_multi_draw_indirect_count 1
GLAPI int GLAD_GL_NV_bindless_multi_draw_indirect_count;
#define GL_ARB_ES2_compatibility 1
GLAPI int GLAD_GL_ARB_ES2_compatibility;
#define GL_ARB_indirect_parameters 1
GLAPI int GLAD_GL_ARB_indirect_parameters;
#define GL_EXT_window_rectangles 1
GLAPI int GLAD_GL_EXT_window_rectangles;
#define GL_NV_half_float 1
GLAPI int GLAD_GL_NV_half_float;
#define GL_ARB_ES3_2_compatibility 1
GLAPI int GLAD_GL_ARB_ES3_2_compatibility;
#define GL_ATI_texture_mirror_once 1
GLAPI int GLAD_GL_ATI_texture_mirror_once;
#define GL_IBM_rasterpos_clip 1
GLAPI int GLAD_GL_IBM_rasterpos_clip;
#define GL_SGIX_shadow 1
GLAPI int GLAD_GL_SGIX_shadow;
#define GL_EXT_polygon_offset_clamp 1
GLAPI int GLAD_GL_EXT_polygon_offset_clamp;
#define GL_NV_deep_texture3D 1
GLAPI int GLAD_GL_NV_deep_texture3D;
#define GL_ARB_shader_draw_parameters 1
GLAPI int GLAD_GL_ARB_shader_draw_parameters;
#define GL_SGIX_calligraphic_fragment 1
GLAPI int GLAD_GL_SGIX_calligraphic_fragment;
#define GL_ARB_shader_bit_encoding 1
GLAPI int GLAD_GL_ARB_shader_bit_encoding;
#define GL_EXT_compiled_vertex_array 1
GLAPI int GLAD_GL_EXT_compiled_vertex_array;
#define GL_NV_depth_buffer_float 1
GLAPI int GLAD_GL_NV_depth_buffer_float;
#define GL_NV_occlusion_query 1
GLAPI int GLAD_GL_NV_occlusion_query;
#define GL_APPLE_flush_buffer_range 1
GLAPI int GLAD_GL_APPLE_flush_buffer_range;
#define GL_ARB_imaging 1
GLAPI int GLAD_GL_ARB_imaging;
#define GL_NV_shader_atomic_float 1
GLAPI int GLAD_GL_NV_shader_atomic_float;
#define GL_ARB_draw_buffers_blend 1
GLAPI int GLAD_GL_ARB_draw_buffers_blend;
#define GL_AMD_gcn_shader 1
GLAPI int GLAD_GL_AMD_gcn_shader;
#define GL_AMD_blend_minmax_factor 1
GLAPI int GLAD_GL_AMD_blend_minmax_factor;
#define GL_EXT_texture_sRGB_decode 1
GLAPI int GLAD_GL_EXT_texture_sRGB_decode;
#define GL_ARB_shading_language_420pack 1
GLAPI int GLAD_GL_ARB_shading_language_420pack;
#define GL_ARB_shader_viewport_layer_array 1
GLAPI int GLAD_GL_ARB_shader_viewport_layer_array;
#define GL_ATI_meminfo 1
GLAPI int GLAD_GL_ATI_meminfo;
#define GL_EXT_abgr 1
GLAPI int GLAD_GL_EXT_abgr;
#define GL_AMD_pinned_memory 1
GLAPI int GLAD_GL_AMD_pinned_memory;
#define GL_EXT_texture_snorm 1
GLAPI int GLAD_GL_EXT_texture_snorm;
#define GL_SGIX_texture_coordinate_clamp 1
GLAPI int GLAD_GL_SGIX_texture_coordinate_clamp;
#define GL_ARB_clear_buffer_object 1
GLAPI int GLAD_GL_ARB_clear_buffer_object;
#define GL_ARB_multisample 1
GLAPI int GLAD_GL_ARB_multisample;
#define GL_EXT_debug_label 1
GLAPI int GLAD_GL_EXT_debug_label;
#define GL_ARB_sample_shading 1
GLAPI int GLAD_GL_ARB_sample_shading;
#define GL_NV_internalformat_sample_query 1
GLAPI int GLAD_GL_NV_internalformat_sample_query;
#define GL_INTEL_map_texture 1
GLAPI int GLAD_GL_INTEL_map_texture;
#define GL_ARB_texture_env_crossbar 1
GLAPI int GLAD_GL_ARB_texture_env_crossbar;
#define GL_EXT_422_pixels 1
GLAPI int GLAD_GL_EXT_422_pixels;
#define GL_NV_conservative_raster_pre_snap_triangles 1
GLAPI int GLAD_GL_NV_conservative_raster_pre_snap_triangles;
#define GL_ARB_compute_shader 1
GLAPI int GLAD_GL_ARB_compute_shader;
#define GL_EXT_blend_logic_op 1
GLAPI int GLAD_GL_EXT_blend_logic_op;
#define GL_IBM_cull_vertex 1
GLAPI int GLAD_GL_IBM_cull_vertex;
#define GL_IBM_vertex_array_lists 1
GLAPI int GLAD_GL_IBM_vertex_array_lists;
#define GL_ARB_color_buffer_float 1
GLAPI int GLAD_GL_ARB_color_buffer_float;
#define GL_ARB_bindless_texture 1
GLAPI int GLAD_GL_ARB_bindless_texture;
#define GL_ARB_window_pos 1
GLAPI int GLAD_GL_ARB_window_pos;
#define GL_ARB_internalformat_query 1
GLAPI int GLAD_GL_ARB_internalformat_query;
#define GL_ARB_shadow 1
GLAPI int GLAD_GL_ARB_shadow;
#define GL_ARB_texture_mirrored_repeat 1
GLAPI int GLAD_GL_ARB_texture_mirrored_repeat;
#define GL_EXT_shader_image_load_store 1
GLAPI int GLAD_GL_EXT_shader_image_load_store;
#define GL_EXT_copy_texture 1
GLAPI int GLAD_GL_EXT_copy_texture;
#define GL_NV_register_combiners2 1
GLAPI int GLAD_GL_NV_register_combiners2;
#define GL_SGIX_ycrcb_subsample 1
GLAPI int GLAD_GL_SGIX_ycrcb_subsample;
#define GL_SGIX_ir_instrument1 1
GLAPI int GLAD_GL_SGIX_ir_instrument1;
#define GL_NV_draw_texture 1
GLAPI int GLAD_GL_NV_draw_texture;
#define GL_EXT_texture_shared_exponent 1
GLAPI int GLAD_GL_EXT_texture_shared_exponent;
#define GL_EXT_draw_instanced 1
GLAPI int GLAD_GL_EXT_draw_instanced;
#define GL_NV_copy_depth_to_color 1
GLAPI int GLAD_GL_NV_copy_depth_to_color;
#define GL_ARB_viewport_array 1
GLAPI int GLAD_GL_ARB_viewport_array;
#define GL_ARB_separate_shader_objects 1
GLAPI int GLAD_GL_ARB_separate_shader_objects;
#define GL_EXT_depth_bounds_test 1
GLAPI int GLAD_GL_EXT_depth_bounds_test;
#define GL_HP_image_transform 1
GLAPI int GLAD_GL_HP_image_transform;
#define GL_ARB_texture_env_add 1
GLAPI int GLAD_GL_ARB_texture_env_add;
#define GL_NV_video_capture 1
GLAPI int GLAD_GL_NV_video_capture;
#define GL_ARB_sampler_objects 1
GLAPI int GLAD_GL_ARB_sampler_objects;
#define GL_ARB_matrix_palette 1
GLAPI int GLAD_GL_ARB_matrix_palette;
#define GL_SGIS_texture_color_mask 1
GLAPI int GLAD_GL_SGIS_texture_color_mask;
#define GL_EXT_packed_pixels 1
GLAPI int GLAD_GL_EXT_packed_pixels;
#define GL_EXT_coordinate_frame 1
GLAPI int GLAD_GL_EXT_coordinate_frame;
#define GL_ARB_texture_compression 1
GLAPI int GLAD_GL_ARB_texture_compression;
#define GL_APPLE_aux_depth_stencil 1
GLAPI int GLAD_GL_APPLE_aux_depth_stencil;
#define GL_ARB_shader_subroutine 1
GLAPI int GLAD_GL_ARB_shader_subroutine;
#define GL_EXT_framebuffer_sRGB 1
GLAPI int GLAD_GL_EXT_framebuffer_sRGB;
#define GL_ARB_texture_storage_multisample 1
GLAPI int GLAD_GL_ARB_texture_storage_multisample;
#define GL_KHR_blend_equation_advanced_coherent 1
GLAPI int GLAD_GL_KHR_blend_equation_advanced_coherent;
#define GL_EXT_vertex_attrib_64bit 1
GLAPI int GLAD_GL_EXT_vertex_attrib_64bit;
#define GL_NV_shader_atomic_float64 1
GLAPI int GLAD_GL_NV_shader_atomic_float64;
#define GL_ARB_depth_texture 1
GLAPI int GLAD_GL_ARB_depth_texture;
#define GL_NV_shader_buffer_store 1
GLAPI int GLAD_GL_NV_shader_buffer_store;
#define GL_OES_query_matrix 1
GLAPI int GLAD_GL_OES_query_matrix;
#define GL_MESA_window_pos 1
GLAPI int GLAD_GL_MESA_window_pos;
#define GL_NV_fill_rectangle 1
GLAPI int GLAD_GL_NV_fill_rectangle;
#define GL_NV_shader_storage_buffer_object 1
GLAPI int GLAD_GL_NV_shader_storage_buffer_object;
#define GL_ARB_texture_query_lod 1
GLAPI int GLAD_GL_ARB_texture_query_lod;
#define GL_ARB_copy_buffer 1
GLAPI int GLAD_GL_ARB_copy_buffer;
#define GL_ARB_shader_image_size 1
GLAPI int GLAD_GL_ARB_shader_image_size;
#define GL_NV_shader_atomic_counters 1
GLAPI int GLAD_GL_NV_shader_atomic_counters;
#define GL_APPLE_object_purgeable 1
GLAPI int GLAD_GL_APPLE_object_purgeable;
#define GL_ARB_occlusion_query 1
GLAPI int GLAD_GL_ARB_occlusion_query;
#define GL_INGR_color_clamp 1
GLAPI int GLAD_GL_INGR_color_clamp;
#define GL_SGI_color_table 1
GLAPI int GLAD_GL_SGI_color_table;
#define GL_NV_gpu_program5_mem_extended 1
GLAPI int GLAD_GL_NV_gpu_program5_mem_extended;
#define GL_ARB_texture_cube_map_array 1
GLAPI int GLAD_GL_ARB_texture_cube_map_array;
#define GL_SGIX_scalebias_hint 1
GLAPI int GLAD_GL_SGIX_scalebias_hint;
#define GL_EXT_gpu_shader4 1
GLAPI int GLAD_GL_EXT_gpu_shader4;
#define GL_NV_geometry_program4 1
GLAPI int GLAD_GL_NV_geometry_program4;
#define GL_EXT_framebuffer_multisample_blit_scaled 1
GLAPI int GLAD_GL_EXT_framebuffer_multisample_blit_scaled;
#define GL_AMD_debug_output 1
GLAPI int GLAD_GL_AMD_debug_output;
#define GL_ARB_texture_border_clamp 1
GLAPI int GLAD_GL_ARB_texture_border_clamp;
#define GL_ARB_fragment_coord_conventions 1
GLAPI int GLAD_GL_ARB_fragment_coord_conventions;
#define GL_ARB_multitexture 1
GLAPI int GLAD_GL_ARB_multitexture;
#define GL_SGIX_polynomial_ffd 1
GLAPI int GLAD_GL_SGIX_polynomial_ffd;
#define GL_EXT_provoking_vertex 1
GLAPI int GLAD_GL_EXT_provoking_vertex;
#define GL_ARB_point_parameters 1
GLAPI int GLAD_GL_ARB_point_parameters;
#define GL_ARB_shader_image_load_store 1
GLAPI int GLAD_GL_ARB_shader_image_load_store;
#define GL_ARB_conditional_render_inverted 1
GLAPI int GLAD_GL_ARB_conditional_render_inverted;
#define GL_HP_occlusion_test 1
GLAPI int GLAD_GL_HP_occlusion_test;
#define GL_ARB_ES3_compatibility 1
GLAPI int GLAD_GL_ARB_ES3_compatibility;
#define GL_ARB_texture_barrier 1
GLAPI int GLAD_GL_ARB_texture_barrier;
#define GL_ARB_texture_buffer_object_rgb32 1
GLAPI int GLAD_GL_ARB_texture_buffer_object_rgb32;
#define GL_NV_bindless_multi_draw_indirect 1
GLAPI int GLAD_GL_NV_bindless_multi_draw_indirect;
#define GL_SGIX_texture_multi_buffer 1
GLAPI int GLAD_GL_SGIX_texture_multi_buffer;
#define GL_EXT_transform_feedback 1
GLAPI int GLAD_GL_EXT_transform_feedback;
#define GL_KHR_texture_compression_astc_ldr 1
GLAPI int GLAD_GL_KHR_texture_compression_astc_ldr;
#define GL_3DFX_multisample 1
GLAPI int GLAD_GL_3DFX_multisample;
#define GL_INTEL_fragment_shader_ordering 1
GLAPI int GLAD_GL_INTEL_fragment_shader_ordering;
#define GL_ARB_texture_env_dot3 1
GLAPI int GLAD_GL_ARB_texture_env_dot3;
#define GL_NV_gpu_program4 1
GLAPI int GLAD_GL_NV_gpu_program4;
#define GL_NV_gpu_program5 1
GLAPI int GLAD_GL_NV_gpu_program5;
#define GL_NV_float_buffer 1
GLAPI int GLAD_GL_NV_float_buffer;
#define GL_SGIS_texture_edge_clamp 1
GLAPI int GLAD_GL_SGIS_texture_edge_clamp;
#define GL_ARB_framebuffer_sRGB 1
GLAPI int GLAD_GL_ARB_framebuffer_sRGB;
#define GL_SUN_slice_accum 1
GLAPI int GLAD_GL_SUN_slice_accum;
#define GL_EXT_index_texture 1
GLAPI int GLAD_GL_EXT_index_texture;
#define GL_EXT_shader_image_load_formatted 1
GLAPI int GLAD_GL_EXT_shader_image_load_formatted;
#define GL_ARB_geometry_shader4 1
GLAPI int GLAD_GL_ARB_geometry_shader4;
#define GL_EXT_separate_specular_color 1
GLAPI int GLAD_GL_EXT_separate_specular_color;
#define GL_AMD_depth_clamp_separate 1
GLAPI int GLAD_GL_AMD_depth_clamp_separate;
#define GL_NV_conservative_raster 1
GLAPI int GLAD_GL_NV_conservative_raster;
#define GL_ARB_sparse_texture2 1
GLAPI int GLAD_GL_ARB_sparse_texture2;
#define GL_SGIX_sprite 1
GLAPI int GLAD_GL_SGIX_sprite;
#define GL_ARB_get_program_binary 1
GLAPI int GLAD_GL_ARB_get_program_binary;
#define GL_AMD_occlusion_query_event 1
GLAPI int GLAD_GL_AMD_occlusion_query_event;
#define GL_SGIS_multisample 1
GLAPI int GLAD_GL_SGIS_multisample;
#define GL_EXT_framebuffer_object 1
GLAPI int GLAD_GL_EXT_framebuffer_object;
#define GL_ARB_robustness_isolation 1
GLAPI int GLAD_GL_ARB_robustness_isolation;
#define GL_ARB_vertex_array_bgra 1
GLAPI int GLAD_GL_ARB_vertex_array_bgra;
#define GL_APPLE_vertex_array_range 1
GLAPI int GLAD_GL_APPLE_vertex_array_range;
#define GL_AMD_query_buffer_object 1
GLAPI int GLAD_GL_AMD_query_buffer_object;
#define GL_NV_register_combiners 1
GLAPI int GLAD_GL_NV_register_combiners;
#define GL_ARB_draw_buffers 1
GLAPI int GLAD_GL_ARB_draw_buffers;
#define GL_EXT_texture_env_dot3 1
GLAPI int GLAD_GL_EXT_texture_env_dot3;
#define GL_ARB_debug_output 1
GLAPI int GLAD_GL_ARB_debug_output;
#define GL_SGI_color_matrix 1
GLAPI int GLAD_GL_SGI_color_matrix;
#define GL_EXT_cull_vertex 1
GLAPI int GLAD_GL_EXT_cull_vertex;
#define GL_EXT_texture_sRGB 1
GLAPI int GLAD_GL_EXT_texture_sRGB;
#define GL_APPLE_row_bytes 1
GLAPI int GLAD_GL_APPLE_row_bytes;
#define GL_NV_texgen_reflection 1
GLAPI int GLAD_GL_NV_texgen_reflection;
#define GL_IBM_multimode_draw_arrays 1
GLAPI int GLAD_GL_IBM_multimode_draw_arrays;
#define GL_APPLE_vertex_array_object 1
GLAPI int GLAD_GL_APPLE_vertex_array_object;
#define GL_3DFX_texture_compression_FXT1 1
GLAPI int GLAD_GL_3DFX_texture_compression_FXT1;
#define GL_NV_fragment_shader_interlock 1
GLAPI int GLAD_GL_NV_fragment_shader_interlock;
#define GL_AMD_conservative_depth 1
GLAPI int GLAD_GL_AMD_conservative_depth;
#define GL_ARB_texture_float 1
GLAPI int GLAD_GL_ARB_texture_float;
#define GL_ARB_compressed_texture_pixel_storage 1
GLAPI int GLAD_GL_ARB_compressed_texture_pixel_storage;
#define GL_SGIS_detail_texture 1
GLAPI int GLAD_GL_SGIS_detail_texture;
#define GL_NV_geometry_shader_passthrough 1
GLAPI int GLAD_GL_NV_geometry_shader_passthrough;
#define GL_ARB_draw_instanced 1
GLAPI int GLAD_GL_ARB_draw_instanced;
#define GL_OES_read_format 1
GLAPI int GLAD_GL_OES_read_format;
#define GL_ATI_texture_float 1
GLAPI int GLAD_GL_ATI_texture_float;
#define GL_ARB_texture_gather 1
GLAPI int GLAD_GL_ARB_texture_gather;
#define GL_AMD_vertex_shader_layer 1
GLAPI int GLAD_GL_AMD_vertex_shader_layer;
#define GL_ARB_shading_language_include 1
GLAPI int GLAD_GL_ARB_shading_language_include;
#define GL_APPLE_client_storage 1
GLAPI int GLAD_GL_APPLE_client_storage;
#define GL_WIN_phong_shading 1
GLAPI int GLAD_GL_WIN_phong_shading;
#define GL_INGR_blend_func_separate 1
GLAPI int GLAD_GL_INGR_blend_func_separate;
#define GL_NV_path_rendering 1
GLAPI int GLAD_GL_NV_path_rendering;
#define GL_NV_conservative_raster_dilate 1
GLAPI int GLAD_GL_NV_conservative_raster_dilate;
#define GL_AMD_gpu_shader_half_float 1
GLAPI int GLAD_GL_AMD_gpu_shader_half_float;
#define GL_ARB_post_depth_coverage 1
GLAPI int GLAD_GL_ARB_post_depth_coverage;
#define GL_ARB_texture_non_power_of_two 1
GLAPI int GLAD_GL_ARB_texture_non_power_of_two;
#define GL_APPLE_rgb_422 1
GLAPI int GLAD_GL_APPLE_rgb_422;
#define GL_EXT_texture_lod_bias 1
GLAPI int GLAD_GL_EXT_texture_lod_bias;
#define GL_ARB_gpu_shader_int64 1
GLAPI int GLAD_GL_ARB_gpu_shader_int64;
#define GL_ARB_seamless_cube_map 1
GLAPI int GLAD_GL_ARB_seamless_cube_map;
#define GL_ARB_shader_group_vote 1
GLAPI int GLAD_GL_ARB_shader_group_vote;
#define GL_NV_vdpau_interop 1
GLAPI int GLAD_GL_NV_vdpau_interop;
#define GL_ARB_occlusion_query2 1
GLAPI int GLAD_GL_ARB_occlusion_query2;
#define GL_ARB_internalformat_query2 1
GLAPI int GLAD_GL_ARB_internalformat_query2;
#define GL_EXT_texture_filter_anisotropic 1
GLAPI int GLAD_GL_EXT_texture_filter_anisotropic;
#define GL_SUN_vertex 1
GLAPI int GLAD_GL_SUN_vertex;
#define GL_SGIX_igloo_interface 1
GLAPI int GLAD_GL_SGIX_igloo_interface;
#define GL_SGIS_texture_lod 1
GLAPI int GLAD_GL_SGIS_texture_lod;
#define GL_NV_vertex_program3 1
GLAPI int GLAD_GL_NV_vertex_program3;
#define GL_ARB_draw_indirect 1
GLAPI int GLAD_GL_ARB_draw_indirect;
#define GL_NV_vertex_program4 1
GLAPI int GLAD_GL_NV_vertex_program4;
#define GL_AMD_transform_feedback3_lines_triangles 1
GLAPI int GLAD_GL_AMD_transform_feedback3_lines_triangles;
#define GL_SGIS_fog_function 1
GLAPI int GLAD_GL_SGIS_fog_function;
#define GL_EXT_x11_sync_object 1
GLAPI int GLAD_GL_EXT_x11_sync_object;
#define GL_ARB_sync 1
GLAPI int GLAD_GL_ARB_sync;
#define GL_NV_sample_locations 1
GLAPI int GLAD_GL_NV_sample_locations;
#define GL_ARB_compute_variable_group_size 1
GLAPI int GLAD_GL_ARB_compute_variable_group_size;
#define GL_OES_fixed_point 1
GLAPI int GLAD_GL_OES_fixed_point;
#define GL_NV_blend_square 1
GLAPI int GLAD_GL_NV_blend_square;
#define GL_EXT_framebuffer_multisample 1
GLAPI int GLAD_GL_EXT_framebuffer_multisample;
#define GL_ARB_gpu_shader5 1
GLAPI int GLAD_GL_ARB_gpu_shader5;
#define GL_SGIS_texture4D 1
GLAPI int GLAD_GL_SGIS_texture4D;
#define GL_EXT_texture3D 1
GLAPI int GLAD_GL_EXT_texture3D;
#define GL_EXT_multisample 1
GLAPI int GLAD_GL_EXT_multisample;
#define GL_EXT_secondary_color 1
GLAPI int GLAD_GL_EXT_secondary_color;
#define GL_INTEL_conservative_rasterization 1
GLAPI int GLAD_GL_INTEL_conservative_rasterization;
#define GL_ARB_texture_filter_minmax 1
GLAPI int GLAD_GL_ARB_texture_filter_minmax;
#define GL_ATI_vertex_array_object 1
GLAPI int GLAD_GL_ATI_vertex_array_object;
#define GL_ARB_parallel_shader_compile 1
GLAPI int GLAD_GL_ARB_parallel_shader_compile;
#define GL_NVX_gpu_memory_info 1
GLAPI int GLAD_GL_NVX_gpu_memory_info;
#define GL_ARB_sparse_texture 1
GLAPI int GLAD_GL_ARB_sparse_texture;
#define GL_SGIS_point_line_texgen 1
GLAPI int GLAD_GL_SGIS_point_line_texgen;
#define GL_ARB_sample_locations 1
GLAPI int GLAD_GL_ARB_sample_locations;
#define GL_ARB_sparse_buffer 1
GLAPI int GLAD_GL_ARB_sparse_buffer;
#define GL_EXT_draw_range_elements 1
GLAPI int GLAD_GL_EXT_draw_range_elements;
#define GL_SGIX_blend_alpha_minmax 1
GLAPI int GLAD_GL_SGIX_blend_alpha_minmax;
#define GL_KHR_context_flush_control 1
GLAPI int GLAD_GL_KHR_context_flush_control;


#include <stddef.h>
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLclampx;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef unsigned short GLhalfARB;
typedef unsigned short GLhalf;
typedef GLint GLfixed;
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
typedef int64_t GLint64;
typedef uint64_t GLuint64;
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
struct _cl_context;
struct _cl_event;
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;

#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS 0x919A
#define GL_BACK_NORMALS_HINT_PGI 0x1A223
#define GL_PIXEL_TILE_HEIGHT_SGIX 0x8141
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_DITHER 0x0BD0
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT 0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT 0x9069
#define GL_RGBA_INTEGER_EXT 0x8D99
#define GL_ALPHA_FLOAT32_ATI 0x8816
#define GL_MIRROR_CLAMP_TO_EDGE_EXT 0x8743
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_PRIMITIVE_RESTART_NV 0x8558
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT 0x88ED
#define GL_IMAGE_1D_EXT 0x904C
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E
#define GL_SOURCE2_ALPHA_EXT 0x858A
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_SIGNED_HILO_NV 0x86F9
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_FRAGMENT_LIGHTING_SGIX 0x8400
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT 0x802C
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS 0x809F
#define GL_BLEND_EQUATION 0x8009
#define GL_BYTE 0x1400
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_SAMPLER_1D_ARRAY_EXT 0x8DC0
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_BUFFER_USAGE 0x8765
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV 0x9351
#define GL_PROGRAM_TARGET_NV 0x8646
#define GL_DEPTH32F_STENCIL8_NV 0x8DAC
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT 0x884E
#define GL_COLOR_ATTACHMENT28 0x8CFC
#define GL_COLOR_ATTACHMENT29 0x8CFD
#define GL_MATRIX_PALETTE_ARB 0x8840
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_COLOR_ATTACHMENT24 0x8CF8
#define GL_COLOR_ATTACHMENT25 0x8CF9
#define GL_COLOR_ATTACHMENT26 0x8CFA
#define GL_COLOR_ATTACHMENT27 0x8CFB
#define GL_COLOR_ATTACHMENT20 0x8CF4
#define GL_COLOR_ATTACHMENT21 0x8CF5
#define GL_COLOR_ATTACHMENT22 0x8CF6
#define GL_COLOR_ATTACHMENT23 0x8CF7
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSLATE_Y_NV 0x908F
#define GL_BGRA_EXT 0x80E1
#define GL_FLOAT_RGBA32_NV 0x888B
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI 0x80DD
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_ALLOW_DRAW_FRG_HINT_PGI 0x1A210
#define GL_RG_SNORM 0x8F91
#define GL_RENDERBUFFER_FREE_MEMORY_ATI 0x87FD
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_BLEND_DST_ALPHA_EXT 0x80CA
#define GL_CON_26_ATI 0x895B
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_COUNT_DOWN_NV 0x9089
#define GL_DOUBLEBUFFER 0x0C32
#define GL_COVERAGE_MODULATION_NV 0x9332
#define GL_TESSELLATION_FACTOR_AMD 0x9005
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI 0x87F7
#define GL_RGB9_E5_EXT 0x8C3D
#define GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE 0x8A04
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB 0x8806
#define GL_MAP2_VERTEX_ATTRIB4_4_NV 0x8674
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT 0x87C7
#define GL_IMAGE_BINDING_ACCESS_EXT 0x8F3E
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_R1UI_T2F_N3F_V3F_SUN 0x85CA
#define GL_SCISSOR_COMMAND_NV 0x0011
#define GL_HISTOGRAM_FORMAT_EXT 0x8027
#define GL_MATRIX1_ARB 0x88C1
#define GL_READ_WRITE_ARB 0x88BA
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_QUAD_MESH_SUN 0x8614
#define GL_TEXTURE_DEPTH 0x8071
#define GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV 0x90FC
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_COPY 0x1503
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_VERTEX_STREAM2_ATI 0x876E
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_RGBA_FLOAT_MODE_ATI 0x8820
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT 0x8C1B
#define GL_FILL 0x1B02
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_SRC_COLOR 0x0300
#define GL_FLOAT_RGB_NV 0x8882
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_RGBA_INTEGER 0x8D99
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_VERTEX_WEIGHT_ARRAY_EXT 0x850C
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT 0x8DE1
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT 0x8DBD
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT 0x808C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES 0x8B9A
#define GL_GREEN_NV 0x1904
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE 0x8A02
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_R32I 0x8235
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_R32F 0x822E
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV 0x887C
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT 0x87C6
#define GL_ELEMENT_ARRAY_ATI 0x8768
#define GL_CMYKA_EXT 0x800D
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_PROXY_TEXTURE_2D_EXT 0x8064
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT 0x000D
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI 0x80B7
#define GL_OBJECT_LINK_STATUS_ARB 0x8B82
#define GL_REG_31_ATI 0x8940
#define GL_BUMP_TARGET_ATI 0x877C
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM 103082
#define GL_TEXTURE_SWIZZLE_A_EXT 0x8E45
#define GL_TEXTURE_HI_SIZE_NV 0x871B
#define GL_PROGRAM_PARAMETERS_ARB 0x88A8
#define GL_SRC1_ALPHA 0x8589
#define GL_MODELVIEW30_ARB 0x873E
#define GL_SIGNED_ALPHA_NV 0x8705
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_MULTISAMPLE_EXT 0x809D
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_RELATIVE_LINE_TO_NV 0x05
#define GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE 0x8A06
#define GL_OP_CLAMP_EXT 0x878E
#define GL_PALETTE8_R5_G6_B5_OES 0x8B97
#define GL_OBJECT_TYPE_ARB 0x8B4E
#define GL_BLUE_MAX_CLAMP_INGR 0x8566
#define GL_CND_ATI 0x896A
#define GL_CULL_MODES_NV 0x86E0
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_CLIP_DISTANCE_NV 0x8C7A
#define GL_PROGRAM_INPUT 0x92E3
#define GL_STENCIL_TEST_TWO_SIDE_EXT 0x8910
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV 0x9357
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_SCALED_RESOLVE_FASTEST_EXT 0x90BA
#define GL_MULTISAMPLE_FILTER_HINT_NV 0x8534
#define GL_4PASS_2_EXT 0x80A6
#define GL_UNSIGNED_INT_8_8_8_8_EXT 0x8035
#define GL_VIEWPORT_SWIZZLE_X_NV 0x9358
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_TEXTURE_COMPARE_FUNC_ARB 0x884D
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV 0x8DA3
#define GL_PATH_END_CAPS_NV 0x9076
#define GL_PROGRAM_ATTRIBS_ARB 0x88AC
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_FLOAT_RG_NV 0x8881
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_RGBA_SIGNED_COMPONENTS_EXT 0x8C3C
#define GL_LINE 0x1B01
#define GL_SHARED_EDGE_NV 0xC0
#define GL_LUMINANCE16_EXT 0x8042
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_MATRIX3_NV 0x8633
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_BLUE_INTEGER 0x8D96
#define GL_GEOMETRY_PROGRAM_NV 0x8C26
#define GL_SYNC_FLAGS 0x9115
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB 0x8872
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_PROXY_COLOR_TABLE_SGI 0x80D3
#define GL_DRAW_BUFFER3_ARB 0x8828
#define GL_QUERY_BUFFER 0x9192
#define GL_BUFFER_FLUSHING_UNMAP_APPLE 0x8A13
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_BUFFER_MAPPED_ARB 0x88BC
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_EVAL_VERTEX_ATTRIB5_NV 0x86CB
#define GL_MAX_SHININESS_NV 0x8504
#define GL_CONVOLUTION_HINT_SGIX 0x8316
#define GL_ADD_SIGNED_ARB 0x8574
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_LUMINANCE_FLOAT32_APPLE 0x8818
#define GL_HI_BIAS_NV 0x8714
#define GL_RESAMPLE_ZERO_FILL_OML 0x8987
#define GL_EVAL_VERTEX_ATTRIB7_NV 0x86CD
#define GL_SAMPLES_SGIS 0x80A9
#define GL_COLOR_SAMPLES_NV 0x8E20
#define GL_HILO8_NV 0x885E
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_DYNAMIC_READ_ARB 0x88E9
#define GL_MAX_VARYING_FLOATS_ARB 0x8B4B
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_VERTEX_ARRAY_OBJECT_AMD 0x9154
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX 0x817C
#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC
#define GL_MAT_SPECULAR_BIT_PGI 0x04000000
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV 0x8850
#define GL_MATRIX30_ARB 0x88DE
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV 0x9024
#define GL_MODELVIEW1_EXT 0x850A
#define GL_POINT_SIZE_MAX_SGIS 0x8127
#define GL_MAX_PROGRAM_IF_DEPTH_NV 0x88F6
#define GL_INTERLACE_SGIX 0x8094
#define GL_EXCLUSION_KHR 0x92A0
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_SHADER_TYPE 0x8B4F
#define GL_MAP_COHERENT_BIT 0x0080
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_RGBA32I_EXT 0x8D82
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_SLUMINANCE8_ALPHA8_EXT 0x8C45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_VARIANT_VALUE_EXT 0x87E4
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_COUNTER_TYPE_AMD 0x8BC0
#define GL_MAP2_VERTEX_ATTRIB1_4_NV 0x8671
#define GL_PROGRAM_FORMAT_ARB 0x8876
#define GL_INT_IMAGE_2D_EXT 0x9058
#define GL_VERTEX_STREAM0_ATI 0x876C
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_LOCATION_COMPONENT 0x934A
#define GL_TEXTURE0_ARB 0x84C0
#define GL_STEREO 0x0C33
#define GL_MATRIX21_ARB 0x88D5
#define GL_ACCUM_ADJACENT_PAIRS_NV 0x90AD
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT 0x8DD4
#define GL_SAMPLER_3D_ARB 0x8B5F
#define GL_DISCARD_ATI 0x8763
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_PRIMITIVES_GENERATED_NV 0x8C87
#define GL_OUTPUT_TEXTURE_COORD4_EXT 0x87A1
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_POINTS 0x0000
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX 0x844F
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_PATH_TERMINAL_END_CAP_NV 0x9078
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_SCISSOR_BOX 0x0C10
#define GL_COMBINER_SUM_OUTPUT_NV 0x854C
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TEXTURE_SWIZZLE_R_EXT 0x8E42
#define GL_VERTEX_ARRAY_BINDING_APPLE 0x85B5
#define GL_OP_MUL_EXT 0x8786
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_PERFQUERY_WAIT_INTEL 0x83FB
#define GL_DONT_CARE 0x1100
#define GL_LUMINANCE_ALPHA_FLOAT32_APPLE 0x8819
#define GL_CURRENT_VERTEX_WEIGHT_EXT 0x850B
#define GL_MODELVIEW0_MATRIX_EXT 0x0BA6
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_LOCAL_CONSTANT_DATATYPE_EXT 0x87ED
#define GL_NEXT_BUFFER_NV -2
#define GL_LEQUAL 0x0203
#define GL_SAMPLE_COVERAGE_INVERT_ARB 0x80AB
#define GL_VIEWPORT_POSITION_W_SCALE_NV 0x937C
#define GL_RED_MIN_CLAMP_INGR 0x8560
#define GL_UNSIGNED_INVERT_NV 0x8537
#define GL_INTERPOLATE_ARB 0x8575
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_VERTEX_ARRAY_SIZE_EXT 0x807A
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_MATERIAL_SIDE_HINT_PGI 0x1A22C
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_SCALE_BY_TWO_NV 0x853E
#define GL_MATRIX10_ARB 0x88CA
#define GL_OP_EXP_BASE_2_EXT 0x8791
#define GL_LINES_ADJACENCY 0x000A
#define GL_OPERAND2_RGB_ARB 0x8592
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_CON_24_ATI 0x8959
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MODELVIEW27_ARB 0x873B
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_STATIC_READ 0x88E5
#define GL_VERTEX_ATTRIB_MAP2_APPLE 0x8A01
#define GL_TEXTURE_DEFORMATION_SGIX 0x8195
#define GL_SAMPLER_1D_ARB 0x8B5D
#define GL_IMAGE_BINDING_LEVEL_EXT 0x8F3B
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_BOOL_VEC3_ARB 0x8B58
#define GL_UNPACK_RESAMPLE_OML 0x8985
#define GL_CONVOLUTION_2D_EXT 0x8011
#define GL_MIN_SPARSE_LEVEL_AMD 0x919B
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_POINT_SIZE 0x0B11
#define GL_SHARED_TEXTURE_PALETTE_EXT 0x81FB
#define GL_ACTIVE_STENCIL_FACE_EXT 0x8911
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_HILO_NV 0x86F4
#define GL_RGB_FLOAT16_APPLE 0x881B
#define GL_VERTEX_STREAM5_ATI 0x8771
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_ASYNC_READ_PIXELS_SGIX 0x8361
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_DSDT8_MAG8_NV 0x870A
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV 0x9353
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_IMAGE_MAG_FILTER_HP 0x815C
#define GL_MODULATE_SUBTRACT_ATI 0x8746
#define GL_NOR 0x1508
#define GL_TEXTURE_LIGHTING_MODE_HP 0x8167
#define GL_DU8DV8_ATI 0x877A
#define GL_RGB_FLOAT32_APPLE 0x8815
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE 0x851F
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_RED_NV 0x1903
#define GL_PATH_STENCIL_FUNC_NV 0x90B7
#define GL_TEXTURE_INTENSITY_TYPE_ARB 0x8C15
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT 0x8022
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_MATRIX17_ARB 0x88D1
#define GL_2PASS_1_EXT 0x80A3
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_COLOR_INDEX4_EXT 0x80E4
#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_TEXTURE_STORAGE_HINT_APPLE 0x85BC
#define GL_SAMPLE_MASK_INVERT_SGIS 0x80AB
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_LUMINANCE_ALPHA32I_EXT 0x8D87
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_SOURCE3_ALPHA_NV 0x858B
#define GL_PROGRAM_LENGTH_ARB 0x8627
#define GL_COLOR_TABLE_BLUE_SIZE_SGI 0x80DC
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV 0x8C8A
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV 0x8855
#define GL_CONSTANT_COLOR_EXT 0x8001
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_STORAGE_CACHED_APPLE 0x85BE
#define GL_DST_ATOP_NV 0x928F
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_FLOAT16_NV 0x8FF8
#define GL_TEXTURE24_ARB 0x84D8
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL 0x83F7
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV 0x885D
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_INT_IMAGE_3D 0x9059
#define GL_RGB12_EXT 0x8053
#define GL_VERTEX_STREAM6_ATI 0x8772
#define GL_BLUE_INTEGER_EXT 0x8D96
#define GL_CONSTANT_ALPHA 0x8003
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_VERTEX_ARRAY_RANGE_VALID_NV 0x851F
#define GL_R16I 0x8233
#define GL_ASYNC_READ_PIXELS_SGIX 0x835E
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_CULL_VERTEX_EYE_POSITION_EXT 0x81AB
#define GL_MAX_TEXTURE_COORDS_ARB 0x8871
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 0x862E
#define GL_QUERY_ALL_EVENT_BITS_AMD 0xFFFFFFFF
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV 0x8C82
#define GL_MAX_IMAGE_SAMPLES_EXT 0x906D
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_OUTPUT_TEXTURE_COORD15_EXT 0x87AC
#define GL_CUBIC_CURVE_TO_NV 0x0C
#define GL_EYE_DISTANCE_TO_POINT_SGIS 0x81F0
#define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
#define GL_SRC_ATOP_NV 0x928E
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_INCR_WRAP 0x8507
#define GL_TEXTURE_2D_BINDING_EXT 0x8069
#define GL_INDEX_ARRAY_ADDRESS_NV 0x8F24
#define GL_SQUARE_NV 0x90A3
#define GL_LOCAL_CONSTANT_VALUE_EXT 0x87EC
#define GL_STORAGE_PRIVATE_APPLE 0x85BD
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX 0x85A1
#define GL_EVAL_VERTEX_ATTRIB12_NV 0x86D2
#define GL_DEPTH_CLAMP 0x864F
#define GL_LUMINANCE_ALPHA_INTEGER_EXT 0x8D9D
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT8_NV 0x8FE0
#define GL_TEXTURE28_ARB 0x84DC
#define GL_FRAGMENT_LIGHT6_SGIX 0x8412
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT 0x8C88
#define GL_DEBUG_CATEGORY_API_ERROR_AMD 0x9149
#define GL_INDEX_ARRAY_EXT 0x8077
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV 0x86DB
#define GL_FOG_OFFSET_SGIX 0x8198
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_PATH_STROKE_MASK_NV 0x9084
#define GL_NATIVE_GRAPHICS_HANDLE_PGI 0x1A202
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI 0x80B4
#define GL_UNSIGNED_BYTE_3_3_2_EXT 0x8032
#define GL_OPERAND0_ALPHA_ARB 0x8598
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX 0x00000002
#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_1D_BINDING_EXT 0x8068
#define GL_MATRIX7_ARB 0x88C7
#define GL_ZERO 0
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_READ_ONLY 0x88B8
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_RETAINED_APPLE 0x8A1B
#define GL_MULTIPLY_NV 0x9294
#define GL_INVARIANT_EXT 0x87C2
#define GL_FIXED 0x140C
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_TEXTURE_COORD_ARRAY_EXT 0x8078
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV 0x954E
#define GL_DIFFERENCE_KHR 0x929E
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_SIGNED_RGB_NV 0x86FE
#define GL_RGBA16_SNORM 0x8F9B
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_PROXY_TEXTURE_1D_EXT 0x8063
#define GL_MATRIX31_ARB 0x88DF
#define GL_MULTISAMPLES_NV 0x9371
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT 0x8DE0
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_LOW_FLOAT 0x8DF0
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_ALPHA_MIN_CLAMP_INGR 0x8563
#define GL_COMPILE_STATUS 0x8B81
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_ALPHA_FLOAT32_APPLE 0x8816
#define GL_VIEWPORT_SWIZZLE_Y_NV 0x9359
#define GL_DUAL_INTENSITY4_SGIS 0x8118
#define GL_GUILTY_CONTEXT_RESET 0x8253
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_UNSIGNED_BYTE 0x1401
#define GL_TESSELLATION_MODE_AMD 0x9004
#define GL_INT_SAMPLER_BUFFER_EXT 0x8DD0
#define GL_DECR_WRAP 0x8508
#define GL_STENCIL_SAMPLES_NV 0x932E
#define GL_R16 0x822A
#define GL_CONSERVATIVE_RASTERIZATION_NV 0x9346
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_TEXTURE_LOD_BIAS_T_SGIX 0x818F
#define GL_OUTPUT_FOG_EXT 0x87BD
#define GL_HISTOGRAM_ALPHA_SIZE_EXT 0x802B
#define GL_422_REV_AVERAGE_EXT 0x80CF
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_YCBCR_422_APPLE 0x85B9
#define GL_VERTEX_ATTRIB_ARRAY6_NV 0x8656
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS 0x8355
#define GL_UNIFORM_BUFFER_UNIFIED_NV 0x936E
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_STENCIL_INDEX16 0x8D49
#define GL_OUTPUT_TEXTURE_COORD21_EXT 0x87B2
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV 0x8642
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR 0x93BA
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV 0x9355
#define GL_MIRROR_CLAMP_TO_EDGE_ATI 0x8743
#define GL_RED_INTEGER_EXT 0x8D94
#define GL_BUMP_NUM_TEX_UNITS_ATI 0x8777
#define GL_COLOR_ATTACHMENT3_EXT 0x8CE3
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_INT_IMAGE_1D_ARRAY_EXT 0x905D
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_POINT_SIZE_MAX_ARB 0x8127
#define GL_MITER_REVERT_NV 0x90A7
#define GL_IMAGE_BINDING_FORMAT_EXT 0x906E
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT 0x8C2D
#define GL_LUMINANCE32I_EXT 0x8D86
#define GL_TRANSLATE_2D_NV 0x9090
#define GL_BLEND_ADVANCED_COHERENT_NV 0x9285
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT 0x8C3B
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV 0x9350
#define GL_OUTPUT_TEXTURE_COORD24_EXT 0x87B5
#define GL_RGB5_A1 0x8057
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_WEIGHT_ARRAY_STRIDE_ARB 0x86AA
#define GL_CURRENT_WEIGHT_ARB 0x86A8
#define GL_SHADOW_ATTENUATION_EXT 0x834E
#define GL_PATH_DASH_OFFSET_NV 0x907E
#define GL_HARDLIGHT_KHR 0x929B
#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_VERTEX_PROGRAM_ARB 0x8620
#define GL_INSTRUMENT_MEASUREMENTS_SGIX 0x8181
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB 0x933D
#define GL_MAP1_VERTEX_ATTRIB9_4_NV 0x8669
#define GL_PATH_PROJECTION_MATRIX_NV 0x0BA7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_AUX_DEPTH_STENCIL_APPLE 0x8A14
#define GL_CLAMP_READ_COLOR_ARB 0x891C
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV 0x8C85
#define GL_PROXY_HISTOGRAM_EXT 0x8025
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_REG_21_ATI 0x8936
#define GL_TRANSFORM_FEEDBACK_RECORD_NV 0x8C86
#define GL_MAT_DIFFUSE_BIT_PGI 0x00400000
#define GL_DOUBLE 0x140A
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_UNIFORM 0x92E1
#define GL_SAMPLER_2D_ARRAY_EXT 0x8DC1
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_MAX_TEXTURE_UNITS_ARB 0x84E2
#define GL_VARIABLE_C_NV 0x8525
#define GL_FONT_HAS_KERNING_BIT_NV 0x10000000
#define GL_REG_14_ATI 0x892F
#define GL_MAX_ACTIVE_LIGHTS_SGIX 0x8405
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_TEXCOORD3_BIT_PGI 0x40000000
#define GL_BLEND_DST_RGB_EXT 0x80C8
#define GL_INTENSITY16_SNORM 0x901B
#define GL_MATRIX24_ARB 0x88D8
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_REG_19_ATI 0x8934
#define GL_TEXTURE_1D 0x0DE0
#define GL_QUERY_WAIT 0x8E13
#define GL_PROGRAM_OBJECT_ARB 0x8B40
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_FRAGMENT_LIGHT1_SGIX 0x840D
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_SURFACE_REGISTERED_NV 0x86FD
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5C
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_BGRA 0x80E1
#define GL_RENDERBUFFER_WIDTH_EXT 0x8D42
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV 0x8F26
#define GL_TEXTURE_FREE_MEMORY_ATI 0x87FC
#define GL_POINT 0x1B00
#define GL_VERTEX4_BIT_PGI 0x00000008
#define GL_RENDERBUFFER_HEIGHT_EXT 0x8D43
#define GL_RGB16I_EXT 0x8D89
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_COMPRESSED_RGBA_FXT1_3DFX 0x86B1
#define GL_PLUS_NV 0x9291
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#define GL_TEXTURE_MAX_CLAMP_S_SGIX 0x8369
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_PALETTE4_R5_G6_B5_OES 0x8B92
#define GL_REPLACE_MIDDLE_SUN 0x0002
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_SCALED_RESOLVE_NICEST_EXT 0x90BB
#define GL_ALPHA_REF_COMMAND_NV 0x000F
#define GL_REFERENCE_PLANE_SGIX 0x817D
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_EXCLUSION_NV 0x92A0
#define GL_ELEMENT_ARRAY_TYPE_APPLE 0x8A0D
#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV 0x933E
#define GL_MUL_ATI 0x8964
#define GL_UNSIGNED_INT64_VEC2_NV 0x8FF5
#define GL_INTERPOLATE_EXT 0x8575
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8178
#define GL_HISTOGRAM_GREEN_SIZE_EXT 0x8029
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_FORMAT_SUBSAMPLE_24_24_OML 0x8982
#define GL_TEXTURE_RED_TYPE_ARB 0x8C10
#define GL_CLAMP_TO_EDGE_SGIS 0x812F
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX 0x8175
#define GL_IMAGE_2D_MULTISAMPLE_EXT 0x9055
#define GL_BLUE_MIN_CLAMP_INGR 0x8562
#define GL_PASS_THROUGH_NV 0x86E6
#define GL_LINE_STRIP_ADJACENCY_EXT 0x000B
#define GL_INT_SAMPLER_1D_ARRAY_EXT 0x8DCE
#define GL_STATIC_COPY 0x88E6
#define GL_FOG_COORD_ARRAY_ADDRESS_NV 0x8F28
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_SAMPLER_2D_SHADOW_ARB 0x8B62
#define GL_ELEMENT_ARRAY_TYPE_ATI 0x8769
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_DT_SCALE_NV 0x8711
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MATRIX15_ARB 0x88CF
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV 0x888D
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE23 0x84D7
#define GL_VARIANT_ARRAY_TYPE_EXT 0x87E7
#define GL_DEPTH_STENCIL_NV 0x84F9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_TERMINATE_SEQUENCE_COMMAND_NV 0x0000
#define GL_TEXTURE27 0x84DB
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_CON_15_ATI 0x8950
#define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV 0x0007
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_POLYGON_OFFSET_COMMAND_NV 0x000E
#define GL_BACK_LEFT 0x0402
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_MODELVIEW23_ARB 0x8737
#define GL_STENCIL_ATTACHMENT_EXT 0x8D20
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV 0x0004
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_ALWAYS_FAST_HINT_PGI 0x1A20C
#define GL_DOUBLE_MAT4x3 0x8F4E
#define GL_PROGRAM_STRING_ARB 0x8628
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_SRGB_READ 0x8297
#define GL_GLYPH_HEIGHT_BIT_NV 0x02
#define GL_TEXCOORD1_BIT_PGI 0x10000000
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD 0x9199
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF
#define GL_RELATIVE_MOVE_TO_NV 0x03
#define GL_INTERLEAVED_ATTRIBS_EXT 0x8C8C
#define GL_DST_OUT_NV 0x928D
#define GL_OUTPUT_TEXTURE_COORD10_EXT 0x87A7
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_FORMAT_SUBSAMPLE_244_244_OML 0x8983
#define GL_MODELVIEW18_ARB 0x8732
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_SAMPLE_LOCATION_NV 0x8E50
#define GL_QUAD_INTENSITY4_SGIS 0x8122
#define GL_PATH_MODELVIEW_NV 0x1700
#define GL_OP_LOG_BASE_2_EXT 0x8792
#define GL_REG_9_ATI 0x892A
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_TEXTURE_LIGHT_EXT 0x8350
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_SAMPLER_CUBE 0x8B60
#define GL_GLYPH_WIDTH_BIT_NV 0x01
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_INT_2_10_10_10_REV 0x8D9F
#define GL_TANGENT_ARRAY_STRIDE_EXT 0x843F
#define GL_FRAGMENT_LIGHT5_SGIX 0x8411
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_TEXCOORD4_BIT_PGI 0x80000000
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT 0x8C4C
#define GL_PROXY_TEXTURE_3D_EXT 0x8070
#define GL_MATRIX4_ARB 0x88C4
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AE
#define GL_INVERTED_SCREEN_W_REND 0x8491
#define GL_ALPHA8_SNORM 0x9014
#define GL_REG_6_ATI 0x8927
#define GL_ARRAY_BUFFER 0x8892
#define GL_PATH_CLIENT_LENGTH_NV 0x907F
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT 0x8DD7
#define GL_TEXTURE_ALPHA_TYPE_ARB 0x8C13
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_MATRIX14_ARB 0x88CE
#define GL_IMAGE_ROTATE_ORIGIN_X_HP 0x815A
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV 0x8640
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SPRITE_OBJECT_ALIGNED_SGIX 0x814D
#define GL_LARGE_CCW_ARC_TO_NV 0x16
#define GL_TEXTURE_COMPARE_SGIX 0x819A
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT 0x88F3
#define GL_RG32F 0x8230
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV 0x851E
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX 0x8143
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_MAP1_VERTEX_ATTRIB6_4_NV 0x8666
#define GL_RG32I 0x823B
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_TEXTURE_CONSTANT_DATA_SUNX 0x81D6
#define GL_TEXTURE_ALPHA_SIZE_EXT 0x805F
#define GL_TEXTURE_2D_STACK_BINDING_MESAX 0x875E
#define GL_LUMINANCE8_SNORM 0x9015
#define GL_RGBA8UI 0x8D7C
#define GL_STREAM_RASTERIZATION_AMD 0x91A0
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT 0x906B
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_OP_MAX_EXT 0x878A
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB 0x84E5
#define GL_PLUS_CLAMPED_NV 0x92B1
#define GL_HALF_FLOAT 0x140B
#define GL_RGBA_SNORM 0x8F93
#define GL_OPERAND1_RGB_ARB 0x8591
#define GL_NAND 0x150E
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS 0x8128
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_INTENSITY8I_EXT 0x8D91
#define GL_VERTEX_BLEND_ARB 0x86A7
#define GL_CONVOLUTION_1D_EXT 0x8010
#define GL_ASYNC_HISTOGRAM_SGIX 0x832C
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM 103083
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV 0x8C8F
#define GL_ALPHA 0x1906
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_MODELVIEW0_STACK_DEPTH_EXT 0x0BA3
#define GL_MAP2_VERTEX_ATTRIB10_4_NV 0x867A
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_CONVOLUTION_BORDER_COLOR_HP 0x8154
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_4PASS_0_SGIS 0x80A4
#define GL_TEXTURE_BLUE_TYPE_ARB 0x8C12
#define GL_REG_27_ATI 0x893C
#define GL_SRC1_COLOR 0x88F9
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COLOR_ARRAY_STRIDE_EXT 0x8083
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT 0x81AC
#define GL_SAMPLE_MASK_NV 0x8E51
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_EQUAL 0x0202
#define GL_MAX_CULL_DISTANCES 0x82F9
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_MAX_FOG_FUNC_POINTS_SGIS 0x812C
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B
#define GL_CUBIC_HP 0x815F
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX 0x8144
#define GL_MIRROR_CLAMP_TO_BORDER_EXT 0x8912
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_INT_SAMPLER_1D_EXT 0x8DC9
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
#define GL_ASYNC_TEX_IMAGE_SGIX 0x835C
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_BUFFER 0x82E0
#define GL_DOUBLE_MAT4_EXT 0x8F48
#define GL_COLOR 0x1800
#define GL_INTENSITY_FLOAT16_ATI 0x881D
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_DYNAMIC_READ 0x88E9
#define GL_RELATIVE_CONIC_CURVE_TO_NV 0x1B
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT 0x850F
#define GL_INDEX_ARRAY_LENGTH_NV 0x8F2E
#define GL_DUAL_ALPHA8_SGIS 0x8111
#define GL_SAMPLER_OBJECT_AMD 0x9155
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_REG_22_ATI 0x8937
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_TEXTURE_DT_SIZE_NV 0x871E
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT 0x8C1C
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE24 0x84D8
#define GL_DOUBLE_MAT2_EXT 0x8F46
#define GL_R8_SNORM 0x8F94
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE28 0x84DC
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_TEXTURE_1D_STACK_BINDING_MESAX 0x875D
#define GL_SYNC_X11_FENCE_EXT 0x90E1
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_BLEND_EQUATION_EXT 0x8009
#define GL_INVARIANT_VALUE_EXT 0x87EA
#define GL_FIXED_ONLY_ARB 0x891D
#define GL_FRAMEBUFFER_SRGB_EXT 0x8DB9
#define GL_MAX_CONVOLUTION_HEIGHT_EXT 0x801B
#define GL_DSDT8_NV 0x8709
#define GL_NEGATE_BIT_ATI 0x00000004
#define GL_INTENSITY32UI_EXT 0x8D73
#define GL_STRICT_SCISSOR_HINT_PGI 0x1A218
#define GL_PLUS_DARKER_NV 0x9292
#define GL_TEXTURE_2D_ARRAY_EXT 0x8C1A
#define GL_EDGE_FLAG_ARRAY_EXT 0x8079
#define GL_FRONT_AND_BACK 0x0408
#define GL_PALETTE4_RGBA4_OES 0x8B93
#define GL_BINORMAL_ARRAY_STRIDE_EXT 0x8441
#define GL_Z4Y12Z4CB12Z4CR12_444_NV 0x9037
#define GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX 0x9048
#define GL_TEXTURE_2D 0x0DE1
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_DOUBLE_MAT4x3_EXT 0x8F4E
#define GL_BUFFER_STORAGE_FLAGS 0x8220
#define GL_CON_12_ATI 0x894D
#define GL_TEXTURE_INTENSITY_SIZE_EXT 0x8061
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_CURRENT_TANGENT_EXT 0x843B
#define GL_BUFFER_MAPPED 0x88BC
#define GL_DEBUG_CATEGORY_PERFORMANCE_AMD 0x914D
#define GL_SHADER_OBJECT_EXT 0x8B48
#define GL_VERTEX_ATTRIB_ARRAY7_NV 0x8657
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_STREAM_DRAW 0x88E0
#define GL_ALPHA4_EXT 0x803B
#define GL_OBJECT_POINT_SGIS 0x81F5
#define GL_SAMPLE_PATTERN_SGIS 0x80AC
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_SIGNALED 0x9119
#define GL_BOOL_VEC4_ARB 0x8B59
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT 0x9067
#define GL_UNSIGNED_INT16_VEC4_NV 0x8FF3
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV 0x9343
#define GL_VERTEX_SHADER_VARIANTS_EXT 0x87D0
#define GL_RGB32I_EXT 0x8D83
#define GL_SAMPLER_BUFFER_AMD 0x9001
#define GL_POINT_SIZE_MIN_ARB 0x8126
#define GL_PROGRAM_PARAMETER_NV 0x8644
#define GL_OP_INDEX_EXT 0x8782
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_SECONDARY_INTERPOLATOR_ATI 0x896D
#define GL_OUTPUT_COLOR0_EXT 0x879B
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_LOCATION_INDEX 0x930F
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL 0x83F8
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE 0x851E
#define GL_DRAW_BUFFER14_ATI 0x8833
#define GL_REG_24_ATI 0x8939
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_TRANSFORM_FEEDBACK_NV 0x8E22
#define GL_REG_7_ATI 0x8928
#define GL_UNSIGNED_INT16_VEC2_NV 0x8FF1
#define GL_EVAL_VERTEX_ATTRIB14_NV 0x86D4
#define GL_CONVOLUTION_FORMAT_EXT 0x8017
#define GL_OP_MOV_EXT 0x8799
#define GL_FIELD_UPPER_NV 0x9022
#define GL_STATIC_READ_ARB 0x88E5
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV 0x902D
#define GL_MATRIX1_NV 0x8631
#define GL_OFFSET_TEXTURE_2D_SCALE_NV 0x86E2
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_VERTEX_ARRAY_RANGE_NV 0x851D
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
#define GL_STENCIL_INDEX4_EXT 0x8D47
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_INDEX_ARRAY_STRIDE_EXT 0x8086
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_RED_BIT_ATI 0x00000001
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT 0x8DC3
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_QUARTER_BIT_ATI 0x00000010
#define GL_TEXTURE5_ARB 0x84C5
#define GL_VERTEX_ATTRIB_ARRAY15_NV 0x865F
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT 0x8C70
#define GL_VARIABLE_A_NV 0x8523
#define GL_LESS 0x0201
#define GL_VERTEX_ATTRIB_ARRAY13_NV 0x865D
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87D2
#define GL_RGB_RAW_422_APPLE 0x8A51
#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV 0x8E5D
#define GL_OP_CROSS_PRODUCT_EXT 0x8797
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8174
#define GL_PHONG_WIN 0x80EA
#define GL_COMBINE4_NV 0x8503
#define GL_VERTEX_SHADER_INVOCATIONS_ARB 0x82F0
#define GL_MAX_DRAW_BUFFERS_ARB 0x8824
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV 0x8F45
#define GL_PACK_SKIP_VOLUMES_SGIS 0x8130
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148
#define GL_STENCIL_INDEX16_EXT 0x8D49
#define GL_LAYOUT_LINEAR_INTEL 1
#define GL_INT64_VEC4_NV 0x8FEB
#define GL_MAP2_VERTEX_ATTRIB11_4_NV 0x867B
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_VALIDATE_STATUS 0x8B83
#define GL_RG16 0x822C
#define GL_OP_ROUND_EXT 0x8790
#define GL_UNIFORM_ADDRESS_COMMAND_NV 0x000A
#define GL_RGB_SCALE_ARB 0x8573
#define GL_PIXEL_MAG_FILTER_EXT 0x8331
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_OVERLAY_NV 0x9296
#define GL_INDEX_TEST_FUNC_EXT 0x81B6
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB 0x851B
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_NORMAL_ARRAY_POINTER_EXT 0x808F
#define GL_READ_FRAMEBUFFER_BINDING_EXT 0x8CAA
#define GL_LOCAL_EXT 0x87C4
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE 0x8A08
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT 0x8DD3
#define GL_MAP1_VERTEX_ATTRIB12_4_NV 0x866C
#define GL_LINES 0x0001
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_MODELVIEW11_ARB 0x872B
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX 0x835F
#define GL_RGB 0x1907
#define GL_MAP2_VERTEX_ATTRIB7_4_NV 0x8677
#define GL_TEXTURE_BASE_LEVEL_SGIS 0x813C
#define GL_TEXTURE_DS_SIZE_NV 0x871D
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT 0x8023
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_DEPTH_STENCIL_TO_BGRA_NV 0x886F
#define GL_CONFORMANT_NV 0x9374
#define GL_RGBA32F 0x8814
#define GL_RGBA32I 0x8D82
#define GL_HSL_COLOR_NV 0x92AF
#define GL_INDEX_MATERIAL_EXT 0x81B8
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_RG8 0x822B
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT 0x8338
#define GL_PACK_RESAMPLE_OML 0x8984
#define GL_VERTEX_ATTRIB_ARRAY8_NV 0x8658
#define GL_PN_TRIANGLES_POINT_MODE_ATI 0x87F2
#define GL_SRC_OVER_NV 0x9288
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_MODELVIEW0_ARB 0x1700
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PARAMETER_BUFFER_BINDING_ARB 0x80EF
#define GL_STENCIL_BACK_OP_VALUE_AMD 0x874D
#define GL_PARTIAL_SUCCESS_NV 0x902E
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV 0x8E53
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_3D 0x806F
#define GL_VIDEO_BUFFER_BINDING_NV 0x9021
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV 0x902A
#define GL_COMBINER_SCALE_NV 0x8548
#define GL_PIXEL_TEX_GEN_SGIX 0x8139
#define GL_CON_11_ATI 0x894C
#define GL_SIGNED_INTENSITY8_NV 0x8708
#define GL_MIN_EXT 0x8007
#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV 0x888F
#define GL_MAX_CONVOLUTION_WIDTH_EXT 0x801A
#define GL_TEXTURE_LO_SIZE_NV 0x871C
#define GL_MODELVIEW16_ARB 0x8730
#define GL_TRANSFORM_HINT_APPLE 0x85B1
#define GL_TEXTURE_MAG_SIZE_NV 0x871F
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_TEXTURE_STORAGE_SPARSE_BIT_AMD 0x00000001
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_CLIP_ORIGIN 0x935C
#define GL_PROXY_TEXTURE_RECTANGLE_NV 0x84F7
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_OBJECT_TYPE 0x9112
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_BACK_PRIMARY_COLOR_NV 0x8C77
#define GL_SYSTEM_FONT_NAME_NV 0x9073
#define GL_RED_SNORM 0x8F90
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_ARRAY_OBJECT_OFFSET_ATI 0x8767
#define GL_CLIP_DEPTH_MODE 0x935D
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_CLIP_DISTANCE6 0x3006
#define GL_DUAL_INTENSITY8_SGIS 0x8119
#define GL_BGR_EXT 0x80E0
#define GL_DEPTH_COMPONENT16_SGIX 0x81A5
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV 0x8905
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_SAMPLE_LOCATION_ARB 0x8E50
#define GL_INDEX_ARRAY_POINTER_EXT 0x8091
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD 0x9160
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_TEXTURE_1D_ARRAY_EXT 0x8C18
#define GL_PERFQUERY_COUNTER_RAW_INTEL 0x94F4
#define GL_MAX_GENERAL_COMBINERS_NV 0x854D
#define GL_MAJOR_VERSION 0x821B
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV 0x8C8E
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
#define GL_VERTEX_SHADER_OPTIMIZED_EXT 0x87D4
#define GL_MAX_VIEWS_OVR 0x9631
#define GL_TEXTURE10_ARB 0x84CA
#define GL_UTF8_NV 0x909A
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_COLOR_ARRAY_LENGTH_NV 0x8F2D
#define GL_MITER_TRUNCATE_NV 0x90A8
#define GL_NORMAL_ARRAY_EXT 0x8075
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_DRAW_BUFFER15_ARB 0x8834
#define GL_MODELVIEW26_ARB 0x873A
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_OUTPUT_TEXTURE_COORD1_EXT 0x879E
#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
#define GL_COLOR_ARRAY_ADDRESS_NV 0x8F23
#define GL_WIDE_LINE_HINT_PGI 0x1A222
#define GL_MINMAX_EXT 0x802E
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV 0x9036
#define GL_POINT_SIZE_MIN_EXT 0x8126
#define GL_PACK_CMYK_HINT_EXT 0x800E
#define GL_UNPACK_CLIENT_STORAGE_APPLE 0x85B2
#define GL_TEXTURE_STENCIL_SIZE_EXT 0x88F1
#define GL_ATTENUATION_EXT 0x834D
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV 0x903C
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV 0x8909
#define GL_MODELVIEW25_ARB 0x8739
#define GL_REG_26_ATI 0x893B
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV 0x8DA6
#define GL_OUTPUT_TEXTURE_COORD6_EXT 0x87A3
#define GL_POLYGON_OFFSET_BIAS_EXT 0x8039
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_DECODE_EXT 0x8A49
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8852
#define GL_FENCE_STATUS_NV 0x84F3
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT 0x00000100
#define GL_HALF_BIAS_NEGATE_NV 0x853B
#define GL_SIGNED_LUMINANCE_ALPHA_NV 0x8703
#define GL_COLOR_ARRAY_COUNT_EXT 0x8084
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_BLUE_NV 0x1905
#define GL_GEOMETRY_SHADER_EXT 0x8DD9
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_HALF_FLOAT_NV 0x140B
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_REPLACE_VALUE_AMD 0x874B
#define GL_HALF_BIAS_NORMAL_NV 0x853A
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_INTENSITY_SNORM 0x9013
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_CON_5_ATI 0x8946
#define GL_BLEND_PREMULTIPLIED_SRC_NV 0x9280
#define GL_RGB_INTEGER 0x8D98
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_DOT3_RGB_ARB 0x86AE
#define GL_SMALL_CW_ARC_TO_NV 0x14
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_VIBRANCE_SCALE_NV 0x8713
#define GL_NEGATIVE_Z_EXT 0x87DB
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT 0x8C8A
#define GL_CLOSE_PATH_NV 0x00
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_DSDT_MAG_INTENSITY_NV 0x86DC
#define GL_MAX_IMAGE_UNITS_EXT 0x8F38
#define GL_ALPHA8_EXT 0x803C
#define GL_STREAM_DRAW_ARB 0x88E0
#define GL_ROUND_NV 0x90A4
#define GL_DEPTH_TEXTURE_MODE_ARB 0x884B
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_LINE_WIDTH_COMMAND_NV 0x000D
#define GL_ATTRIB_ARRAY_TYPE_NV 0x8625
#define GL_DRAW_BUFFER7_ARB 0x882C
#define GL_VERTEX_ARRAY_COUNT_EXT 0x807D
#define GL_BLEND_SRC 0x0BE1
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255
#define GL_IMAGE_TRANSFORM_2D_HP 0x8161
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_PALETTE8_RGBA4_OES 0x8B98
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_SAMPLE_BUFFERS_ARB 0x80A8
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT 0x8DD6
#define GL_UNSIGNED_INT8_VEC3_NV 0x8FEE
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
#define GL_TEXTURE16_ARB 0x84D0
#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX 0x813E
#define GL_ANY_SAMPLES_PASSED 0x8C2F
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB 0x8B89
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM 103084
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_LUMINANCE_ARB 0x84EA
#define GL_MAP_WRITE_BIT 0x0002
#define GL_GENERATE_MIPMAP_HINT_SGIS 0x8192
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_ALL_STATIC_DATA_IBM 103060
#define GL_RGBA16F_ARB 0x881A
#define GL_VERTEX_ATTRIB_ARRAY14_NV 0x865E
#define GL_NORMAL_MAP_EXT 0x8511
#define GL_ALPHA16_SNORM 0x9018
#define GL_REPLICATE_BORDER_HP 0x8153
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV 0x8C7F
#define GL_LINEAR_DETAIL_ALPHA_SGIS 0x8098
#define GL_MINUS_NV 0x929F
#define GL_BGRA_INTEGER_EXT 0x8D9B
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_STREAM_READ 0x88E1
#define GL_LINEAR 0x2601
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_COLOR_FLOAT_APPLE 0x8A0F
#define GL_STRICT_DEPTHFUNC_HINT_PGI 0x1A216
#define GL_STENCIL_INDEX 0x1901
#define GL_TEXTURE_GREEN_SIZE_EXT 0x805D
#define GL_SEPARATE_ATTRIBS_NV 0x8C8D
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_GREATER 0x0204
#define GL_IUI_N3F_V3F_EXT 0x81B0
#define GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16
#define GL_BLOCK_INDEX 0x92FD
#define GL_PIXEL_SUBSAMPLE_4444_SGIX 0x85A2
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_LUMINANCE_ALPHA32F_ARB 0x8819
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_FRONT_FACE 0x0B46
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI 0x80B9
#define GL_RESAMPLE_ZERO_FILL_SGIX 0x8434
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_UNSIGNED_INT16_VEC3_NV 0x8FF2
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_HSL_COLOR_KHR 0x92AF
#define GL_VERTEX_TEXTURE 0x829B
#define GL_MULTIPLY_KHR 0x9294
#define GL_VERTEX_STREAM3_ATI 0x876F
#define GL_VERTEX_ARRAY_EXT 0x8074
#define GL_TANGENT_ARRAY_TYPE_EXT 0x843E
#define GL_IS_ROW_MAJOR 0x9300
#define GL_OUTPUT_TEXTURE_COORD8_EXT 0x87A5
#define GL_POINT_SIZE_MIN_SGIS 0x8126
#define GL_SAMPLER_1D_SHADOW_ARB 0x8B61
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_CLEAR_TEXTURE 0x9365
#define GL_COLOR_ARRAY_TYPE_EXT 0x8082
#define GL_POST_CONVOLUTION_RED_SCALE_EXT 0x801C
#define GL_REGISTER_COMBINERS_NV 0x8522
#define GL_R16UI 0x8234
#define GL_POINT_SPRITE_NV 0x8861
#define GL_POLYGON_OFFSET_EXT 0x8037
#define GL_MIN 0x8007
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT 0x87C9
#define GL_FUNC_SUBTRACT_EXT 0x800A
#define GL_PLUS_CLAMPED_ALPHA_NV 0x92B2
#define GL_DRAW_BUFFER1_ATI 0x8826
#define GL_TIMESTAMP 0x8E28
#define GL_ACTIVE_VARYINGS_NV 0x8C81
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_BLUE_BIT_ATI 0x00000004
#define GL_MAP2_VERTEX_ATTRIB2_4_NV 0x8672
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB 0x9343
#define GL_SLICE_ACCUM_SUN 0x85CC
#define GL_MAX_DRAW_BUFFERS_ATI 0x8824
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_RGBA_FLOAT16_ATI 0x881A
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#define GL_FLOAT_VEC2_ARB 0x8B50
#define GL_NORMALIZED_RANGE_EXT 0x87E0
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV 0x8C84
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_MULTISAMPLE_BIT_EXT 0x20000000
#define GL_MODELVIEW14_ARB 0x872E
#define GL_ELEMENT_ADDRESS_COMMAND_NV 0x0008
#define GL_OPERAND1_ALPHA_ARB 0x8599
#define GL_FIRST_VERTEX_CONVENTION_EXT 0x8E4D
#define GL_TEXTURE3_ARB 0x84C3
#define GL_BOOL_VEC3 0x8B58
#define GL_TESS_CONTROL_PROGRAM_NV 0x891E
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D5
#define GL_HISTOGRAM_WIDTH_EXT 0x8026
#define GL_SOURCE0_RGB_ARB 0x8580
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT 0x8C84
#define GL_MODELVIEW10_ARB 0x872A
#define GL_MAP1_VERTEX_ATTRIB7_4_NV 0x8667
#define GL_ALPHA_MIN_SGIX 0x8320
#define GL_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_PACK_SUBSAMPLE_RATE_SGIX 0x85A0
#define GL_REG_12_ATI 0x892D
#define GL_LUMINANCE16I_EXT 0x8D8C
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI 0x80DF
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB 0x8807
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
#define GL_MAP2_VERTEX_ATTRIB0_4_NV 0x8670
#define GL_OUTPUT_TEXTURE_COORD25_EXT 0x87B6
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR 0x00000008
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_RGBA16F 0x881A
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_INCR_WRAP_EXT 0x8507
#define GL_RED 0x1903
#define GL_RGB16_EXT 0x8054
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261
#define GL_NEGATIVE_Y_EXT 0x87DA
#define GL_BLEND_OVERLAP_NV 0x9281
#define GL_MAGNITUDE_SCALE_NV 0x8712
#define GL_BACK_SECONDARY_COLOR_NV 0x8C78
#define GL_PROXY_TEXTURE_1D_STACK_MESAX 0x875B
#define GL_VERTEX_DATA_HINT_PGI 0x1A22A
#define GL_INT_IMAGE_2D 0x9058
#define GL_SAMPLER_2D_RECT_ARB 0x8B63
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_TRANSPOSE_AFFINE_2D_NV 0x9096
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_COUNT_UP_NV 0x9088
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_MAP1_BINORMAL_EXT 0x8446
#define GL_VERTEX_STREAM4_ATI 0x8770
#define GL_VERTEX_ELEMENT_SWIZZLE_AMD 0x91A4
#define GL_INT16_VEC4_NV 0x8FE7
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_SPRITE_AXIAL_SGIX 0x814C
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_LEQUAL_R_SGIX 0x819C
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB 0x88A1
#define GL_LINEAR_SHARPEN_SGIS 0x80AD
#define GL_UNSIGNED_INT 0x1405
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_BLEND_ADVANCED_COHERENT_KHR 0x9285
#define GL_REFLECTION_MAP_EXT 0x8512
#define GL_INT_SAMPLER_2D_RECT_EXT 0x8DCD
#define GL_BOOL_VEC2 0x8B57
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_HISTOGRAM_RED_SIZE_EXT 0x8028
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_HORIZONTAL_LINE_TO_NV 0x06
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT 0x8352
#define GL_EYE_DISTANCE_TO_LINE_SGIS 0x81F2
#define GL_INDEX_ARRAY_LIST_IBM 103073
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT 0x8C76
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_NUM_SAMPLE_COUNTS 0x9380
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI 0x80BB
#define GL_MAX_TEXTURE_COORDS_NV 0x8871
#define GL_MATRIX18_ARB 0x88D2
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_RGB8UI_EXT 0x8D7D
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_REG_0_ATI 0x8921
#define GL_READ_PIXELS_TYPE 0x828E
#define GL_SAMPLER_CUBE_SHADOW_EXT 0x8DC5
#define GL_VIBRANCE_BIAS_NV 0x8719
#define GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE 0x8A05
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_STORAGE_SHARED_APPLE 0x85BF
#define GL_SOURCE1_RGB_ARB 0x8581
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_MIRROR_CLAMP_ATI 0x8742
#define GL_VERTEX23_BIT_PGI 0x00000004
#define GL_INT_SAMPLER_2D_ARRAY_EXT 0x8DCF
#define GL_MAP1_VERTEX_ATTRIB15_4_NV 0x866F
#define GL_TEXTURE11_ARB 0x84CB
#define GL_PURGED_CONTEXT_RESET_NV 0x92BB
#define GL_BUFFER_ACCESS_ARB 0x88BB
#define GL_OFFSET_TEXTURE_RECTANGLE_NV 0x864C
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_DRAW_BUFFER8_ATI 0x882D
#define GL_INT16_VEC2_NV 0x8FE5
#define GL_SAMPLE_MASK_VALUE_SGIS 0x80AA
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB 0x933F
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_LUMINANCE_ALPHA_SNORM 0x9012
#define GL_VARIANT_ARRAY_STRIDE_EXT 0x87E6
#define GL_LERP_ATI 0x8969
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_RIGHT 0x0407
#define GL_INT_SAMPLER_RENDERBUFFER_NV 0x8E57
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV 0x937A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_PRESENT_TIME_NV 0x8E2A
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV 0x00080000
#define GL_READ_ONLY_ARB 0x88B8
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_CONSTANT_COLOR 0x8001
#define GL_DRAW_BUFFER4_ARB 0x8829
#define GL_TEXTURE2_ARB 0x84C2
#define GL_COMPRESSED_RG 0x8226
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_GEOMETRY_VERTICES_OUT_EXT 0x8DDA
#define GL_CONSTANT_ARB 0x8576
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_SAMPLE_MASK_INVERT_EXT 0x80AB
#define GL_TEXTURE_LOD_BIAS_R_SGIX 0x8190
#define GL_COMPRESSED_INTENSITY_ARB 0x84EC
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_EVAL_2D_NV 0x86C0
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_COLOR_INDEX1_EXT 0x80E2
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB 0x8625
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_CON_19_ATI 0x8954
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_TEXTURE_CUBE_MAP_EXT 0x8513
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_MAP2_VERTEX_ATTRIB12_4_NV 0x867C
#define GL_FACTOR_MAX_AMD 0x901D
#define GL_LUMINANCE4_EXT 0x803F
#define GL_UNPACK_CONSTANT_DATA_SUNX 0x81D5
#define GL_COLOR_COMPONENTS 0x8283
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR 0x93B8
#define GL_UNSIGNED_INT8_VEC2_NV 0x8FED
#define GL_UNSIGNED_INT64_NV 0x140F
#define GL_W_EXT 0x87D8
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_DECR 0x1E03
#define GL_PATH_TERMINAL_DASH_CAP_NV 0x907D
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_UNIFORM_BUFFER_EXT 0x8DEE
#define GL_BACK 0x0405
#define GL_DSDT_MAG_NV 0x86F6
#define GL_NEGATIVE_ONE_EXT 0x87DF
#define GL_SCREEN_NV 0x9295
#define GL_TRIANGLE_FAN 0x0006
#define GL_NORMAL_BIT_PGI 0x08000000
#define GL_TEXTURE_MAX_CLAMP_R_SGIX 0x836B
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX 0x8401
#define GL_QUERY_DEPTH_BOUNDS_FAIL_EVENT_BIT_AMD 0x00000008
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_TEXTURE_LOD_BIAS_EXT 0x84FD
#define GL_FENCE_APPLE 0x8A0B
#define GL_FRAME_NV 0x8E26
#define GL_PALETTE4_RGBA8_OES 0x8B91
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB 0x9341
#define GL_MODELVIEW2_ARB 0x8722
#define GL_MAP2_VERTEX_ATTRIB5_4_NV 0x8675
#define GL_MIPMAP 0x8293
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV 0x8C88
#define GL_RGBA2_EXT 0x8055
#define GL_DOT3_RGBA_EXT 0x8741
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_POINT_SPRITE_R_MODE_NV 0x8863
#define GL_YCBYCR8_422_NV 0x9031
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CURRENT_MATRIX_INDEX_ARB 0x8845
#define GL_MOVE_TO_RESETS_NV 0x90B5
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT 0x9065
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX 0x812E
#define GL_DEBUG_SEVERITY_LOW_AMD 0x9148
#define GL_MINOR_VERSION 0x821C
#define GL_CURRENT_PALETTE_MATRIX_ARB 0x8843
#define GL_SAMPLE_MASK 0x8E51
#define GL_EDGE_FLAG_ARRAY_LIST_IBM 103075
#define GL_STENCIL_REF_COMMAND_NV 0x000C
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX 0x817A
#define GL_IR_INSTRUMENT1_SGIX 0x817F
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_IMAGE_TRANSLATE_Y_HP 0x8158
#define GL_SAMPLES_ARB 0x80A9
#define GL_TRANSLATE_X_NV 0x908E
#define GL_CLIP_NEAR_HINT_PGI 0x1A220
#define GL_REG_15_ATI 0x8930
#define GL_PREVIOUS_ARB 0x8578
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_INT8_VEC3_NV 0x8FE2
#define GL_PATH_STROKE_WIDTH_NV 0x9075
#define GL_SURFACE_STATE_NV 0x86EB
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9056
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_TRANSPOSE_AFFINE_3D_NV 0x9098
#define GL_MAX_VERTEX_ATTRIBS_ARB 0x8869
#define GL_RGBA8 0x8058
#define GL_R1UI_T2F_V3F_SUN 0x85C9
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT 0x8DBE
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT 0x8C72
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI 0x881F
#define GL_SRGB8 0x8C41
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_SRGB_ALPHA_EXT 0x8C42
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_FIELDS_NV 0x8E27
#define GL_DUAL_INTENSITY16_SGIS 0x811B
#define GL_SRGB_DECODE_ARB 0x8299
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV 0x9348
#define GL_QUERY_OBJECT_AMD 0x9153
#define GL_ALPHA_INTEGER_EXT 0x8D97
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM 103080
#define GL_MIN_PROGRAM_TEXEL_OFFSET_EXT 0x8904
#define GL_NUM_PASSES_ATI 0x8970
#define GL_TEXTURE20_ARB 0x84D4
#define GL_OP_NEGATE_EXT 0x8783
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_MODELVIEW9_ARB 0x8729
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS 0x81EF
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_RGB_S3TC 0x83A0
#define GL_SAMPLE_SHADING_ARB 0x8C36
#define GL_QUERY_DEPTH_PASS_EVENT_BIT_AMD 0x00000001
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB 0x8128
#define GL_PROGRAM_FORMAT_ASCII_ARB 0x8875
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT 0x87CE
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_PATH_INITIAL_END_CAP_NV 0x9077
#define GL_MAX_CLIPMAP_DEPTH_SGIX 0x8177
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM 103077
#define GL_COMPRESSED_RGB_FXT1_3DFX 0x86B0
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV 0x17
#define GL_MAP2_VERTEX_ATTRIB14_4_NV 0x867E
#define GL_BUFFER_BINDING 0x9302
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_SUPERSAMPLE_SCALE_X_NV 0x9372
#define GL_MATRIX_STRIDE 0x92FF
#define GL_COMP_BIT_ATI 0x00000002
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8857
#define GL_DEPTH_COMPONENT32_SGIX 0x81A7
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV 0x9029
#define GL_FLOAT_MAT2_ARB 0x8B5A
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5
#define GL_UNSIGNED_INT64_AMD 0x8BC2
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_LAYER_NV 0x8DAA
#define GL_FOG_COORD_ARRAY_LENGTH_NV 0x8F32
#define GL_RGB10_A2 0x8059
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_NUM_SPARSE_LEVELS_ARB 0x91AA
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_RASTER_POSITION_UNCLIPPED_IBM 0x19262
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_CONSTANT_BORDER_HP 0x8151
#define GL_DEPTH_COMPONENT32_ARB 0x81A7
#define GL_EVAL_TRIANGULAR_2D_NV 0x86C1
#define GL_MAX_MAP_TESSELLATION_NV 0x86D6
#define GL_SOURCE2_ALPHA_ARB 0x858A
#define GL_COLOR_TABLE_GREEN_SIZE_SGI 0x80DB
#define GL_COMPRESSED_ALPHA_ARB 0x84E9
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV 0x9026
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_OUTPUT_TEXTURE_COORD3_EXT 0x87A0
#define GL_TEXTURE16 0x84D0
#define GL_CURRENT_ATTRIB_NV 0x8626
#define GL_SIGNED_INTENSITY_NV 0x8707
#define GL_IMAGE_MIN_FILTER_HP 0x815D
#define GL_VERTEX_ATTRIB_MAP1_APPLE 0x8A00
#define GL_NORMAL_ARRAY_ADDRESS_NV 0x8F22
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_TEXTURE_FLOAT_COMPONENTS_NV 0x888C
#define GL_FRAGMENT_SHADER_ARB 0x8B30
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS 0x81F3
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_FLOAT16_MAT2_AMD 0x91C5
#define GL_FONT_GLYPHS_AVAILABLE_NV 0x9368
#define GL_SHORT 0x1402
#define GL_WARPS_PER_SM_NV 0x933A
#define GL_PERFMON_RESULT_AVAILABLE_AMD 0x8BC4
#define GL_LINEAR_DETAIL_COLOR_SGIS 0x8099
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS 0x809E
#define GL_IMAGE_1D_ARRAY_EXT 0x9052
#define GL_COMBINER_CD_OUTPUT_NV 0x854B
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_RENDERBUFFER 0x8D41
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_SHADER_COMPILER 0x8DFA
#define GL_VBO_FREE_MEMORY_ATI 0x87FB
#define GL_INDEX_ARRAY_TYPE_EXT 0x8085
#define GL_4PASS_3_EXT 0x80A7
#define GL_OUTPUT_TEXTURE_COORD0_EXT 0x879D
#define GL_VERTICES_SUBMITTED_ARB 0x82EE
#define GL_TEXTURE_CUBE_MAP_ARB 0x8513
#define GL_FOG_FUNC_POINTS_SGIS 0x812B
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_RASTER_SAMPLES_EXT 0x9328
#define GL_BUFFER_USAGE_ARB 0x8765
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#define GL_TEXTURE9_ARB 0x84C9
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX 0x840B
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV 0x8704
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_LIST_PRIORITY_SGIX 0x8182
#define GL_SAMPLE_COVERAGE_ARB 0x80A0
#define GL_CONTEXT_ROBUST_ACCESS 0x90F3
#define GL_PATH_MODELVIEW_MATRIX_NV 0x0BA6
#define GL_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_INTENSITY_FLOAT32_APPLE 0x8817
#define GL_CLIP_DISTANCE1 0x3001
#define GL_RGBA16UI_EXT 0x8D76
#define GL_REG_11_ATI 0x892C
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV 0x9347
#define GL_REG_1_ATI 0x8922
#define GL_ELEMENT_ARRAY_POINTER_ATI 0x876A
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_4PASS_0_EXT 0x80A4
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_QUERY_NO_WAIT_NV 0x8E14
#define GL_GREEN_INTEGER_EXT 0x8D95
#define GL_INDEX_TEST_EXT 0x81B5
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB 0x8847
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_PIXEL_COUNTER_BITS_NV 0x8864
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI 0x87F5
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR 0x93B0
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_VERTEX_PRECLIP_HINT_SGIX 0x83EF
#define GL_CONTEXT_PROFILE_MASK 0x9126
#define GL_MOVE_TO_NV 0x02
#define GL_INT16_VEC3_NV 0x8FE6
#define GL_BLEND_EQUATION_ALPHA_EXT 0x883D
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA
#define GL_COLOR_ARRAY_POINTER_EXT 0x8090
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB 0x9197
#define GL_OUTPUT_VERTEX_EXT 0x879A
#define GL_TRIANGLE_STRIP 0x0005
#define GL_INT64_VEC4_ARB 0x8FEB
#define GL_FRONT_LEFT 0x0400
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV 0x15
#define GL_PERCENTAGE_AMD 0x8BC3
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_SIGNED_ALPHA8_NV 0x8706
#define GL_LINEAR_SHARPEN_ALPHA_SGIS 0x80AE
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV 0x92DD
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_STENCIL_FUNC 0x0B92
#define GL_DRAW_BUFFER8_ARB 0x882D
#define GL_INVERT 0x150A
#define GL_LUMINANCE8UI_EXT 0x8D80
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_INT 0x1404
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB 0x8849
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#define GL_AFFINE_2D_NV 0x9092
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV 0x9342
#define GL_WARP_SIZE_NV 0x9339
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_BGR_INTEGER 0x8D9A
#define GL_EXPAND_NEGATE_NV 0x8539
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT 0x8088
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_SYNC_FENCE 0x9116
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT 0x850E
#define GL_RGB8_SNORM 0x8F96
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_HIGH_FLOAT 0x8DF2
#define GL_OFFSET_TEXTURE_BIAS_NV 0x86E3
#define GL_LO_BIAS_NV 0x8715
#define GL_EVAL_VERTEX_ATTRIB8_NV 0x86CE
#define GL_COLORBURN_KHR 0x929A
#define GL_CON_4_ATI 0x8945
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV 0x9035
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX 0x813F
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT 0x87CB
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE 0x85B0
#define GL_DISJOINT_NV 0x9283
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV 0x8C75
#define GL_IS_PER_PATCH 0x92E7
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_LUMINANCE32UI_EXT 0x8D74
#define GL_CONVOLUTION_HEIGHT_EXT 0x8019
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_TYPE 0x8A37
#define GL_RENDERBUFFER_RED_SIZE_EXT 0x8D50
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_COLOR_ATTACHMENT13_EXT 0x8CED
#define GL_LUMINANCE8_ALPHA8_SNORM 0x9016
#define GL_EIGHTH_BIT_ATI 0x00000020
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_GLOBAL_ALPHA_SUN 0x81D9
#define GL_FRONT_RIGHT 0x0401
#define GL_PROGRAM_ERROR_STRING_NV 0x8874
#define GL_DEPTH_TEST 0x0B71
#define GL_OPERAND3_ALPHA_NV 0x859B
#define GL_PIXEL_TEX_GEN_MODE_SGIX 0x832B
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
#define GL_INT8_VEC2_NV 0x8FE1
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV 0x903A
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_DEPTH_RANGE 0x0B70
#define GL_FRAGMENT_LIGHT4_SGIX 0x8410
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV 0x9341
#define GL_NEAREST 0x2600
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS 0x811C
#define GL_MAX_RENDERBUFFER_SIZE_EXT 0x84E8
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
#define GL_SPRITE_SGIX 0x8148
#define GL_RESTART_PATH_NV 0xF0
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV 0x8E58
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_SWIZZLE_STRQ_ATI 0x897A
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_UNSIGNED_INT_10_10_10_2_EXT 0x8036
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT 0x8DD8
#define GL_OP_MULTIPLY_MATRIX_EXT 0x8798
#define GL_SRC_ALPHA 0x0302
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_VERTEX_PRECLIP_SGIX 0x83EE
#define GL_BLEND_COLOR_EXT 0x8005
#define GL_SIGNED_LUMINANCE_NV 0x8701
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_BEVEL_NV 0x90A6
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_UNDEFINED_APPLE 0x8A1C
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX 0x818D
#define GL_TEXTURE19_ARB 0x84D3
#define GL_CONTRAST_NV 0x92A1
#define GL_LINEAR_CLIPMAP_LINEAR_SGIX 0x8170
#define GL_YCRCBA_SGIX 0x8319
#define GL_INVALID_VALUE 0x0501
#define GL_EVAL_VERTEX_ATTRIB1_NV 0x86C7
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_COMPRESSED_SLUMINANCE_EXT 0x8C4A
#define GL_ELEMENT_ARRAY_BUFFER_ARB 0x8893
#define GL_FLOAT_VEC3_ARB 0x8B51
#define GL_FONT_DESCENDER_BIT_NV 0x00400000
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT 0x8C8B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV 0x870C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_MATRIX3_ARB 0x88C3
#define GL_COLORDODGE_KHR 0x9299
#define GL_CONSTANT_ALPHA_EXT 0x8003
#define GL_INTENSITY_FLOAT32_ATI 0x8817
#define GL_AND_INVERTED 0x1504
#define GL_FRAMEBUFFER_SRGB 0x8DB9
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_INTENSITY32I_EXT 0x8D85
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_TEXTURE_GATHER 0x82A2
#define GL_LUMINANCE12_EXT 0x8041
#define GL_MODELVIEW17_ARB 0x8731
#define GL_RECT_NV 0xF6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_2PASS_0_EXT 0x80A2
#define GL_ALPHA8UI_EXT 0x8D7E
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_UNSIGNALED 0x9118
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#define GL_SAMPLER_RENDERBUFFER_NV 0x8E56
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_MATRIX13_ARB 0x88CD
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_BGRA_INTEGER 0x8D9B
#define GL_ALPHA12_EXT 0x803D
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MODELVIEW1_ARB 0x850A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT 0x8C4B
#define GL_SOURCE2_RGB_EXT 0x8582
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT 0x8DE4
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_RGB4_EXT 0x804F
#define GL_DYNAMIC_COPY_ARB 0x88EA
#define GL_LINE_WIDTH 0x0B21
#define GL_TEXTURE_PRE_SPECULAR_HP 0x8169
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV 0x84F8
#define GL_REG_16_ATI 0x8931
#define GL_MAP2_BINORMAL_EXT 0x8447
#define GL_COLOR_ATTACHMENT17 0x8CF1
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL 0x83F6
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT 0x8C3E
#define GL_CULL_VERTEX_IBM 103050
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_NUM_EXTENSIONS 0x821D
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV 0x8E23
#define GL_HSL_HUE_NV 0x92AD
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX 0x844E
#define GL_UNSIGNED_SHORT_8_8_REV_MESA 0x85BB
#define GL_COMBINER_MAPPING_NV 0x8543
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8337
#define GL_POST_CONVOLUTION_RED_BIAS_EXT 0x8020
#define GL_QUAD_LUMINANCE4_SGIS 0x8120
#define GL_DEPTH_FUNC 0x0B74
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX 0x817B
#define GL_HALF_APPLE 0x140B
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_TEXTURE_LOD_BIAS_S_SGIX 0x818E
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT 0x9066
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV 0x8DAF
#define GL_DEPTH_COMPONENT 0x1902
#define GL_SPARE0_NV 0x852E
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX 0x8173
#define GL_PROGRAM_INSTRUCTIONS_ARB 0x88A0
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_HI_SCALE_NV 0x870E
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B
#define GL_CONVOLUTION_FILTER_BIAS_EXT 0x8015
#define GL_MULTISAMPLE_BIT_3DFX 0x20000000
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT 0x8514
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_COLOR_ATTACHMENT6_EXT 0x8CE6
#define GL_PRIMARY_COLOR_ARB 0x8577
#define GL_OBJECT_SUBTYPE_ARB 0x8B4F
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV 0x9352
#define GL_PATH_OBJECT_BOUNDING_BOX_NV 0x908A
#define GL_SKIP_COMPONENTS3_NV -4
#define GL_SCALEBIAS_HINT_SGIX 0x8322
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_COMBINER5_NV 0x8555
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_RELATIVE_VERTICAL_LINE_TO_NV 0x09
#define GL_PROGRAM 0x82E2
#define GL_TEXTURE_RECTANGLE_NV 0x84F5
#define GL_ATTRIB_ARRAY_SIZE_NV 0x8623
#define GL_2PASS_1_SGIS 0x80A3
#define GL_IUI_V3F_EXT 0x81AE
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_SCALE_BY_FOUR_NV 0x853F
#define GL_LUMINANCE16UI_EXT 0x8D7A
#define GL_ARRAY_STRIDE 0x92FE
#define GL_BINORMAL_ARRAY_POINTER_EXT 0x8443
#define GL_KEEP 0x1E00
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_8X_BIT_ATI 0x00000004
#define GL_OPERAND1_RGB_EXT 0x8591
#define GL_OPERAND2_RGB_EXT 0x8592
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_PRIMITIVES_SUBMITTED_ARB 0x82EF
#define GL_EYE_PLANE_ABSOLUTE_NV 0x855C
#define GL_DS_BIAS_NV 0x8716
#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_LINE_LOOP 0x0002
#define GL_PACK_INVERT_MESA 0x8758
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB 0x8805
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV 0x00020000
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_COLOR_ENCODING 0x8296
#define GL_R3_G3_B2 0x2A10
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_LUMINANCE_FLOAT16_APPLE 0x881E
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_SAMPLES_3DFX 0x86B4
#define GL_FUNC_ADD 0x8006
#define GL_COMBINE_ALPHA_ARB 0x8572
#define GL_BUFFER_ACCESS 0x88BB
#define GL_EYE_POINT_SGIS 0x81F4
#define GL_POLYGON_OFFSET_FACTOR_EXT 0x8038
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#define GL_PIXEL_UNPACK_BUFFER_EXT 0x88EC
#define GL_ITALIC_BIT_NV 0x02
#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_NICEST 0x1102
#define GL_MAP2_VERTEX_ATTRIB15_4_NV 0x867F
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV 0x86D9
#define GL_FRAGMENT_LIGHT2_SGIX 0x840E
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_SURFACE_MAPPED_NV 0x8700
#define GL_DEBUG_CATEGORY_DEPRECATION_AMD 0x914B
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_TEXTURE31_ARB 0x84DF
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_REG_23_ATI 0x8938
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX 0x819B
#define GL_RGB10_A2_EXT 0x8059
#define GL_TEXTURE_PRIORITY_EXT 0x8066
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_RGB10_EXT 0x8052
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT 0x8C80
#define GL_MATRIX22_ARB 0x88D6
#define GL_PIXEL_TEXTURE_SGIS 0x8353
#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_TRIANGLES 0x0004
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_COLOR_ATTACHMENT12_EXT 0x8CEC
#define GL_IMAGE_BINDING_NAME_EXT 0x8F3A
#define GL_ASYNC_MARKER_SGIX 0x8329
#define GL_READ_PIXEL_DATA_RANGE_NV 0x8879
#define GL_NORMAL_ARRAY_STRIDE_EXT 0x807F
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_GLOBAL_ALPHA_FACTOR_SUN 0x81DA
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_CON_10_ATI 0x894B
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_MAX_PROGRAM_PARAMETERS_ARB 0x88A9
#define GL_CLAMP_TO_BORDER_ARB 0x812D
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV 0x0BA3
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM 103076
#define GL_SIGNED_RGBA8_NV 0x86FC
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM 103087
#define GL_QUERY_COUNTER_BITS_ARB 0x8864
#define GL_TEXTURE_MEMORY_LAYOUT_INTEL 0x83FF
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_DETAIL_TEXTURE_MODE_SGIS 0x809B
#define GL_EVAL_VERTEX_ATTRIB2_NV 0x86C8
#define GL_AVERAGE_EXT 0x8335
#define GL_WINDOW_RECTANGLE_MODE_EXT 0x8F13
#define GL_INTERLACE_OML 0x8980
#define GL_OPERAND0_ALPHA_EXT 0x8598
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_MAX_COLOR_ATTACHMENTS_EXT 0x8CDF
#define GL_BINORMAL_ARRAY_EXT 0x843A
#define GL_DETAIL_TEXTURE_2D_SGIS 0x8095
#define GL_MAD_ATI 0x8968
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_NUM_GENERAL_COMBINERS_NV 0x854E
#define GL_HARDMIX_NV 0x92A9
#define GL_MOV_ATI 0x8961
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_MODELVIEW_PROJECTION_NV 0x8629
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_OFFSET_HILO_TEXTURE_2D_NV 0x8854
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_FRAGMENT_PROGRAM_NV 0x8870
#define GL_EQUIV 0x1509
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_MATRIX25_ARB 0x88D9
#define GL_CON_21_ATI 0x8956
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
#define GL_TEXTURE_RENDERBUFFER_NV 0x8E55
#define GL_LIGHT_ENV_MODE_SGIX 0x8407
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT 0x808B
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT 0x88FF
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI 0x8802
#define GL_SHADER_INCLUDE_ARB 0x8DAE
#define GL_INVALID_INDEX 0xFFFFFFFF
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define GL_DOUBLE_MAT3x2_EXT 0x8F4B
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV 0x8865
#define GL_SRGB_WRITE 0x8298
#define GL_POINT_SIZE_MAX_EXT 0x8127
#define GL_PERFORMANCE_MONITOR_AMD 0x9152
#define GL_TEXTURE7_ARB 0x84C7
#define GL_RESAMPLE_REPLICATE_OML 0x8986
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV 0x8C8B
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_DEPTH_SAMPLES_NV 0x932D
#define GL_RGB8I_EXT 0x8D8F
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B0
#define GL_COMPRESSED_RGB_ARB 0x84ED
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX 0x9049
#define GL_OP_POWER_EXT 0x8793
#define GL_DOT_PRODUCT_NV 0x86EC
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_INDEX_SIZE_EXT 0x80ED
#define GL_REFERENCE_PLANE_EQUATION_SGIX 0x817E
#define GL_VERTEX_SHADER_BINDING_EXT 0x8781
#define GL_LUMINANCE12_ALPHA4_EXT 0x8046
#define GL_MAX_LAYERS 0x8281
#define GL_ALLOW_DRAW_OBJ_HINT_PGI 0x1A20E
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_SHADER_OPERATION_NV 0x86DF
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_SHADER_CONSISTENT_NV 0x86DD
#define GL_PIXEL_CUBIC_WEIGHT_EXT 0x8333
#define GL_FLOAT_VEC4_ARB 0x8B52
#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
#define GL_QUERY_WAIT_INVERTED 0x8E17
#define GL_TRANSFORM_FEEDBACK_BINDING_NV 0x8E25
#define GL_FLOAT16_MAT3x4_AMD 0x91CB
#define GL_DRAW_BUFFER7_ATI 0x882C
#define GL_DUAL_INTENSITY12_SGIS 0x811A
#define GL_GREEN_MIN_CLAMP_INGR 0x8561
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_SCALAR_EXT 0x87BE
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_RGB8 0x8051
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_CULL_FACE 0x0B44
#define GL_VERTEX_ID_NV 0x8C7B
#define GL_PATH_COVER_DEPTH_FUNC_NV 0x90BF
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB 0x851C
#define GL_EYE_LINE_SGIS 0x81F6
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV 0x887A
#define GL_PATH_STENCIL_VALUE_MASK_NV 0x90B9
#define GL_COLOR_TABLE_BIAS_SGI 0x80D7
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#define GL_TEXTURE_WRAP_Q_SGIS 0x8137
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_RGBA 0x1908
#define GL_ABGR_EXT 0x8000
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5B
#define GL_VENDOR 0x1F00
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV 0x9354
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_EMBOSS_CONSTANT_NV 0x855E
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_R8UI 0x8232
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_TESS_GEN_MODE 0x8E76
#define GL_DRAW_BUFFER1_ARB 0x8826
#define GL_UNSIGNED_INT64_VEC4_NV 0x8FF7
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV 0x19
#define GL_OUTPUT_TEXTURE_COORD9_EXT 0x87A6
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_SRGB8_ALPHA8_EXT 0x8C43
#define GL_DEPTH_COMPONENT24_SGIX 0x81A6
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_MAP_TESSELLATION_NV 0x86C2
#define GL_SLUMINANCE_EXT 0x8C46
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F1
#define GL_IMAGE_BUFFER_EXT 0x9051
#define GL_SEPARATE_ATTRIBS_EXT 0x8C8D
#define GL_FULL_RANGE_EXT 0x87E1
#define GL_SAMPLE_MASK_SGIS 0x80A0
#define GL_PATH_MITER_LIMIT_NV 0x907A
#define GL_PATH_STROKE_BOUNDING_BOX_NV 0x90A2
#define GL_SOURCE1_ALPHA_ARB 0x8589
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT 0x932C
#define GL_RG16F 0x822F
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_VERTEX_BINDING_STRIDE 0x82D8
#define GL_RG16I 0x8239
#define GL_WRITE_ONLY 0x88B9
#define GL_TEXTURE_COORD_NV 0x8C79
#define GL_LAYOUT_DEFAULT_INTEL 0
#define GL_PATH_GEN_COEFF_NV 0x90B1
#define GL_CURRENT_RASTER_NORMAL_SGIX 0x8406
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS 0x80B0
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_R1UI_C3F_V3F_SUN 0x85C6
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_LINEARBURN_NV 0x92A5
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_OUTPUT_TEXTURE_COORD20_EXT 0x87B1
#define GL_TEXCOORD2_BIT_PGI 0x20000000
#define GL_PROVOKING_VERTEX_EXT 0x8E4F
#define GL_SRC_IN_NV 0x928A
#define GL_CONSERVATIVE_RASTERIZATION_INTEL 0x83FE
#define GL_SKIP_COMPONENTS2_NV -5
#define GL_SAMPLER_2D_ARB 0x8B5E
#define GL_DST_ALPHA 0x0304
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_COMBINE_EXT 0x8570
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_IMAGE_2D_ARRAY_EXT 0x9053
#define GL_VIVIDLIGHT_NV 0x92A6
#define GL_OUTPUT_TEXTURE_COORD19_EXT 0x87B0
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_LINE_STRIP_ADJACENCY_ARB 0x000B
#define GL_PATH_ERROR_POSITION_NV 0x90AB
#define GL_SRGB8_EXT 0x8C41
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_LUMINANCE16F_ARB 0x881E
#define GL_RGB9_E5 0x8C3D
#define GL_NUM_FRAGMENT_CONSTANTS_ATI 0x896F
#define GL_CALLIGRAPHIC_FRAGMENT_SGIX 0x8183
#define GL_RGBA32UI 0x8D70
#define GL_FLOAT16_MAT3x2_AMD 0x91CA
#define GL_INVERT_OVG_NV 0x92B4
#define GL_MODELVIEW6_ARB 0x8726
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_MAX_PROGRAM_CALL_DEPTH_NV 0x88F5
#define GL_TEXTURE21_ARB 0x84D5
#define GL_PATH_DASH_CAPS_NV 0x907B
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_PATH_COORD_COUNT_NV 0x909E
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT 0x8C1D
#define GL_DETAIL_TEXTURE_LEVEL_SGIS 0x809A
#define GL_BUFFER_MAP_POINTER_ARB 0x88BD
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_TEXTURE_DEPTH_TYPE_ARB 0x8C16
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_WAIT_FAILED 0x911D
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB 0x8848
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX 0x8145
#define GL_ATTRIB_ARRAY_POINTER_NV 0x8645
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MATRIX19_ARB 0x88D3
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB 0x91A8
#define GL_PROVOKING_VERTEX 0x8E4F
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV 0x8F2F
#define GL_COLOR_ATTACHMENT15_EXT 0x8CEF
#define GL_SPARE1_NV 0x852F
#define GL_MAP_PERSISTENT_BIT 0x0040
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
#define GL_CMYK_EXT 0x800C
#define GL_RGB12 0x8053
#define GL_TIME_ELAPSED_EXT 0x88BF
#define GL_RGB10 0x8052
#define GL_RGB16 0x8054
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_FRONT_FACE_COMMAND_NV 0x0012
#define GL_RGB8_EXT 0x8051
#define GL_SKIP_COMPONENTS4_NV -3
#define GL_ALL_COMPLETED_NV 0x84F2
#define GL_1PASS_EXT 0x80A1
#define GL_TEXTURE_SWIZZLE_G_EXT 0x8E43
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_TEXTURE_BLUE_SIZE_EXT 0x805E
#define GL_MATRIX9_ARB 0x88C9
#define GL_FENCE_CONDITION_NV 0x84F4
#define GL_COLOR_ARRAY_LIST_IBM 103072
#define GL_T2F_IUI_V2F_EXT 0x81B1
#define GL_UNSIGNED_INT_VEC4_EXT 0x8DC8
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_COMBINE_ALPHA_EXT 0x8572
#define GL_RGB5_A1_EXT 0x8057
#define GL_TRANSPOSE_COLOR_MATRIX_ARB 0x84E6
#define GL_CURRENT_FOG_COORDINATE_EXT 0x8453
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SOURCE2_RGB_ARB 0x8582
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_PATH_COMMAND_COUNT_NV 0x909D
#define GL_LUMINANCE4_ALPHA4_EXT 0x8043
#define GL_TEXTURE27_ARB 0x84DB
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI 0x87F3
#define GL_LINES_ADJACENCY_EXT 0x000A
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_FLOAT16_MAT2x4_AMD 0x91C9
#define GL_SAMPLER_BINDING 0x8919
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_CONVOLUTION_FILTER_SCALE_EXT 0x8014
#define GL_COLOR_ATTACHMENT11_EXT 0x8CEB
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV 0x20000000
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB 0x8846
#define GL_MIN_LOD_WARNING_AMD 0x919C
#define GL_UPPER_LEFT 0x8CA2
#define GL_MAP1_VERTEX_ATTRIB2_4_NV 0x8662
#define GL_INT_IMAGE_2D_ARRAY_EXT 0x905E
#define GL_CON_2_ATI 0x8943
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI 0x8973
#define GL_MAX_DEPTH 0x8280
#define GL_COUNTER_RANGE_AMD 0x8BC1
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_MULTISAMPLE_ARB 0x809D
#define GL_MINUS_CLAMPED_NV 0x92B3
#define GL_CCW 0x0901
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_STATIC_DRAW_ARB 0x88E4
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FIXED_OES 0x140C
#define GL_SAMPLE_ALPHA_TO_ONE_EXT 0x809F
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_OPERAND0_RGB_EXT 0x8590
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV 0x9340
#define GL_MATRIX20_ARB 0x88D4
#define GL_RGB32F 0x8815
#define GL_DEPTH 0x1801
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_PALETTE4_RGB8_OES 0x8B90
#define GL_DSDT_NV 0x86F5
#define GL_FONT_HEIGHT_BIT_NV 0x00800000
#define GL_COLOR_ATTACHMENT8_EXT 0x8CE8
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT 0x8021
#define GL_422_EXT 0x80CC
#define GL_RG8I 0x8237
#define GL_RGBA8I 0x8D8E
#define GL_COMPUTE_PROGRAM_NV 0x90FB
#define GL_SPARSE_STORAGE_BIT_ARB 0x0400
#define GL_STENCIL_TAG_BITS_EXT 0x88F2
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX 0x8179
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_HILO16_NV 0x86F8
#define GL_IMAGE_ROTATE_ANGLE_HP 0x8159
#define GL_TEXTURE_BUFFER_FORMAT_EXT 0x8C2E
#define GL_RASTERIZER_DISCARD_EXT 0x8C89
#define GL_MAP1_VERTEX_ATTRIB5_4_NV 0x8665
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_VIEWPORT_SWIZZLE_W_NV 0x935B
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB 0x9342
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_PACK_IMAGE_HEIGHT_EXT 0x806C
#define GL_TEXTURE_4DSIZE_SGIS 0x8136
#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_TEXTURE 0x1702
#define GL_DOUBLE_MAT4x2_EXT 0x8F4D
#define GL_MAX_CLIP_DISTANCES 0x0D32
#define GL_UNSIGNED_INT64_VEC4_ARB 0x8FF7
#define GL_T2F_IUI_N3F_V2F_EXT 0x81B3
#define GL_4PASS_1_EXT 0x80A5
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_FLOAT16_MAT4_AMD 0x91C7
#define GL_FLOAT16_MAT4x3_AMD 0x91CD
#define GL_DOT2_ADD_ATI 0x896C
#define GL_RECLAIM_MEMORY_HINT_PGI 0x1A1FE
#define GL_EVAL_VERTEX_ATTRIB3_NV 0x86C9
#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT 0x8C8E
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#define GL_YCBCR_MESA 0x8757
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_SECONDARY_COLOR_ARRAY_EXT 0x845E
#define GL_CURRENT_VERTEX_EXT 0x87E2
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_ALPHA_FLOAT16_APPLE 0x881C
#define GL_RASTERIZER_DISCARD_NV 0x8C89
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_NORMAL_ARRAY_TYPE_EXT 0x807E
#define GL_LUMINANCE16_ALPHA16_EXT 0x8048
#define GL_PATH_COMPUTED_LENGTH_NV 0x90A0
#define GL_ROUNDED_RECT2_NV 0xEA
#define GL_CLAMP_VERTEX_COLOR_ARB 0x891A
#define GL_FRAGMENT_COLOR_EXT 0x834C
#define GL_TEXTURE_APPLICATION_MODE_EXT 0x834F
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_DOUBLE_MAT2x4_EXT 0x8F4A
#define GL_MODELVIEW28_ARB 0x873C
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_CONSTANT_COLOR1_NV 0x852B
#define GL_PATH_DASH_OFFSET_RESET_NV 0x90B4
#define GL_SIGNED_RGBA_NV 0x86FB
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_PATH_DASH_ARRAY_COUNT_NV 0x909F
#define GL_DRAW_BUFFER4_ATI 0x8829
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR 0x93B7
#define GL_LINEARLIGHT_NV 0x92A7
#define GL_MAX_VERTEX_UNITS_ARB 0x86A4
#define GL_RGBA32UI_EXT 0x8D70
#define GL_COVERAGE_MODULATION_TABLE_NV 0x9331
#define GL_DOUBLE_MAT2x3_EXT 0x8F49
#define GL_MINMAX_SINK_EXT 0x8030
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV 0x902B
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_BOOL_VEC2_ARB 0x8B57
#define GL_RGBA_FLOAT16_APPLE 0x881A
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_ALPHA16_EXT 0x803E
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_ZERO_EXT 0x87DD
#define GL_MOVE_TO_CONTINUES_NV 0x90B6
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
#define GL_UNPACK_ROW_BYTES_APPLE 0x8A16
#define GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV 0x937E
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_DEBUG_CATEGORY_APPLICATION_AMD 0x914F
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT 0x8093
#define GL_INVALID_OPERATION 0x0502
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_DISTANCE_ATTENUATION_EXT 0x8129
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_TEXTURE_LUMINANCE_TYPE_ARB 0x8C14
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_TEXTURE_RANGE_POINTER_APPLE 0x85B8
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_MATRIX5_NV 0x8635
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV 0x8DA0
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV 0x887B
#define GL_OUTPUT_TEXTURE_COORD23_EXT 0x87B4
#define GL_PATCH_VERTICES 0x8E72
#define GL_CULL_FACE_MODE 0x0B45
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV 0x8DA2
#define GL_PATH_FILL_BOUNDING_BOX_NV 0x90A1
#define GL_TEXTURE_RESIDENT_EXT 0x8067
#define GL_RGBA_INTEGER_MODE_EXT 0x8D9E
#define GL_SIGNED_HILO8_NV 0x885F
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_QUAD_TEXTURE_SELECT_SGIS 0x8125
#define GL_COMBINE_RGB_EXT 0x8571
#define GL_RGB_SNORM 0x8F92
#define GL_SAMPLE_MASK_VALUE_NV 0x8E52
#define GL_MAX_PROGRAM_MATRICES_ARB 0x862F
#define GL_ALWAYS 0x0207
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_FLOAT_MAT3_ARB 0x8B5B
#define GL_CONSERVATIVE_RASTER_MODE_NV 0x954D
#define GL_ROUNDED_RECT8_NV 0xEE
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_PIXEL_COUNT_NV 0x8866
#define GL_SAMPLE_POSITION_NV 0x8E50
#define GL_IMAGE_SCALE_X_HP 0x8155
#define GL_MAX_WIDTH 0x827E
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_UNSIGNED_INT16_NV 0x8FF0
#define GL_DEBUG_SEVERITY_MEDIUM_AMD 0x9147
#define GL_CON_30_ATI 0x895F
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX 0x8402
#define GL_MATRIX7_NV 0x8637
#define GL_DRAW_BUFFER11 0x8830
#define GL_RG16UI 0x823A
#define GL_SWIZZLE_STRQ_DQ_ATI 0x897B
#define GL_Z_EXT 0x87D7
#define GL_MAX_PROGRAM_TEMPORARIES_ARB 0x88A5
#define GL_PIXEL_GROUP_COLOR_SGIS 0x8356
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_CON_9_ATI 0x894A
#define GL_INT_IMAGE_BUFFER_EXT 0x905C
#define GL_ALREADY_SIGNALED 0x911A
#define GL_STATIC_COPY_ARB 0x88E6
#define GL_QUADRATIC_CURVE_TO_NV 0x0A
#define GL_MEDIUM_INT 0x8DF4
#define GL_REG_2_ATI 0x8923
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_MAX_ELEMENTS_INDICES_EXT 0x80E9
#define GL_VERTEX_ARRAY_OBJECT_EXT 0x9154
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D4
#define GL_COLOR_INDEX16_EXT 0x80E7
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_COLOR_ATTACHMENT10_EXT 0x8CEA
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT 0x8D54
#define GL_FRAMEZOOM_SGIX 0x818B
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_SAMPLES_PASSED_ARB 0x8914
#define GL_SUCCESS_NV 0x902F
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_READ_PIXELS 0x828C
#define GL_REG_18_ATI 0x8933
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI 0x80B5
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_UNSIGNED_INT_VEC3_EXT 0x8DC7
#define GL_MAX_EXT 0x8008
#define GL_FLOAT_MAT4_ARB 0x8B5C
#define GL_FILE_NAME_NV 0x9074
#define GL_RGBA_FLOAT32_APPLE 0x8814
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_DISTANCE_ATTENUATION_SGIS 0x8129
#define GL_MAX_SAMPLE_MASK_WORDS_NV 0x8E59
#define GL_COMBINE_ARB 0x8570
#define GL_PIXEL_TRANSFORM_2D_EXT 0x8330
#define GL_RGBA_S3TC 0x83A2
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MIRROR_CLAMP_TO_EDGE 0x8743
#define GL_REFLECTION_MAP_NV 0x8512
#define GL_FIRST_TO_REST_NV 0x90AF
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX 0x8403
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN 0x85C1
#define GL_USE_MISSING_GLYPH_NV 0x90AA
#define GL_MAP1_VERTEX_ATTRIB0_4_NV 0x8660
#define GL_OP_FRAC_EXT 0x8789
#define GL_COMBINER_BIAS_NV 0x8549
#define GL_MODELVIEW20_ARB 0x8734
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT 0x850D
#define GL_CON_17_ATI 0x8952
#define GL_IMAGE_3D_EXT 0x904E
#define GL_TRIANGULAR_NV 0x90A5
#define GL_INT_SAMPLER_2D_EXT 0x8DCA
#define GL_FLOAT16_VEC2_NV 0x8FF9
#define GL_DISCARD_NV 0x8530
#define GL_COMPLETION_STATUS_ARB 0x91B1
#define GL_LUMINANCE8I_EXT 0x8D92
#define GL_LUMINANCE_ALPHA16F_ARB 0x881F
#define GL_DRAW_BUFFER9_ATI 0x882E
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x00000001
#define GL_SRC_NV 0x9286
#define GL_SCREEN_COORDINATES_REND 0x8490
#define GL_SPRITE_AXIS_SGIX 0x814A
#define GL_TRANSPOSE_NV 0x862C
#define GL_ALPHA_SNORM 0x9010
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_INT_VEC2_ARB 0x8B53
#define GL_TEXTURE_FILTER_CONTROL_EXT 0x8500
#define GL_DST_OVER_NV 0x9289
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_COMPRESSED_RED_RGTC1_EXT 0x8DBB
#define GL_RGB_INTEGER_EXT 0x8D98
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT 0x9060
#define GL_RGBA32F_ARB 0x8814
#define GL_TEXTURE_DEFORMATION_BIT_SGIX 0x00000001
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_DT_BIAS_NV 0x8717
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV 0x8859
#define GL_INT_VEC4_ARB 0x8B55
#define GL_DRAW_BUFFER6_ATI 0x882B
#define GL_RGBA8UI_EXT 0x8D7C
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_UNCORRELATED_NV 0x9282
#define GL_RGB2_EXT 0x804E
#define GL_TRIANGLES_ADJACENCY_ARB 0x000C
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_LUMINANCE_ALPHA32UI_EXT 0x8D75
#define GL_LOCATION 0x930E
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_LINE_TO_NV 0x04
#define GL_INT_VEC3_ARB 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC2 0x8B53
#define GL_STENCIL_FAIL 0x0B94
#define GL_LAYOUT_LINEAR_CPU_CACHED_INTEL 2
#define GL_PACK_SKIP_IMAGES_EXT 0x806B
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
#define GL_RELATIVE_ROUNDED_RECT2_NV 0xEB
#define GL_MAX_PROGRAM_LOOP_COUNT_NV 0x88F8
#define GL_SOFTLIGHT_NV 0x929C
#define GL_DUAL_LUMINANCE12_SGIS 0x8116
#define GL_MAP2_VERTEX_ATTRIB13_4_NV 0x867D
#define GL_TEXTURE_3D_EXT 0x806F
#define GL_VERTEX_ARRAY_STRIDE_EXT 0x807C
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV 0x933D
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV 0x864D
#define GL_VERTEX_ATTRIB_ARRAY2_NV 0x8652
#define GL_VIEWPORT_COMMAND_NV 0x0010
#define GL_EXTENSIONS 0x1F03
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER15 0x8834
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_SKIP_DECODE_EXT 0x8A4A
#define GL_DARKEN_KHR 0x9297
#define GL_OFFSET 0x92FC
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV 0x0009
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX 0x844D
#define GL_QUERY_BUFFER_BINDING_AMD 0x9193
#define GL_FRAGMENT_PROGRAM_ARB 0x8804
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_MAX_HEIGHT 0x827F
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_STENCIL 0x1802
#define GL_INTENSITY_FLOAT16_APPLE 0x881D
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#define GL_OBJECT_INFO_LOG_LENGTH_ARB 0x8B84
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV 0x8DA4
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV 0x9025
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_HIGH_INT 0x8DF5
#define GL_MODELVIEW15_ARB 0x872F
#define GL_RGB_SCALE_EXT 0x8573
#define GL_DOUBLE_MAT3_EXT 0x8F47
#define GL_MAP2_VERTEX_ATTRIB6_4_NV 0x8676
#define GL_BOLD_BIT_NV 0x01
#define GL_TEXTURE_WRAP_R_EXT 0x8072
#define GL_SAMPLE_POSITION 0x8E50
#define GL_INCR 0x1E02
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D2
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E
#define GL_MAP_ATTRIB_V_ORDER_NV 0x86C4
#define GL_TRUE 1
#define GL_PROGRAM_ERROR_STRING_ARB 0x8874
#define GL_COLOR_ALPHA_PAIRING_ATI 0x8975
#define GL_CURRENT_QUERY 0x8865
#define GL_MODELVIEW1_MATRIX_EXT 0x8506
#define GL_DRAW_BUFFER3_ATI 0x8828
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV 0x8908
#define GL_RGB16UI 0x8D77
#define GL_COPY_INVERTED 0x150C
#define GL_OP_SET_LT_EXT 0x878D
#define GL_LINEARDODGE_NV 0x92A4
#define GL_LOWER_LEFT 0x8CA1
#define GL_MAX_DEFORMATION_ORDER_SGIX 0x8197
#define GL_VIDEO_BUFFER_PITCH_NV 0x9028
#define GL_BLEND_COLOR_COMMAND_NV 0x000B
#define GL_PALETTE4_RGB5_A1_OES 0x8B94
#define GL_FOG_COORDINATE_ARRAY_EXT 0x8457
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT 0x80F0
#define GL_CONSTANT_COLOR0_NV 0x852A
#define GL_TEXTURE_FILTER4_SIZE_SGIS 0x8147
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_BLEND_SRC_RGB_EXT 0x80C9
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87C8
#define GL_UTF16_NV 0x909B
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT 0x8DBC
#define GL_MODELVIEW19_ARB 0x8733
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV 0x8C7E
#define GL_SMALL_CCW_ARC_TO_NV 0x12
#define GL_TEXTURE_COVERAGE_SAMPLES_NV 0x9045
#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV 0x8904
#define GL_CON_16_ATI 0x8951
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_PINLIGHT_NV 0x92A8
#define GL_FLOAT_RGBA16_NV 0x888A
#define GL_HISTOGRAM_BLUE_SIZE_EXT 0x802A
#define GL_COMPRESSED_RED 0x8225
#define GL_BGR 0x80E0
#define GL_RGB16F_ARB 0x881B
#define GL_COMBINER_MUX_SUM_NV 0x8547
#define GL_OP_RECIP_EXT 0x8794
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_DEBUG_OUTPUT 0x92E0
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_CIRCULAR_TANGENT_ARC_TO_NV 0xFC
#define GL_QUERY_RESULT_NO_WAIT 0x9194
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_PREVIOUS_TEXTURE_INPUT_NV 0x86E4
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_OUTPUT_TEXTURE_COORD17_EXT 0x87AE
#define GL_MATRIX16_ARB 0x88D0
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_READ_WRITE 0x88BA
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV 0x01000000
#define GL_DRAW_BUFFER0_ATI 0x8825
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_TANGENT_ARRAY_EXT 0x8439
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP 0x815B
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_RGB8I 0x8D8F
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT 0x8DE2
#define GL_DRAW_BUFFER 0x0C01
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_MATRIX23_ARB 0x88D7
#define GL_STENCIL_INDEX8 0x8D48
#define GL_REG_5_ATI 0x8926
#define GL_RGB8UI 0x8D7D
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT 0x00001000
#define GL_DOT_PRODUCT_TEXTURE_2D_NV 0x86EE
#define GL_MATRIX6_NV 0x8636
#define GL_OP_DOT4_EXT 0x8785
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB 0x8623
#define GL_BLEND_DST_RGB 0x80C8
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT 0x88FD
#define GL_CLEAR 0x1500
#define GL_MATRIX4_NV 0x8634
#define GL_TEXTURE22_ARB 0x84D6
#define GL_SUPERSAMPLE_SCALE_Y_NV 0x9373
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_FRAGMENT_SHADER_ATI 0x8920
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_VARIABLE_B_NV 0x8524
#define GL_RGBA16_EXT 0x805B
#define GL_YCRCB_444_SGIX 0x81BC
#define GL_DST_NV 0x9287
#define GL_VARIABLE_F_NV 0x8528
#define GL_DRAW_ARRAYS_COMMAND_NV 0x0003
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_EVAL_VERTEX_ATTRIB15_NV 0x86D5
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_MATRIX6_ARB 0x88C6
#define GL_TRIANGLE_LIST_SUN 0x81D7
#define GL_INVERSE_NV 0x862B
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV 0x86ED
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_R11F_G11F_B10F_EXT 0x8C3A
#define GL_FLOAT_RGB32_NV 0x8889
#define GL_FACTOR_MIN_AMD 0x901C
#define GL_PATH_GEN_MODE_NV 0x90B0
#define GL_BUFFER_MAP_OFFSET 0x9121
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_BUFFER_SIZE 0x8764
#define GL_STATIC_ATI 0x8760
#define GL_MAP1_VERTEX_ATTRIB14_4_NV 0x866E
#define GL_COLOR_SUM_EXT 0x8458
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_RGBA4_S3TC 0x83A3
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_OR_REVERSE 0x150B
#define GL_SMOOTH_CUBIC_CURVE_TO_NV 0x10
#define GL_SEPARABLE_2D_EXT 0x8012
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT 0x8DDF
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_LUMINANCE_ALPHA8I_EXT 0x8D93
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_UNSIGNED_INT_IMAGE_3D_EXT 0x9064
#define GL_PATH_STROKE_COVER_MODE_NV 0x9083
#define GL_VERTEX_ATTRIB_ARRAY4_NV 0x8654
#define GL_MAP_ATTRIB_U_ORDER_NV 0x86C3
#define GL_MATRIX28_ARB 0x88DC
#define GL_OP_RECIP_SQRT_EXT 0x8795
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_MAX_SAMPLES 0x8D57
#define GL_QUAD_LUMINANCE8_SGIS 0x8121
#define GL_GEOMETRY_OUTPUT_TYPE_EXT 0x8DDC
#define GL_NOOP 0x1505
#define GL_ALPHA32F_ARB 0x8816
#define GL_PIXEL_MIN_FILTER_EXT 0x8332
#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129
#define GL_CONTEXT_FLAGS 0x821E
#define GL_PROGRAM_LENGTH_NV 0x8627
#define GL_BOOL 0x8B56
#define GL_FLOAT16_VEC3_NV 0x8FFA
#define GL_CONSERVATIVE_RASTER_DILATE_NV 0x9379
#define GL_FIELD_LOWER_NV 0x9023
#define GL_FOG_FUNC_SGIS 0x812A
#define GL_TEXTURE15_ARB 0x84CF
#define GL_OUTPUT_TEXTURE_COORD2_EXT 0x879F
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_R1UI_N3F_V3F_SUN 0x85C7
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT 0x851C
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_FRAGMENT_MATERIAL_EXT 0x8349
#define GL_HISTOGRAM_EXT 0x8024
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT 0x8DD2
#define GL_IGNORE_BORDER_HP 0x8150
#define GL_CURRENT_MATRIX_ARB 0x8641
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8162
#define GL_ALPHA16UI_EXT 0x8D78
#define GL_WEIGHT_SUM_UNITY_ARB 0x86A6
#define GL_PIXEL_SUBSAMPLE_4242_SGIX 0x85A4
#define GL_PROGRAM_BINARY_FORMATS 0x87FF
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT 0x00000200
#define GL_SRGB 0x8C40
#define GL_COLOR_MATRIX_SGI 0x80B1
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_VIRTUAL_PAGE_SIZE_Z_AMD 0x9197
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_EVAL_VERTEX_ATTRIB13_NV 0x86D3
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_UNSIGNED_SHORT_8_8_MESA 0x85BA
#define GL_LUMINANCE_ALPHA16UI_EXT 0x8D7B
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#define GL_PALETTE8_RGB8_OES 0x8B95
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_REPLACE_OLDEST_SUN 0x0003
#define GL_GEOMETRY_INPUT_TYPE_EXT 0x8DDB
#define GL_AND_REVERSE 0x1502
#define GL_MAX_INTEGER_SAMPLES 0x9110
#define GL_EVAL_VERTEX_ATTRIB11_NV 0x86D1
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_RGBA8_SNORM 0x8F97
#define GL_COLOR3_BIT_PGI 0x00010000
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_BUMP_TEX_UNITS_ATI 0x8778
#define GL_DYNAMIC_STORAGE_BIT 0x0100
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_AND 0x1501
#define GL_ACTIVE_PROGRAM_EXT 0x8B8D
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB 0x82F6
#define GL_IUI_V2F_EXT 0x81AD
#define GL_COORD_REPLACE_ARB 0x8862
#define GL_CON_6_ATI 0x8947
#define GL_FUNC_REVERSE_SUBTRACT_EXT 0x800B
#define GL_RESAMPLE_AVERAGE_OML 0x8988
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX 0x8172
#define GL_TEXTURE_SHARED_SIZE_EXT 0x8C3F
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_UNIFORM_BARRIER_BIT_EXT 0x00000004
#define GL_ALPHA_FLOAT16_ATI 0x881C
#define GL_COMPRESSED_SRGB_EXT 0x8C48
#define GL_2X_BIT_ATI 0x00000001
#define GL_NEGATIVE_X_EXT 0x87D9
#define GL_PRIMITIVE_ID_NV 0x8C7C
#define GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX 0x9047
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV 0x8DA1
#define GL_ALPHA_MAX_SGIX 0x8321
#define GL_SYNC_STATUS 0x9114
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV 0x902C
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT 0x8DD5
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_DRAW_BUFFER12_ATI 0x8831
#define GL_PERTURB_EXT 0x85AE
#define GL_MAX_SPOT_EXPONENT_NV 0x8505
#define GL_UNPACK_SKIP_IMAGES_EXT 0x806D
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV 0x8E54
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_PERFMON_RESULT_SIZE_AMD 0x8BC5
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_MODULATE_SIGNED_ADD_ATI 0x8745
#define GL_PIXEL_COUNT_AVAILABLE_NV 0x8867
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_DEPTH_COMPONENT24_ARB 0x81A6
#define GL_MAT_COLOR_INDEXES_BIT_PGI 0x01000000
#define GL_PRIMITIVES_GENERATED_EXT 0x8C87
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT 0x8D55
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI 0x8971
#define GL_STENCIL_INDEX1_EXT 0x8D46
#define GL_STATIC_VERTEX_ARRAY_IBM 103061
#define GL_2PASS_0_SGIS 0x80A2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAP1_VERTEX_ATTRIB11_4_NV 0x866B
#define GL_RGB_422_APPLE 0x8A1F
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_STENCIL_REF 0x0B97
#define GL_LUMINANCE_ALPHA8UI_EXT 0x8D81
#define GL_BLEND_EQUATION_RGB_EXT 0x8009
#define GL_COPY_WRITE_BUFFER 0x8F37
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_UNSIGNED_INT8_NV 0x8FEC
#define GL_RGBA4_DXT5_S3TC 0x83A5
#define GL_MODELVIEW13_ARB 0x872D
#define GL_FORCE_BLUE_TO_ONE_NV 0x8860
#define GL_DUAL_LUMINANCE4_SGIS 0x8114
#define GL_TEXTURE29_ARB 0x84DD
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS 0x811D
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_FULL_SUPPORT 0x82B7
#define GL_MAX_PALETTE_MATRICES_ARB 0x8842
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_VERTEX_ARRAY_POINTER_EXT 0x808E
#define GL_TEXTURE_MIN_LOD_SGIS 0x813A
#define GL_INT64_NV 0x140E
#define GL_FLOAT_RGB16_NV 0x8888
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87C5
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB 0x8B86
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_RASTER_MULTISAMPLE_EXT 0x9327
#define GL_SIGNED_RGB8_NV 0x86FF
#define GL_INDEX_MATERIAL_PARAMETER_EXT 0x81B9
#define GL_LEFT 0x0406
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x906A
#define GL_MIRRORED_REPEAT_IBM 0x8370
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_CONTEXT_LOST 0x0507
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT 0x8DDD
#define GL_ALPHA8I_EXT 0x8D90
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_CLEAR_BUFFER 0x82B4
#define GL_MATRIX12_ARB 0x88CC
#define GL_PROGRAM_POINT_SIZE_EXT 0x8642
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_CLAMP_FRAGMENT_COLOR_ARB 0x891B
#define GL_ATTRIB_ARRAY_STRIDE_NV 0x8624
#define GL_XOR_NV 0x1506
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_UNPACK_IMAGE_HEIGHT_EXT 0x806E
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV 0x8E24
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
#define GL_DRAW_BUFFER13_ARB 0x8832
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_DUAL_ALPHA12_SGIS 0x8112
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD 0x9003
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_FRAGMENT_NORMAL_EXT 0x834A
#define GL_DRAW_BUFFER10_ARB 0x882F
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT 0x8128
#define GL_FIXED_ONLY 0x891D
#define GL_VERTEX_ATTRIB_ARRAY11_NV 0x865B
#define GL_NONE 0
#define GL_POLYGON_MODE 0x0B40
#define GL_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define GL_LUMINANCE12_ALPHA12_EXT 0x8047
#define GL_LINEAR_DETAIL_SGIS 0x8097
#define GL_EXCLUSIVE_EXT 0x8F11
#define GL_SET_AMD 0x874A
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_INNOCENT_CONTEXT_RESET 0x8254
#define GL_PATH_GEN_COMPONENTS_NV 0x90B3
#define GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD 0x914A
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_SLUMINANCE_ALPHA_EXT 0x8C44
#define GL_PATH_FORMAT_PS_NV 0x9071
#define GL_PROGRAM_PIPELINE_OBJECT_EXT 0x8A4F
#define GL_INCLUSIVE_EXT 0x8F10
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_CW 0x0900
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AA
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_INT_SAMPLER_3D_EXT 0x8DCB
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_INT16_NV 0x8FE4
#define GL_COMPRESSED_RGB 0x84ED
#define GL_DUDV_ATI 0x8779
#define GL_SCISSOR_TEST 0x0C11
#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#define GL_TEXTURE12_ARB 0x84CC
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_SM_COUNT_NV 0x933B
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_QUERY_RESULT_ARB 0x8866
#define GL_OUTPUT_COLOR1_EXT 0x879C
#define GL_FLOAT_RG32_NV 0x8887
#define GL_RELATIVE_ARC_TO_NV 0xFF
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV 0x8906
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_1PASS_SGIS 0x80A1
#define GL_TABLE_TOO_LARGE_EXT 0x8031
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x906C
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_MATRIX5_ARB 0x88C5
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_LINE_STRIP 0x0003
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_VARIABLE_G_NV 0x8529
#define GL_DRAW_BUFFER0_ARB 0x8825
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN 0x85C2
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV 0x9034
#define GL_LUMINANCE6_ALPHA2_EXT 0x8044
#define GL_DEPTH_STENCIL 0x84F9
#define GL_CONSTANT_EXT 0x8576
#define GL_UNIFORM_BUFFER_BINDING_EXT 0x8DEF
#define GL_SYNC_CONDITION 0x9113
#define GL_TEXTURE_4D_SGIS 0x8134
#define GL_TEXTURE1_ARB 0x84C1
#define GL_COLOR_SUM_ARB 0x8458
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_REPLACE 0x1E01
#define GL_READ_BUFFER 0x0C02
#define GL_ELEMENT_ARRAY_APPLE 0x8A0C
#define GL_PATH_FILL_MASK_NV 0x9081
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_GEQUAL 0x0206
#define GL_MODELVIEW8_ARB 0x8728
#define GL_EXPAND_NORMAL_NV 0x8538
#define GL_R16F 0x822D
#define GL_MAX_4D_TEXTURE_SIZE_SGIS 0x8138
#define GL_QUERY_NO_WAIT_INVERTED 0x8E18
#define GL_VARIANT_EXT 0x87C1
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT 0x8E4C
#define GL_SHADOW_AMBIENT_SGIX 0x80BF
#define GL_VERTEX_ID_SWIZZLE_AMD 0x91A5
#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_LUMINANCE16_ALPHA16_SNORM 0x901A
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB 0x9340
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV 0x86F1
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MULTISAMPLE_SGIS 0x809D
#define GL_OBJECT_ATTACHED_OBJECTS_ARB 0x8B85
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_RELATIVE_CUBIC_CURVE_TO_NV 0x0D
#define GL_COLORBURN_NV 0x929A
#define GL_REG_28_ATI 0x893D
#define GL_VARIABLE_E_NV 0x8527
#define GL_IUI_N3F_V2F_EXT 0x81AF
#define GL_OFFSET_TEXTURE_2D_NV 0x86E8
#define GL_FRAMEBUFFER 0x8D40
#define GL_ALLOW_DRAW_WIN_HINT_PGI 0x1A20F
#define GL_COLOR_TABLE_FORMAT_SGI 0x80D8
#define GL_MAX_PROGRAM_ATTRIBS_ARB 0x88AD
#define GL_HALF_FLOAT_ARB 0x140B
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM 103086
#define GL_EVAL_VERTEX_ATTRIB10_NV 0x86D0
#define GL_PATH_INITIAL_DASH_CAP_NV 0x907C
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_RGB5_EXT 0x8050
#define GL_Y_EXT 0x87D6
#define GL_GENERATE_MIPMAP_SGIS 0x8191
#define GL_INTENSITY8UI_EXT 0x8D7F
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_QUERY_WAIT_NV 0x8E13
#define GL_ADD_ATI 0x8963
#define GL_INVERT_RGB_NV 0x92A3
#define GL_MULTISAMPLE_3DFX 0x86B2
#define GL_BINORMAL_ARRAY_TYPE_EXT 0x8440
#define GL_RGBA16I_EXT 0x8D88
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_REG_8_ATI 0x8929
#define GL_QUERY_RESULT_AVAILABLE_ARB 0x8867
#define GL_TEXTURE18_ARB 0x84D2
#define GL_RESAMPLE_DECIMATE_OML 0x8989
#define GL_PATH_FILL_COVER_MODE_NV 0x9082
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_INT_IMAGE_3D_EXT 0x9059
#define GL_DUAL_ALPHA4_SGIS 0x8110
#define GL_SPRITE_EYE_ALIGNED_SGIX 0x814E
#define GL_VERTEX_ATTRIB_ARRAY1_NV 0x8651
#define GL_MAX_WINDOW_RECTANGLES_EXT 0x8F14
#define GL_VARIANT_ARRAY_EXT 0x87E8
#define GL_LAST_VERTEX_CONVENTION_EXT 0x8E4E
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT 0x8004
#define GL_CURRENT_MATRIX_NV 0x8641
#define GL_UNSIGNED_SHORT 0x1403
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_COLOR_INDEX8_EXT 0x80E5
#define GL_PARALLEL_ARRAYS_INTEL 0x83F4
#define GL_AFFINE_3D_NV 0x9094
#define GL_OPERAND0_RGB_ARB 0x8590
#define GL_SWIZZLE_STQ_DQ_ATI 0x8979
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_EYE_RADIAL_NV 0x855B
#define GL_XOR 0x1506
#define GL_VERTEX_ATTRIB_ARRAY3_NV 0x8653
#define GL_RELATIVE_ROUNDED_RECT4_NV 0xED
#define GL_ALLOW_DRAW_MEM_HINT_PGI 0x1A211
#define GL_INT_SAMPLER_BUFFER_AMD 0x9002
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CA
#define GL_DEPTH_BOUNDS_TEST_EXT 0x8890
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_FONT_X_MIN_BOUNDS_BIT_NV 0x00010000
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CUBIC_WEIGHT_HP 0x815E
#define GL_REG_4_ATI 0x8925
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM 103085
#define GL_DOUBLE_MAT3x4_EXT 0x8F4C
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT 0x00000001
#define GL_ADD_SIGNED_EXT 0x8574
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI 0x87F6
#define GL_MAX_SHADER_COMPILER_THREADS_ARB 0x91B0
#define GL_CON_18_ATI 0x8953
#define GL_T2F_IUI_N3F_V3F_EXT 0x81B4
#define GL_REPEAT 0x2901
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT 0x8C8F
#define GL_OBJECT_DELETE_STATUS_ARB 0x8B80
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x00000000
#define GL_WEIGHT_ARRAY_SIZE_ARB 0x86AB
#define GL_UNSIGNED_INT64_VEC3_ARB 0x8FF6
#define GL_MAX_FRAGMENT_LIGHTS_SGIX 0x8404
#define GL_MAP1_VERTEX_ATTRIB8_4_NV 0x8668
#define GL_VERTEX_SHADER_EXT 0x8780
#define GL_OCCLUSION_TEST_HP 0x8165
#define GL_REG_25_ATI 0x893A
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT 0x8DD1
#define GL_DRAW_BUFFER12_ARB 0x8831
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_SAMPLE_MASK_EXT 0x80A0
#define GL_RGB16UI_EXT 0x8D77
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX 0x8176
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_COLOR_ATTACHMENT5_EXT 0x8CE5
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D1
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT 0x8002
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F4
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX 0x8360
#define GL_CONVOLUTION_WIDTH_EXT 0x8018
#define GL_IMAGE_CUBE_EXT 0x9050
#define GL_TEXTURE_TOO_LARGE_EXT 0x8065
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS 0x8096
#define GL_FLOAT16_MAT4x2_AMD 0x91CC
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_REG_17_ATI 0x8932
#define GL_INT64_VEC3_ARB 0x8FEA
#define GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX 0x904A
#define GL_OUTPUT_TEXTURE_COORD28_EXT 0x87B9
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_NEGATIVE_W_EXT 0x87DC
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_OBJECT_LINE_SGIS 0x81F7
#define GL_COMPARE_R_TO_TEXTURE_ARB 0x884E
#define GL_FLOAT_RGBA_NV 0x8883
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_SAMPLE_MASK_VALUE_EXT 0x80AA
#define GL_REG_30_ATI 0x893F
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_NORMAL_ARRAY_LENGTH_NV 0x8F2C
#define GL_CON_28_ATI 0x895D
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_PERFMON_RESULT_AMD 0x8BC6
#define GL_STENCIL_INDEX8_EXT 0x8D48
#define GL_MODULATE_ADD_ATI 0x8744
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_TESS_EVALUATION_PROGRAM_NV 0x891F
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV 0x933F
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV 0x88FD
#define GL_VERTEX_ARRAY_LENGTH_NV 0x8F2B
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB 0x933E
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_SCALE_BY_ONE_HALF_NV 0x8540
#define GL_DRAW_BUFFER5_ARB 0x882A
#define GL_TEXTURE_VIEW 0x82B5
#define GL_TEXTURE_SWIZZLE_B_EXT 0x8E44
#define GL_FRAGMENT_LIGHT0_SGIX 0x840C
#define GL_TANGENT_ARRAY_POINTER_EXT 0x8442
#define GL_DOT4_ATI 0x8967
#define GL_VERTEX_ATTRIB_ARRAY12_NV 0x865C
#define GL_UNSIGNED_INT8_VEC4_NV 0x8FEF
#define GL_OUTPUT_TEXTURE_COORD13_EXT 0x87AA
#define GL_MAX_RASTER_SAMPLES_EXT 0x9329
#define GL_RG32UI 0x823C
#define GL_OUTPUT_TEXTURE_COORD7_EXT 0x87A4
#define GL_SAMPLE_BUFFERS_SGIS 0x80A8
#define GL_INTERLACE_READ_INGR 0x8568
#define GL_INTERLEAVED_ATTRIBS_NV 0x8C8C
#define GL_REG_3_ATI 0x8924
#define GL_QUERY_TARGET 0x82EA
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV 0x885A
#define GL_VERTEX_ATTRIB_ARRAY10_NV 0x865A
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI 0x80B8
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT 0x8454
#define GL_MATRIX11_ARB 0x88CB
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_TEXTURE_RANGE_LENGTH_APPLE 0x85B7
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_VERTEX_PROGRAM_BINDING_NV 0x864A
#define GL_PATH_FORMAT_SVG_NV 0x9070
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_RGBA_FLOAT32_ATI 0x8814
#define GL_COLOR4_BIT_PGI 0x00020000
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_DRAW_BUFFER13_ATI 0x8832
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_MAX_ASYNC_HISTOGRAM_SGIX 0x832D
#define GL_BIAS_BIT_ATI 0x00000008
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV 0x8853
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV 0x8E5A
#define GL_PROGRAM_ERROR_POSITION_ARB 0x864B
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV 0x86F2
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV 0x86E1
#define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19
#define GL_VERTEX_ARRAY_LIST_IBM 103070
#define GL_LUMINANCE32F_ARB 0x8818
#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB 0x9198
#define GL_STENCIL_OP_VALUE_AMD 0x874C
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_INTENSITY16UI_EXT 0x8D79
#define GL_TEXTURE_COLOR_SAMPLES_NV 0x9046
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_TEXTURE_NORMAL_EXT 0x85AF
#define GL_FLOAT16_VEC4_NV 0x8FFB
#define GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE 0x8A07
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0E
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR 0x93B1
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV 0xF2
#define GL_SINGLE_COLOR_EXT 0x81F9
#define GL_TEXTURE_ENV_BIAS_SGIX 0x80BE
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_MAX_LEVEL_SGIS 0x813D
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT 0x87CD
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_QUERY_RESULT 0x8866
#define GL_SRC_OUT_NV 0x928C
#define GL_R16_SNORM 0x8F98
#define GL_DEBUG_SEVERITY_HIGH_AMD 0x9146
#define GL_DOUBLE_VEC2_EXT 0x8FFC
#define GL_DOT_PRODUCT_TEXTURE_1D_NV 0x885C
#define GL_OP_SUB_EXT 0x8796
#define GL_COLOR_ATTACHMENT1_EXT 0x8CE1
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR 0x93B3
#define GL_IMAGE_2D 0x904D
#define GL_RGB16_SNORM 0x8F9A
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_OUTPUT_TEXTURE_COORD30_EXT 0x87BB
#define GL_CONIC_CURVE_TO_NV 0x1A
#define GL_ASYNC_DRAW_PIXELS_SGIX 0x835D
#define GL_TEXTURE_MAX_CLAMP_T_SGIX 0x836A
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_WRITE_ONLY_ARB 0x88B9
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_SUBTRACT_ARB 0x84E7
#define GL_INT64_VEC3_NV 0x8FEA
#define GL_OCCLUSION_QUERY_EVENT_MASK_AMD 0x874F
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_UNSIGNED_INT_IMAGE_1D_EXT 0x9062
#define GL_DRAW_BUFFER2_ARB 0x8827
#define GL_PARAMETER_BUFFER_ARB 0x80EE
#define GL_FOG_DISTANCE_MODE_NV 0x855A
#define GL_CON_0_ATI 0x8941
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR 0x9630
#define GL_4X_BIT_ATI 0x00000002
#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
#define GL_RG 0x8227
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV 0x8C27
#define GL_DYNAMIC_ATI 0x8761
#define GL_GREEN_INTEGER 0x8D95
#define GL_DOT3_RGB_EXT 0x8740
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_DRAW_BUFFER11_ATI 0x8830
#define GL_OP_FLOOR_EXT 0x878F
#define GL_ALPHA16F_ARB 0x881C
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_REPLACEMENT_CODE_SUN 0x81D8
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
#define GL_IMAGE_SCALE_Y_HP 0x8156
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX 0x8408
#define GL_FLOAT_R_NV 0x8880
#define GL_FUNC_ADD_EXT 0x8006
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_VERTEX_STREAM1_ATI 0x876D
#define GL_UNSIGNED_INT64_VEC2_ARB 0x8FF5
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_COLOR_ARRAY_SIZE_EXT 0x8081
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT 0x808D
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS 0x809C
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT 0x8034
#define GL_ZERO_TO_ONE 0x935F
#define GL_OVERLAY_KHR 0x9296
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT 0x8C73
#define GL_VERTEX_STREAM7_ATI 0x8773
#define GL_PRIMARY_COLOR_EXT 0x8577
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_R8 0x8229
#define GL_NUM_LOOPBACK_COMPONENTS_ATI 0x8974
#define GL_BOUNDING_BOX_NV 0x908D
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_CON_23_ATI 0x8958
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_POINT_SPRITE_ARB 0x8861
#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR 0x93B2
#define GL_PERFQUERY_COUNTER_EVENT_INTEL 0x94F0
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT 0x8D56
#define GL_MODELVIEW24_ARB 0x8738
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
#define GL_R1UI_C4UB_V3F_SUN 0x85C5
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_VIEWPORT 0x0BA2
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_DS_SCALE_NV 0x8710
#define GL_UNSIGNED_INT_IMAGE_2D_EXT 0x9063
#define GL_FOG_SPECULAR_TEXTURE_WIN 0x80EC
#define GL_CON_14_ATI 0x894F
#define GL_PIXEL_SUBSAMPLE_2424_SGIX 0x85A3
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_TEXTURE_MATERIAL_FACE_EXT 0x8351
#define GL_ONE_EXT 0x87DE
#define GL_FONT_X_MAX_BOUNDS_BIT_NV 0x00040000
#define GL_MODELVIEW7_ARB 0x8727
#define GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV 0x90D0
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#define GL_SAMPLER_2D_RECT_SHADOW_ARB 0x8B64
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_WRITE_PIXEL_DATA_RANGE_NV 0x8878
#define GL_WEIGHT_ARRAY_ARB 0x86AD
#define GL_WRITE_DISCARD_NV 0x88BE
#define GL_DEPENDENT_AR_TEXTURE_2D_NV 0x86E9
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV 0x8872
#define GL_FONT_UNINTELLIGIBLE_NV 0x936B
#define GL_RGBA_DXT5_S3TC 0x83A4
#define GL_HISTOGRAM_SINK_EXT 0x802D
#define GL_PIXEL_TILE_WIDTH_SGIX 0x8140
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI 0x00200000
#define GL_TRIANGLES_ADJACENCY_EXT 0x000C
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_INT_IMAGE_2D_RECT_EXT 0x905A
#define GL_PROGRAM_TEMPORARIES_ARB 0x88A4
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB 0x9196
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV 0x9038
#define GL_GREEN_MAX_CLAMP_INGR 0x8565
#define GL_TEXTURE_DEPTH_EXT 0x8071
#define GL_SHADER 0x82E1
#define GL_QUERY_BUFFER_AMD 0x9192
#define GL_UNIFORM_BUFFER_LENGTH_NV 0x9370
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87CC
#define GL_RED_INTEGER 0x8D94
#define GL_CONVOLUTION_BORDER_MODE_EXT 0x8013
#define GL_REDUCE_EXT 0x8016
#define GL_HARDLIGHT_NV 0x929B
#define GL_OPERAND2_ALPHA_ARB 0x859A
#define GL_DUAL_LUMINANCE16_SGIS 0x8117
#define GL_INT64_ARB 0x140E
#define GL_PN_TRIANGLES_ATI 0x87F0
#define GL_NOP_COMMAND_NV 0x0001
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN 0x85C3
#define GL_BLEND 0x0BE2
#define GL_DEPENDENT_GB_TEXTURE_2D_NV 0x86EA
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV 0x8858
#define GL_PROXY_TEXTURE_2D_STACK_MESAX 0x875C
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_FRAGMENT_LIGHT7_SGIX 0x8413
#define GL_FRAGMENT_DEPTH_EXT 0x8452
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PATCHES 0x000E
#define GL_COLORDODGE_NV 0x9299
#define GL_COORD_REPLACE_NV 0x8862
#define GL_COLOR_ATTACHMENT14_EXT 0x8CEE
#define GL_IMAGE_2D_EXT 0x904D
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x8DBA
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_SRGB_ALPHA 0x8C42
#define GL_DRAW_BUFFER9_ARB 0x882E
#define GL_RGBA16I 0x8D88
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV 0x954F
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_INT_IMAGE_CUBE_EXT 0x905B
#define GL_REG_20_ATI 0x8935
#define GL_DRAW_BUFFER6_ARB 0x882B
#define GL_R8I 0x8231
#define GL_COMBINER3_NV 0x8553
#define GL_LUMINANCE8_EXT 0x8040
#define GL_PROGRAM_RESIDENT_NV 0x8647
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT 0x8089
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV 0x8C83
#define GL_BLEND_COLOR 0x8005
#define GL_SAMPLE_PATTERN_EXT 0x80AC
#define GL_FILTER4_SGIS 0x8146
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_BUFFER_OBJECT_APPLE 0x85B3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT 0x8DC4
#define GL_CON_22_ATI 0x8957
#define GL_SUBSAMPLE_DISTANCE_AMD 0x883F
#define GL_TRANSLATE_3D_NV 0x9091
#define GL_CON_8_ATI 0x8949
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_ALPHA_MAX_CLAMP_INGR 0x8567
#define GL_DRAW_BUFFER14 0x8833
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_BLEND_SRC_ALPHA_EXT 0x80CB
#define GL_OUTPUT_TEXTURE_COORD22_EXT 0x87B3
#define GL_INTENSITY32F_ARB 0x8817
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_ADJACENT_PAIRS_NV 0x90AE
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT 0x00000008
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM 103081
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_SAMPLES_PASSED 0x8914
#define GL_REPLACE_EXT 0x8062
#define GL_MATRIX26_ARB 0x88DA
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_IMAGE_3D 0x904E
#define GL_TEXTURE_COLOR_TABLE_SGI 0x80BC
#define GL_LIGHTEN_NV 0x9298
#define GL_MAP1_VERTEX_ATTRIB1_4_NV 0x8661
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DEPTH_COMPONENT16_ARB 0x81A5
#define GL_CULL_VERTEX_EXT 0x81AA
#define GL_FONT_UNAVAILABLE_NV 0x936A
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_COMBINER_COMPONENT_USAGE_NV 0x8544
#define GL_CULL_FRAGMENT_NV 0x86E7
#define GL_RGBA_FLOAT_MODE_ARB 0x8820
#define GL_TEXTURE_SPARSE_ARB 0x91A6
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI 0x80DE
#define GL_TEXTURE_BINDING_BUFFER_EXT 0x8C2C
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8336
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_PRESERVE_ATI 0x8762
#define GL_DSDT_MAG_VIB_NV 0x86F7
#define GL_TEXTURE_DEPTH_SIZE_ARB 0x884A
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_DEPTH_STENCIL_EXT 0x84F9
#define GL_EVAL_VERTEX_ATTRIB0_NV 0x86C6
#define GL_VERTEX_ATTRIB_ARRAY5_NV 0x8655
#define GL_SRGB_EXT 0x8C40
#define GL_PERFQUERY_DONOT_FLUSH_INTEL 0x83F9
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR 0x93B4
#define GL_TEXTURE_LUMINANCE_SIZE_EXT 0x8060
#define GL_CON_1_ATI 0x8942
#define GL_VERTEX_SOURCE_ATI 0x8774
#define GL_TEXTURE26_ARB 0x84DA
#define GL_MATRIX29_ARB 0x88DD
#define GL_MAX_PROGRAM_TEXEL_OFFSET_EXT 0x8905
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT 0x8510
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF
#define GL_NEGATIVE_ONE_TO_ONE 0x935E
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_VIRTUAL_PAGE_SIZE_Y_AMD 0x9196
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT 0x8033
#define GL_LINEAR_SHARPEN_COLOR_SGIS 0x80AF
#define GL_DST_COLOR 0x0306
#define GL_DOT3_ATI 0x8966
#define GL_MAX_SAMPLES_EXT 0x8D57
#define GL_DRAW_BUFFER5_ATI 0x882A
#define GL_DEPTH_BOUNDS_EXT 0x8891
#define GL_GREEN 0x1904
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_DRAW_BUFFER15_ATI 0x8834
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR 0x93B9
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB 0x88B7
#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT 0x00000080
#define GL_RG16_SNORM 0x8F99
#define GL_DUAL_ALPHA16_SGIS 0x8113
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
#define GL_COLOR_TABLE_WIDTH_SGI 0x80D9
#define GL_TEXTURE_2D_STACK_MESAX 0x875A
#define GL_RG_INTEGER 0x8228
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_SOURCE0_ALPHA_EXT 0x8588
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV 0x8F44
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RGB4_S3TC 0x83A1
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_OPERAND1_ALPHA_EXT 0x8599
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_MAX_DEBUG_MESSAGE_LENGTH_AMD 0x9143
#define GL_RGBA4_EXT 0x8056
#define GL_LUMINANCE16_SNORM 0x9019
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_SOURCE3_RGB_NV 0x8583
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_CURRENT_BINORMAL_EXT 0x843C
#define GL_STREAM_COPY 0x88E2
#define GL_INT64_VEC2_NV 0x8FE9
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_RELATIVE_RECT_NV 0xF7
#define GL_SAMPLER_BUFFER_EXT 0x8DC2
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV 0x870D
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_DRAW_FRAMEBUFFER_EXT 0x8CA9
#define GL_DRAW_BUFFER14_ARB 0x8833
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT 0x8C7F
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_INT8_VEC4_NV 0x8FE3
#define GL_REFLECTION_MAP_ARB 0x8512
#define GL_NUM_FRAGMENT_REGISTERS_ATI 0x896E
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_OBJECT_COMPILE_STATUS_ARB 0x8B81
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_FASTEST 0x1101
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_IMAGE_TRANSLATE_X_HP 0x8157
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_INDEX_BIT_PGI 0x00080000
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_MATRIX2_ARB 0x88C2
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_INTENSITY8_EXT 0x804B
#define GL_SAMPLER_CUBE_ARB 0x8B60
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_FLOAT_R16_NV 0x8884
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35
#define GL_VERTEX_SHADER_LOCALS_EXT 0x87D3
#define GL_4PASS_3_SGIS 0x80A7
#define GL_TEXTURE_WIDTH 0x1000
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV 0x13
#define GL_UNIFORM_SIZE 0x8A38
#define GL_QUERY_RESULT_NO_WAIT_AMD 0x9194
#define GL_OFFSET_TEXTURE_MATRIX_NV 0x86E1
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_UNPACK_IMAGE_DEPTH_SGIS 0x8133
#define GL_PATH_PROJECTION_NV 0x1701
#define GL_OFFSET_TEXTURE_2D_BIAS_NV 0x86E3
#define GL_GLYPH_HAS_KERNING_BIT_NV 0x100
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV 0x8E10
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_OUT_OF_MEMORY 0x0505
#define GL_TEXTURE30_ARB 0x84DE
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_HSL_LUMINOSITY_KHR 0x92B0
#define GL_ARRAY_SIZE 0x92FB
#define GL_SOURCE1_RGB_EXT 0x8581
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_PHONG_HINT_WIN 0x80EB
#define GL_CURRENT_TIME_NV 0x8E28
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_RENDERBUFFER_SAMPLES_EXT 0x8CAB
#define GL_TEXTURE_BUFFER_EXT 0x8C2A
#define GL_PALETTE8_RGB5_A1_OES 0x8B99
#define GL_DRAW_BUFFER2_ATI 0x8827
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT 0x8C83
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_COMPRESSED_SRGB_ALPHA_EXT 0x8C49
#define GL_STENCIL_TEST 0x0B90
#define GL_ALPHA32UI_EXT 0x8D72
#define GL_WEIGHT_ARRAY_TYPE_ARB 0x86A9
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_ARRAY_BUFFER_BINDING_ARB 0x8894
#define GL_PROGRAM_RESULT_COMPONENTS_NV 0x8907
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS 0x8354
#define GL_VIRTUAL_PAGE_SIZE_X_ARB 0x9195
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX 0x8171
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX 0x8142
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH_STENCIL_TO_RGBA_NV 0x886E
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_PACK_ROW_BYTES_APPLE 0x8A15
#define GL_FILTER 0x829A
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_PREVIOUS_EXT 0x8578
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_TEXTURE17_ARB 0x84D1
#define GL_TRACK_MATRIX_TRANSFORM_NV 0x8649
#define GL_DOT_PRODUCT_TEXTURE_3D_NV 0x86EF
#define GL_MAGNITUDE_BIAS_NV 0x8718
#define GL_RELATIVE_ROUNDED_RECT8_NV 0xEF
#define GL_VERTEX_ARRAY_TYPE_EXT 0x807B
#define GL_VARIANT_DATATYPE_EXT 0x87E5
#define GL_SHADER_OBJECT_ARB 0x8B48
#define GL_422_REV_EXT 0x80CD
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9061
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_RGB16I 0x8D89
#define GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX 0x904B
#define GL_COLOR_TABLE_SGI 0x80D0
#define GL_RGB16F 0x881B
#define GL_MIRROR_CLAMP_EXT 0x8742
#define GL_MODELVIEW31_ARB 0x873F
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX 0x840A
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_COLOR_ATTACHMENT4_EXT 0x8CE4
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_GPU_ADDRESS_NV 0x8F34
#define GL_MATRIX8_ARB 0x88C8
#define GL_CONDITION_SATISFIED 0x911C
#define GL_SUB_ATI 0x8965
#define GL_UNSIGNED_NORMALIZED_ARB 0x8C17
#define GL_GENERIC_ATTRIB_NV 0x8C7D
#define GL_BUFFER_OBJECT_EXT 0x9151
#define GL_BGR_INTEGER_EXT 0x8D9A
#define GL_CON_20_ATI 0x8955
#define GL_DYNAMIC_COPY 0x88EA
#define GL_VIDEO_BUFFER_NV 0x9020
#define GL_INTERLACE_READ_OML 0x8981
#define GL_OUTPUT_TEXTURE_COORD18_EXT 0x87AF
#define GL_RGB565 0x8D62
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_CURRENT_VERTEX_ATTRIB_ARB 0x8626
#define GL_VERTEX_SHADER_ARB 0x8B31
#define GL_PIXEL_PACK_BUFFER_EXT 0x88EB
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_GEOMETRY_DEFORMATION_SGIX 0x8194
#define GL_SAMPLE_BUFFERS_3DFX 0x86B3
#define GL_VERTEX_PROGRAM_NV 0x8620
#define GL_LUMINANCE_ALPHA16I_EXT 0x8D8D
#define GL_COMBINER_AB_OUTPUT_NV 0x854A
#define GL_DUAL_TEXTURE_SELECT_SGIS 0x8124
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_DRAW_BUFFER10_ATI 0x882F
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX 0x8409
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_COMBINE_RGB_ARB 0x8571
#define GL_DUAL_LUMINANCE8_SGIS 0x8115
#define GL_FAILURE_NV 0x9030
#define GL_TEXTURE13_ARB 0x84CD
#define GL_ALWAYS_SOFT_HINT_PGI 0x1A20D
#define GL_DRAW_ELEMENTS_COMMAND_NV 0x0002
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LOCAL_CONSTANT_EXT 0x87C3
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_VARIABLE_D_NV 0x8526
#define GL_MAP_READ_BIT 0x0001
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_COMBINER6_NV 0x8556
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_VERTEX_ARRAY_ADDRESS_NV 0x8F21
#define GL_STRICT_LIGHTING_HINT_PGI 0x1A217
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_COMBINER4_NV 0x8554
#define GL_RELEASED_APPLE 0x8A19
#define GL_INTENSITY16I_EXT 0x8D8B
#define GL_MAP1_VERTEX_ATTRIB3_4_NV 0x8663
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_TEXTURE_RED_SIZE_EXT 0x805C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B3
#define GL_MAX_ELEMENTS_VERTICES_EXT 0x80E8
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS 0x81F1
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x905F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV 0x8C80
#define GL_DEPTH_CLAMP_NV 0x864F
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT 0x8CDD
#define GL_RGBA12 0x805A
#define GL_PERFQUERY_FLUSH_INTEL 0x83FA
#define GL_RGBA16 0x805B
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_COMBINER0_NV 0x8550
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV 0x864E
#define GL_HALF_BIT_ATI 0x00000008
#define GL_CON_31_ATI 0x8960
#define GL_SOURCE1_ALPHA_EXT 0x8589
#define GL_CIRCULAR_CW_ARC_TO_NV 0xFA
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_TEXTURE_GEQUAL_R_SGIX 0x819D
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV 0x8521
#define GL_CON_27_ATI 0x895C
#define GL_READ_FRAMEBUFFER_EXT 0x8CA8
#define GL_NORMAL_ARRAY_LIST_IBM 103071
#define GL_MAP1_VERTEX_ATTRIB13_4_NV 0x866D
#define GL_OUTPUT_TEXTURE_COORD14_EXT 0x87AB
#define GL_SAMPLE_ALPHA_TO_ONE_ARB 0x809F
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV 0x8541
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_INVARIANT_DATATYPE_EXT 0x87EB
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV 0x8F30
#define GL_CON_25_ATI 0x895A
#define GL_IMAGE_BINDING_LAYER_EXT 0x8F3D
#define GL_NOTEQUAL 0x0205
#define GL_TEXTURE_SWIZZLE_RGBA_EXT 0x8E46
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR 0x93B5
#define GL_MAT_EMISSION_BIT_PGI 0x00800000
#define GL_DATA_BUFFER_AMD 0x9151
#define GL_SEPARATE_SPECULAR_COLOR_EXT 0x81FA
#define GL_PATH_FILL_MODE_NV 0x9080
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV 0x88F7
#define GL_CURRENT_QUERY_ARB 0x8865
#define GL_RGBA12_EXT 0x805A
#define GL_COMBINER2_NV 0x8552
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV 0x8851
#define GL_OPERAND2_ALPHA_EXT 0x859A
#define GL_SOFTLIGHT_KHR 0x929C
#define GL_OUTPUT_TEXTURE_COORD11_EXT 0x87A8
#define GL_SATURATE_BIT_ATI 0x00000040
#define GL_DEFORMATIONS_MASK_SGIX 0x8196
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_RED_MAX_CLAMP_INGR 0x8564
#define GL_COMBINER_CD_DOT_PRODUCT_NV 0x8546
#define GL_DOUBLE_VEC4_EXT 0x8FFE
#define GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV 0x8C74
#define GL_INTENSITY16F_ARB 0x881D
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_OUTPUT_TEXTURE_COORD16_EXT 0x87AD
#define GL_BLUE 0x1905
#define GL_CURRENT_SECONDARY_COLOR_EXT 0x8459
#define GL_STENCIL_BACK_FUNC_ATI 0x8800
#define GL_IMAGE_1D 0x904C
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV 0x8856
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_TEXTURE_SHADER_NV 0x86DE
#define GL_STATIC_DRAW 0x88E4
#define GL_TEXTURE_BORDER_VALUES_NV 0x871A
#define GL_VERTEX_STATE_PROGRAM_NV 0x8621
#define GL_RGB_FLOAT32_ATI 0x8815
#define GL_INTENSITY16_EXT 0x804D
#define GL_SOURCE0_ALPHA_ARB 0x8588
#define GL_PER_STAGE_CONSTANTS_NV 0x8535
#define GL_SAMPLER_3D 0x8B5F
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_YCBAYCR8A_4224_NV 0x9032
#define GL_OR_INVERTED 0x150D
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_FULL_STIPPLE_HINT_PGI 0x1A219
#define GL_BUFFER_SIZE_ARB 0x8764
#define GL_COLOR_ATTACHMENT7_EXT 0x8CE7
#define GL_TEXTURE8_ARB 0x84C8
#define GL_ARC_TO_NV 0xFE
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_INTENSITY_EXT 0x8049
#define GL_SIGNED_IDENTITY_NV 0x853C
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5F
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNDEFINED_VERTEX 0x8260
#define GL_SWIZZLE_STR_DR_ATI 0x8978
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_IMAGE_2D_RECT 0x904F
#define GL_OBJECT_BUFFER_SIZE_ATI 0x8764
#define GL_SAMPLER 0x82E6
#define GL_SAMPLES 0x80A9
#define GL_LUMINANCE_ALPHA_FLOAT16_APPLE 0x881F
#define GL_DEBUG_LOGGED_MESSAGES_AMD 0x9145
#define GL_COLOR_ARRAY_EXT 0x8076
#define GL_BUFFER_SERIALIZED_MODIFY_APPLE 0x8A12
#define GL_R1UI_V3F_SUN 0x85C4
#define GL_MAX_VARYING_COMPONENTS_EXT 0x8B4B
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_LUMINANCE_INTEGER_EXT 0x8D9C
#define GL_AVERAGE_HP 0x8160
#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_REG_29_ATI 0x893E
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#define GL_SPRITE_MODE_SGIX 0x8149
#define GL_FLOAT_RG16_NV 0x8886
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_RGB32UI 0x8D71
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_PROGRAM_ERROR_POSITION_NV 0x864B
#define GL_TEXTURE4_ARB 0x84C4
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_STENCIL_BACK_FAIL_ATI 0x8801
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT 0x8DE3
#define GL_CON_13_ATI 0x894E
#define GL_RG8UI 0x8238
#define GL_TEXTURE8 0x84C8
#define GL_MAP2_TANGENT_EXT 0x8445
#define GL_TEXTURE4 0x84C4
#define GL_INT64_VEC2_ARB 0x8FE9
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_BOOL_VEC4 0x8B59
#define GL_RENDERBUFFER_BINDING_EXT 0x8CA7
#define GL_REG_10_ATI 0x892B
#define GL_NORMAL_MAP_NV 0x8511
#define GL_STREAM_READ_ARB 0x88E1
#define GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD 0x914E
#define GL_OBJECT_VALIDATE_STATUS_ARB 0x8B83
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_RESAMPLE_REPLICATE_SGIX 0x8433
#define GL_ONE 1
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV 0x8DA5
#define GL_VECTOR_EXT 0x87BF
#define GL_DEPTH_CLAMP_NEAR_AMD 0x901E
#define GL_DRAW_PIXELS_APPLE 0x8A0A
#define GL_MAX_DEBUG_LOGGED_MESSAGES_AMD 0x9144
#define GL_TEXTURE_POST_SPECULAR_HP 0x8168
#define GL_EMBOSS_LIGHT_NV 0x855D
#define GL_RESCALE_NORMAL_EXT 0x803A
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI 0x8819
#define GL_R1UI_C4F_N3F_V3F_SUN 0x85C8
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_VERTEX_ARRAY_BINDING 0x85B5
#define GL_NATIVE_GRAPHICS_END_HINT_PGI 0x1A204
#define GL_COMBINER_AB_DOT_PRODUCT_NV 0x8545
#define GL_CLIP_FAR_HINT_PGI 0x1A221
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_PRIMITIVE_RESTART_INDEX_NV 0x8559
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT 0x851B
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F
#define GL_MAX_VERTEX_STREAMS_ATI 0x876B
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE7 0x3007
#define GL_FLOAT16_MAT3_AMD 0x91C6
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV 0x9027
#define GL_TEXTURE_COMPARE_MODE_ARB 0x884C
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV 0x9039
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MODELVIEW0_EXT 0x1700
#define GL_WINDOW_RECTANGLE_EXT 0x8F12
#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_DOUBLE_VEC4 0x8FFE
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_SAMPLES_EXT 0x80A9
#define GL_MAP1_VERTEX_ATTRIB10_4_NV 0x866A
#define GL_RGBA16UI 0x8D76
#define GL_INTENSITY12_EXT 0x804C
#define GL_OUTPUT_TEXTURE_COORD5_EXT 0x87A2
#define GL_UNSIGNED_INT64_ARB 0x140F
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_MODELVIEW21_ARB 0x8735
#define GL_UNSIGNED_IDENTITY_NV 0x8536
#define GL_R32UI 0x8236
#define GL_RGBA8_EXT 0x8058
#define GL_QUERY_OBJECT_EXT 0x9153
#define GL_CON_3_ATI 0x8944
#define GL_E_TIMES_F_NV 0x8531
#define GL_COLOR_ATTACHMENT9_EXT 0x8CE9
#define GL_TEXT_FRAGMENT_SHADER_ATI 0x8200
#define GL_FLOAT16_MAT2x3_AMD 0x91C8
#define GL_4PASS_1_SGIS 0x80A5
#define GL_VERSION 0x1F02
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_MATRIX2_NV 0x8632
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B2
#define GL_ALL_BARRIER_BITS_EXT 0xFFFFFFFF
#define GL_4PASS_2_SGIS 0x80A6
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT 0x8CD6
#define GL_COMMAND_BARRIER_BIT_EXT 0x00000040
#define GL_SIGNED_LUMINANCE8_NV 0x8702
#define GL_NUM_WINDOW_RECTANGLES_EXT 0x8F15
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI 0x87F8
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MODELVIEW4_ARB 0x8724
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TRACK_MATRIX_NV 0x8648
#define GL_FLOAT_R32_NV 0x8885
#define GL_IMAGE_BINDING_LAYERED_EXT 0x8F3C
#define GL_MULTISAMPLE 0x809D
#define GL_EVAL_VERTEX_ATTRIB6_NV 0x86CC
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_FUNC_SUBTRACT 0x800A
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_ELEMENT_INDEX 0x8D6B
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT16 0x8CF0
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT19 0x8CF3
#define GL_COLOR_ATTACHMENT18 0x8CF2
#define GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD 0x914C
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT 0x8C85
#define GL_MAX_RATIONAL_EVAL_ORDER_NV 0x86D7
#define GL_VERTEX_ARRAY_RANGE_APPLE 0x851D
#define GL_QUAD_ALPHA8_SGIS 0x811F
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES 0x8B9B
#define GL_DYNAMIC_DRAW_ARB 0x88E8
#define GL_QUERY_STENCIL_FAIL_EVENT_BIT_AMD 0x00000004
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_CONJOINT_NV 0x9284
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV 0x8C28
#define GL_COMPUTE_SHADER 0x91B9
#define GL_COMBINER7_NV 0x8557
#define GL_HSL_SATURATION_NV 0x92AE
#define GL_QUERY 0x82E3
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI 0x80BD
#define GL_RELATIVE_ROUNDED_RECT_NV 0xE9
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB 0x91A7
#define GL_VERTICAL_LINE_TO_NV 0x08
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_RESAMPLE_DECIMATE_SGIX 0x8430
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_MAX_UNIFORM_LOCATIONS 0x826E
#define GL_VERTEX_ATTRIB_ARRAY0_NV 0x8650
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_FLOAT 0x1406
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI 0x8972
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333
#define GL_UNPACK_RESAMPLE_SGIX 0x842F
#define GL_SAMPLER_2D 0x8B5E
#define GL_IMAGE_BUFFER 0x9051
#define GL_FONT_UNITS_PER_EM_BIT_NV 0x00100000
#define GL_SLUMINANCE8_EXT 0x8C47
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN 0x85CB
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV 0xF4
#define GL_COMBINER1_NV 0x8551
#define GL_SWIZZLE_STR_ATI 0x8976
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_LINK_STATUS 0x8B82
#define GL_DEBUG_CATEGORY_OTHER_AMD 0x9150
#define GL_ROUNDED_RECT_NV 0xE8
#define GL_MATRIX0_NV 0x8630
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_TYPE 0x92FA
#define GL_ELEMENT_ARRAY_POINTER_APPLE 0x8A0E
#define GL_YCRCB_SGIX 0x8318
#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_RGBA8I_EXT 0x8D8E
#define GL_MAT_SHININESS_BIT_PGI 0x02000000
#define GL_TEXTURE14_ARB 0x84CE
#define GL_MODELVIEW29_ARB 0x873D
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT 0x8DED
#define GL_PROXY_TEXTURE_4D_SGIS 0x8135
#define GL_FILL_RECTANGLE_NV 0x933C
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_BUMP_ENVMAP_ATI 0x877B
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV 0x937D
#define GL_MATRIX_INDEX_ARRAY_ARB 0x8844
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_OUTPUT_TEXTURE_COORD31_EXT 0x87BC
#define GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE 0x8A03
#define GL_TEXTURE_REDUCTION_MODE_ARB 0x9366
#define GL_RGB32I 0x8D83
#define GL_OUTPUT_TEXTURE_COORD26_EXT 0x87B7
#define GL_FALSE 0
#define GL_MAP2_VERTEX_ATTRIB9_4_NV 0x8679
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_MAX_VERTEX_HINT_PGI 0x1A22D
#define GL_VIRTUAL_PAGE_SIZE_X_AMD 0x9195
#define GL_PROGRAM_BINDING_ARB 0x8677
#define GL_FRAMEZOOM_FACTOR_SGIX 0x818C
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB 0x8514
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT 0x801E
#define GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV 0x937B
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_UNSIGNED_INT_VEC2_EXT 0x8DC6
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DISCRETE_AMD 0x9006
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV 0x86F0
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8163
#define GL_DOUBLE_VEC3_EXT 0x8FFD
#define GL_UNSIGNED_INT_S8_S8_8_8_NV 0x86DA
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_PRIMITIVE_BOUNDING_BOX_ARB 0x92BE
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNSIGNED_INT_24_8_NV 0x84FA
#define GL_FRONT 0x0404
#define GL_INDEX_MATERIAL_FACE_EXT 0x81BA
#define GL_VERTEX_CONSISTENT_HINT_PGI 0x1A22B
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_LUMINANCE_FLOAT16_ATI 0x881E
#define GL_TRIANGLE_MESH_SUN 0x8615
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_PURGEABLE_APPLE 0x8A1D
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_COLOR_RENDERABLE 0x8286
#define GL_SET 0x150F
#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV 0x86F3
#define GL_MAT_AMBIENT_BIT_PGI 0x00100000
#define GL_HSL_HUE_KHR 0x92AD
#define GL_HSL_SATURATION_KHR 0x92AE
#define GL_TEXTURE9 0x84C9
#define GL_INVALID_ENUM 0x0500
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT 0x8DDE
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR 0x93B6
#define GL_STANDARD_FONT_NAME_NV 0x9072
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT 0x8D53
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB 0x809E
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_SAMPLE_COVERAGE_VALUE_ARB 0x80AA
#define GL_MULTISAMPLE_COVERAGE_MODES_NV 0x8E12
#define GL_PRESENT_DURATION_NV 0x8E2B
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV 0x887D
#define GL_OBJECT_BUFFER_USAGE_ATI 0x8765
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT 0x81A8
#define GL_PREFER_DOUBLEBUFFER_HINT_PGI 0x1A1F8
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_STANDARD_FONT_FORMAT_NV 0x936C
#define GL_INT_IMAGE_1D 0x9057
#define GL_MAP2_VERTEX_ATTRIB3_4_NV 0x8673
#define GL_MAP1_TANGENT_EXT 0x8444
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_TEXTURE_COMPRESSION_HINT_ARB 0x84EF
#define GL_WRAP_BORDER_SUN 0x81D4
#define GL_CONSERVE_MEMORY_HINT_PGI 0x1A1FD
#define GL_IDENTITY_NV 0x862A
#define GL_OP_MIN_EXT 0x878B
#define GL_MIRRORED_REPEAT_ARB 0x8370
#define GL_CND0_ATI 0x896B
#define GL_FONT_ASCENDER_BIT_NV 0x00200000
#define GL_LARGE_CW_ARC_TO_NV 0x18
#define GL_WEIGHT_ARRAY_POINTER_ARB 0x86AC
#define GL_RGB32F_ARB 0x8815
#define GL_RG8_SNORM 0x8F95
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#define GL_TEXTURE5 0x84C5
#define GL_CON_29_ATI 0x895E
#define GL_STREAM_COPY_ARB 0x88E2
#define GL_QUAD_INTENSITY8_SGIS 0x8123
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL 0x83F5
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB 0x8643
#define GL_UNSIGNED_INT64_VEC3_NV 0x8FF6
#define GL_OP_DOT3_EXT 0x8784
#define GL_LOW_INT 0x8DF3
#define GL_COLOR_TABLE_RED_SIZE_SGI 0x80DA
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA
#define GL_SIGNED_NEGATE_NV 0x853D
#define GL_NAME_LENGTH 0x92F9
#define GL_PROGRAM_STRING_NV 0x8628
#define GL_MAP2_VERTEX_ATTRIB8_4_NV 0x8678
#define GL_MATRIX_EXT 0x87C0
#define GL_OR 0x1507
#define GL_TEXTURE_TARGET 0x1006
#define GL_DSDT8_MAG8_INTENSITY8_NV 0x870B
#define GL_TEXTURE6_ARB 0x84C6
#define GL_COLOR_INDEX2_EXT 0x80E3
#define GL_BACK_RIGHT 0x0403
#define GL_INT_SAMPLER_CUBE_EXT 0x8DCC
#define GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV 0x90D1
#define GL_VERTEX_ATTRIB_ARRAY9_NV 0x8659
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501
#define GL_CIRCULAR_CCW_ARC_TO_NV 0xF8
#define GL_VERTEX_SHADER_INVARIANTS_EXT 0x87D1
#define GL_PROGRAM_OBJECT_EXT 0x8B40
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM 103074
#define GL_UNPACK_SKIP_VOLUMES_SGIS 0x8132
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT 0x00000400
#define GL_TIME_ELAPSED 0x88BF
#define GL_SKIP_COMPONENTS1_NV -6
#define GL_T2F_IUI_V3F_EXT 0x81B2
#define GL_CONVEX_HULL_NV 0x908B
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_IMAGE_2D_RECT_EXT 0x904F
#define GL_MVP_MATRIX_EXT 0x87E3
#define GL_NORMAL_ARRAY_COUNT_EXT 0x8080
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV 0x9356
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI 0x80B6
#define GL_DOT_PRODUCT_PASS_THROUGH_NV 0x885B
#define GL_OCCLUSION_TEST_RESULT_HP 0x8166
#define GL_MAP1_VERTEX_ATTRIB4_4_NV 0x8664
#define GL_MATRIX27_ARB 0x88DB
#define GL_UNPACK_CMYK_HINT_EXT 0x800F
#define GL_422_AVERAGE_EXT 0x80CE
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV 0x0005
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_VOLATILE_APPLE 0x8A1A
#define GL_TEXTURE_MAX_LOD_SGIS 0x813B
#define GL_SKIP_MISSING_GLYPH_NV 0x90A9
#define GL_UNIFORM_BUFFER_ADDRESS_NV 0x936F
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_PALETTE8_RGBA8_OES 0x8B96
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CF
#define GL_MATRIX0_ARB 0x88C0
#define GL_HSL_LUMINOSITY_NV 0x92B0
#define GL_LUMINANCE_SNORM 0x9011
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#define GL_MAX_TRACK_MATRICES_NV 0x862F
#define GL_INVERSE_TRANSPOSE_NV 0x862D
#define GL_DELETE_STATUS 0x8B80
#define GL_EMBOSS_MAP_NV 0x855F
#define GL_BOOL_ARB 0x8B56
#define GL_DST_IN_NV 0x928B
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_MULTISAMPLE_BIT_ARB 0x20000000
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_CONTINUOUS_AMD 0x9007
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV 0x903B
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_RENDERER 0x1F01
#define GL_INDEX_ARRAY_COUNT_EXT 0x8087
#define GL_RENDERBUFFER_BLUE_SIZE_EXT 0x8D52
#define GL_SAMPLE_BUFFERS_EXT 0x80A8
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_MODELVIEW12_ARB 0x872C
#define GL_VIEWPORT_SWIZZLE_Z_NV 0x935A
#define GL_EVAL_VERTEX_ATTRIB9_NV 0x86CF
#define GL_FRAGMENT_PROGRAM_BINDING_NV 0x8873
#define GL_REPLACEMENT_CODE_ARRAY_SUN 0x85C0
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_DARKEN_NV 0x9297
#define GL_OUTPUT_TEXTURE_COORD27_EXT 0x87B8
#define GL_IMAGE_CUBE 0x9050
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI 0x8803
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI 0x1A203
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV 0x9033
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_YCRCB_422_SGIX 0x81BB
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_SPARSE_TEXTURE_SIZE_AMD 0x9198
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_X_EXT 0x87D5
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_PACK_IMAGE_DEPTH_SGIS 0x8131
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_OP_SET_GE_EXT 0x878C
#define GL_RGB_FLOAT16_ATI 0x881B
#define GL_ACTIVE_VERTEX_UNITS_ARB 0x86A5
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_FRAGMENT_COVERAGE_COLOR_NV 0x92DE
#define GL_ACTIVE_TEXTURE_ARB 0x84E0
#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
#define GL_PATH_JOIN_STYLE_NV 0x9079
#define GL_RENDERBUFFER_GREEN_SIZE_EXT 0x8D51
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT 0x8C71
#define GL_TEXTURE23_ARB 0x84D7
#define GL_COLOR_SUM_CLAMP_NV 0x854F
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV 0x9349
#define GL_BUMP_ROT_MATRIX_ATI 0x8775
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV 0x8868
#define GL_MINMAX_FORMAT_EXT 0x802F
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_FRAGMENT_INPUT_NV 0x936D
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_ALPHA16I_EXT 0x8D8A
#define GL_UNKNOWN_CONTEXT_RESET 0x8255
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT 0x8C2B
#define GL_MODELVIEW5_ARB 0x8725
#define GL_SPRITE_TRANSLATION_SGIX 0x814B
#define GL_DEPTH_CLAMP_FAR_AMD 0x901F
#define GL_INDEX_TEST_REF_EXT 0x81B7
#define GL_QUAD_ALPHA4_SGIS 0x811E
#define GL_CONST_EYE_NV 0x86E5
#define GL_STORAGE_CLIENT_APPLE 0x85B4
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE 0x8521
#define GL_FLOAT_RGBA_MODE_NV 0x888E
#define GL_COLOR_ATTACHMENT31 0x8CFF
#define GL_COLOR_ATTACHMENT30 0x8CFE
#define GL_OP_ADD_EXT 0x8787
#define GL_RGB32UI_EXT 0x8D71
#define GL_EDGEFLAG_BIT_PGI 0x00040000
#define GL_QUERY_BY_REGION_WAIT_NV 0x8E15
#define GL_MAX_VIEWPORTS 0x825B
#define GL_SHADING_LANGUAGE_VERSION_ARB 0x8B8C
#define GL_VERTEX_WEIGHTING_EXT 0x8509
#define GL_VARIANT_ARRAY_POINTER_EXT 0x87E9
#define GL_INTENSITY4_EXT 0x804A
#define GL_FRAGMENT_LIGHT3_SGIX 0x840F
#define GL_FONT_TARGET_UNAVAILABLE_NV 0x9369
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB 0x82F8
#define GL_OPERAND3_RGB_NV 0x8593
#define GL_TEXTURE_1D_STACK_MESAX 0x8759
#define GL_INTENSITY8_SNORM 0x9017
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT 0x9068
#define GL_CUBIC_EXT 0x8334
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5E
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT 0x81A9
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV 0x0006
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0x000D
#define GL_MAX_3D_TEXTURE_SIZE_EXT 0x8073
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_CON_7_ATI 0x8948
#define GL_LUMINANCE8_ALPHA8_EXT 0x8045
#define GL_COMBINER_INPUT_NV 0x8542
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI 0x80BA
#define GL_QUERY_DEPTH_FAIL_EVENT_BIT_AMD 0x00000002
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT 0x8C19
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_PATH_STENCIL_REF_NV 0x90B8
#define GL_OUTPUT_TEXTURE_COORD12_EXT 0x87A9
#define GL_INT_IMAGE_1D_EXT 0x9057
#define GL_REG_13_ATI 0x892E
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_SWIZZLE_STQ_ATI 0x8977
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT 0x00000800
#define GL_DOT3_RGBA_ARB 0x86AF
#define GL_DRAW_BUFFER11_ARB 0x8830
#define GL_CLAMP_TO_BORDER_SGIS 0x812D
#define GL_BUMP_ROT_MATRIX_SIZE_ATI 0x8776
#define GL_NO_ERROR 0
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB 0x8841
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_LINES_ADJACENCY_ARB 0x000A
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV 0x8643
#define GL_MODELVIEW3_ARB 0x8723
#define GL_CLIENT_STORAGE_BIT 0x0200
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_SIGNED_HILO16_NV 0x86FA
#define GL_WEIGHTED_AVERAGE_ARB 0x9367
#define GL_FOG_OFFSET_VALUE_SGIX 0x8199
#define GL_POLYGON_OFFSET_CLAMP_EXT 0x8E1B
#define GL_GREEN_BIT_ATI 0x00000002
#define GL_SCREEN_KHR 0x9295
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_SAMPLER_1D 0x8B5D
#define GL_COLOR_ATTACHMENT2_EXT 0x8CE2
#define GL_OP_MADD_EXT 0x8788
#define GL_LO_SCALE_NV 0x870F
#define GL_EVAL_VERTEX_ATTRIB4_NV 0x86CA
#define GL_DIFFERENCE_NV 0x929E
#define GL_NEVER 0x0200
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_BLEND_DST 0x0BE0
#define GL_NUM_FILL_STREAMS_NV 0x8E29
#define GL_DECR_WRAP_EXT 0x8508
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241
#define GL_COLOR_INDEX12_EXT 0x80E6
#define GL_MAX_PROGRAM_PATCH_ATTRIBS_NV 0x86D8
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT 0x00000002
#define GL_TEXTURE25_ARB 0x84D9
#define GL_ARRAY_OBJECT_BUFFER_ATI 0x8766
#define GL_COMPRESSED_RGBA_ARB 0x84EE
#define GL_SAMPLE_ALPHA_TO_MASK_EXT 0x809E
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DEPTH_COMPONENT32F_NV 0x8DAB
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_MODELVIEW1_STACK_DEPTH_EXT 0x8502
#define GL_OUTPUT_TEXTURE_COORD29_EXT 0x87BA
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_ISOLINES 0x8E7A
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_PACK_RESAMPLE_SGIX 0x842E
#define GL_MODELVIEW22_ARB 0x8736
#define GL_INSTRUMENT_BUFFER_POINTER_SGIX 0x8180
#define GL_TEXTURE_4D_BINDING_SGIS 0x814F
#define GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE 0x8A09
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT 0x9054
#define GL_SOURCE0_RGB_EXT 0x8580
#define GL_LUMINANCE_FLOAT32_ATI 0x8818
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_MAX 0x8008
#define GL_LINE_SMOOTH 0x0B20
#define GL_LIGHTEN_KHR 0x9298
#define GL_COLOR_TABLE_SCALE_SGI 0x80D6
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_OFFSET_TEXTURE_SCALE_NV 0x86E2
#define GL_TEXTURE_BINDING_RECTANGLE_NV 0x84F6
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533
#define GL_NORMAL_MAP_ARB 0x8511
#define GL_RESTART_SUN 0x0001
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV 0x86C5
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ALPHA32I_EXT 0x8D84
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_ROUNDED_RECT4_NV 0xEC
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_TEXTURE_3D_BINDING_EXT 0x806A
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_RGB10_A2UI 0x906F
#define GL_TEXTURE_GREEN_TYPE_ARB 0x8C11

typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64ARBPROC)(GLuint program, GLint location, GLint64 x);
typedef void (APIENTRYP PFNGLHINTPGIPROC)(GLenum target, GLint mode);
typedef void (APIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SARBPROC)(GLenum target, GLshort s, GLshort t);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4FARBPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint *params);
typedef GLenum (APIENTRYP PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLUNIFORM4UIEXTPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLPATHGLYPHSNVPROC)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v);
typedef void (APIENTRYP PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEX2XOESPROC)(GLfixed x);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat *val);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef void (APIENTRYP PFNGLGENPERFMONITORSAMDPROC)(GLsizei n, GLuint *monitors);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3HVNVPROC)(GLuint index, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALFSGIXPROC)(GLenum face, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLVDPAUGETSURFACEIVNVPROC)(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLGETFRAGMENTMATERIALFVSGIXPROC)(GLenum face, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXENVXVOESPROC)(GLenum target, GLenum pname, GLfixed *params);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLINSERTEVENTMARKEREXTPROC)(GLsizei length, const GLchar *marker);
typedef void (APIENTRYP PFNGLBEGINVERTEXSHADEREXTPROC)();
typedef void (APIENTRYP PFNGLNORMAL3FVERTEX3FSUNPROC)(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLTEXBUFFEREXTPROC)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLDRAWTEXTURENVPROC)(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef void (APIENTRYP PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)(GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4SATIPROC)(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint *arrays);
typedef void (APIENTRYP PFNGLWINDOWPOS3IMESAPROC)(GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX2FSUNPROC)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVNVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4HVNVPROC)(GLuint index, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLGETPROGRAMSTRINGNVPROC)(GLuint id, GLenum pname, GLubyte *program);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLMATRIXLOADFEXTPROC)(GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64VNVPROC)(GLuint index, const GLint64EXT *v);
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4FVNVPROC)(GLuint index, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKNVPROC)();
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VEXTPROC)(GLuint id, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLENDPERFMONITORAMDPROC)(GLuint monitor);
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1IVATIPROC)(GLenum stream, const GLint *coords);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4INVPROC)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSAPPLEPROC)(GLsizei n, const GLuint *arrays);
typedef GLbitfield (APIENTRYP PFNGLQUERYMATRIXXOESPROC)(GLfixed *mantissa, GLint *exponent);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
typedef GLvdpauSurfaceNV (APIENTRYP PFNGLVDPAUREGISTERVIDEOSURFACENVPROC)(const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLBINDBUFFERBASENVPROC)(GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELISGIXPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLLISTPARAMETERISGIXPROC)(GLuint list, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLUNIFORMUI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FARBPROC)(GLenum target, GLfloat s);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLCOLOR4XOESPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLSPRITEPARAMETERIVSGIXPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLMATERIALXOESPROC)(GLenum face, GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef GLboolean (APIENTRYP PFNGLTESTOBJECTAPPLEPROC)(GLenum object, GLuint name);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLENDFRAGMENTSHADERATIPROC)();
typedef void (APIENTRYP PFNGLPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLFRAMEZOOMSGIXPROC)(GLint factor);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FEXTPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFNGLGETTEXBUMPPARAMETERIVATIPROC)(GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLSECONDARYCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVNVPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum stage, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1FATIPROC)(GLenum stream, GLfloat x);
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
typedef void (APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC)(GLuint count);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER1DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYAPPLEPROC)(GLuint array);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVARBPROC)(GLenum target, const GLfloat *v);
typedef GLenum (APIENTRYP PFNGLVIDEOCAPTURENVPROC)(GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURELIGHTEXTPROC)(GLenum pname);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (APIENTRYP PFNGLTEXCOORD4FVERTEX4FSUNPROC)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTFVSGIXPROC)(GLenum light, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLWINDOWPOS3SARBPROC)(GLshort x, GLshort y, GLshort z);
typedef GLhandleARB (APIENTRYP PFNGLCREATESHADEROBJECTARBPROC)(GLenum shaderType);
typedef void (APIENTRYP PFNGLGETPROGRAMIVARBPROC)(GLenum target, GLenum pname, GLint *params);
typedef GLushort (APIENTRYP PFNGLGETSTAGEINDEXNVPROC)(GLenum shadertype);
typedef void (APIENTRYP PFNGLPATHGLYPHRANGENVPROC)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREBUFFEREXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLGETMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLBUFFERPARAMETERIAPPLEPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP3ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
typedef void (APIENTRYP PFNGLGETPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, GLfloat *value);
typedef void (APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVEXTPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESXOESPROC)(GLsizei n, const GLuint *textures, const GLfixed *priorities);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLWINDOWPOS3SMESAPROC)(GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1FVATIPROC)(GLenum stream, const GLfloat *coords);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLSCALEXOESPROC)(GLfixed x, GLfixed y, GLfixed z);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLBEGINVIDEOCAPTURENVPROC)(GLuint video_capture_slot);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void *img);
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC)(GLfloat value);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void (APIENTRYP PFNGLDELETEFENCESAPPLEPROC)(GLsizei n, const GLuint *fences);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3IVATIPROC)(GLenum stream, const GLint *coords);
typedef void (APIENTRYP PFNGLENDQUERYARBPROC)(GLenum target);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
typedef void (APIENTRYP PFNGLTEXCOORD4BVOESPROC)(const GLbyte *coords);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FARBPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX2FVSUNPROC)(const GLubyte *c, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint level, void *img);
typedef void (APIENTRYP PFNGLUNMAPOBJECTBUFFERATIPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLDELETEQUERIESARBPROC)(GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLWINDOWPOS3SVARBPROC)(const GLshort *v);
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum target, GLuint index, const GLdouble *params);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVNVPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETCOLORTABLEEXTPROC)(GLenum target, GLenum format, GLenum type, void *data);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETOCCLUSIONQUERYUIVNVPROC)(GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVDPAUINITNVPROC)(const void *vdpDevice, const void *getProcAddress);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1HVNVPROC)(GLuint index, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLGETINTEGERUI64I_VNVPROC)(GLenum value, GLuint index, GLuint64EXT *result);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64NVPROC)(GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLVERTEX3HNVPROC)(GLhalfNV x, GLhalfNV y, GLhalfNV z);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLMATERIALXVOESPROC)(GLenum face, GLenum pname, const GLfixed *param);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLALPHAFUNCXOESPROC)(GLenum func, GLfixed ref);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)(GLenum mode, const void *indirect, GLsizei primcount, GLsizei stride);
typedef void (APIENTRYP PFNGLNORMALSTREAM3IVATIPROC)(GLenum stream, const GLint *coords);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUSVSUNPROC)(const GLushort *code);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
typedef void (APIENTRYP PFNGLMAPCONTROLPOINTSNVPROC)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void *points);
typedef void (APIENTRYP PFNGLDEFORMATIONMAP3DSGIXPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4BOESPROC)(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble *params);
typedef void (APIENTRYP PFNGLCULLPARAMETERDVEXTPROC)(GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLBEGINPERFMONITORAMDPROC)(GLuint monitor);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERXVOESPROC)(GLenum target, GLenum pname, GLfixed *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLTEXCOORD2BOESPROC)(GLbyte s, GLbyte t);
typedef GLuint (APIENTRYP PFNGLBINDMATERIALPARAMETEREXTPROC)(GLenum face, GLenum value);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUBSUNPROC)(GLubyte factor);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64NVPROC)(GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFSGISPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCOLORSUBTABLEEXTPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1FVNVPROC)(GLuint index, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLint *params);
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef GLboolean (APIENTRYP PFNGLISVARIANTENABLEDEXTPROC)(GLuint id, GLenum cap);
typedef void (APIENTRYP PFNGLPASSTHROUGHXOESPROC)(GLfixed token);
typedef void (APIENTRYP PFNGLMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
typedef void (APIENTRYP PFNGLDRAWELEMENTARRAYAPPLEPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLSYNCTEXTUREINTELPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLGETARRAYOBJECTIVATIPROC)(GLenum array, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC)(GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLBUFFERDATAARBPROC)(GLenum target, GLsizeiptrARB size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLUNIFORM2UIVEXTPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLGETPATHDASHARRAYNVPROC)(GLuint path, GLfloat *dashArray);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLCOLORMASKINDEXEDEXTPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLMATRIXSCALEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)();
typedef GLuint (APIENTRYP PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)(GLenum unit, GLenum value);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *n, const GLfloat *v);
typedef void (APIENTRYP PFNGLDELETEPERFQUERYINTELPROC)(GLuint queryHandle);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMARBPROC)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLLISTPARAMETERFSGIXPROC)(GLuint list, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3SATIPROC)(GLenum stream, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVARBPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLUNIFORM3IARBPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef GLhandleARB (APIENTRYP PFNGLCREATEPROGRAMOBJECTARBPROC)();
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVARBPROC)(GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64NVPROC)(GLuint program, GLint location, GLint64EXT x);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVARBPROC)(GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFEXTPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLGETVIDEOCAPTURESTREAMFVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FARBPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1DVATIPROC)(GLenum stream, const GLdouble *coords);
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFEREXTPROC)(GLuint framebuffer);
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)(GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLSAMPLEMASKSGISPROC)(GLclampf value, GLboolean invert);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORFSUNPROC)(GLfloat factor);
typedef void (APIENTRYP PFNGLGETPERFCOUNTERINFOINTELPROC)(GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLPIXELZOOMXOESPROC)(GLfixed xfactor, GLfixed yfactor);
typedef void (APIENTRYP PFNGLRASTERPOS2XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLGETPROGRAMPARAMETERDVNVPROC)(GLenum target, GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2DVATIPROC)(GLenum stream, const GLdouble *coords);
typedef void (APIENTRYP PFNGLVERTEX3XOESPROC)(GLfixed x, GLfixed y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETDOUBLEINDEXEDVEXTPROC)(GLenum target, GLuint index, GLdouble *data);
typedef void (APIENTRYP PFNGLWINDOWPOS2FMESAPROC)(GLfloat x, GLfloat y);
typedef GLint (APIENTRYP PFNGLGETVARYINGLOCATIONNVPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFEREXTPROC)(GLenum target, GLuint framebuffer);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
typedef GLuint (APIENTRYP PFNGLGENPATHSNVPROC)(GLsizei range);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2DATIPROC)(GLenum stream, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFARBPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLWINDOWPOS2DMESAPROC)(GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4UINVPROC)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2HVNVPROC)(GLuint index, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERIHPPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)(GLuint dst, const GLfloat *value);
typedef void (APIENTRYP PFNGLSTATECAPTURENVPROC)(GLuint state, GLenum mode);
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLWEIGHTPATHSNVPROC)(GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP2ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLDELETEPERFMONITORSAMDPROC)(GLsizei n, GLuint *monitors);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSNVPROC)(GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count);
typedef void (APIENTRYP PFNGLUNIFORM3IVARBPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLMATRIXMULT3X3FNVPROC)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)(GLenum variable, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
typedef void (APIENTRYP PFNGLTEXCOORDFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLMULTITEXGENFEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLDELETEVERTEXSHADEREXTPROC)(GLuint id);
typedef void (APIENTRYP PFNGLTEXIMAGE3DEXTPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLPATHCOMMANDSNVPROC)(GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLNORMALSTREAM3IATIPROC)(GLenum stream, GLint nx, GLint ny, GLint nz);
typedef void (APIENTRYP PFNGLUNIFORMUI64NVPROC)(GLint location, GLuint64EXT value);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVEXTPROC)(const GLubyte *v);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERS4FVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFNGLTEXBUMPPARAMETERIVATIPROC)(GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSAPPLEPROC)(GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXENVXVOESPROC)(GLenum target, GLenum pname, const GLfixed *params);
typedef void (APIENTRYP PFNGLCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLCLEARDEPTHXOESPROC)(GLfixed depth);
typedef void (APIENTRYP PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *tc, const GLfloat *n, const GLfloat *v);
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFEREXTPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLGETFLOATI_VEXTPROC)(GLenum pname, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFNGLGENPROGRAMSARBPROC)(GLsizei n, GLuint *programs);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVNVPROC)(GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *n, const GLfloat *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVNVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64VNVPROC)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLBINORMAL3DVEXTPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLPNTRIANGLESIATIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYAPPLEPROC)(GLuint array);
typedef void (APIENTRYP PFNGLTRACKMATRIXNVPROC)(GLenum target, GLuint address, GLenum matrix, GLenum transform);
typedef void (APIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTHVNVPROC)(const GLhalfNV *weight);
typedef void (APIENTRYP PFNGLTEXCOORD2XOESPROC)(GLfixed s, GLfixed t);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)(GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERNVPROC)();
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERINVPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFNGLDETAILTEXFUNCSGISPROC)(GLenum target, GLsizei n, const GLfloat *points);
typedef void (APIENTRYP PFNGLINDEXPOINTERLISTIBMPROC)(GLenum type, GLint stride, const void **pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum texture);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2DVNVPROC)(GLuint index, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLTEXFILTERFUNCSGISPROC)(GLenum target, GLenum filter, GLsizei n, const GLfloat *weights);
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLCOLOR3HNVPROC)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)(GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLPIXELSTOREXPROC)(GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVEXTPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERIVARBPROC)(GLhandleARB obj, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLVERTEX2HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLWINDOWPOS3DARBPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2FVNVPROC)(GLuint index, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
typedef void (APIENTRYP PFNGLWINDOWPOS2DARBPROC)(GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLNORMAL3XOESPROC)(GLfixed nx, GLfixed ny, GLfixed nz);
typedef void (APIENTRYP PFNGLREFERENCEPLANESGIXPROC)(const GLdouble *equation);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC)(GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
typedef void (APIENTRYP PFNGLHISTOGRAMEXTPROC)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint index, GLenum pname, void **pointer);
typedef void (APIENTRYP PFNGLMATRIXINDEXUIVARBPROC)(GLint size, const GLuint *indices);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXBUMPPARAMETERFVATIPROC)(GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERXVOESPROC)(GLenum target, GLenum pname, const GLfixed *params);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLPNTRIANGLESFATIPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLGENFENCESAPPLEPROC)(GLsizei n, GLuint *fences);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLTEXTURERANGEAPPLEPROC)(GLenum target, GLsizei length, const void *pointer);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SARBPROC)(GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4DVNVPROC)(GLenum target, GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVNVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)();
typedef GLboolean (APIENTRYP PFNGLISVERTEXATTRIBENABLEDAPPLEPROC)(GLuint index, GLenum pname);
typedef void (APIENTRYP PFNGLWEIGHTSVARBPROC)(GLint size, const GLshort *weights);
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLMULTITEXBUFFEREXTPROC)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFNGLGETMAPATTRIBPARAMETERFVNVPROC)(GLenum target, GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLVARIANTARRAYOBJECTATIPROC)(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
typedef void (APIENTRYP PFNGLNORMALFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FNVPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPEXTPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
typedef void (APIENTRYP PFNGLMULTITEXENVIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4FVNVPROC)(GLenum target, GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLGETVARIANTINTEGERVEXTPROC)(GLuint id, GLenum value, GLint *data);
typedef void (APIENTRYP PFNGLBLENDEQUATIONINDEXEDAMDPROC)(GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLDELETESTATESNVPROC)(GLsizei n, const GLuint *states);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVEXTPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLVDPAUFININVPROC)();
typedef void (APIENTRYP PFNGLMAKEBUFFERNONRESIDENTNVPROC)(GLenum target);
typedef void (APIENTRYP PFNGLUNIFORM1UI64ARBPROC)(GLint location, GLuint64 x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SARBPROC)(GLenum target, GLshort s);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONFILTEREXTPROC)(GLenum target, GLenum format, GLenum type, void *image);
typedef void (APIENTRYP PFNGLFOGCOORDPOINTEREXTPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLTRANSLATEXOESPROC)(GLfixed x, GLfixed y, GLfixed z);
typedef void (APIENTRYP PFNGLTEXTURECOLORMASKSGISPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1SVATIPROC)(GLenum stream, const GLshort *coords);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2IATIPROC)(GLenum stream, GLint x, GLint y);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLASYNCMARKERSGIXPROC)(GLuint marker);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESEXTPROC)(GLsizei n, const GLuint *textures, const GLclampf *priorities);
typedef void (APIENTRYP PFNGLGETOCCLUSIONQUERYIVNVPROC)(GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATEMULTITEXMIPMAPEXTPROC)(GLenum texunit, GLenum target);
typedef void (APIENTRYP PFNGLWINDOWPOS3DVMESAPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLMULTITEXENVFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVSGISPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)(GLenum target, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1DVNVPROC)(GLuint index, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLBLENDPARAMETERINVPROC)(GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLSAMPLEMASKINDEXEDNVPROC)(GLuint index, GLbitfield mask);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLMATRIXLOAD3X3FNVPROC)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FARBPROC)(GLenum target, GLfloat s, GLfloat t);
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKNVPROC)(GLuint id);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
typedef void (APIENTRYP PFNGLSETFENCEAPPLEPROC)(GLuint fence);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DARBPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLGETHISTOGRAMEXTPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
typedef void (APIENTRYP PFNGLWINDOWPOS2FVARBPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLENABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLTEXCOORD1BVOESPROC)(const GLbyte *coords);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEPOINTERSUNPROC)(GLenum type, GLsizei stride, const void **pointer);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDARBPROC)(const GLdouble *m);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLCOMPILESHADERARBPROC)(GLhandleARB shaderObj);
typedef void (APIENTRYP PFNGLNORMALSTREAM3FVATIPROC)(GLenum stream, const GLfloat *coords);
typedef void (APIENTRYP PFNGLUNIFORM4UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2FVATIPROC)(GLenum stream, const GLfloat *coords);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint *pipelines);
typedef void (APIENTRYP PFNGLSTOPINSTRUMENTSSGIXPROC)(GLint marker);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBAPPLEPROC)(GLuint index, GLenum pname);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4IVNVPROC)(GLenum target, GLuint index, const GLint *params);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERVEXTPROC)(GLuint vaobj, GLenum pname, GLint *param);
typedef GLboolean (APIENTRYP PFNGLVDPAUISSURFACENVPROC)(GLvdpauSurfaceNV surface);
typedef GLboolean (APIENTRYP PFNGLISCOMMANDLISTNVPROC)(GLuint list);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIEXTPROC)(GLenum target, GLenum pname, GLint params);
typedef void (APIENTRYP PFNGLPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, const GLfloat *value);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
typedef void (APIENTRYP PFNGLVERTEXARRAYRANGEAPPLEPROC)(GLsizei length, void *pointer);
typedef void (APIENTRYP PFNGLCOLOR4HNVPROC)(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
typedef void (APIENTRYP PFNGLWEIGHTFVARBPROC)(GLint size, const GLfloat *weights);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DARBPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLGETTEXBUMPPARAMETERFVATIPROC)(GLenum pname, GLfloat *param);
typedef void (APIENTRYP PFNGLBINDPROGRAMARBPROC)(GLenum target, GLuint program);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEARBPROC)(GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3SVATIPROC)(GLenum stream, const GLshort *coords);
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
typedef void (APIENTRYP PFNGLPOINTPARAMETERINVPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEEXTPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXIMAGE4DSGISPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERARBPROC)(GLenum target);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64VNVPROC)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLDETACHOBJECTARBPROC)(GLhandleARB containerObj, GLhandleARB attachedObj);
typedef void (APIENTRYP PFNGLDELETEPATHSNVPROC)(GLuint path, GLsizei range);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXNVPROC)(GLuint index);
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERLISTIBMPROC)(GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLRECTXOESPROC)(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVARBPROC)(GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFOGCOORDFVEXTPROC)(const GLfloat *coord);
typedef void (APIENTRYP PFNGLUNIFORM4UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC)(GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC)(GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMATRIXORTHOEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef void (APIENTRYP PFNGLGETDETAILTEXFUNCSGISPROC)(GLenum target, GLfloat *points);
typedef void (APIENTRYP PFNGLMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLLISTPARAMETERIVSGIXPROC)(GLuint list, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONTABLENVPROC)(GLsizei n, const GLfloat *v);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVARBPROC)(GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLNORMAL3XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLGETACTIVEVARYINGNVPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLTEXCOORD4XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLGETVARIANTBOOLEANVEXTPROC)(GLuint id, GLenum value, GLboolean *data);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)(GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFNGLSPRITEPARAMETERFVSGIXPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLSHADERSOURCEARBPROC)(GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length);
typedef void (APIENTRYP PFNGLSHADEROP3EXTPROC)(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXEXTPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLVARIANTUBVEXTPROC)(GLuint id, const GLubyte *addr);
typedef void (APIENTRYP PFNGLFLUSHPROC)();
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPRESENTFRAMEDUALFILLNVPROC)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef void (APIENTRYP PFNGLDEPTHRANGEFOESPROC)(GLclampf n, GLclampf f);
typedef void (APIENTRYP PFNGLGETVARIANTPOINTERVEXTPROC)(GLuint id, GLenum value, void **data);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3XVOESPROC)(GLenum texture, const GLfixed *coords);
typedef void (APIENTRYP PFNGLWINDOWPOS3FVMESAPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLSTENCILOPVALUEAMDPROC)(GLenum face, GLuint value);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)(GLenum target, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2HNVPROC)(GLenum target, GLhalfNV s, GLhalfNV t);
typedef GLboolean (APIENTRYP PFNGLISFENCEAPPLEPROC)(GLuint fence);
typedef void (APIENTRYP PFNGLCOMBINERINPUTNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (APIENTRYP PFNGLMAPVERTEXATTRIB2DAPPLEPROC)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIEXTPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLLINEWIDTHXOESPROC)(GLfixed width);
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERIVSGISPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLUNIFORM2I64ARBPROC)(GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint *samplers);
typedef void (APIENTRYP PFNGLGETLIGHTXOESPROC)(GLenum light, GLenum pname, GLfixed *params);
typedef void (APIENTRYP PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLDRAWMESHARRAYSSUNPROC)(GLenum mode, GLint first, GLsizei count, GLsizei width);
typedef void (APIENTRYP PFNGLGETPATHCOMMANDSNVPROC)(GLuint path, GLubyte *commands);
typedef void (APIENTRYP PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLGETPERFQUERYINFOINTELPROC)(GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);
typedef void (APIENTRYP PFNGLUNIFORM2FARBPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEEXTPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETPROGRAMSTRINGARBPROC)(GLenum target, GLenum pname, void *string);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEARBPROC)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVARBPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLWINDOWPOS3FMESAPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERXOESPROC)(GLenum target, GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLNORMALSTREAM3DATIPROC)(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64VNVPROC)(GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFNGLUNIFORM2I64VARBPROC)(GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVARBPROC)(GLenum target, const GLdouble *v);
typedef void * (APIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
typedef void (APIENTRYP PFNGLTEXCOORD1HNVPROC)(GLhalfNV s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1HVNVPROC)(GLenum target, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLWEIGHTBVARBPROC)(GLint size, const GLbyte *weights);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLRECTXVOESPROC)(const GLfixed *v1, const GLfixed *v2);
typedef void (APIENTRYP PFNGLFINISHPROC)();
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVIEWPORTPOSITIONWSCALENVPROC)(GLuint index, GLfloat xcoeff, GLfloat ycoeff);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVEXTPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLGETPROGRAMPARAMETERFVNVPROC)(GLenum target, GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLWEIGHTIVARBPROC)(GLint size, const GLint *weights);
typedef void (APIENTRYP PFNGLINSERTCOMPONENTEXTPROC)(GLuint res, GLuint src, GLuint num);
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2XVOESPROC)(GLenum texture, const GLfixed *coords);
typedef void (APIENTRYP PFNGLTEXGENXVOESPROC)(GLenum coord, GLenum pname, const GLfixed *params);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFARBPROC)(const GLfloat *m);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)(GLenum primitiveMode);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIVEXTPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DEXTPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLFRAGMENTCOLORMATERIALSGIXPROC)(GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
typedef void (APIENTRYP PFNGLRASTERPOS4XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask);
typedef void (APIENTRYP PFNGLCREATESTATESNVPROC)(GLsizei n, GLuint *states);
typedef void (APIENTRYP PFNGLCLEARDEPTHDNVPROC)(GLdouble depth);
typedef void (APIENTRYP PFNGLBINDMULTITEXTUREEXTPROC)(GLenum texunit, GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVARBPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIARBPROC)(GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBAPPLEPROC)(GLuint index, GLenum pname);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei primcount, GLsizei stride);
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)(GLuint id, GLenum value, GLboolean *data);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)(GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3FVNVPROC)(GLuint index, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLUNIFORM3UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERFVNVPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC)(GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)(GLuint id, GLenum value, GLint *data);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVARBPROC)(GLenum target, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLMULTMATRIXXOESPROC)(const GLfixed *m);
typedef void (APIENTRYP PFNGLCOLORPOINTERLISTIBMPROC)(GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLMAPVERTEXATTRIB1DAPPLEPROC)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
typedef void (APIENTRYP PFNGLFOGFUNCSGISPROC)(GLsizei n, const GLfloat *points);
typedef void (APIENTRYP PFNGLGETUNIFORMIVARBPROC)(GLhandleARB programObj, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERNVPROC)();
typedef void (APIENTRYP PFNGLMULTITEXCOORD2BVOESPROC)(GLenum texture, const GLbyte *coords);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
typedef void (APIENTRYP PFNGLUNIFORM3I64VARBPROC)(GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)(GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLUNIFORM1UIEXTPROC)(GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLVERTEXARRAYRANGENVPROC)(GLsizei length, const void *pointer);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
typedef GLboolean (APIENTRYP PFNGLISNAMEDSTRINGARBPROC)(GLint namelen, const GLchar *name);
typedef void (APIENTRYP PFNGLPIXELTRANSFERXOESPROC)(GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX3FSUNPROC)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum target, GLuint index, GLfloat *params);
typedef GLhandleARB (APIENTRYP PFNGLGETHANDLEARBPROC)(GLenum pname);
typedef void (APIENTRYP PFNGLPIXELMAPXPROC)(GLenum map, GLint size, const GLfixed *values);
typedef void (APIENTRYP PFNGLEVALCOORD2XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC)(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum pname, void *string);
typedef void (APIENTRYP PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint index);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTEREXTPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLFOGXVOESPROC)(GLenum pname, const GLfixed *param);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2SVNVPROC)(GLuint index, GLsizei count, const GLshort *v);
typedef void (APIENTRYP PFNGLFINALCOMBINERINPUTNVPROC)(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
typedef GLboolean (APIENTRYP PFNGLISENABLEDINDEXEDEXTPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXPOINTERLISTIBMPROC)(GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SARBPROC)(GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVARBPROC)(GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VEXTPROC)(GLuint id, GLenum pname, GLuint64 *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVEXTPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4IVATIPROC)(GLenum stream, const GLint *coords);
typedef void (APIENTRYP PFNGLGETPROGRAMIVNVPROC)(GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC)();
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLI64VNVPROC)(GLuint index, GLenum pname, GLint64EXT *params);
typedef void (APIENTRYP PFNGLWEIGHTUIVARBPROC)(GLint size, const GLuint *weights);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VARBPROC)(GLuint program, GLint location, GLuint64 *params);
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
typedef void (APIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)(GLuint id, GLsizei len, const GLubyte *name, GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLuint *params);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKNVPROC)(GLenum primitiveMode);
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (APIENTRYP PFNGLBINORMAL3IEXTPROC)(GLint bx, GLint by, GLint bz);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORBSUNPROC)(GLbyte factor);
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTEXTPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)(GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFEREXTPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)(GLenum target, GLuint index, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVARBPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLVARIANTDVEXTPROC)(GLuint id, const GLdouble *addr);
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLFOGCOORDHNVPROC)(GLhalfNV fog);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64 *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64VNVPROC)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLGETVIDEOIVNVPROC)(GLuint video_slot, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
typedef void (APIENTRYP PFNGLPATHPARAMETERINVPROC)(GLuint path, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLCREATECOMMANDLISTSNVPROC)(GLsizei n, GLuint *lists);
typedef void (APIENTRYP PFNGLCOPYCOLORSUBTABLEEXTPROC)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLVARIANTSVEXTPROC)(GLuint id, const GLshort *addr);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLUNIFORM4UIVEXTPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLORTHOXOESPROC)(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIEXTPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLUNIFORM1UIVEXTPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVEXTPROC)(GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREEXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)(GLuint program, GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRYP PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *c, const GLfloat *n, const GLfloat *v);
typedef void (APIENTRYP PFNGLSEPARABLEFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
typedef void (APIENTRYP PFNGLCLEARACCUMXOESPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLWEIGHTUBVARBPROC)(GLint size, const GLubyte *weights);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLNORMAL3HNVPROC)(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
typedef void (APIENTRYP PFNGLVARIANTUSVEXTPROC)(GLuint id, const GLushort *addr);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4DNVPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVSUNPROC)(const GLuint *code);
typedef void (APIENTRYP PFNGLDELETEASYNCMARKERSSGIXPROC)(GLuint marker, GLsizei range);
typedef void (APIENTRYP PFNGLGETSHARPENTEXFUNCSGISPROC)(GLenum target, GLfloat *points);
typedef void (APIENTRYP PFNGLIGLOOINTERFACESGIXPROC)(GLenum pname, const void *params);
typedef void (APIENTRYP PFNGLWINDOWPOS2DVARBPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLFRAMETERMINATORGREMEDYPROC)();
typedef void (APIENTRYP PFNGLBLENDBARRIERKHRPROC)();
typedef void (APIENTRYP PFNGLUNIFORM1I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVARBPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVEXTPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLGETVARIANTARRAYOBJECTFVATIPROC)(GLuint id, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint *params);
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVARBPROC)(GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLGETMAPXVOESPROC)(GLenum target, GLenum query, GLfixed *v);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLCOLORPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERLISTIBMPROC)(GLint stride, const GLboolean **pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLUSEPROGRAMOBJECTARBPROC)(GLhandleARB programObj);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLSHADEROP2EXTPROC)(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLBINORMAL3DEXTPROC)(GLdouble bx, GLdouble by, GLdouble bz);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLMATRIXSCALEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNMAPTEXTURE2DINTELPROC)(GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPEXTPROC)(GLenum target);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVEXTPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLPATHCOORDSNVPROC)(GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4XVOESPROC)(GLenum texture, const GLfixed *coords);
typedef void (APIENTRYP PFNGLFRAMEBUFFERREADBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
typedef void (APIENTRYP PFNGLGENBUFFERSARBPROC)(GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLFOGCOORDDEXTPROC)(GLdouble coord);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVNVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAARBPROC)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void *data);
typedef void (APIENTRYP PFNGLGETPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, GLint *value);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLELEMENTPOINTERATIPROC)(GLenum type, const void *pointer);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVARIANTBVEXTPROC)(GLuint id, const GLbyte *addr);
typedef void (APIENTRYP PFNGLFOGXOESPROC)(GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLCLEARDEPTHFOESPROC)(GLclampf depth);
typedef void (APIENTRYP PFNGLVERTEX4HNVPROC)(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
typedef void (APIENTRYP PFNGLPATHSUBCOORDSNVPROC)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFNGLPROGRAMSTRINGARBPROC)(GLenum target, GLenum format, GLsizei len, const void *string);
typedef void (APIENTRYP PFNGLMATRIXINDEXUSVARBPROC)(GLint size, const GLushort *indices);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVEXTPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLDRAWBUFFERSATIPROC)(GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLAPPLYTEXTUREEXTPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLGETFIXEDVOESPROC)(GLenum pname, GLfixed *params);
typedef void (APIENTRYP PFNGLSAMPLEPATTERNEXTPROC)(GLenum pattern);
typedef void (APIENTRYP PFNGLFOGCOORDDVEXTPROC)(const GLdouble *coord);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKEXTPROC)();
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUBSUNPROC)(GLubyte code);
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef GLint (APIENTRYP PFNGLFINISHASYNCSGIXPROC)(GLuint *markerp);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)(GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSAMDPROC)(GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
typedef void (APIENTRYP PFNGLGENQUERIESARBPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLACTIVESTENCILFACEEXTPROC)(GLenum face);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3BOESPROC)(GLenum texture, GLbyte s, GLbyte t, GLbyte r);
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)(GLenum target, GLuint index, const GLuint *params);
typedef void (APIENTRYP PFNGLWINDOWPOS4DMESAPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLGETFRAGMENTLIGHTIVSGIXPROC)(GLenum light, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREEXTPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLLINKPROGRAMARBPROC)(GLhandleARB programObj);
typedef void (APIENTRYP PFNGLFINISHFENCEAPPLEPROC)(GLuint fence);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)(GLenum target, GLuint index, GLuint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPOINTERINDEXEDVEXTPROC)(GLenum target, GLuint index, void **data);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVNVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLWINDOWPOS4SMESAPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVDPAUMAPSURFACESNVPROC)(GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVNVPROC)(GLuint index, GLenum pname, void **pointer);
typedef GLuint (APIENTRYP PFNGLBINDPARAMETEREXTPROC)(GLenum value);
typedef void (APIENTRYP PFNGLUNIFORM4FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLGETTRACKMATRIXIVNVPROC)(GLenum target, GLuint address, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISNAMEDBUFFERRESIDENTNVPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLCOVERFILLPATHNVPROC)(GLuint path, GLenum coverMode);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLuint *params);
typedef void (APIENTRYP PFNGLMEMORYBARRIEREXTPROC)(GLbitfield barriers);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLSETFENCENVPROC)(GLuint fence, GLenum condition);
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVEXTPROC)(GLuint index, const GLushort *v);
typedef GLboolean (APIENTRYP PFNGLISPATHNVPROC)(GLuint path);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void *userParam);
typedef void (APIENTRYP PFNGLTANGENT3SVEXTPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPARAMETERIAMDPROC)(GLuint index, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC)(GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLGETPATHMETRICSNVPROC)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3DVATIPROC)(GLenum stream, const GLdouble *coords);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
typedef GLboolean (APIENTRYP PFNGLPOINTALONGPATHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERS4DVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef GLintptr (APIENTRYP PFNGLGETUNIFORMOFFSETEXTPROC)(GLuint program, GLint location);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLTANGENT3FEXTPROC)(GLfloat tx, GLfloat ty, GLfloat tz);
typedef void (APIENTRYP PFNGLGETPATHMETRICRANGENVPROC)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)(GLuint rc, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLWINDOWPOS3FARBPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFEREXTPROC)(GLuint buffer, GLenum access);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINORMAL3SVEXTPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEFVNVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (APIENTRYP PFNGLBINORMALPOINTEREXTPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLEXTRACTCOMPONENTEXTPROC)(GLuint res, GLuint src, GLuint num);
typedef void (APIENTRYP PFNGLUNIFORM2IVARBPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)(GLuint index, GLenum pname, GLfloat *params);
typedef GLenum (APIENTRYP PFNGLOBJECTPURGEABLEAPPLEPROC)(GLenum objectType, GLuint name, GLenum option);
typedef void (APIENTRYP PFNGLCOLORTABLESGIPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLWINDOWPOS2FVMESAPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETXOESPROC)(GLfixed factor, GLfixed units);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLBINDFRAGMENTSHADERATIPROC)(GLuint id);
typedef void (APIENTRYP PFNGLLISTPARAMETERFVSGIXPROC)(GLuint list, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOLOR3XOESPROC)(GLfixed red, GLfixed green, GLfixed blue);
typedef void (APIENTRYP PFNGLSTENCILFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC)(GLuint id);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3HNVPROC)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint *param);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLGETMATERIALXOESPROC)(GLenum face, GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLTANGENT3BEXTPROC)(GLbyte tx, GLbyte ty, GLbyte tz);
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC)();
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)(GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKNVPROC)(GLenum mode, GLuint id);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
typedef void (APIENTRYP PFNGLWINDOWPOS2SVMESAPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXXOESPROC)(const GLfixed *m);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSNVPROC)(GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKNVPROC)();
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLFLUSHRASTERSGIXPROC)();
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)();
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
typedef void (APIENTRYP PFNGLNORMALSTREAM3FATIPROC)(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (APIENTRYP PFNGLUNIFORM1I64NVPROC)(GLint location, GLint64EXT x);
typedef void (APIENTRYP PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)(GLuint id, GLsizei len, const GLubyte *name, GLdouble *params);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *c, const GLfloat *v);
typedef void (APIENTRYP PFNGLTANGENT3DEXTPROC)(GLdouble tx, GLdouble ty, GLdouble tz);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVARBPROC)(GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLUSESHADERPROGRAMEXTPROC)(GLenum type, GLuint program);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFEREXTPROC)(GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)(GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)(GLuint program, GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3XOESPROC)(GLenum texture, GLfixed s, GLfixed t, GLfixed r);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void *indirect);
typedef void (APIENTRYP PFNGLGETVARIANTARRAYOBJECTIVATIPROC)(GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DARBPROC)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
typedef GLuint (APIENTRYP PFNGLGENASYNCMARKERSSGIXPROC)(GLsizei range);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLSETMULTISAMPLEFVAMDPROC)(GLenum pname, GLuint index, const GLfloat *val);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLINDEXXVOESPROC)(const GLfixed *component);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USEXTPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRYP PFNGLGETPOINTERVEXTPROC)(GLenum pname, void **params);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)(const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFNGLUNIFORM4UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)(GLenum variable, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLTEXCOORD4XOESPROC)(GLfixed s, GLfixed t, GLfixed r, GLfixed q);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void * (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE4DSGISPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (APIENTRYP PFNGLEVALMAPSNVPROC)(GLenum target, GLenum mode);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint lod, void *img);
typedef void (APIENTRYP PFNGLDRAWBUFFERSARBPROC)(GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
typedef GLuint (APIENTRYP PFNGLNEWOBJECTBUFFERATIPROC)(GLsizei size, const void *pointer, GLenum usage);
typedef void (APIENTRYP PFNGLVIEWPORTSWIZZLENVPROC)(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
typedef void (APIENTRYP PFNGLROTATEXOESPROC)(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLATTACHOBJECTARBPROC)(GLhandleARB containerObj, GLhandleARB obj);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVEXTPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLUNIFORM4FARBPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SNVPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLBINDBUFFERARBPROC)(GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SNVPROC)(GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLDEPTHRANGEDNVPROC)(GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLNORMALPOINTERVINTELPROC)(GLenum type, const void **pointer);
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERIVAPPLEPROC)(GLenum objectType, GLuint name, GLenum pname, GLint *params);
typedef GLint (APIENTRYP PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(GLuint program, GLint location);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount);
typedef void (APIENTRYP PFNGLUNIFORM1FARBPROC)(GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLEVALCOORD1XOESPROC)(GLfixed u);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLGETLISTPARAMETERIVSGIXPROC)(GLuint list, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLUNIFORM2UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLTANGENT3SEXTPROC)(GLshort tx, GLshort ty, GLshort tz);
typedef void (APIENTRYP PFNGLFRUSTUMXOESPROC)(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
typedef void (APIENTRYP PFNGLINSTRUMENTSBUFFERSGIXPROC)(GLsizei size, GLint *buffer);
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint program, GLenum shadertype, const GLchar *name);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLUNIFORM3UIEXTPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDARBPROC)(const GLdouble *m);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DEXTPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLDEFORMSGIXPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLCOPYPATHNVPROC)(GLuint resultPath, GLuint srcPath);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
typedef GLvdpauSurfaceNV (APIENTRYP PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC)(const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHNVPROC)(GLuint path, GLenum coverMode);
typedef void (APIENTRYP PFNGLVERTEX3BOESPROC)(GLbyte x, GLbyte y, GLbyte z);
typedef void (APIENTRYP PFNGLTESSELLATIONFACTORAMDPROC)(GLfloat factor);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef GLboolean (APIENTRYP PFNGLISOBJECTBUFFERATIPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVARBPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONARBPROC)(GLhandleARB programObj, const GLcharARB *name);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3HVNVPROC)(GLenum target, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLMATRIXPUSHEXTPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVEXTPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)();
typedef void (APIENTRYP PFNGLTESSELLATIONMODEAMDPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLLOADPROGRAMNVPROC)(GLenum target, GLuint id, GLsizei len, const GLubyte *program);
typedef void (APIENTRYP PFNGLWRITEMASKEXTPROC)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)();
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLINDEXPOINTEREXTPROC)(GLenum type, GLsizei stride, GLsizei count, const void *pointer);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUBVSUNPROC)(const GLubyte *code);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGAMDPROC)(GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4DVNVPROC)(GLuint index, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64NVPROC)(GLuint index, GLint64EXT x);
typedef void (APIENTRYP PFNGLORTHOFOESPROC)(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLDRAWELEMENTARRAYATIPROC)(GLenum mode, GLsizei count);
typedef void (APIENTRYP PFNGLUNIFORM3UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLMATRIXROTATEDEXTPROC)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMNVPROC)(GLuint id);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
typedef void (APIENTRYP PFNGLDEPTHBOUNDSEXTPROC)(GLclampd zmin, GLclampd zmax);
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERIVSGIPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble *data);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLCLEARCOLORXOESPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4SVATIPROC)(GLenum stream, const GLshort *coords);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IARBPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRYP PFNGLVARIANTFVEXTPROC)(GLuint id, const GLfloat *addr);
typedef void (APIENTRYP PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERLISTIBMPROC)(GLenum type, GLint stride, const void **pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVEXTPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVDPAUSURFACEACCESSNVPROC)(GLvdpauSurfaceNV surface, GLenum access);
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
typedef void (APIENTRYP PFNGLWINDOWPOS3DVARBPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint *samplers);
typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)(GLuint buffer, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLBLENDCOLORXOESPROC)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALFVSGIXPROC)(GLenum face, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLDELETENAMESAMDPROC)(GLenum identifier, GLuint num, const GLuint *names);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLDELETEBUFFERSARBPROC)(GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLNORMALSTREAM3SVATIPROC)(GLenum stream, const GLshort *coords);
typedef void (APIENTRYP PFNGLPATHSTENCILFUNCNVPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSETINVARIANTEXTPROC)(GLuint id, GLenum type, const void *addr);
typedef void (APIENTRYP PFNGLENDOCCLUSIONQUERYNVPROC)();
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2HVNVPROC)(GLenum target, const GLhalfNV *v);
typedef void * (APIENTRYP PFNGLMAPTEXTURE2DINTELPROC)(GLuint texture, GLint level, GLbitfield access, GLint *stride, GLenum *layout);
typedef void (APIENTRYP PFNGLGETMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVEXTPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONNVPROC)(GLenum components);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLBEGINPERFQUERYINTELPROC)(GLuint queryHandle);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLTEXCOORD3HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLUNIFORM3FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLDELETEOBJECTARBPROC)(GLhandleARB obj);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCALLCOMMANDLISTNVPROC)(GLuint list);
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB programObj, const GLcharARB *name);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FARBPROC)(GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMAPPARAMETERFVNVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)(GLsizei count, const GLint *attribs, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETVIDEOI64VNVPROC)(GLuint video_slot, GLenum pname, GLint64EXT *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLSWIZZLEEXTPROC)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLenum target, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLGETNEXTPERFQUERYIDINTELPROC)(GLuint queryId, GLuint *nextQueryId);
typedef GLboolean (APIENTRYP PFNGLISNAMEAMDPROC)(GLenum identifier, GLuint name);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXSTORAGESPARSEAMDPROC)(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
typedef void (APIENTRYP PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXCOORD3HNVPROC)(GLhalfNV s, GLhalfNV t, GLhalfNV r);
typedef void (APIENTRYP PFNGLMULTIMODEDRAWELEMENTSIBMPROC)(const GLenum *mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, GLint modestride);
typedef void (APIENTRYP PFNGLUNIFORM2IARBPROC)(GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLCOLORPOINTERVINTELPROC)(GLint size, GLenum type, const void **pointer);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLTEXCOORD2FVERTEX3FVSUNPROC)(const GLfloat *tc, const GLfloat *v);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUSSUNPROC)(GLushort code);
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLGETARRAYOBJECTFVATIPROC)(GLenum array, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVNVPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLSHADEROP1EXTPROC)(GLenum op, GLuint res, GLuint arg1);
typedef void (APIENTRYP PFNGLCLEARCOLORIIEXTPROC)(GLint red, GLint green, GLint blue, GLint alpha);
typedef void (APIENTRYP PFNGLCOMBINEROUTPUTNVPROC)(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLTEXCOORD1XOESPROC)(GLfixed s);
typedef void (APIENTRYP PFNGLMULTIMODEDRAWARRAYSIBMPROC)(const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2HNVPROC)(GLuint index, GLhalfNV x, GLhalfNV y);
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKNVPROC)();
typedef void (APIENTRYP PFNGLGETFENCEIVNVPROC)(GLuint fence, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)(const GLfloat *tc, const GLubyte *c, const GLfloat *v);
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLRASTERPOS2XOESPROC)(GLfixed x, GLfixed y);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVARBPROC)(GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLSPRITEPARAMETERFSGIXPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLMAP2XOESPROC)(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTHNVPROC)(GLhalfNV weight);
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP1ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVEXTPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DNVPROC)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3DVNVPROC)(GLuint index, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1HNVPROC)(GLenum target, GLhalfNV s);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERXVOESPROC)(GLenum target, GLenum pname, GLfixed *params);
typedef void (APIENTRYP PFNGLSTRINGMARKERGREMEDYPROC)(GLsizei len, const void *string);
typedef void (APIENTRYP PFNGLGETOBJECTLABELEXTPROC)(GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VNVPROC)(GLint location, GLsizei count, const GLuint64 *value);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVARBPROC)(GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLGETMINMAXEXTPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLTEXRENDERBUFFERNVPROC)(GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC)(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
typedef void (APIENTRYP PFNGLTBUFFERMASK3DFXPROC)(GLuint mask);
typedef void (APIENTRYP PFNGLTEXGENXOESPROC)(GLenum coord, GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLMATRIXFRUSTUMEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDARBPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar *name);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLSAMPLEPATTERNSGISPROC)(GLenum pattern);
typedef void (APIENTRYP PFNGLRASTERPOS3XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DEXTPROC)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
typedef void (APIENTRYP PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)(GLenum target, GLsizei count, const GLuint *params);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BEXTPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
typedef void (APIENTRYP PFNGLWINDOWPOS4FVMESAPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTEREXTPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLMAPVERTEXATTRIB1FAPPLEPROC)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLFOGCOORDFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLGETMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4DARBPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETUNIFORMI64VNVPROC)(GLuint program, GLint location, GLint64EXT *params);
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERVEXTPROC)(GLuint vaobj, GLenum pname, void **param);
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLQUERYOBJECTPARAMETERUIAMDPROC)(GLenum target, GLuint id, GLenum pname, GLuint param);
typedef void (APIENTRYP PFNGLVARIANTPOINTEREXTPROC)(GLuint id, GLenum type, GLuint stride, const void *addr);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort *v);
typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXARRAYNVPROC)(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IARBPROC)(GLenum target, GLint s);
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERFNVPROC)(GLenum pname, GLfloat value);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTIVSGIXPROC)(GLenum light, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXCOORDPOINTEREXTPROC)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLEMAPATIPROC)(GLuint dst, GLuint interp, GLenum swizzle);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVARBPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)(GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLUNIFORMBUFFEREXTPROC)(GLuint program, GLint location, GLuint buffer);
typedef void (APIENTRYP PFNGLWINDOWPOS2IVMESAPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLUNIFORM3I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLWINDOWPOS4DVMESAPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVEXTPROC)(GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFEXTPROC)(GLenum target, GLenum pname, GLfloat params);
typedef void (APIENTRYP PFNGLACTIVEVARYINGNVPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVEXTPROC)(GLuint index, const GLint *v);
typedef GLsync (APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC)(struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4DATIPROC)(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLGETNUNIFORMUI64VARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIEXTPROC)(GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
typedef void (APIENTRYP PFNGLRESETHISTOGRAMEXTPROC)(GLenum target);
typedef void (APIENTRYP PFNGLLIGHTXOESPROC)(GLenum light, GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLGETOBJECTPARAMETERFVARBPROC)(GLhandleARB obj, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETOBJECTBUFFERIVATIPROC)(GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)(const GLuint *rc, const GLubyte *c, const GLfloat *v);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEINGRPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1IATIPROC)(GLenum stream, GLint x);
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat *values);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLUNIFORM2I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SNVPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLUNIFORM1UI64NVPROC)(GLint location, GLuint64EXT x);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLARRAYOBJECTATIPROC)(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
typedef void (APIENTRYP PFNGLGETINTEGERUI64VNVPROC)(GLenum value, GLuint64EXT *result);
typedef void (APIENTRYP PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLWEIGHTPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLFINISHFENCENVPROC)(GLuint fence);
typedef void (APIENTRYP PFNGLDEPTHRANGEXOESPROC)(GLfixed n, GLfixed f);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VNVPROC)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1SVNVPROC)(GLuint index, GLsizei count, const GLshort *v);
typedef void (APIENTRYP PFNGLUNIFORM1FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLGETVARIANTFLOATVEXTPROC)(GLuint id, GLenum value, GLfloat *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2SVATIPROC)(GLenum stream, const GLshort *coords);
typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLGETUNIFORMFVARBPROC)(GLhandleARB programObj, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLACTIVEPROGRAMEXTPROC)(GLuint program);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLWEIGHTUSVARBPROC)(GLint size, const GLushort *weights);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2XOESPROC)(GLenum texture, GLfixed s, GLfixed t);
typedef void (APIENTRYP PFNGLTEXCOORD2FVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETEXTPROC)(GLfloat factor, GLfloat bias);
typedef void (APIENTRYP PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum stage, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DEXTPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLMATRIXMULTFEXTPROC)(GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVEXTPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLWINDOWPOS2IARBPROC)(GLint x, GLint y);
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3HNVPROC)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFEREXTPROC)(GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETINVARIANTFLOATVEXTPROC)(GLuint id, GLenum value, GLfloat *data);
typedef void (APIENTRYP PFNGLUNIFORM4IARBPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPATHSUBCOMMANDSNVPROC)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
typedef void (APIENTRYP PFNGLFRUSTUMFOESPROC)(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint *samplers);
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
typedef void (APIENTRYP PFNGLWINDOWPOS3IVARBPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERFNVPROC)(GLenum pname, GLfloat param);
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)(GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORISUNPROC)(GLint factor);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLBINORMAL3SEXTPROC)(GLshort bx, GLshort by, GLshort bz);
typedef void (APIENTRYP PFNGLSHARPENTEXFUNCSGISPROC)(GLenum target, GLsizei n, const GLfloat *points);
typedef void (APIENTRYP PFNGLTEXCOORDPOINTEREXTPROC)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FNVPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERNVXPROC)();
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBEXTPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRYP PFNGLBINORMAL3FEXTPROC)(GLfloat bx, GLfloat by, GLfloat bz);
typedef void (APIENTRYP PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint *params);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXFILTERFUNCSGISPROC)(GLenum target, GLenum filter, GLfloat *weights);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVARBPROC)(GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLBINDPROGRAMNVPROC)(GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FNVPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLMULTITEXGENIEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLGENOCCLUSIONQUERIESNVPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLBINORMAL3IVEXTPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)(GLenum stream);
typedef void (APIENTRYP PFNGLRASTERPOS3XOESPROC)(GLfixed x, GLfixed y, GLfixed z);
typedef void (APIENTRYP PFNGLGETMAPPARAMETERIVNVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETFIRSTPERFQUERYIDINTELPROC)(GLuint *queryId);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB programObj, GLuint index, const GLcharARB *name);
typedef void (APIENTRYP PFNGLBUFFERADDRESSRANGENVPROC)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
typedef void (APIENTRYP PFNGLMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIEXTPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4BVOESPROC)(GLenum texture, const GLbyte *coords);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, void **param);
typedef GLint (APIENTRYP PFNGLGETINSTRUMENTSSGIXPROC)();
typedef void (APIENTRYP PFNGLBINORMAL3BEXTPROC)(GLbyte bx, GLbyte by, GLbyte bz);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLINTERPOLATEPATHSNVPROC)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4INVPROC)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLGETQUERYIVARBPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLDRAWARRAYSEXTPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLBLENDEQUATIONEXTPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64 *data);
typedef void (APIENTRYP PFNGLBLENDFUNCINDEXEDAMDPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM1UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
typedef GLsync (APIENTRYP PFNGLIMPORTSYNCEXTPROC)(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1BVOESPROC)(GLenum texture, const GLbyte *coords);
typedef void (APIENTRYP PFNGLGETLISTPARAMETERFVSGIXPROC)(GLuint list, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void *ptr, GLsizei length, const GLchar *label);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (APIENTRYP PFNGLTANGENT3IVEXTPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4UBVNVPROC)(GLuint index, GLsizei count, const GLubyte *v);
typedef void (APIENTRYP PFNGLFOGCOORDHVNVPROC)(const GLhalfNV *fog);
typedef void (APIENTRYP PFNGLUNIFORM2I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLTEXCOORD3XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLTANGENT3DVEXTPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1XVOESPROC)(GLenum texture, const GLfixed *coords);
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)(GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DEXTPROC)(GLuint program, GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLNORMAL3HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)(GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOLOR4UBVERTEX3FVSUNPROC)(const GLubyte *c, const GLfloat *v);
typedef GLuint (APIENTRYP PFNGLGETCOMMANDHEADERNVPROC)(GLenum tokenID, GLuint size);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)(GLuint group, GLuint counter, GLenum pname, void *data);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVARBPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IEXTPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP3ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
typedef void (APIENTRYP PFNGLRESIZEBUFFERSMESAPROC)();
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTAMDPROC)(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef GLenum (APIENTRYP PFNGLOBJECTUNPURGEABLEAPPLEPROC)(GLenum objectType, GLuint name, GLenum option);
typedef void (APIENTRYP PFNGLGETMAPPARAMETERFVNVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLGETINVARIANTBOOLEANVEXTPROC)(GLuint id, GLenum value, GLboolean *data);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLPATHCOVERDEPTHFUNCNVPROC)(GLenum func);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESNVPROC)(GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFNGLMAP1XOESPROC)(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVNVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLGETMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLTEXCOORD1BOESPROC)(GLbyte s);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLENVPROC)(GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLFINISHTEXTURESUNXPROC)();
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4SVNVPROC)(GLuint index, GLsizei count, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FARBPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat *m);
typedef void (APIENTRYP PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLINDEXFORMATNVPROC)(GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *v);
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void (APIENTRYP PFNGLWINDOWPOS3SVMESAPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEATIPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FNVPROC)(GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLMAPVERTEXATTRIB2FAPPLEPROC)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
typedef GLuint (APIENTRYP PFNGLGENVERTEXSHADERSEXTPROC)(GLuint range);
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IEXTPROC)(GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLUNIFORM4I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVNVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS2HVNVPROC)(GLuint index, GLsizei n, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMARBPROC)(GLhandleARB programObj);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSEXTPROC)(GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFNGLRESETMINMAXEXTPROC)(GLenum target);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVNVPROC)(GLuint index, const GLfloat *v);
typedef GLboolean (APIENTRYP PFNGLISQUERYARBPROC)(GLuint id);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETINVARIANTINTEGERVEXTPROC)(GLuint id, GLenum value, GLint *data);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSEXTPROC)(GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVARBPROC)(GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTFEXTPROC)(GLfloat weight);
typedef void (APIENTRYP PFNGLWINDOWPOS4IVMESAPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUSSUNPROC)(GLushort factor);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVNVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSAMPLEMASKEXTPROC)(GLclampf value, GLboolean invert);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLTEXCOORD1XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSEXTPROC)(GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLTEXCOORD3BVOESPROC)(const GLbyte *coords);
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERINVPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VEXTPROC)(GLenum pname, GLuint index, GLdouble *params);
typedef void (APIENTRYP PFNGLFOGCOORDFEXTPROC)(GLfloat coord);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DARBPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLUNIFORM3I64ARBPROC)(GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)(GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DNVPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERISGISPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLCOLORTABLEEXTPROC)(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *table);
typedef void (APIENTRYP PFNGLEXECUTEPROGRAMNVPROC)(GLenum target, GLuint id, const GLfloat *params);
typedef void (APIENTRYP PFNGLCOLOR3XVOESPROC)(const GLfixed *components);
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLMATRIXPOPEXTPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1SATIPROC)(GLenum stream, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IEXTPROC)(GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLFRAGMENTCOVERAGECOLORNVPROC)(GLuint color);
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSAMDPROC)(GLint *numGroups, GLsizei groupsSize, GLuint *groups);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTEREXTPROC)(GLsizei stride, GLsizei count, const GLboolean *pointer);
typedef void (APIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4IATIPROC)(GLenum stream, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVARBPROC)(GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLVARIANTUIVEXTPROC)(GLuint id, const GLuint *addr);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSPRITEPARAMETERISGIXPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLUNIFORM4I64ARBPROC)(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFNGLTEXTURENORMALEXTPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVARBPROC)(GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
typedef void (APIENTRYP PFNGLWINDOWPOS4FMESAPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFNGLRESOLVEDEPTHVALUESNVPROC)();
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMEXTPROC)(GLenum type, const GLchar *string);
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)(GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
typedef void (APIENTRYP PFNGLUNIFORM2UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLBINDVERTEXSHADEREXTPROC)(GLuint id);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3FATIPROC)(GLenum stream, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLUNIFORM2UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERVINTELPROC)(GLint size, GLenum type, const void **pointer);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLNORMALPOINTEREXTPROC)(GLenum type, GLsizei stride, GLsizei count, const void *pointer);
typedef void (APIENTRYP PFNGLTEXTURESTORAGESPARSEAMDPROC)(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLENDPERFQUERYINTELPROC)(GLuint queryHandle);
typedef void (APIENTRYP PFNGLVERTEX3BVOESPROC)(const GLbyte *coords);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC)();
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLLABELOBJECTEXTPROC)(GLenum type, GLuint object, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATANVPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLfloat *params);
typedef void (APIENTRYP PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef GLboolean (APIENTRYP PFNGLAREPROGRAMSRESIDENTNVPROC)(GLsizei n, const GLuint *programs, GLboolean *residences);
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLENVPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLDELETEFENCESNVPROC)(GLsizei n, const GLuint *fences);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2SATIPROC)(GLenum stream, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPOINTSIZEXOESPROC)(GLfixed size);
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
typedef void (APIENTRYP PFNGLWEIGHTDVARBPROC)(GLint size, const GLdouble *weights);
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORARBPROC)(GLuint index, GLuint divisor);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, GLsizei bufSize, void *img);
typedef void (APIENTRYP PFNGLMATRIXLOADDEXTPROC)(GLenum mode, const GLdouble *m);
typedef GLfloat (APIENTRYP PFNGLGETPATHLENGTHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLMAPGRID2XOESPROC)(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLGETVIDEOUI64VNVPROC)(GLuint video_slot, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLUNIFORM2UIEXTPROC)(GLint location, GLuint v0, GLuint v1);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS1HVNVPROC)(GLuint index, GLsizei n, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLTEXTURERENDERBUFFEREXTPROC)(GLuint texture, GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVEXTPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLUNIFORM2UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)(GLuint buffer, GLenum access);
typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXRANGENVPROC)(GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DARBPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef GLboolean (APIENTRYP PFNGLISASYNCMARKERSGIXPROC)(GLuint marker);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DEXTPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble *data);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLBINDBUFFEROFFSETEXTPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum target, GLuint index, const GLfloat *params);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)(GLuint program, GLuint index, GLint *location);
typedef void (APIENTRYP PFNGLVERTEXSTREAM1DATIPROC)(GLenum stream, GLdouble x);
typedef void (APIENTRYP PFNGLCOLORFRAGMENTOP2ATIPROC)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLENVPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLDELETEPROGRAMSARBPROC)(GLsizei n, const GLuint *programs);
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERXOESPROC)(GLsizei n, GLenum type, const GLfixed *buffer);
typedef void (APIENTRYP PFNGLBLENDCOLOREXTPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLDELETEPROGRAMSNVPROC)(GLsizei n, const GLuint *programs);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLVERTEXBLENDARBPROC)(GLint count);
typedef void (APIENTRYP PFNGLPIXELDATARANGENVPROC)(GLenum target, GLsizei length, const void *pointer);
typedef GLint (APIENTRYP PFNGLPOLLINSTRUMENTSSGIXPROC)(GLint *marker_p);
typedef void (APIENTRYP PFNGLINDEXFUNCEXTPROC)(GLenum func, GLclampf ref);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
typedef void (APIENTRYP PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)(GLenum stage, GLenum portion, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERFVSGIPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLMULTITEXRENDERBUFFEREXTPROC)(GLenum texunit, GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXARBPROC)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLdouble *params);
typedef void (APIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2IVATIPROC)(GLenum stream, const GLint *coords);
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGENPROGRAMSNVPROC)(GLsizei n, GLuint *programs);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTFSGIXPROC)(GLenum light, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLSUBPIXELPRECISIONBIASNVPROC)(GLuint xbits, GLuint ybits);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLTANGENT3FVEXTPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DNVPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFNGLSTENCILCLEARTAGEXTPROC)(GLsizei stencilTagBits, GLuint stencilClearTag);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEENABLEAMDPROC)(GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DEXTPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSEXTPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLint *params);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLWINDOWPOS3FVARBPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLUNIFORM4IVARBPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC)(GLint namelen, const GLchar *name, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64VNVPROC)(GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVNVPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *c, const GLfloat *v);
typedef void (APIENTRYP PFNGLNORMALSTREAM3DVATIPROC)(GLenum stream, const GLdouble *coords);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLPATHSTENCILDEPTHOFFSETNVPROC)(GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFARBPROC)(const GLfloat *m);
typedef GLboolean (APIENTRYP PFNGLISSTATENVPROC)(GLuint state);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM1I64VARBPROC)(GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLCOLOR3FVERTEX3FSUNPROC)(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DEXTPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble near, GLdouble far);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLCOLOR3HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLWINDOWPOS2DVMESAPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLNORMALSTREAM3BVATIPROC)(GLenum stream, const GLbyte *coords);
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (APIENTRYP PFNGLSTENCILFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask);
typedef void (APIENTRYP PFNGLWINDOWPOS3IARBPROC)(GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEX4XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLPROGRAMVERTEXLIMITNVPROC)(GLenum target, GLint limit);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLUNIFORM3I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3SVNVPROC)(GLuint index, GLsizei count, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXBLENDENVFATIPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERUI64VNVPROC)(GLenum target, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVEXTPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVEXTPROC)(const GLbyte *v);
typedef void (APIENTRYP PFNGLTANGENT3BVEXTPROC)(const GLbyte *v);
typedef void (APIENTRYP PFNGLMATRIXINDEXUBVARBPROC)(GLint size, const GLubyte *indices);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VNVPROC)(GLuint index, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVNVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLGETMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENQUERIESPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLGETMAPATTRIBPARAMETERIVNVPROC)(GLenum target, GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVARBPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVNVPROC)(GLenum pname, GLuint index, GLfloat *val);
typedef void * (APIENTRYP PFNGLMAPOBJECTBUFFERATIPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64NVPROC)(GLuint program, GLint location, GLuint64EXT value);
typedef void (APIENTRYP PFNGLLOADMATRIXXOESPROC)(const GLfixed *m);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLMATRIXROTATEFEXTPROC)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLGETCLIPPLANEXOESPROC)(GLenum plane, GLfixed *equation);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVEXTPROC)(const GLuint *v);
typedef void * (APIENTRYP PFNGLMAPBUFFERARBPROC)(GLenum target, GLenum access);
typedef void (APIENTRYP PFNGLGETPATHSPACINGNVPROC)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORDSUNPROC)(GLdouble factor);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLMATRIXLOAD3X2FNVPROC)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLGENTEXTURESEXTPROC)(GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLTANGENT3IEXTPROC)(GLint tx, GLint ty, GLint tz);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
typedef void (APIENTRYP PFNGLDISABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERXVOESPROC)(GLenum target, GLenum pname, GLfixed *params);
typedef void (APIENTRYP PFNGLDELETEFRAGMENTSHADERATIPROC)(GLuint id);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLWINDOWRECTANGLESEXTPROC)(GLenum mode, GLsizei count, const GLint *box);
typedef void (APIENTRYP PFNGLBEGINQUERYARBPROC)(GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLVERTEX4BVOESPROC)(const GLbyte *coords);
typedef GLboolean (APIENTRYP PFNGLTESTFENCENVPROC)(GLuint fence);
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLBINORMAL3BVEXTPROC)(const GLbyte *v);
typedef void (APIENTRYP PFNGLCLIPPLANEXOESPROC)(GLenum plane, const GLfixed *equation);
typedef void (APIENTRYP PFNGLGENFENCESNVPROC)(GLsizei n, GLuint *fences);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERNVXPROC)(GLuint id);
typedef void (APIENTRYP PFNGLFINISHOBJECTAPPLEPROC)(GLenum object, GLint name);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)(const GLuint *rc, const GLfloat *tc, const GLfloat *v);
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
typedef void (APIENTRYP PFNGLVERTEXWEIGHTFVEXTPROC)(const GLfloat *weight);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLGETCOLORTABLESGIPROC)(GLenum target, GLenum format, GLenum type, void *table);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLFREEOBJECTBUFFERATIPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLBLENDBARRIERNVPROC)();
typedef void (APIENTRYP PFNGLUNIFORM4I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETVIDEOCAPTURESTREAMIVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLUNIFORM1I64ARBPROC)(GLint location, GLint64 x);
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLARRAYELEMENTEXTPROC)(GLint i);
typedef void (APIENTRYP PFNGLUNIFORM3UIVEXTPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPOPGROUPMARKEREXTPROC)();
typedef void (APIENTRYP PFNGLSETLOCALCONSTANTEXTPROC)(GLuint id, GLenum type, const void *addr);
typedef void (APIENTRYP PFNGLCOLOR4HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
typedef void (APIENTRYP PFNGLWINDOWPOS4IMESAPROC)(GLint x, GLint y, GLint z, GLint w);
typedef GLint (APIENTRYP PFNGLPOLLASYNCSGIXPROC)(GLuint *markerp);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1XOESPROC)(GLenum texture, GLfixed s);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFNGLVERTEXPOINTERVINTELPROC)(GLint size, GLenum type, const void **pointer);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVEXTPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLGETSEPARABLEFILTEREXTPROC)(GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IARBPROC)(GLenum target, GLint s, GLint t, GLint r);
typedef void (APIENTRYP PFNGLVERTEX3HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLGETMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETFLOATINDEXEDVEXTPROC)(GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLTRANSFORMPATHNVPROC)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLVDPAUUNMAPSURFACESNVPROC)(GLsizei numSurface, const GLvdpauSurfaceNV *surfaces);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLFLUSHPIXELDATARANGENVPROC)(GLenum target);
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFNGLUNIFORM3UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SNVPROC)(GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXSTREAM2FATIPROC)(GLenum stream, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DARBPROC)(GLenum target, GLdouble s, GLdouble t);
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLNORMALSTREAM3SATIPROC)(GLenum stream, GLshort nx, GLshort ny, GLshort nz);
typedef void (APIENTRYP PFNGLTEXENVXOESPROC)(GLenum target, GLenum pname, GLfixed param);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBNVPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4XOESPROC)(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3FVATIPROC)(GLenum stream, const GLfloat *coords);
typedef void (APIENTRYP PFNGLCULLPARAMETERFVEXTPROC)(GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLEDGEFLAGFORMATNVPROC)(GLsizei stride);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLTEXBUFFERARBPROC)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERNVPROC)(GLuint index, GLint fsize, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)(GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v);
typedef void (APIENTRYP PFNGLCOMPILECOMMANDLISTNVPROC)(GLuint list);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar *name);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISBUFFERRESIDENTNVPROC)(GLenum target);
typedef void (APIENTRYP PFNGLTEXCOORD2XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
typedef void (APIENTRYP PFNGLTAGSAMPLEBUFFERSGIXPROC)();
typedef void (APIENTRYP PFNGLVDPAUUNREGISTERSURFACENVPROC)(GLvdpauSurfaceNV surface);
typedef void (APIENTRYP PFNGLGETPERFQUERYIDBYNAMEINTELPROC)(GLchar *queryName, GLuint *queryId);
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 *data);
typedef void (APIENTRYP PFNGLVERTEX2BOESPROC)(GLbyte x, GLbyte y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVARBPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IARBPROC)(GLenum target, GLint s, GLint t);
typedef GLboolean (APIENTRYP PFNGLTESTFENCEAPPLEPROC)(GLuint fence);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64VNVPROC)(GLuint index, const GLint64EXT *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVARBPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLMATRIXMULT3X2FNVPROC)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERXVOESPROC)(GLenum target, GLint level, GLenum pname, GLfixed *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVNVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLBITMAPXOESPROC)(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte *bitmap);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)(GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMIVEXTPROC)(GLuint program, GLenum target, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISFENCENVPROC)(GLuint fence);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLuint *params);
typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(GLenum target);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLDELETEOCCLUSIONQUERIESNVPROC)(GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLVERTEX4HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLUNLOCKARRAYSEXTPROC)();
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
typedef void (APIENTRYP PFNGLPRESENTFRAMEKEYEDNVPROC)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLUNIFORM4I64VARBPROC)(GLint location, GLsizei count, const GLint64 *value);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLPUSHGROUPMARKEREXTPROC)(GLsizei length, const GLchar *marker);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXXOESPROC)(const GLfixed *m);
typedef void (APIENTRYP PFNGLGETPIXELMAPXVPROC)(GLenum map, GLint size, GLfixed *values);
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLenum target, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)(GLenum target, GLuint index, GLuint *param);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVEXTPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
typedef void (APIENTRYP PFNGLGETVIDEOCAPTURESTREAMDVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4FVATIPROC)(GLenum stream, const GLfloat *coords);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLDEFORMATIONMAP3FSGIXPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum target, GLuint index, const GLfloat *params);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)();
typedef void (APIENTRYP PFNGLWINDOWPOS2SMESAPROC)(GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFVEXTPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVARBPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum target, GLuint index, const GLdouble *params);
typedef void (APIENTRYP PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)(GLenum target, GLuint index, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISOCCLUSIONQUERYNVPROC)(GLuint id);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLTEXCOORD1HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERFVSGISPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SARBPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef GLboolean (APIENTRYP PFNGLISBUFFERARBPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1BOESPROC)(GLenum texture, GLbyte s);
typedef void (APIENTRYP PFNGLTEXCOORD4HNVPROC)(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
typedef GLuint (APIENTRYP PFNGLGENSYMBOLSEXTPROC)(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLTANGENTPOINTEREXTPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint *samplers);
typedef void (APIENTRYP PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)(GLenum target, GLuint index, GLint *params);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLBEGINFRAGMENTSHADERATIPROC)();
typedef void (APIENTRYP PFNGLGENNAMESAMDPROC)(GLenum identifier, GLuint num, GLuint *names);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IEXTPROC)(GLint red, GLint green, GLint blue);
typedef void (APIENTRYP PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)(GLenum target, GLuint index, GLsizei count, const GLuint *params);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC)(GLDEBUGPROCARB callback, const void *userParam);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *tc, const GLfloat *c, const GLfloat *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
typedef void (APIENTRYP PFNGLMULTITEXGENDEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
typedef void (APIENTRYP PFNGLTEXCOORD2HNVPROC)(GLhalfNV s, GLhalfNV t);
typedef void (APIENTRYP PFNGLREQUESTRESIDENTPROGRAMSNVPROC)(GLsizei n, const GLuint *programs);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLEVALUATEDEPTHVALUESARBPROC)();
typedef void (APIENTRYP PFNGLWINDOWPOS2SARBPROC)(GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLTEXPARAMETERXOESPROC)(GLenum target, GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)(GLuint64 handle);
typedef void (APIENTRYP PFNGLENDVERTEXSHADEREXTPROC)();
typedef void (APIENTRYP PFNGLUNIFORM1IARBPROC)(GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM1UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLGETCLIPPLANEFOESPROC)(GLenum plane, GLfloat *equation);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETER4FNVPROC)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4HVNVPROC)(GLenum target, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC)();
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLTEXCOORD2BVOESPROC)(const GLbyte *coords);
typedef void (APIENTRYP PFNGLEVALCOORD2XOESPROC)(GLfixed u, GLfixed v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void *indirect);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4FATIPROC)(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLGETCOVERAGEMODULATIONTABLENVPROC)(GLsizei bufsize, GLfloat *v);
typedef void (APIENTRYP PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETUNIFORMI64VARBPROC)(GLuint program, GLint location, GLint64 *params);
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTEXTPROC)(GLsizei n, const GLuint *textures, GLboolean *residences);
typedef void (APIENTRYP PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params);
typedef void (APIENTRYP PFNGLMAPPARAMETERIVNVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVARBPROC)(GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SEXTPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTNVPROC)();
typedef void (APIENTRYP PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)(GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC)(GLuint index, const GLuint64EXT *v);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVARBPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
typedef void (APIENTRYP PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMARBPROC)(GLuint program);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREEXTPROC)(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
typedef void (APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLEVALCOORD1XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLALPHAFRAGMENTOP1ATIPROC)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DARBPROC)(GLenum target, GLdouble s);
typedef void (APIENTRYP PFNGLCREATEPERFQUERYINTELPROC)(GLuint queryId, GLuint *queryHandle);
typedef void (APIENTRYP PFNGLWINDOWPOS3IVMESAPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLPIXELTEXGENPARAMETERFSGISPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM3FARBPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
typedef void (APIENTRYP PFNGLVERTEX2HNVPROC)(GLhalfNV x, GLhalfNV y);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint index);
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
typedef void (APIENTRYP PFNGLTEXCOORD4HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLUNIFORM3UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT *value);
typedef void (APIENTRYP PFNGLGETVIDEOUIVNVPROC)(GLuint video_slot, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVARBPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLBINORMAL3FVEXTPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64ARBPROC)(GLuint program, GLint location, GLuint64 x);
typedef void (APIENTRYP PFNGLWINDOWPOS2SVARBPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEX4XOESPROC)(GLfixed x, GLfixed y, GLfixed z);
typedef void (APIENTRYP PFNGLWINDOWPOS2IVARBPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)(GLuint vaobj, GLuint index, GLuint divisor);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)(GLenum target, GLuint index, const GLint *params);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONEXTPROC)(GLuint program, GLuint color, const GLchar *name);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void **pointer);
typedef GLuint (APIENTRYP PFNGLBINDLIGHTPARAMETEREXTPROC)(GLenum light, GLenum value);
typedef void (APIENTRYP PFNGLGETFOGFUNCSGISPROC)(GLfloat *points);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTISGIXPROC)(GLenum light, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETATTACHEDOBJECTSARBPROC)(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
typedef void (APIENTRYP PFNGLINDEXXOESPROC)(GLfixed component);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLMATRIXINDEXPOINTERARBPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLDELETECOMMANDLISTSNVPROC)(GLsizei n, const GLuint *lists);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVEXTPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLMAKEBUFFERRESIDENTNVPROC)(GLenum target, GLenum access);
typedef void (APIENTRYP PFNGLACTIVETEXTUREARBPROC)(GLenum texture);
typedef void (APIENTRYP PFNGLGETPERFQUERYDATAINTELPROC)(GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid *data, GLuint *bytesWritten);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLPATHPARAMETERFNVPROC)(GLuint path, GLenum pname, GLfloat value);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVARBPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLDEPTHBOUNDSDNVPROC)(GLdouble zmin, GLdouble zmax);
typedef void (APIENTRYP PFNGLDELETETEXTURESEXTPROC)(GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLLIGHTMODELXVOESPROC)(GLenum pname, const GLfixed *param);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLFLUSHSTATICDATAIBMPROC)(GLenum target);
typedef void (APIENTRYP PFNGLRASTERPOS4XOESPROC)(GLfixed x, GLfixed y, GLfixed z, GLfixed w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVARBPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLLIGHTENVISGIXPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSADDRESSNVPROC)(GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)(GLsizei length, void *pointer);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVARBPROC)(GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAGMENTLIGHTMODELFSGIXPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLGETPOINTERI_VEXTPROC)(GLenum pname, GLuint index, void **params);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLMAPGRID1XOESPROC)(GLint n, GLfixed u1, GLfixed u2);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVEXTPROC)(const GLushort *v);
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALIVSGIXPROC)(GLenum face, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVARIANTIVEXTPROC)(GLuint id, const GLint *addr);
typedef void (APIENTRYP PFNGLTEXTUREMATERIALEXTPROC)(GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLGETPATHCOORDSNVPROC)(GLuint path, GLfloat *coords);
typedef void (APIENTRYP PFNGLCOLOR4XVOESPROC)(const GLfixed *components);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLCLAMPCOLORARBPROC)(GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLVERTEX4BOESPROC)(GLbyte x, GLbyte y, GLbyte z, GLbyte w);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVARBPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLGETINFOLOGARBPROC)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORSSUNPROC)(GLshort factor);
typedef void (APIENTRYP PFNGLMATRIXMULTDEXTPROC)(GLenum mode, const GLdouble *m);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVARBPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3IATIPROC)(GLenum stream, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLTEXPARAMETERXVOESPROC)(GLenum target, GLenum pname, const GLfixed *params);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETNUNIFORMI64VARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC)(GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAARBPROC)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void *data);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC)(GLuint index, GLenum pname, GLuint64EXT *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLIMAGETRANSFORMPARAMETERFHPPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLVERTEX2BVOESPROC)(const GLbyte *coords);
typedef void (APIENTRYP PFNGLGETMAPCONTROLPOINTSNVPROC)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void *points);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS4HVNVPROC)(GLuint index, GLsizei n, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGENVPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLNORMALPOINTERLISTIBMPROC)(GLenum type, GLint stride, const void **pointer, GLint ptrstride);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLREPLACEMENTCODEUISUNPROC)(GLuint code);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVNVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXSTREAM3DATIPROC)(GLenum stream, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLLIGHTXVOESPROC)(GLenum light, GLenum pname, const GLfixed *params);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDARBPROC)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFNGLWINDOWPOS2IMESAPROC)(GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEX2XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
typedef GLboolean (APIENTRYP PFNGLISPOINTINFILLPATHNVPROC)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIEXTPROC)(GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLGETFRAGMENTLIGHTFVSGIXPROC)(GLenum light, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLBINDBUFFEROFFSETNVPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLPASSTEXCOORDATIPROC)(GLuint dst, GLuint coord, GLenum swizzle);
typedef void (APIENTRYP PFNGLGETTEXGENXVOESPROC)(GLenum coord, GLenum pname, GLfixed *params);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLACCUMXOESPROC)(GLenum op, GLfixed value);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLCLIPPLANEFOESPROC)(GLenum plane, const GLfloat *equation);
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLPOINTPARAMETERXVOESPROC)(GLenum pname, const GLfixed *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBS3HVNVPROC)(GLuint index, GLsizei n, const GLhalfNV *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4HNVPROC)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IEXTPROC)(GLuint index, GLint x);
typedef void (APIENTRYP PFNGLLIGHTMODELXOESPROC)(GLenum pname, GLfixed param);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLVERTEXSTREAM4DVATIPROC)(GLenum stream, const GLdouble *coords);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLVERTEXBLENDENVIATIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKNVPROC)(GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGETOBJECTBUFFERFVATIPROC)(GLuint buffer, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLENDVIDEOCAPTURENVPROC)(GLuint video_capture_slot);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLTEXCOORD4FVERTEX4FVSUNPROC)(const GLfloat *tc, const GLfloat *v);
typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFNGLGETFRAGMENTMATERIALIVSGIXPROC)(GLenum face, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLWINDOWPOS3DMESAPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4HNVPROC)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVEXTPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC)();
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPEXTPROC)(GLuint texture, GLenum target);
typedef void (APIENTRYP PFNGLTEXCOORD3BOESPROC)(GLbyte s, GLbyte t, GLbyte r);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2FVARBPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)(GLenum target, GLuint index, const GLuint *params);
typedef void (APIENTRYP PFNGLFLUSHVERTEXARRAYRANGENVPROC)();
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVEXTPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLINDEXMATERIALEXTPROC)(GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLTEXCOORD2HVNVPROC)(const GLhalfNV *v);
typedef void (APIENTRYP PFNGLGLOBALALPHAFACTORUISUNPROC)(GLuint factor);
typedef void (APIENTRYP PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)(GLuint id);
typedef void (APIENTRYP PFNGLUNIFORM4UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 *value);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKAMDPROC)(GLDEBUGPROCAMD callback, void *userParam);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DNVPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLWINDOWPOS4SVMESAPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLELEMENTPOINTERAPPLEPROC)(GLenum type, const void *pointer);
typedef void (APIENTRYP PFNGLPATHSTRINGNVPROC)(GLuint path, GLenum format, GLsizei length, const void *pathString);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPATHDASHARRAYNVPROC)(GLuint path, GLsizei dashCount, const GLfloat *dashArray);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLEARBPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLPIXELTEXGENSGIXPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLGETLOCALCONSTANTFLOATVEXTPROC)(GLuint id, GLenum value, GLfloat *data);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLCLEARCOLORIUIEXTPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint lod, void *img);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte *v);
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER2DEXTPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
typedef void (APIENTRYP PFNGLLOCKARRAYSEXTPROC)(GLint first, GLsizei count);
typedef GLuint (APIENTRYP PFNGLGENFRAGMENTSHADERSATIPROC)(GLuint range);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEEXTPROC)(GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SARBPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLVERTEX3XVOESPROC)(const GLfixed *coords);
typedef void (APIENTRYP PFNGLUPDATEOBJECTBUFFERATIPROC)(GLuint buffer, GLuint offset, GLsizei size, const void *pointer, GLenum preserve);
typedef void (APIENTRYP PFNGLWINDOWPOS2FARBPROC)(GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLCOPYCOLORTABLESGIPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SARBPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)(GLenum matrixMode, const GLfloat *m);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)();
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLBINDTEXTUREEXTPROC)(GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1HNVPROC)(GLuint index, GLhalfNV x);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3BVOESPROC)(GLenum texture, const GLbyte *coords);
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
typedef GLuint (APIENTRYP PFNGLBINDTEXGENPARAMETEREXTPROC)(GLenum unit, GLenum coord, GLenum value);
typedef void (APIENTRYP PFNGLNORMALSTREAM3BATIPROC)(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVEXTPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLSTARTINSTRUMENTSSGIXPROC)();
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)(GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3HNVPROC)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
typedef void (APIENTRYP PFNGLGETVIDEOCAPTUREIVNVPROC)(GLuint video_capture_slot, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSNVPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLCOMBINERPARAMETERIVNVPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLTEXCOORD4BOESPROC)(GLbyte s, GLbyte t, GLbyte r, GLbyte q);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (APIENTRYP PFNGLRASTERSAMPLESEXTPROC)(GLuint samples, GLboolean fixedsamplelocations);
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONEXTPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLTEXCOORD3XOESPROC)(GLfixed s, GLfixed t, GLfixed r);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DEXTPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLCOMMANDLISTSEGMENTSNVPROC)(GLuint list, GLuint segments);
typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTARRAYATIPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAGMENTMATERIALISGIXPROC)(GLenum face, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLREADINSTRUMENTSSGIXPROC)(GLint marker);
typedef void (APIENTRYP PFNGLBEGINOCCLUSIONQUERYNVPROC)(GLuint id);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)(GLuint id);
typedef void (APIENTRYP PFNGLMINMAXEXTPROC)(GLenum target, GLenum internalformat, GLboolean sink);
typedef void (APIENTRYP PFNGLUNIFORM1IVARBPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2BOESPROC)(GLenum texture, GLbyte s, GLbyte t);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef GLboolean (APIENTRYP PFNGLISPOINTINSTROKEPATHNVPROC)(GLuint path, GLfloat x, GLfloat y);

GLAPI PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC glad_glMultiDrawArraysIndirectBindlessCountNV;
#define glMultiDrawArraysIndirectBindlessCountNV glad_glMultiDrawArraysIndirectBindlessCountNV
GLAPI PFNGLCOPYTEXIMAGE1DPROC glad_glCopyTexImage1D;
#define glCopyTexImage1D glad_glCopyTexImage1D
GLAPI PFNGLPROGRAMUNIFORM1I64ARBPROC glad_glProgramUniform1i64ARB;
#define glProgramUniform1i64ARB glad_glProgramUniform1i64ARB
GLAPI PFNGLHINTPGIPROC glad_glHintPGI;
#define glHintPGI glad_glHintPGI
GLAPI PFNGLGETINTEGERINDEXEDVEXTPROC glad_glGetIntegerIndexedvEXT;
#define glGetIntegerIndexedvEXT glad_glGetIntegerIndexedvEXT
GLAPI PFNGLPROGRAMUNIFORM4UI64ARBPROC glad_glProgramUniform4ui64ARB;
#define glProgramUniform4ui64ARB glad_glProgramUniform4ui64ARB
GLAPI PFNGLMULTITEXCOORD2SARBPROC glad_glMultiTexCoord2sARB;
#define glMultiTexCoord2sARB glad_glMultiTexCoord2sARB
GLAPI PFNGLPROGRAMENVPARAMETER4FARBPROC glad_glProgramEnvParameter4fARB;
#define glProgramEnvParameter4fARB glad_glProgramEnvParameter4fARB
GLAPI PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC glad_glProgramBufferParametersIuivNV;
#define glProgramBufferParametersIuivNV glad_glProgramBufferParametersIuivNV
GLAPI PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC glad_glPathMemoryGlyphIndexArrayNV;
#define glPathMemoryGlyphIndexArrayNV glad_glPathMemoryGlyphIndexArrayNV
GLAPI PFNGLUNIFORM4UIEXTPROC glad_glUniform4uiEXT;
#define glUniform4uiEXT glad_glUniform4uiEXT
GLAPI PFNGLPROGRAMUNIFORM3UI64ARBPROC glad_glProgramUniform3ui64ARB;
#define glProgramUniform3ui64ARB glad_glProgramUniform3ui64ARB
GLAPI PFNGLDISABLECLIENTSTATEIEXTPROC glad_glDisableClientStateiEXT;
#define glDisableClientStateiEXT glad_glDisableClientStateiEXT
GLAPI PFNGLPATHGLYPHSNVPROC glad_glPathGlyphsNV;
#define glPathGlyphsNV glad_glPathGlyphsNV
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glad_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN glad_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
GLAPI PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glad_glGetCombinerInputParameterivNV;
#define glGetCombinerInputParameterivNV glad_glGetCombinerInputParameterivNV
GLAPI PFNGLVERTEX2XOESPROC glad_glVertex2xOES;
#define glVertex2xOES glad_glVertex2xOES
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glad_glDrawElementsInstancedBaseInstance;
#define glDrawElementsInstancedBaseInstance glad_glDrawElementsInstancedBaseInstance
GLAPI PFNGLGETTEXTUREPARAMETERIVEXTPROC glad_glGetTextureParameterivEXT;
#define glGetTextureParameterivEXT glad_glGetTextureParameterivEXT
GLAPI PFNGLVERTEXATTRIBP4UIPROC glad_glVertexAttribP4ui;
#define glVertexAttribP4ui glad_glVertexAttribP4ui
GLAPI PFNGLISBUFFERPROC glad_glIsBuffer;
#define glIsBuffer glad_glIsBuffer
GLAPI PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv;
#define glGetMultisamplefv glad_glGetMultisamplefv
GLAPI PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC glad_glTextureImage2DMultisampleNV;
#define glTextureImage2DMultisampleNV glad_glTextureImage2DMultisampleNV
GLAPI PFNGLGENPERFMONITORSAMDPROC glad_glGenPerfMonitorsAMD;
#define glGenPerfMonitorsAMD glad_glGenPerfMonitorsAMD
GLAPI PFNGLVERTEXATTRIB3HVNVPROC glad_glVertexAttrib3hvNV;
#define glVertexAttrib3hvNV glad_glVertexAttrib3hvNV
GLAPI PFNGLFRAGMENTMATERIALFSGIXPROC glad_glFragmentMaterialfSGIX;
#define glFragmentMaterialfSGIX glad_glFragmentMaterialfSGIX
GLAPI PFNGLVDPAUGETSURFACEIVNVPROC glad_glVDPAUGetSurfaceivNV;
#define glVDPAUGetSurfaceivNV glad_glVDPAUGetSurfaceivNV
GLAPI PFNGLGETINTERNALFORMATSAMPLEIVNVPROC glad_glGetInternalformatSampleivNV;
#define glGetInternalformatSampleivNV glad_glGetInternalformatSampleivNV
GLAPI PFNGLVERTEXATTRIB4UBVPROC glad_glVertexAttrib4ubv;
#define glVertexAttrib4ubv glad_glVertexAttrib4ubv
GLAPI PFNGLVERTEXATTRIB4NUBVARBPROC glad_glVertexAttrib4NubvARB;
#define glVertexAttrib4NubvARB glad_glVertexAttrib4NubvARB
GLAPI PFNGLPROGRAMUNIFORM2FEXTPROC glad_glProgramUniform2fEXT;
#define glProgramUniform2fEXT glad_glProgramUniform2fEXT
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC glad_glMultiDrawElementsIndirectBindlessNV;
#define glMultiDrawElementsIndirectBindlessNV glad_glMultiDrawElementsIndirectBindlessNV
GLAPI PFNGLPROGRAMUNIFORM3FPROC glad_glProgramUniform3f;
#define glProgramUniform3f glad_glProgramUniform3f
GLAPI PFNGLVERTEXATTRIBL4DPROC glad_glVertexAttribL4d;
#define glVertexAttribL4d glad_glVertexAttribL4d
GLAPI PFNGLGETFRAGMENTMATERIALFVSGIXPROC glad_glGetFragmentMaterialfvSGIX;
#define glGetFragmentMaterialfvSGIX glad_glGetFragmentMaterialfvSGIX
GLAPI PFNGLGETTEXENVXVOESPROC glad_glGetTexEnvxvOES;
#define glGetTexEnvxvOES glad_glGetTexEnvxvOES
GLAPI PFNGLUNIFORMMATRIX3DVPROC glad_glUniformMatrix3dv;
#define glUniformMatrix3dv glad_glUniformMatrix3dv
GLAPI PFNGLGETVERTEXARRAYINDEXEDIVPROC glad_glGetVertexArrayIndexediv;
#define glGetVertexArrayIndexediv glad_glGetVertexArrayIndexediv
GLAPI PFNGLINSERTEVENTMARKEREXTPROC glad_glInsertEventMarkerEXT;
#define glInsertEventMarkerEXT glad_glInsertEventMarkerEXT
GLAPI PFNGLBEGINVERTEXSHADEREXTPROC glad_glBeginVertexShaderEXT;
#define glBeginVertexShaderEXT glad_glBeginVertexShaderEXT
GLAPI PFNGLNORMAL3FVERTEX3FSUNPROC glad_glNormal3fVertex3fSUN;
#define glNormal3fVertex3fSUN glad_glNormal3fVertex3fSUN
GLAPI PFNGLISENABLEDPROC glad_glIsEnabled;
#define glIsEnabled glad_glIsEnabled
GLAPI PFNGLSTENCILOPPROC glad_glStencilOp;
#define glStencilOp glad_glStencilOp
GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D;
#define glFramebufferTexture2D glad_glFramebufferTexture2D
GLAPI PFNGLVERTEXARRAYATTRIBIFORMATPROC glad_glVertexArrayAttribIFormat;
#define glVertexArrayAttribIFormat glad_glVertexArrayAttribIFormat
GLAPI PFNGLTEXBUFFEREXTPROC glad_glTexBufferEXT;
#define glTexBufferEXT glad_glTexBufferEXT
GLAPI PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers;
#define glGenFramebuffers glad_glGenFramebuffers
GLAPI PFNGLDRAWTEXTURENVPROC glad_glDrawTextureNV;
#define glDrawTextureNV glad_glDrawTextureNV
GLAPI PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders;
#define glGetAttachedShaders glad_glGetAttachedShaders
GLAPI PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC glad_glGetPixelTexGenParameterfvSGIS;
#define glGetPixelTexGenParameterfvSGIS glad_glGetPixelTexGenParameterfvSGIS
GLAPI PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC glad_glReplacementCodeuiNormal3fVertex3fSUN;
#define glReplacementCodeuiNormal3fVertex3fSUN glad_glReplacementCodeuiNormal3fVertex3fSUN
GLAPI PFNGLVERTEXSTREAM4SATIPROC glad_glVertexStream4sATI;
#define glVertexStream4sATI glad_glVertexStream4sATI
GLAPI PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays;
#define glDeleteVertexArrays glad_glDeleteVertexArrays
GLAPI PFNGLWINDOWPOS3IMESAPROC glad_glWindowPos3iMESA;
#define glWindowPos3iMESA glad_glWindowPos3iMESA
GLAPI PFNGLCOLOR4UBVERTEX2FSUNPROC glad_glColor4ubVertex2fSUN;
#define glColor4ubVertex2fSUN glad_glColor4ubVertex2fSUN
GLAPI PFNGLVERTEXATTRIB2FVNVPROC glad_glVertexAttrib2fvNV;
#define glVertexAttrib2fvNV glad_glVertexAttrib2fvNV
GLAPI PFNGLMEMORYBARRIERBYREGIONPROC glad_glMemoryBarrierByRegion;
#define glMemoryBarrierByRegion glad_glMemoryBarrierByRegion
GLAPI PFNGLUNIFORM2DVPROC glad_glUniform2dv;
#define glUniform2dv glad_glUniform2dv
GLAPI PFNGLVERTEXATTRIB4HVNVPROC glad_glVertexAttrib4hvNV;
#define glVertexAttrib4hvNV glad_glVertexAttrib4hvNV
GLAPI PFNGLGETPROGRAMSTRINGNVPROC glad_glGetProgramStringNV;
#define glGetProgramStringNV glad_glGetProgramStringNV
GLAPI PFNGLGETUNIFORMFVPROC glad_glGetUniformfv;
#define glGetUniformfv glad_glGetUniformfv
GLAPI PFNGLVERTEXARRAYBINDINGDIVISORPROC glad_glVertexArrayBindingDivisor;
#define glVertexArrayBindingDivisor glad_glVertexArrayBindingDivisor
GLAPI PFNGLPROGRAMUNIFORM1DVEXTPROC glad_glProgramUniform1dvEXT;
#define glProgramUniform1dvEXT glad_glProgramUniform1dvEXT
GLAPI PFNGLMATRIXLOADFEXTPROC glad_glMatrixLoadfEXT;
#define glMatrixLoadfEXT glad_glMatrixLoadfEXT
GLAPI PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv;
#define glGetRenderbufferParameteriv glad_glGetRenderbufferParameteriv
GLAPI PFNGLVERTEXATTRIBL3I64VNVPROC glad_glVertexAttribL3i64vNV;
#define glVertexAttribL3i64vNV glad_glVertexAttribL3i64vNV
GLAPI PFNGLFENCESYNCPROC glad_glFenceSync;
#define glFenceSync glad_glFenceSync
GLAPI PFNGLVERTEXATTRIBS4FVNVPROC glad_glVertexAttribs4fvNV;
#define glVertexAttribs4fvNV glad_glVertexAttribs4fvNV
GLAPI PFNGLPAUSETRANSFORMFEEDBACKNVPROC glad_glPauseTransformFeedbackNV;
#define glPauseTransformFeedbackNV glad_glPauseTransformFeedbackNV
GLAPI PFNGLGETQUERYOBJECTI64VEXTPROC glad_glGetQueryObjecti64vEXT;
#define glGetQueryObjecti64vEXT glad_glGetQueryObjecti64vEXT
GLAPI PFNGLVALIDATEPROGRAMPIPELINEPROC glad_glValidateProgramPipeline;
#define glValidateProgramPipeline glad_glValidateProgramPipeline
GLAPI PFNGLENDPERFMONITORAMDPROC glad_glEndPerfMonitorAMD;
#define glEndPerfMonitorAMD glad_glEndPerfMonitorAMD
GLAPI PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC glad_glStencilStrokePathInstancedNV;
#define glStencilStrokePathInstancedNV glad_glStencilStrokePathInstancedNV
GLAPI PFNGLPROGRAMUNIFORM2I64NVPROC glad_glProgramUniform2i64NV;
#define glProgramUniform2i64NV glad_glProgramUniform2i64NV
GLAPI PFNGLVERTEXSTREAM1IVATIPROC glad_glVertexStream1ivATI;
#define glVertexStream1ivATI glad_glVertexStream1ivATI
GLAPI PFNGLPROGRAMENVPARAMETERI4INVPROC glad_glProgramEnvParameterI4iNV;
#define glProgramEnvParameterI4iNV glad_glProgramEnvParameterI4iNV
GLAPI PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glad_glDrawTransformFeedbackInstanced;
#define glDrawTransformFeedbackInstanced glad_glDrawTransformFeedbackInstanced
GLAPI PFNGLDELETEVERTEXARRAYSAPPLEPROC glad_glDeleteVertexArraysAPPLE;
#define glDeleteVertexArraysAPPLE glad_glDeleteVertexArraysAPPLE
GLAPI PFNGLQUERYMATRIXXOESPROC glad_glQueryMatrixxOES;
#define glQueryMatrixxOES glad_glQueryMatrixxOES
GLAPI PFNGLDRAWTRANSFORMFEEDBACKPROC glad_glDrawTransformFeedback;
#define glDrawTransformFeedback glad_glDrawTransformFeedback
GLAPI PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glad_glTexCoord2fColor4fNormal3fVertex3fvSUN;
#define glTexCoord2fColor4fNormal3fVertex3fvSUN glad_glTexCoord2fColor4fNormal3fVertex3fvSUN
GLAPI PFNGLVDPAUREGISTERVIDEOSURFACENVPROC glad_glVDPAURegisterVideoSurfaceNV;
#define glVDPAURegisterVideoSurfaceNV glad_glVDPAURegisterVideoSurfaceNV
GLAPI PFNGLGETTEXPARAMETERIUIVPROC glad_glGetTexParameterIuiv;
#define glGetTexParameterIuiv glad_glGetTexParameterIuiv
GLAPI PFNGLBINDBUFFERBASENVPROC glad_glBindBufferBaseNV;
#define glBindBufferBaseNV glad_glBindBufferBaseNV
GLAPI PFNGLFRAGMENTLIGHTMODELISGIXPROC glad_glFragmentLightModeliSGIX;
#define glFragmentLightModeliSGIX glad_glFragmentLightModeliSGIX
GLAPI PFNGLLISTPARAMETERISGIXPROC glad_glListParameteriSGIX;
#define glListParameteriSGIX glad_glListParameteriSGIX
GLAPI PFNGLUNIFORMUI64VNVPROC glad_glUniformui64vNV;
#define glUniformui64vNV glad_glUniformui64vNV
GLAPI PFNGLISSYNCPROC glad_glIsSync;
#define glIsSync glad_glIsSync
GLAPI PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC glad_glFramebufferTextureLayerEXT;
#define glFramebufferTextureLayerEXT glad_glFramebufferTextureLayerEXT
GLAPI PFNGLGETOBJECTPTRLABELPROC glad_glGetObjectPtrLabel;
#define glGetObjectPtrLabel glad_glGetObjectPtrLabel
GLAPI PFNGLMULTITEXCOORD1FARBPROC glad_glMultiTexCoord1fARB;
#define glMultiTexCoord1fARB glad_glMultiTexCoord1fARB
GLAPI PFNGLUNIFORMMATRIX2X3DVPROC glad_glUniformMatrix2x3dv;
#define glUniformMatrix2x3dv glad_glUniformMatrix2x3dv
GLAPI PFNGLVERTEXATTRIBL3DPROC glad_glVertexAttribL3d;
#define glVertexAttribL3d glad_glVertexAttribL3d
GLAPI PFNGLCOLOR4XOESPROC glad_glColor4xOES;
#define glColor4xOES glad_glColor4xOES
GLAPI PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glad_glGetVertexAttribArrayObjectivATI;
#define glGetVertexAttribArrayObjectivATI glad_glGetVertexAttribArrayObjectivATI
GLAPI PFNGLPROGRAMUNIFORM1UIPROC glad_glProgramUniform1ui;
#define glProgramUniform1ui glad_glProgramUniform1ui
GLAPI PFNGLSPRITEPARAMETERIVSGIXPROC glad_glSpriteParameterivSGIX;
#define glSpriteParameterivSGIX glad_glSpriteParameterivSGIX
GLAPI PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D;
#define glCopyTexImage2D glad_glCopyTexImage2D
GLAPI PFNGLMATERIALXOESPROC glad_glMaterialxOES;
#define glMaterialxOES glad_glMaterialxOES
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC glad_glProgramUniformMatrix2x4fvEXT;
#define glProgramUniformMatrix2x4fvEXT glad_glProgramUniformMatrix2x4fvEXT
GLAPI PFNGLTESTOBJECTAPPLEPROC glad_glTestObjectAPPLE;
#define glTestObjectAPPLE glad_glTestObjectAPPLE
GLAPI PFNGLRENDERBUFFERSTORAGEEXTPROC glad_glRenderbufferStorageEXT;
#define glRenderbufferStorageEXT glad_glRenderbufferStorageEXT
GLAPI PFNGLENDFRAGMENTSHADERATIPROC glad_glEndFragmentShaderATI;
#define glEndFragmentShaderATI glad_glEndFragmentShaderATI
GLAPI PFNGLPATHPARAMETERIVNVPROC glad_glPathParameterivNV;
#define glPathParameterivNV glad_glPathParameterivNV
GLAPI PFNGLUNIFORM4UIVPROC glad_glUniform4uiv;
#define glUniform4uiv glad_glUniform4uiv
GLAPI PFNGLFRAMEZOOMSGIXPROC glad_glFrameZoomSGIX;
#define glFrameZoomSGIX glad_glFrameZoomSGIX
GLAPI PFNGLSECONDARYCOLOR3FEXTPROC glad_glSecondaryColor3fEXT;
#define glSecondaryColor3fEXT glad_glSecondaryColor3fEXT
GLAPI PFNGLGETPROGRAMENVPARAMETERDVARBPROC glad_glGetProgramEnvParameterdvARB;
#define glGetProgramEnvParameterdvARB glad_glGetProgramEnvParameterdvARB
GLAPI PFNGLGETTEXBUMPPARAMETERIVATIPROC glad_glGetTexBumpParameterivATI;
#define glGetTexBumpParameterivATI glad_glGetTexBumpParameterivATI
GLAPI PFNGLSECONDARYCOLORFORMATNVPROC glad_glSecondaryColorFormatNV;
#define glSecondaryColorFormatNV glad_glSecondaryColorFormatNV
GLAPI PFNGLVERTEXATTRIB4UBVNVPROC glad_glVertexAttrib4ubvNV;
#define glVertexAttrib4ubvNV glad_glVertexAttrib4ubvNV
GLAPI PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC glad_glGetCombinerStageParameterfvNV;
#define glGetCombinerStageParameterfvNV glad_glGetCombinerStageParameterfvNV
GLAPI PFNGLVERTEXSTREAM1FATIPROC glad_glVertexStream1fATI;
#define glVertexStream1fATI glad_glVertexStream1fATI
GLAPI PFNGLDELETESYNCPROC glad_glDeleteSync;
#define glDeleteSync glad_glDeleteSync
GLAPI PFNGLMAXSHADERCOMPILERTHREADSARBPROC glad_glMaxShaderCompilerThreadsARB;
#define glMaxShaderCompilerThreadsARB glad_glMaxShaderCompilerThreadsARB
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC glad_glVertexArrayVertexAttribLOffsetEXT;
#define glVertexArrayVertexAttribLOffsetEXT glad_glVertexArrayVertexAttribLOffsetEXT
GLAPI PFNGLISIMAGEHANDLERESIDENTNVPROC glad_glIsImageHandleResidentNV;
#define glIsImageHandleResidentNV glad_glIsImageHandleResidentNV
GLAPI PFNGLCONVOLUTIONFILTER1DEXTPROC glad_glConvolutionFilter1DEXT;
#define glConvolutionFilter1DEXT glad_glConvolutionFilter1DEXT
GLAPI PFNGLISVERTEXARRAYAPPLEPROC glad_glIsVertexArrayAPPLE;
#define glIsVertexArrayAPPLE glad_glIsVertexArrayAPPLE
GLAPI PFNGLUSEPROGRAMPROC glad_glUseProgram;
#define glUseProgram glad_glUseProgram
GLAPI PFNGLMULTITEXCOORD4FVARBPROC glad_glMultiTexCoord4fvARB;
#define glMultiTexCoord4fvARB glad_glMultiTexCoord4fvARB
GLAPI PFNGLVIDEOCAPTURENVPROC glad_glVideoCaptureNV;
#define glVideoCaptureNV glad_glVideoCaptureNV
GLAPI PFNGLMULTITEXIMAGE1DEXTPROC glad_glMultiTexImage1DEXT;
#define glMultiTexImage1DEXT glad_glMultiTexImage1DEXT
GLAPI PFNGLTEXTURELIGHTEXTPROC glad_glTextureLightEXT;
#define glTextureLightEXT glad_glTextureLightEXT
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC glad_glNamedFramebufferTextureEXT;
#define glNamedFramebufferTextureEXT glad_glNamedFramebufferTextureEXT
GLAPI PFNGLDELETESHADERPROC glad_glDeleteShader;
#define glDeleteShader glad_glDeleteShader
GLAPI PFNGLTEXCOORD4FVERTEX4FSUNPROC glad_glTexCoord4fVertex4fSUN;
#define glTexCoord4fVertex4fSUN glad_glTexCoord4fVertex4fSUN
GLAPI PFNGLTEXTUREPARAMETERIUIVPROC glad_glTextureParameterIuiv;
#define glTextureParameterIuiv glad_glTextureParameterIuiv
GLAPI PFNGLFRAGMENTLIGHTFVSGIXPROC glad_glFragmentLightfvSGIX;
#define glFragmentLightfvSGIX glad_glFragmentLightfvSGIX
GLAPI PFNGLWINDOWPOS3SARBPROC glad_glWindowPos3sARB;
#define glWindowPos3sARB glad_glWindowPos3sARB
GLAPI PFNGLCREATESHADEROBJECTARBPROC glad_glCreateShaderObjectARB;
#define glCreateShaderObjectARB glad_glCreateShaderObjectARB
GLAPI PFNGLGETPROGRAMIVARBPROC glad_glGetProgramivARB;
#define glGetProgramivARB glad_glGetProgramivARB
GLAPI PFNGLGETSTAGEINDEXNVPROC glad_glGetStageIndexNV;
#define glGetStageIndexNV glad_glGetStageIndexNV
GLAPI PFNGLPATHGLYPHRANGENVPROC glad_glPathGlyphRangeNV;
#define glPathGlyphRangeNV glad_glPathGlyphRangeNV
GLAPI PFNGLVERTEXATTRIBI4USVPROC glad_glVertexAttribI4usv;
#define glVertexAttribI4usv glad_glVertexAttribI4usv
GLAPI PFNGLTEXPARAMETERFPROC glad_glTexParameterf;
#define glTexParameterf glad_glTexParameterf
GLAPI PFNGLTEXPARAMETERIPROC glad_glTexParameteri;
#define glTexParameteri glad_glTexParameteri
GLAPI PFNGLTEXTUREBUFFEREXTPROC glad_glTextureBufferEXT;
#define glTextureBufferEXT glad_glTextureBufferEXT
GLAPI PFNGLGETMULTITEXIMAGEEXTPROC glad_glGetMultiTexImageEXT;
#define glGetMultiTexImageEXT glad_glGetMultiTexImageEXT
GLAPI PFNGLBUFFERPARAMETERIAPPLEPROC glad_glBufferParameteriAPPLE;
#define glBufferParameteriAPPLE glad_glBufferParameteriAPPLE
GLAPI PFNGLLINKPROGRAMPROC glad_glLinkProgram;
#define glLinkProgram glad_glLinkProgram
GLAPI PFNGLBINDIMAGETEXTURESPROC glad_glBindImageTextures;
#define glBindImageTextures glad_glBindImageTextures
GLAPI PFNGLALPHAFRAGMENTOP3ATIPROC glad_glAlphaFragmentOp3ATI;
#define glAlphaFragmentOp3ATI glad_glAlphaFragmentOp3ATI
GLAPI PFNGLGETPATHPARAMETERFVNVPROC glad_glGetPathParameterfvNV;
#define glGetPathParameterfvNV glad_glGetPathParameterfvNV
GLAPI PFNGLENDQUERYPROC glad_glEndQuery;
#define glEndQuery glad_glEndQuery
GLAPI PFNGLVERTEXATTRIBI4IVEXTPROC glad_glVertexAttribI4ivEXT;
#define glVertexAttribI4ivEXT glad_glVertexAttribI4ivEXT
GLAPI PFNGLPRIORITIZETEXTURESXOESPROC glad_glPrioritizeTexturesxOES;
#define glPrioritizeTexturesxOES glad_glPrioritizeTexturesxOES
GLAPI PFNGLVERTEXATTRIBI2UIPROC glad_glVertexAttribI2ui;
#define glVertexAttribI2ui glad_glVertexAttribI2ui
GLAPI PFNGLWINDOWPOS3SMESAPROC glad_glWindowPos3sMESA;
#define glWindowPos3sMESA glad_glWindowPos3sMESA
GLAPI PFNGLVERTEXSTREAM1FVATIPROC glad_glVertexStream1fvATI;
#define glVertexStream1fvATI glad_glVertexStream1fvATI
GLAPI PFNGLBEGINCONDITIONALRENDERPROC glad_glBeginConditionalRender;
#define glBeginConditionalRender glad_glBeginConditionalRender
GLAPI PFNGLSCALEXOESPROC glad_glScalexOES;
#define glScalexOES glad_glScalexOES
GLAPI PFNGLSAMPLERPARAMETERIPROC glad_glSamplerParameteri;
#define glSamplerParameteri glad_glSamplerParameteri
GLAPI PFNGLSAMPLERPARAMETERFPROC glad_glSamplerParameterf;
#define glSamplerParameterf glad_glSamplerParameterf
GLAPI PFNGLBEGINVIDEOCAPTURENVPROC glad_glBeginVideoCaptureNV;
#define glBeginVideoCaptureNV glad_glBeginVideoCaptureNV
GLAPI PFNGLUNIFORM1FPROC glad_glUniform1f;
#define glUniform1f glad_glUniform1f
GLAPI PFNGLUNIFORM1DPROC glad_glUniform1d;
#define glUniform1d glad_glUniform1d
GLAPI PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage;
#define glGetCompressedTexImage glad_glGetCompressedTexImage
GLAPI PFNGLMINSAMPLESHADINGARBPROC glad_glMinSampleShadingARB;
#define glMinSampleShadingARB glad_glMinSampleShadingARB
GLAPI PFNGLUNIFORM1IPROC glad_glUniform1i;
#define glUniform1i glad_glUniform1i
GLAPI PFNGLDELETEFENCESAPPLEPROC glad_glDeleteFencesAPPLE;
#define glDeleteFencesAPPLE glad_glDeleteFencesAPPLE
GLAPI PFNGLVERTEXSTREAM3IVATIPROC glad_glVertexStream3ivATI;
#define glVertexStream3ivATI glad_glVertexStream3ivATI
GLAPI PFNGLENDQUERYARBPROC glad_glEndQueryARB;
#define glEndQueryARB glad_glEndQueryARB
GLAPI PFNGLVERTEXATTRIB4UIVARBPROC glad_glVertexAttrib4uivARB;
#define glVertexAttrib4uivARB glad_glVertexAttrib4uivARB
GLAPI PFNGLQUERYCOUNTERPROC glad_glQueryCounter;
#define glQueryCounter glad_glQueryCounter
GLAPI PFNGLTEXCOORD4BVOESPROC glad_glTexCoord4bvOES;
#define glTexCoord4bvOES glad_glTexCoord4bvOES
GLAPI PFNGLVERTEXATTRIB3FARBPROC glad_glVertexAttrib3fARB;
#define glVertexAttrib3fARB glad_glVertexAttrib3fARB
GLAPI PFNGLCOLOR4UBVERTEX2FVSUNPROC glad_glColor4ubVertex2fvSUN;
#define glColor4ubVertex2fvSUN glad_glColor4ubVertex2fvSUN
GLAPI PFNGLVERTEXATTRIBI4SVPROC glad_glVertexAttribI4sv;
#define glVertexAttribI4sv glad_glVertexAttribI4sv
GLAPI PFNGLVERTEXATTRIBLFORMATNVPROC glad_glVertexAttribLFormatNV;
#define glVertexAttribLFormatNV glad_glVertexAttribLFormatNV
GLAPI PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glad_glGetCompressedTexImageARB;
#define glGetCompressedTexImageARB glad_glGetCompressedTexImageARB
GLAPI PFNGLUNMAPOBJECTBUFFERATIPROC glad_glUnmapObjectBufferATI;
#define glUnmapObjectBufferATI glad_glUnmapObjectBufferATI
GLAPI PFNGLPROGRAMUNIFORM1IEXTPROC glad_glProgramUniform1iEXT;
#define glProgramUniform1iEXT glad_glProgramUniform1iEXT
GLAPI PFNGLDELETEQUERIESARBPROC glad_glDeleteQueriesARB;
#define glDeleteQueriesARB glad_glDeleteQueriesARB
GLAPI PFNGLWINDOWPOS3SVARBPROC glad_glWindowPos3svARB;
#define glWindowPos3svARB glad_glWindowPos3svARB
GLAPI PFNGLISTRANSFORMFEEDBACKPROC glad_glIsTransformFeedback;
#define glIsTransformFeedback glad_glIsTransformFeedback
GLAPI PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glad_glProgramLocalParameter4dvARB;
#define glProgramLocalParameter4dvARB glad_glProgramLocalParameter4dvARB
GLAPI PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv;
#define glUniformMatrix3fv glad_glUniformMatrix3fv
GLAPI PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC glad_glMakeImageHandleNonResidentARB;
#define glMakeImageHandleNonResidentARB glad_glMakeImageHandleNonResidentARB
GLAPI PFNGLSTENCILFUNCPROC glad_glStencilFunc;
#define glStencilFunc glad_glStencilFunc
GLAPI PFNGLGETVERTEXATTRIBDVNVPROC glad_glGetVertexAttribdvNV;
#define glGetVertexAttribdvNV glad_glGetVertexAttribdvNV
GLAPI PFNGLGETQUERYBUFFEROBJECTIVPROC glad_glGetQueryBufferObjectiv;
#define glGetQueryBufferObjectiv glad_glGetQueryBufferObjectiv
GLAPI PFNGLGETCOLORTABLEEXTPROC glad_glGetColorTableEXT;
#define glGetColorTableEXT glad_glGetColorTableEXT
GLAPI PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog;
#define glGetShaderInfoLog glad_glGetShaderInfoLog
GLAPI PFNGLGETOCCLUSIONQUERYUIVNVPROC glad_glGetOcclusionQueryuivNV;
#define glGetOcclusionQueryuivNV glad_glGetOcclusionQueryuivNV
GLAPI PFNGLVDPAUINITNVPROC glad_glVDPAUInitNV;
#define glVDPAUInitNV glad_glVDPAUInitNV
GLAPI PFNGLVERTEXATTRIB1HVNVPROC glad_glVertexAttrib1hvNV;
#define glVertexAttrib1hvNV glad_glVertexAttrib1hvNV
GLAPI PFNGLGETINTEGERUI64I_VNVPROC glad_glGetIntegerui64i_vNV;
#define glGetIntegerui64i_vNV glad_glGetIntegerui64i_vNV
GLAPI PFNGLUNIFORMHANDLEUI64NVPROC glad_glUniformHandleui64NV;
#define glUniformHandleui64NV glad_glUniformHandleui64NV
GLAPI PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate;
#define glBlendEquationSeparate glad_glBlendEquationSeparate
GLAPI PFNGLVERTEX3HNVPROC glad_glVertex3hNV;
#define glVertex3hNV glad_glVertex3hNV
GLAPI PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC glad_glCompressedTextureImage1DEXT;
#define glCompressedTextureImage1DEXT glad_glCompressedTextureImage1DEXT
GLAPI PFNGLMATERIALXVOESPROC glad_glMaterialxvOES;
#define glMaterialxvOES glad_glMaterialxvOES
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC glad_glNamedProgramLocalParameter4fEXT;
#define glNamedProgramLocalParameter4fEXT glad_glNamedProgramLocalParameter4fEXT
GLAPI PFNGLPROGRAMUNIFORM1UIVEXTPROC glad_glProgramUniform1uivEXT;
#define glProgramUniform1uivEXT glad_glProgramUniform1uivEXT
GLAPI PFNGLTEXTUREIMAGE3DEXTPROC glad_glTextureImage3DEXT;
#define glTextureImage3DEXT glad_glTextureImage3DEXT
GLAPI PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers;
#define glDeleteBuffers glad_glDeleteBuffers
GLAPI PFNGLGETBUFFERSUBDATAPROC glad_glGetBufferSubData;
#define glGetBufferSubData glad_glGetBufferSubData
GLAPI PFNGLALPHAFUNCXOESPROC glad_glAlphaFuncxOES;
#define glAlphaFuncxOES glad_glAlphaFuncxOES
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC glad_glMultiDrawArraysIndirectAMD;
#define glMultiDrawArraysIndirectAMD glad_glMultiDrawArraysIndirectAMD
GLAPI PFNGLNORMALSTREAM3IVATIPROC glad_glNormalStream3ivATI;
#define glNormalStream3ivATI glad_glNormalStream3ivATI
GLAPI PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC glad_glTextureImage3DMultisampleNV;
#define glTextureImage3DMultisampleNV glad_glTextureImage3DMultisampleNV
GLAPI PFNGLREPLACEMENTCODEUSVSUNPROC glad_glReplacementCodeusvSUN;
#define glReplacementCodeusvSUN glad_glReplacementCodeusvSUN
GLAPI PFNGLGETSTRINGIPROC glad_glGetStringi;
#define glGetStringi glad_glGetStringi
GLAPI PFNGLMAPCONTROLPOINTSNVPROC glad_glMapControlPointsNV;
#define glMapControlPointsNV glad_glMapControlPointsNV
GLAPI PFNGLDEFORMATIONMAP3DSGIXPROC glad_glDeformationMap3dSGIX;
#define glDeformationMap3dSGIX glad_glDeformationMap3dSGIX
GLAPI PFNGLUNIFORMMATRIX2FVARBPROC glad_glUniformMatrix2fvARB;
#define glUniformMatrix2fvARB glad_glUniformMatrix2fvARB
GLAPI PFNGLUNIFORM2FVPROC glad_glUniform2fv;
#define glUniform2fv glad_glUniform2fv
GLAPI PFNGLDISPATCHCOMPUTEINDIRECTPROC glad_glDispatchComputeIndirect;
#define glDispatchComputeIndirect glad_glDispatchComputeIndirect
GLAPI PFNGLMULTITEXCOORD4BOESPROC glad_glMultiTexCoord4bOES;
#define glMultiTexCoord4bOES glad_glMultiTexCoord4bOES
GLAPI PFNGLGETUNIFORMDVPROC glad_glGetUniformdv;
#define glGetUniformdv glad_glGetUniformdv
GLAPI PFNGLCULLPARAMETERDVEXTPROC glad_glCullParameterdvEXT;
#define glCullParameterdvEXT glad_glCullParameterdvEXT
GLAPI PFNGLBEGINPERFMONITORAMDPROC glad_glBeginPerfMonitorAMD;
#define glBeginPerfMonitorAMD glad_glBeginPerfMonitorAMD
GLAPI PFNGLGETTEXPARAMETERXVOESPROC glad_glGetTexParameterxvOES;
#define glGetTexParameterxvOES glad_glGetTexParameterxvOES
GLAPI PFNGLPROGRAMUNIFORM3FVEXTPROC glad_glProgramUniform3fvEXT;
#define glProgramUniform3fvEXT glad_glProgramUniform3fvEXT
GLAPI PFNGLTEXCOORD2BOESPROC glad_glTexCoord2bOES;
#define glTexCoord2bOES glad_glTexCoord2bOES
GLAPI PFNGLBINDMATERIALPARAMETEREXTPROC glad_glBindMaterialParameterEXT;
#define glBindMaterialParameterEXT glad_glBindMaterialParameterEXT
GLAPI PFNGLGLOBALALPHAFACTORUBSUNPROC glad_glGlobalAlphaFactorubSUN;
#define glGlobalAlphaFactorubSUN glad_glGlobalAlphaFactorubSUN
GLAPI PFNGLVERTEXATTRIBL1UI64NVPROC glad_glVertexAttribL1ui64NV;
#define glVertexAttribL1ui64NV glad_glVertexAttribL1ui64NV
GLAPI PFNGLPOINTPARAMETERFSGISPROC glad_glPointParameterfSGIS;
#define glPointParameterfSGIS glad_glPointParameterfSGIS
GLAPI PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC glad_glGetImageTransformParameterivHP;
#define glGetImageTransformParameterivHP glad_glGetImageTransformParameterivHP
GLAPI PFNGLCOLORSUBTABLEEXTPROC glad_glColorSubTableEXT;
#define glColorSubTableEXT glad_glColorSubTableEXT
GLAPI PFNGLVERTEXATTRIBS1FVNVPROC glad_glVertexAttribs1fvNV;
#define glVertexAttribs1fvNV glad_glVertexAttribs1fvNV
GLAPI PFNGLBLENDFUNCIARBPROC glad_glBlendFunciARB;
#define glBlendFunciARB glad_glBlendFunciARB
GLAPI PFNGLPROGRAMENVPARAMETERSI4IVNVPROC glad_glProgramEnvParametersI4ivNV;
#define glProgramEnvParametersI4ivNV glad_glProgramEnvParametersI4ivNV
GLAPI PFNGLCOPYIMAGESUBDATAPROC glad_glCopyImageSubData;
#define glCopyImageSubData glad_glCopyImageSubData
GLAPI PFNGLGETUNIFORMSUBROUTINEUIVPROC glad_glGetUniformSubroutineuiv;
#define glGetUniformSubroutineuiv glad_glGetUniformSubroutineuiv
GLAPI PFNGLDEBUGMESSAGEINSERTPROC glad_glDebugMessageInsert;
#define glDebugMessageInsert glad_glDebugMessageInsert
GLAPI PFNGLISVARIANTENABLEDEXTPROC glad_glIsVariantEnabledEXT;
#define glIsVariantEnabledEXT glad_glIsVariantEnabledEXT
GLAPI PFNGLPASSTHROUGHXOESPROC glad_glPassThroughxOES;
#define glPassThroughxOES glad_glPassThroughxOES
GLAPI PFNGLMULTITEXGENIVEXTPROC glad_glMultiTexGenivEXT;
#define glMultiTexGenivEXT glad_glMultiTexGenivEXT
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus;
#define glCheckFramebufferStatus glad_glCheckFramebufferStatus
GLAPI PFNGLDRAWELEMENTARRAYAPPLEPROC glad_glDrawElementArrayAPPLE;
#define glDrawElementArrayAPPLE glad_glDrawElementArrayAPPLE
GLAPI PFNGLBINDIMAGETEXTUREPROC glad_glBindImageTexture;
#define glBindImageTexture glad_glBindImageTexture
GLAPI PFNGLBINDBUFFERBASEPROC glad_glBindBufferBase;
#define glBindBufferBase glad_glBindBufferBase
GLAPI PFNGLSYNCTEXTUREINTELPROC glad_glSyncTextureINTEL;
#define glSyncTextureINTEL glad_glSyncTextureINTEL
GLAPI PFNGLGETARRAYOBJECTIVATIPROC glad_glGetArrayObjectivATI;
#define glGetArrayObjectivATI glad_glGetArrayObjectivATI
GLAPI PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays;
#define glMultiDrawArrays glad_glMultiDrawArrays
GLAPI PFNGLVERTEXATTRIBI4UBVPROC glad_glVertexAttribI4ubv;
#define glVertexAttribI4ubv glad_glVertexAttribI4ubv
GLAPI PFNGLDELETENAMEDSTRINGARBPROC glad_glDeleteNamedStringARB;
#define glDeleteNamedStringARB glad_glDeleteNamedStringARB
GLAPI PFNGLVERTEXATTRIBL1DPROC glad_glVertexAttribL1d;
#define glVertexAttribL1d glad_glVertexAttribL1d
GLAPI PFNGLVERTEXATTRIBI3UIVPROC glad_glVertexAttribI3uiv;
#define glVertexAttribI3uiv glad_glVertexAttribI3uiv
GLAPI PFNGLBUFFERDATAARBPROC glad_glBufferDataARB;
#define glBufferDataARB glad_glBufferDataARB
GLAPI PFNGLVERTEXATTRIBIFORMATPROC glad_glVertexAttribIFormat;
#define glVertexAttribIFormat glad_glVertexAttribIFormat
GLAPI PFNGLUNIFORM2UIVEXTPROC glad_glUniform2uivEXT;
#define glUniform2uivEXT glad_glUniform2uivEXT
GLAPI PFNGLBINDBUFFERPROC glad_glBindBuffer;
#define glBindBuffer glad_glBindBuffer
GLAPI PFNGLGETPATHDASHARRAYNVPROC glad_glGetPathDashArrayNV;
#define glGetPathDashArrayNV glad_glGetPathDashArrayNV
GLAPI PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv;
#define glUniformMatrix2x4fv glad_glUniformMatrix2x4fv
GLAPI PFNGLGETMULTITEXPARAMETERFVEXTPROC glad_glGetMultiTexParameterfvEXT;
#define glGetMultiTexParameterfvEXT glad_glGetMultiTexParameterfvEXT
GLAPI PFNGLDEPTHRANGEINDEXEDPROC glad_glDepthRangeIndexed;
#define glDepthRangeIndexed glad_glDepthRangeIndexed
GLAPI PFNGLCOLORMASKINDEXEDEXTPROC glad_glColorMaskIndexedEXT;
#define glColorMaskIndexedEXT glad_glColorMaskIndexedEXT
GLAPI PFNGLMATRIXSCALEFEXTPROC glad_glMatrixScalefEXT;
#define glMatrixScalefEXT glad_glMatrixScalefEXT
GLAPI PFNGLGETERRORPROC glad_glGetError;
#define glGetError glad_glGetError
GLAPI PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glad_glBindTextureUnitParameterEXT;
#define glBindTextureUnitParameterEXT glad_glBindTextureUnitParameterEXT
GLAPI PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC glad_glReplacementCodeuiNormal3fVertex3fvSUN;
#define glReplacementCodeuiNormal3fVertex3fvSUN glad_glReplacementCodeuiNormal3fVertex3fvSUN
GLAPI PFNGLDELETEPERFQUERYINTELPROC glad_glDeletePerfQueryINTEL;
#define glDeletePerfQueryINTEL glad_glDeletePerfQueryINTEL
GLAPI PFNGLGETACTIVEUNIFORMARBPROC glad_glGetActiveUniformARB;
#define glGetActiveUniformARB glad_glGetActiveUniformARB
GLAPI PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv;
#define glGetTexLevelParameterfv glad_glGetTexLevelParameterfv
GLAPI PFNGLLISTPARAMETERFSGIXPROC glad_glListParameterfSGIX;
#define glListParameterfSGIX glad_glListParameterfSGIX
GLAPI PFNGLNAMEDBUFFERDATAPROC glad_glNamedBufferData;
#define glNamedBufferData glad_glNamedBufferData
GLAPI PFNGLVERTEXSTREAM3SATIPROC glad_glVertexStream3sATI;
#define glVertexStream3sATI glad_glVertexStream3sATI
GLAPI PFNGLVERTEXATTRIB3FVARBPROC glad_glVertexAttrib3fvARB;
#define glVertexAttrib3fvARB glad_glVertexAttrib3fvARB
GLAPI PFNGLUNIFORM3IARBPROC glad_glUniform3iARB;
#define glUniform3iARB glad_glUniform3iARB
GLAPI PFNGLCREATEPROGRAMOBJECTARBPROC glad_glCreateProgramObjectARB;
#define glCreateProgramObjectARB glad_glCreateProgramObjectARB
GLAPI PFNGLMULTITEXCOORD1DVARBPROC glad_glMultiTexCoord1dvARB;
#define glMultiTexCoord1dvARB glad_glMultiTexCoord1dvARB
GLAPI PFNGLPROGRAMUNIFORM3DVEXTPROC glad_glProgramUniform3dvEXT;
#define glProgramUniform3dvEXT glad_glProgramUniform3dvEXT
GLAPI PFNGLPROGRAMUNIFORM1I64NVPROC glad_glProgramUniform1i64NV;
#define glProgramUniform1i64NV glad_glProgramUniform1i64NV
GLAPI PFNGLMULTITEXCOORD1FVARBPROC glad_glMultiTexCoord1fvARB;
#define glMultiTexCoord1fvARB glad_glMultiTexCoord1fvARB
GLAPI PFNGLPOINTPARAMETERFEXTPROC glad_glPointParameterfEXT;
#define glPointParameterfEXT glad_glPointParameterfEXT
GLAPI PFNGLGETVIDEOCAPTURESTREAMFVNVPROC glad_glGetVideoCaptureStreamfvNV;
#define glGetVideoCaptureStreamfvNV glad_glGetVideoCaptureStreamfvNV
GLAPI PFNGLVERTEXATTRIB2FARBPROC glad_glVertexAttrib2fARB;
#define glVertexAttrib2fARB glad_glVertexAttrib2fARB
GLAPI PFNGLVERTEXSTREAM1DVATIPROC glad_glVertexStream1dvATI;
#define glVertexStream1dvATI glad_glVertexStream1dvATI
GLAPI PFNGLISFRAMEBUFFEREXTPROC glad_glIsFramebufferEXT;
#define glIsFramebufferEXT glad_glIsFramebufferEXT
GLAPI PFNGLTEXBUFFERRANGEPROC glad_glTexBufferRange;
#define glTexBufferRange glad_glTexBufferRange
GLAPI PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC glad_glGetPixelTexGenParameterivSGIS;
#define glGetPixelTexGenParameterivSGIS glad_glGetPixelTexGenParameterivSGIS
GLAPI PFNGLVERTEXATTRIBI3UIPROC glad_glVertexAttribI3ui;
#define glVertexAttribI3ui glad_glVertexAttribI3ui
GLAPI PFNGLSAMPLEMASKSGISPROC glad_glSampleMaskSGIS;
#define glSampleMaskSGIS glad_glSampleMaskSGIS
GLAPI PFNGLGLOBALALPHAFACTORFSUNPROC glad_glGlobalAlphaFactorfSUN;
#define glGlobalAlphaFactorfSUN glad_glGlobalAlphaFactorfSUN
GLAPI PFNGLGETPERFCOUNTERINFOINTELPROC glad_glGetPerfCounterInfoINTEL;
#define glGetPerfCounterInfoINTEL glad_glGetPerfCounterInfoINTEL
GLAPI PFNGLPROGRAMLOCALPARAMETERI4UINVPROC glad_glProgramLocalParameterI4uiNV;
#define glProgramLocalParameterI4uiNV glad_glProgramLocalParameterI4uiNV
GLAPI PFNGLPIXELZOOMXOESPROC glad_glPixelZoomxOES;
#define glPixelZoomxOES glad_glPixelZoomxOES
GLAPI PFNGLRASTERPOS2XVOESPROC glad_glRasterPos2xvOES;
#define glRasterPos2xvOES glad_glRasterPos2xvOES
GLAPI PFNGLGETPROGRAMPARAMETERDVNVPROC glad_glGetProgramParameterdvNV;
#define glGetProgramParameterdvNV glad_glGetProgramParameterdvNV
GLAPI PFNGLVERTEXSTREAM2DVATIPROC glad_glVertexStream2dvATI;
#define glVertexStream2dvATI glad_glVertexStream2dvATI
GLAPI PFNGLVERTEX3XOESPROC glad_glVertex3xOES;
#define glVertex3xOES glad_glVertex3xOES
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC glad_glProgramUniformMatrix3x2dvEXT;
#define glProgramUniformMatrix3x2dvEXT glad_glProgramUniformMatrix3x2dvEXT
GLAPI PFNGLGETDOUBLEINDEXEDVEXTPROC glad_glGetDoubleIndexedvEXT;
#define glGetDoubleIndexedvEXT glad_glGetDoubleIndexedvEXT
GLAPI PFNGLWINDOWPOS2FMESAPROC glad_glWindowPos2fMESA;
#define glWindowPos2fMESA glad_glWindowPos2fMESA
GLAPI PFNGLGETVARYINGLOCATIONNVPROC glad_glGetVaryingLocationNV;
#define glGetVaryingLocationNV glad_glGetVaryingLocationNV
GLAPI PFNGLBINDFRAMEBUFFEREXTPROC glad_glBindFramebufferEXT;
#define glBindFramebufferEXT glad_glBindFramebufferEXT
GLAPI PFNGLCREATESHADERPROC glad_glCreateShader;
#define glCreateShader glad_glCreateShader
GLAPI PFNGLGENPATHSNVPROC glad_glGenPathsNV;
#define glGenPathsNV glad_glGenPathsNV
GLAPI PFNGLVERTEXATTRIB4UBVARBPROC glad_glVertexAttrib4ubvARB;
#define glVertexAttrib4ubvARB glad_glVertexAttrib4ubvARB
GLAPI PFNGLTEXSUBIMAGE3DEXTPROC glad_glTexSubImage3DEXT;
#define glTexSubImage3DEXT glad_glTexSubImage3DEXT
GLAPI PFNGLVERTEXSTREAM2DATIPROC glad_glVertexStream2dATI;
#define glVertexStream2dATI glad_glVertexStream2dATI
GLAPI PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D;
#define glCompressedTexImage1D glad_glCompressedTexImage1D
GLAPI PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate;
#define glBlendFuncSeparate glad_glBlendFuncSeparate
GLAPI PFNGLPOINTPARAMETERFARBPROC glad_glPointParameterfARB;
#define glPointParameterfARB glad_glPointParameterfARB
GLAPI PFNGLWINDOWPOS2DMESAPROC glad_glWindowPos2dMESA;
#define glWindowPos2dMESA glad_glWindowPos2dMESA
GLAPI PFNGLBINDTEXTUREUNITPROC glad_glBindTextureUnit;
#define glBindTextureUnit glad_glBindTextureUnit
GLAPI PFNGLPROGRAMENVPARAMETERI4UINVPROC glad_glProgramEnvParameterI4uiNV;
#define glProgramEnvParameterI4uiNV glad_glProgramEnvParameterI4uiNV
GLAPI PFNGLGETPROGRAMPIPELINEINFOLOGPROC glad_glGetProgramPipelineInfoLog;
#define glGetProgramPipelineInfoLog glad_glGetProgramPipelineInfoLog
GLAPI PFNGLUNIFORM3IPROC glad_glUniform3i;
#define glUniform3i glad_glUniform3i
GLAPI PFNGLVERTEXATTRIB2HVNVPROC glad_glVertexAttrib2hvNV;
#define glVertexAttrib2hvNV glad_glVertexAttrib2hvNV
GLAPI PFNGLUNIFORM3DPROC glad_glUniform3d;
#define glUniform3d glad_glUniform3d
GLAPI PFNGLUNIFORM3FPROC glad_glUniform3f;
#define glUniform3f glad_glUniform3f
GLAPI PFNGLPROGRAMUNIFORM1UI64VARBPROC glad_glProgramUniform1ui64vARB;
#define glProgramUniform1ui64vARB glad_glProgramUniform1ui64vARB
GLAPI PFNGLIMAGETRANSFORMPARAMETERIHPPROC glad_glImageTransformParameteriHP;
#define glImageTransformParameteriHP glad_glImageTransformParameteriHP
GLAPI PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glad_glSetFragmentShaderConstantATI;
#define glSetFragmentShaderConstantATI glad_glSetFragmentShaderConstantATI
GLAPI PFNGLSTATECAPTURENVPROC glad_glStateCaptureNV;
#define glStateCaptureNV glad_glStateCaptureNV
GLAPI PFNGLGETFRAGDATAINDEXPROC glad_glGetFragDataIndex;
#define glGetFragDataIndex glad_glGetFragDataIndex
GLAPI PFNGLWEIGHTPATHSNVPROC glad_glWeightPathsNV;
#define glWeightPathsNV glad_glWeightPathsNV
GLAPI PFNGLALPHAFRAGMENTOP2ATIPROC glad_glAlphaFragmentOp2ATI;
#define glAlphaFragmentOp2ATI glad_glAlphaFragmentOp2ATI
GLAPI PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers;
#define glDeleteFramebuffers glad_glDeleteFramebuffers
GLAPI PFNGLUSEPROGRAMSTAGESPROC glad_glUseProgramStages;
#define glUseProgramStages glad_glUseProgramStages
GLAPI PFNGLBLENDFUNCSEPARATEIARBPROC glad_glBlendFuncSeparateiARB;
#define glBlendFuncSeparateiARB glad_glBlendFuncSeparateiARB
GLAPI PFNGLVERTEXATTRIB4NUBPROC glad_glVertexAttrib4Nub;
#define glVertexAttrib4Nub glad_glVertexAttrib4Nub
GLAPI PFNGLDELETEPERFMONITORSAMDPROC glad_glDeletePerfMonitorsAMD;
#define glDeletePerfMonitorsAMD glad_glDeletePerfMonitorsAMD
GLAPI PFNGLDRAWCOMMANDSNVPROC glad_glDrawCommandsNV;
#define glDrawCommandsNV glad_glDrawCommandsNV
GLAPI PFNGLUNIFORM3IVARBPROC glad_glUniform3ivARB;
#define glUniform3ivARB glad_glUniform3ivARB
GLAPI PFNGLMATRIXMULTTRANSPOSEDEXTPROC glad_glMatrixMultTransposedEXT;
#define glMatrixMultTransposedEXT glad_glMatrixMultTransposedEXT
GLAPI PFNGLGETQUERYOBJECTI64VPROC glad_glGetQueryObjecti64v;
#define glGetQueryObjecti64v glad_glGetQueryObjecti64v
GLAPI PFNGLMATRIXMULT3X3FNVPROC glad_glMatrixMult3x3fNV;
#define glMatrixMult3x3fNV glad_glMatrixMult3x3fNV
GLAPI PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glad_glGetFinalCombinerInputParameterivNV;
#define glGetFinalCombinerInputParameterivNV glad_glGetFinalCombinerInputParameterivNV
GLAPI PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer;
#define glIsRenderbuffer glad_glIsRenderbuffer
GLAPI PFNGLTEXCOORDFORMATNVPROC glad_glTexCoordFormatNV;
#define glTexCoordFormatNV glad_glTexCoordFormatNV
GLAPI PFNGLBLITNAMEDFRAMEBUFFERPROC glad_glBlitNamedFramebuffer;
#define glBlitNamedFramebuffer glad_glBlitNamedFramebuffer
GLAPI PFNGLVERTEXARRAYATTRIBLFORMATPROC glad_glVertexArrayAttribLFormat;
#define glVertexArrayAttribLFormat glad_glVertexArrayAttribLFormat
GLAPI PFNGLMULTITEXGENFEXTPROC glad_glMultiTexGenfEXT;
#define glMultiTexGenfEXT glad_glMultiTexGenfEXT
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC glad_glVertexArrayVertexAttribFormatEXT;
#define glVertexArrayVertexAttribFormatEXT glad_glVertexArrayVertexAttribFormatEXT
GLAPI PFNGLDELETEVERTEXSHADEREXTPROC glad_glDeleteVertexShaderEXT;
#define glDeleteVertexShaderEXT glad_glDeleteVertexShaderEXT
GLAPI PFNGLTEXIMAGE3DEXTPROC glad_glTexImage3DEXT;
#define glTexImage3DEXT glad_glTexImage3DEXT
GLAPI PFNGLPATHCOMMANDSNVPROC glad_glPathCommandsNV;
#define glPathCommandsNV glad_glPathCommandsNV
GLAPI PFNGLGETPROGRAMINTERFACEIVPROC glad_glGetProgramInterfaceiv;
#define glGetProgramInterfaceiv glad_glGetProgramInterfaceiv
GLAPI PFNGLNAMEDPROGRAMSTRINGEXTPROC glad_glNamedProgramStringEXT;
#define glNamedProgramStringEXT glad_glNamedProgramStringEXT
GLAPI PFNGLGETTEXTURESUBIMAGEPROC glad_glGetTextureSubImage;
#define glGetTextureSubImage glad_glGetTextureSubImage
GLAPI PFNGLNORMALSTREAM3IATIPROC glad_glNormalStream3iATI;
#define glNormalStream3iATI glad_glNormalStream3iATI
GLAPI PFNGLUNIFORMUI64NVPROC glad_glUniformui64NV;
#define glUniformui64NV glad_glUniformui64NV
GLAPI PFNGLSECONDARYCOLOR3UBVEXTPROC glad_glSecondaryColor3ubvEXT;
#define glSecondaryColor3ubvEXT glad_glSecondaryColor3ubvEXT
GLAPI PFNGLPROGRAMPARAMETERS4FVNVPROC glad_glProgramParameters4fvNV;
#define glProgramParameters4fvNV glad_glProgramParameters4fvNV
GLAPI PFNGLPATCHPARAMETERIPROC glad_glPatchParameteri;
#define glPatchParameteri glad_glPatchParameteri
GLAPI PFNGLGETNAMEDBUFFERSUBDATAEXTPROC glad_glGetNamedBufferSubDataEXT;
#define glGetNamedBufferSubDataEXT glad_glGetNamedBufferSubDataEXT
GLAPI PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC glad_glVertexArrayVertexBindingDivisorEXT;
#define glVertexArrayVertexBindingDivisorEXT glad_glVertexArrayVertexBindingDivisorEXT
GLAPI PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glad_glGetProgramLocalParameterfvARB;
#define glGetProgramLocalParameterfvARB glad_glGetProgramLocalParameterfvARB
GLAPI PFNGLTEXBUMPPARAMETERIVATIPROC glad_glTexBumpParameterivATI;
#define glTexBumpParameterivATI glad_glTexBumpParameterivATI
GLAPI PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetNamedFramebufferAttachmentParameteriv;
#define glGetNamedFramebufferAttachmentParameteriv glad_glGetNamedFramebufferAttachmentParameteriv
GLAPI PFNGLGENVERTEXARRAYSAPPLEPROC glad_glGenVertexArraysAPPLE;
#define glGenVertexArraysAPPLE glad_glGenVertexArraysAPPLE
GLAPI PFNGLFRAMEBUFFERTEXTUREFACEARBPROC glad_glFramebufferTextureFaceARB;
#define glFramebufferTextureFaceARB glad_glFramebufferTextureFaceARB
GLAPI PFNGLTEXTURESTORAGE2DEXTPROC glad_glTextureStorage2DEXT;
#define glTextureStorage2DEXT glad_glTextureStorage2DEXT
GLAPI PFNGLTEXENVXVOESPROC glad_glTexEnvxvOES;
#define glTexEnvxvOES glad_glTexEnvxvOES
GLAPI PFNGLCLIENTATTRIBDEFAULTEXTPROC glad_glClientAttribDefaultEXT;
#define glClientAttribDefaultEXT glad_glClientAttribDefaultEXT
GLAPI PFNGLPROGRAMUNIFORM2IEXTPROC glad_glProgramUniform2iEXT;
#define glProgramUniform2iEXT glad_glProgramUniform2iEXT
GLAPI PFNGLCLEARDEPTHXOESPROC glad_glClearDepthxOES;
#define glClearDepthxOES glad_glClearDepthxOES
GLAPI PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glad_glTexCoord2fNormal3fVertex3fvSUN;
#define glTexCoord2fNormal3fVertex3fvSUN glad_glTexCoord2fNormal3fVertex3fvSUN
GLAPI PFNGLUNMAPNAMEDBUFFEREXTPROC glad_glUnmapNamedBufferEXT;
#define glUnmapNamedBufferEXT glad_glUnmapNamedBufferEXT
GLAPI PFNGLGETFLOATI_VEXTPROC glad_glGetFloati_vEXT;
#define glGetFloati_vEXT glad_glGetFloati_vEXT
GLAPI PFNGLGENPROGRAMSARBPROC glad_glGenProgramsARB;
#define glGenProgramsARB glad_glGenProgramsARB
GLAPI PFNGLGETVERTEXATTRIBFVNVPROC glad_glGetVertexAttribfvNV;
#define glGetVertexAttribfvNV glad_glGetVertexAttribfvNV
GLAPI PFNGLUNIFORM2IPROC glad_glUniform2i;
#define glUniform2i glad_glUniform2i
GLAPI PFNGLUNIFORM2FPROC glad_glUniform2f;
#define glUniform2f glad_glUniform2f
GLAPI PFNGLPROGRAMUNIFORMUI64VNVPROC glad_glProgramUniformui64vNV;
#define glProgramUniformui64vNV glad_glProgramUniformui64vNV
GLAPI PFNGLNORMAL3FVERTEX3FVSUNPROC glad_glNormal3fVertex3fvSUN;
#define glNormal3fVertex3fvSUN glad_glNormal3fVertex3fvSUN
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glad_glProgramUniformMatrix2x4dv;
#define glProgramUniformMatrix2x4dv glad_glProgramUniformMatrix2x4dv
GLAPI PFNGLVERTEXATTRIB2DVNVPROC glad_glVertexAttrib2dvNV;
#define glVertexAttrib2dvNV glad_glVertexAttrib2dvNV
GLAPI PFNGLVERTEXFORMATNVPROC glad_glVertexFormatNV;
#define glVertexFormatNV glad_glVertexFormatNV
GLAPI PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer;
#define glBlitFramebuffer glad_glBlitFramebuffer
GLAPI PFNGLISENABLEDIPROC glad_glIsEnabledi;
#define glIsEnabledi glad_glIsEnabledi
GLAPI PFNGLVERTEXATTRIBL2UI64VNVPROC glad_glVertexAttribL2ui64vNV;
#define glVertexAttribL2ui64vNV glad_glVertexAttribL2ui64vNV
GLAPI PFNGLVERTEXATTRIBL4I64NVPROC glad_glVertexAttribL4i64NV;
#define glVertexAttribL4i64NV glad_glVertexAttribL4i64NV
GLAPI PFNGLMAKETEXTUREHANDLERESIDENTARBPROC glad_glMakeTextureHandleResidentARB;
#define glMakeTextureHandleResidentARB glad_glMakeTextureHandleResidentARB
GLAPI PFNGLBINORMAL3DVEXTPROC glad_glBinormal3dvEXT;
#define glBinormal3dvEXT glad_glBinormal3dvEXT
GLAPI PFNGLPNTRIANGLESIATIPROC glad_glPNTrianglesiATI;
#define glPNTrianglesiATI glad_glPNTrianglesiATI
GLAPI PFNGLBINDVERTEXARRAYAPPLEPROC glad_glBindVertexArrayAPPLE;
#define glBindVertexArrayAPPLE glad_glBindVertexArrayAPPLE
GLAPI PFNGLTRACKMATRIXNVPROC glad_glTrackMatrixNV;
#define glTrackMatrixNV glad_glTrackMatrixNV
GLAPI PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC glad_glProgramPathFragmentInputGenNV;
#define glProgramPathFragmentInputGenNV glad_glProgramPathFragmentInputGenNV
GLAPI PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC glad_glMakeTextureHandleNonResidentNV;
#define glMakeTextureHandleNonResidentNV glad_glMakeTextureHandleNonResidentNV
GLAPI PFNGLPROGRAMUNIFORM2IPROC glad_glProgramUniform2i;
#define glProgramUniform2i glad_glProgramUniform2i
GLAPI PFNGLVERTEXWEIGHTHVNVPROC glad_glVertexWeighthvNV;
#define glVertexWeighthvNV glad_glVertexWeighthvNV
GLAPI PFNGLTEXCOORD2XOESPROC glad_glTexCoord2xOES;
#define glTexCoord2xOES glad_glTexCoord2xOES
GLAPI PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName;
#define glGetActiveUniformBlockName glad_glGetActiveUniformBlockName
GLAPI PFNGLGETNAMEDBUFFERPOINTERVEXTPROC glad_glGetNamedBufferPointervEXT;
#define glGetNamedBufferPointervEXT glad_glGetNamedBufferPointervEXT
GLAPI PFNGLTEXTUREBARRIERNVPROC glad_glTextureBarrierNV;
#define glTextureBarrierNV glad_glTextureBarrierNV
GLAPI PFNGLCOMBINERPARAMETERINVPROC glad_glCombinerParameteriNV;
#define glCombinerParameteriNV glad_glCombinerParameteriNV
GLAPI PFNGLMATRIXMULTTRANSPOSEFEXTPROC glad_glMatrixMultTransposefEXT;
#define glMatrixMultTransposefEXT glad_glMatrixMultTransposefEXT
GLAPI PFNGLDETAILTEXFUNCSGISPROC glad_glDetailTexFuncSGIS;
#define glDetailTexFuncSGIS glad_glDetailTexFuncSGIS
GLAPI PFNGLINDEXPOINTERLISTIBMPROC glad_glIndexPointerListIBM;
#define glIndexPointerListIBM glad_glIndexPointerListIBM
GLAPI PFNGLPROGRAMUNIFORM2FPROC glad_glProgramUniform2f;
#define glProgramUniform2f glad_glProgramUniform2f
GLAPI PFNGLCLIENTACTIVETEXTUREARBPROC glad_glClientActiveTextureARB;
#define glClientActiveTextureARB glad_glClientActiveTextureARB
GLAPI PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray;
#define glBindVertexArray glad_glBindVertexArray
GLAPI PFNGLCOMPILESHADERINCLUDEARBPROC glad_glCompileShaderIncludeARB;
#define glCompileShaderIncludeARB glad_glCompileShaderIncludeARB
GLAPI PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced;
#define glDrawElementsInstanced glad_glDrawElementsInstanced
GLAPI PFNGLVERTEXATTRIBS2DVNVPROC glad_glVertexAttribs2dvNV;
#define glVertexAttribs2dvNV glad_glVertexAttribs2dvNV
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC glad_glReplacementCodeuiTexCoord2fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fVertex3fSUN glad_glReplacementCodeuiTexCoord2fVertex3fSUN
GLAPI PFNGLTEXFILTERFUNCSGISPROC glad_glTexFilterFuncSGIS;
#define glTexFilterFuncSGIS glad_glTexFilterFuncSGIS
GLAPI PFNGLCOPYMULTITEXIMAGE1DEXTPROC glad_glCopyMultiTexImage1DEXT;
#define glCopyMultiTexImage1DEXT glad_glCopyMultiTexImage1DEXT
GLAPI PFNGLUNIFORMMATRIX2X4DVPROC glad_glUniformMatrix2x4dv;
#define glUniformMatrix2x4dv glad_glUniformMatrix2x4dv
GLAPI PFNGLCOLOR3HNVPROC glad_glColor3hNV;
#define glColor3hNV glad_glColor3hNV
GLAPI PFNGLPROGRAMNAMEDPARAMETER4FNVPROC glad_glProgramNamedParameter4fNV;
#define glProgramNamedParameter4fNV glad_glProgramNamedParameter4fNV
GLAPI PFNGLPIXELSTOREXPROC glad_glPixelStorex;
#define glPixelStorex glad_glPixelStorex
GLAPI PFNGLVERTEXATTRIBL1DVEXTPROC glad_glVertexAttribL1dvEXT;
#define glVertexAttribL1dvEXT glad_glVertexAttribL1dvEXT
GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glad_glGetActiveSubroutineUniformiv;
#define glGetActiveSubroutineUniformiv glad_glGetActiveSubroutineUniformiv
GLAPI PFNGLGETOBJECTPARAMETERIVARBPROC glad_glGetObjectParameterivARB;
#define glGetObjectParameterivARB glad_glGetObjectParameterivARB
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glad_glCompressedTexSubImage2DARB;
#define glCompressedTexSubImage2DARB glad_glCompressedTexSubImage2DARB
GLAPI PFNGLVERTEX2HVNVPROC glad_glVertex2hvNV;
#define glVertex2hvNV glad_glVertex2hvNV
GLAPI PFNGLTEXBUFFERPROC glad_glTexBuffer;
#define glTexBuffer glad_glTexBuffer
GLAPI PFNGLPIXELSTOREIPROC glad_glPixelStorei;
#define glPixelStorei glad_glPixelStorei
GLAPI PFNGLPIXELSTOREFPROC glad_glPixelStoref;
#define glPixelStoref glad_glPixelStoref
GLAPI PFNGLWINDOWPOS3DARBPROC glad_glWindowPos3dARB;
#define glWindowPos3dARB glad_glWindowPos3dARB
GLAPI PFNGLCLIPCONTROLPROC glad_glClipControl;
#define glClipControl glad_glClipControl
GLAPI PFNGLVERTEXATTRIBS2FVNVPROC glad_glVertexAttribs2fvNV;
#define glVertexAttribs2fvNV glad_glVertexAttribs2fvNV
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glad_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN glad_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
GLAPI PFNGLWINDOWPOS2DARBPROC glad_glWindowPos2dARB;
#define glWindowPos2dARB glad_glWindowPos2dARB
GLAPI PFNGLNORMAL3XOESPROC glad_glNormal3xOES;
#define glNormal3xOES glad_glNormal3xOES
GLAPI PFNGLREFERENCEPLANESGIXPROC glad_glReferencePlaneSGIX;
#define glReferencePlaneSGIX glad_glReferencePlaneSGIX
GLAPI PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC glad_glClearNamedBufferSubDataEXT;
#define glClearNamedBufferSubDataEXT glad_glClearNamedBufferSubDataEXT
GLAPI PFNGLGETTEXTURESAMPLERHANDLEARBPROC glad_glGetTextureSamplerHandleARB;
#define glGetTextureSamplerHandleARB glad_glGetTextureSamplerHandleARB
GLAPI PFNGLBINDTEXTUREPROC glad_glBindTexture;
#define glBindTexture glad_glBindTexture
GLAPI PFNGLGETACTIVEATTRIBARBPROC glad_glGetActiveAttribARB;
#define glGetActiveAttribARB glad_glGetActiveAttribARB
GLAPI PFNGLHISTOGRAMEXTPROC glad_glHistogramEXT;
#define glHistogramEXT glad_glHistogramEXT
GLAPI PFNGLDETACHSHADERPROC glad_glDetachShader;
#define glDetachShader glad_glDetachShader
GLAPI PFNGLVIEWPORTINDEXEDFVPROC glad_glViewportIndexedfv;
#define glViewportIndexedfv glad_glViewportIndexedfv
GLAPI PFNGLGETVERTEXATTRIBPOINTERVARBPROC glad_glGetVertexAttribPointervARB;
#define glGetVertexAttribPointervARB glad_glGetVertexAttribPointervARB
GLAPI PFNGLMATRIXINDEXUIVARBPROC glad_glMatrixIndexuivARB;
#define glMatrixIndexuivARB glad_glMatrixIndexuivARB
GLAPI PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage;
#define glSampleCoverage glad_glSampleCoverage
GLAPI PFNGLVERTEXATTRIBP3UIVPROC glad_glVertexAttribP3uiv;
#define glVertexAttribP3uiv glad_glVertexAttribP3uiv
GLAPI PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC glad_glMakeTextureHandleNonResidentARB;
#define glMakeTextureHandleNonResidentARB glad_glMakeTextureHandleNonResidentARB
GLAPI PFNGLGETUNIFORMIVPROC glad_glGetUniformiv;
#define glGetUniformiv glad_glGetUniformiv
GLAPI PFNGLUNIFORM4UIPROC glad_glUniform4ui;
#define glUniform4ui glad_glUniform4ui
GLAPI PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer;
#define glBindFramebuffer glad_glBindFramebuffer
GLAPI PFNGLVERTEXATTRIBPOINTERARBPROC glad_glVertexAttribPointerARB;
#define glVertexAttribPointerARB glad_glVertexAttribPointerARB
GLAPI PFNGLPIXELTRANSFORMPARAMETERIEXTPROC glad_glPixelTransformParameteriEXT;
#define glPixelTransformParameteriEXT glad_glPixelTransformParameteriEXT
GLAPI PFNGLTEXBUMPPARAMETERFVATIPROC glad_glTexBumpParameterfvATI;
#define glTexBumpParameterfvATI glad_glTexBumpParameterfvATI
GLAPI PFNGLSHADERSTORAGEBLOCKBINDINGPROC glad_glShaderStorageBlockBinding;
#define glShaderStorageBlockBinding glad_glShaderStorageBlockBinding
GLAPI PFNGLCONVOLUTIONPARAMETERXVOESPROC glad_glConvolutionParameterxvOES;
#define glConvolutionParameterxvOES glad_glConvolutionParameterxvOES
GLAPI PFNGLISTEXTUREHANDLERESIDENTARBPROC glad_glIsTextureHandleResidentARB;
#define glIsTextureHandleResidentARB glad_glIsTextureHandleResidentARB
GLAPI PFNGLPNTRIANGLESFATIPROC glad_glPNTrianglesfATI;
#define glPNTrianglesfATI glad_glPNTrianglesfATI
GLAPI PFNGLGENFENCESAPPLEPROC glad_glGenFencesAPPLE;
#define glGenFencesAPPLE glad_glGenFencesAPPLE
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glad_glCompressedTextureSubImage2D;
#define glCompressedTextureSubImage2D glad_glCompressedTextureSubImage2D
GLAPI PFNGLTEXTURERANGEAPPLEPROC glad_glTextureRangeAPPLE;
#define glTextureRangeAPPLE glad_glTextureRangeAPPLE
GLAPI PFNGLPOINTPARAMETERIPROC glad_glPointParameteri;
#define glPointParameteri glad_glPointParameteri
GLAPI PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer;
#define glUnmapBuffer glad_glUnmapBuffer
GLAPI PFNGLPOINTPARAMETERFPROC glad_glPointParameterf;
#define glPointParameterf glad_glPointParameterf
GLAPI PFNGLVERTEXATTRIB1SARBPROC glad_glVertexAttrib1sARB;
#define glVertexAttrib1sARB glad_glVertexAttrib1sARB
GLAPI PFNGLPROGRAMPARAMETER4DVNVPROC glad_glProgramParameter4dvNV;
#define glProgramParameter4dvNV glad_glProgramParameter4dvNV
GLAPI PFNGLGETCOLORTABLEPARAMETERFVSGIPROC glad_glGetColorTableParameterfvSGI;
#define glGetColorTableParameterfvSGI glad_glGetColorTableParameterfvSGI
GLAPI PFNGLVERTEXATTRIB1SVNVPROC glad_glVertexAttrib1svNV;
#define glVertexAttrib1svNV glad_glVertexAttrib1svNV
GLAPI PFNGLRELEASESHADERCOMPILERPROC glad_glReleaseShaderCompiler;
#define glReleaseShaderCompiler glad_glReleaseShaderCompiler
GLAPI PFNGLISVERTEXATTRIBENABLEDAPPLEPROC glad_glIsVertexAttribEnabledAPPLE;
#define glIsVertexAttribEnabledAPPLE glad_glIsVertexAttribEnabledAPPLE
GLAPI PFNGLWEIGHTSVARBPROC glad_glWeightsvARB;
#define glWeightsvARB glad_glWeightsvARB
GLAPI PFNGLGETHISTOGRAMPARAMETERIVEXTPROC glad_glGetHistogramParameterivEXT;
#define glGetHistogramParameterivEXT glad_glGetHistogramParameterivEXT
GLAPI PFNGLREADNPIXELSARBPROC glad_glReadnPixelsARB;
#define glReadnPixelsARB glad_glReadnPixelsARB
GLAPI PFNGLMULTITEXBUFFEREXTPROC glad_glMultiTexBufferEXT;
#define glMultiTexBufferEXT glad_glMultiTexBufferEXT
GLAPI PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glad_glNamedFramebufferDrawBuffer;
#define glNamedFramebufferDrawBuffer glad_glNamedFramebufferDrawBuffer
GLAPI PFNGLGETMAPATTRIBPARAMETERFVNVPROC glad_glGetMapAttribParameterfvNV;
#define glGetMapAttribParameterfvNV glad_glGetMapAttribParameterfvNV
GLAPI PFNGLGETNUNIFORMUIVPROC glad_glGetnUniformuiv;
#define glGetnUniformuiv glad_glGetnUniformuiv
GLAPI PFNGLGENBUFFERSPROC glad_glGenBuffers;
#define glGenBuffers glad_glGenBuffers
GLAPI PFNGLVARIANTARRAYOBJECTATIPROC glad_glVariantArrayObjectATI;
#define glVariantArrayObjectATI glad_glVariantArrayObjectATI
GLAPI PFNGLNORMALFORMATNVPROC glad_glNormalFormatNV;
#define glNormalFormatNV glad_glNormalFormatNV
GLAPI PFNGLVERTEXATTRIB3FNVPROC glad_glVertexAttrib3fNV;
#define glVertexAttrib3fNV glad_glVertexAttrib3fNV
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glad_glClearNamedFramebufferiv;
#define glClearNamedFramebufferiv glad_glClearNamedFramebufferiv
GLAPI PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer;
#define glIsFramebuffer glad_glIsFramebuffer
GLAPI PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC glad_glDrawRangeElementArrayAPPLE;
#define glDrawRangeElementArrayAPPLE glad_glDrawRangeElementArrayAPPLE
GLAPI PFNGLPOLYGONOFFSETCLAMPEXTPROC glad_glPolygonOffsetClampEXT;
#define glPolygonOffsetClampEXT glad_glPolygonOffsetClampEXT
GLAPI PFNGLMULTITEXENVIEXTPROC glad_glMultiTexEnviEXT;
#define glMultiTexEnviEXT glad_glMultiTexEnviEXT
GLAPI PFNGLPROGRAMPARAMETER4FVNVPROC glad_glProgramParameter4fvNV;
#define glProgramParameter4fvNV glad_glProgramParameter4fvNV
GLAPI PFNGLGETVARIANTINTEGERVEXTPROC glad_glGetVariantIntegervEXT;
#define glGetVariantIntegervEXT glad_glGetVariantIntegervEXT
GLAPI PFNGLBLENDEQUATIONINDEXEDAMDPROC glad_glBlendEquationIndexedAMD;
#define glBlendEquationIndexedAMD glad_glBlendEquationIndexedAMD
GLAPI PFNGLDELETESTATESNVPROC glad_glDeleteStatesNV;
#define glDeleteStatesNV glad_glDeleteStatesNV
GLAPI PFNGLVERTEXATTRIBI2IVEXTPROC glad_glVertexAttribI2ivEXT;
#define glVertexAttribI2ivEXT glad_glVertexAttribI2ivEXT
GLAPI PFNGLPROGRAMUNIFORM4DVPROC glad_glProgramUniform4dv;
#define glProgramUniform4dv glad_glProgramUniform4dv
GLAPI PFNGLVDPAUFININVPROC glad_glVDPAUFiniNV;
#define glVDPAUFiniNV glad_glVDPAUFiniNV
GLAPI PFNGLMAKEBUFFERNONRESIDENTNVPROC glad_glMakeBufferNonResidentNV;
#define glMakeBufferNonResidentNV glad_glMakeBufferNonResidentNV
GLAPI PFNGLUNIFORM1UI64ARBPROC glad_glUniform1ui64ARB;
#define glUniform1ui64ARB glad_glUniform1ui64ARB
GLAPI PFNGLPROGRAMUNIFORM3UIVPROC glad_glProgramUniform3uiv;
#define glProgramUniform3uiv glad_glProgramUniform3uiv
GLAPI PFNGLMULTITEXCOORD1SARBPROC glad_glMultiTexCoord1sARB;
#define glMultiTexCoord1sARB glad_glMultiTexCoord1sARB
GLAPI PFNGLPROGRAMUNIFORM2UIEXTPROC glad_glProgramUniform2uiEXT;
#define glProgramUniform2uiEXT glad_glProgramUniform2uiEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC glad_glProgramUniformMatrix4x3fvEXT;
#define glProgramUniformMatrix4x3fvEXT glad_glProgramUniformMatrix4x3fvEXT
GLAPI PFNGLPROGRAMUNIFORM3DEXTPROC glad_glProgramUniform3dEXT;
#define glProgramUniform3dEXT glad_glProgramUniform3dEXT
GLAPI PFNGLGETCONVOLUTIONFILTEREXTPROC glad_glGetConvolutionFilterEXT;
#define glGetConvolutionFilterEXT glad_glGetConvolutionFilterEXT
GLAPI PFNGLFOGCOORDPOINTEREXTPROC glad_glFogCoordPointerEXT;
#define glFogCoordPointerEXT glad_glFogCoordPointerEXT
GLAPI PFNGLTRANSLATEXOESPROC glad_glTranslatexOES;
#define glTranslatexOES glad_glTranslatexOES
GLAPI PFNGLTEXTURECOLORMASKSGISPROC glad_glTextureColorMaskSGIS;
#define glTextureColorMaskSGIS glad_glTextureColorMaskSGIS
GLAPI PFNGLVERTEXSTREAM1SVATIPROC glad_glVertexStream1svATI;
#define glVertexStream1svATI glad_glVertexStream1svATI
GLAPI PFNGLVERTEXSTREAM2IATIPROC glad_glVertexStream2iATI;
#define glVertexStream2iATI glad_glVertexStream2iATI
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC glad_glNamedFramebufferTextureFaceEXT;
#define glNamedFramebufferTextureFaceEXT glad_glNamedFramebufferTextureFaceEXT
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glad_glCompressedTextureSubImage3D;
#define glCompressedTextureSubImage3D glad_glCompressedTextureSubImage3D
GLAPI PFNGLASYNCMARKERSGIXPROC glad_glAsyncMarkerSGIX;
#define glAsyncMarkerSGIX glad_glAsyncMarkerSGIX
GLAPI PFNGLVERTEXATTRIB4NBVPROC glad_glVertexAttrib4Nbv;
#define glVertexAttrib4Nbv glad_glVertexAttrib4Nbv
GLAPI PFNGLPRIORITIZETEXTURESEXTPROC glad_glPrioritizeTexturesEXT;
#define glPrioritizeTexturesEXT glad_glPrioritizeTexturesEXT
GLAPI PFNGLGETOCCLUSIONQUERYIVNVPROC glad_glGetOcclusionQueryivNV;
#define glGetOcclusionQueryivNV glad_glGetOcclusionQueryivNV
GLAPI PFNGLGENERATEMULTITEXMIPMAPEXTPROC glad_glGenerateMultiTexMipmapEXT;
#define glGenerateMultiTexMipmapEXT glad_glGenerateMultiTexMipmapEXT
GLAPI PFNGLWINDOWPOS3DVMESAPROC glad_glWindowPos3dvMESA;
#define glWindowPos3dvMESA glad_glWindowPos3dvMESA
GLAPI PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture;
#define glFramebufferTexture glad_glFramebufferTexture
GLAPI PFNGLMULTITEXENVFEXTPROC glad_glMultiTexEnvfEXT;
#define glMultiTexEnvfEXT glad_glMultiTexEnvfEXT
GLAPI PFNGLPOINTPARAMETERFVSGISPROC glad_glPointParameterfvSGIS;
#define glPointParameterfvSGIS glad_glPointParameterfvSGIS
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glad_glProgramUniformMatrix2x4fv;
#define glProgramUniformMatrix2x4fv glad_glProgramUniformMatrix2x4fv
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC glad_glFlushMappedBufferRangeAPPLE;
#define glFlushMappedBufferRangeAPPLE glad_glFlushMappedBufferRangeAPPLE
GLAPI PFNGLVERTEXATTRIBS1DVNVPROC glad_glVertexAttribs1dvNV;
#define glVertexAttribs1dvNV glad_glVertexAttribs1dvNV
GLAPI PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv;
#define glUniformMatrix2fv glad_glUniformMatrix2fv
GLAPI PFNGLBLENDPARAMETERINVPROC glad_glBlendParameteriNV;
#define glBlendParameteriNV glad_glBlendParameteriNV
GLAPI PFNGLSAMPLEMASKINDEXEDNVPROC glad_glSampleMaskIndexedNV;
#define glSampleMaskIndexedNV glad_glSampleMaskIndexedNV
GLAPI PFNGLGETTEXTUREPARAMETERFVEXTPROC glad_glGetTextureParameterfvEXT;
#define glGetTextureParameterfvEXT glad_glGetTextureParameterfvEXT
GLAPI PFNGLMATRIXLOAD3X3FNVPROC glad_glMatrixLoad3x3fNV;
#define glMatrixLoad3x3fNV glad_glMatrixLoad3x3fNV
GLAPI PFNGLMULTITEXCOORD2FARBPROC glad_glMultiTexCoord2fARB;
#define glMultiTexCoord2fARB glad_glMultiTexCoord2fARB
GLAPI PFNGLISTRANSFORMFEEDBACKNVPROC glad_glIsTransformFeedbackNV;
#define glIsTransformFeedbackNV glad_glIsTransformFeedbackNV
GLAPI PFNGLGETINTEGERVPROC glad_glGetIntegerv;
#define glGetIntegerv glad_glGetIntegerv
GLAPI PFNGLSETFENCEAPPLEPROC glad_glSetFenceAPPLE;
#define glSetFenceAPPLE glad_glSetFenceAPPLE
GLAPI PFNGLVERTEXATTRIB4DARBPROC glad_glVertexAttrib4dARB;
#define glVertexAttrib4dARB glad_glVertexAttrib4dARB
GLAPI PFNGLGETHISTOGRAMEXTPROC glad_glGetHistogramEXT;
#define glGetHistogramEXT glad_glGetHistogramEXT
GLAPI PFNGLWINDOWPOS2FVARBPROC glad_glWindowPos2fvARB;
#define glWindowPos2fvARB glad_glWindowPos2fvARB
GLAPI PFNGLENABLEINDEXEDEXTPROC glad_glEnableIndexedEXT;
#define glEnableIndexedEXT glad_glEnableIndexedEXT
GLAPI PFNGLTEXCOORD1BVOESPROC glad_glTexCoord1bvOES;
#define glTexCoord1bvOES glad_glTexCoord1bvOES
GLAPI PFNGLREPLACEMENTCODEPOINTERSUNPROC glad_glReplacementCodePointerSUN;
#define glReplacementCodePointerSUN glad_glReplacementCodePointerSUN
GLAPI PFNGLLOADTRANSPOSEMATRIXDARBPROC glad_glLoadTransposeMatrixdARB;
#define glLoadTransposeMatrixdARB glad_glLoadTransposeMatrixdARB
GLAPI PFNGLVERTEXATTRIB4NUBVPROC glad_glVertexAttrib4Nubv;
#define glVertexAttrib4Nubv glad_glVertexAttrib4Nubv
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC glad_glVertexArrayVertexAttribIOffsetEXT;
#define glVertexArrayVertexAttribIOffsetEXT glad_glVertexArrayVertexAttribIOffsetEXT
GLAPI PFNGLCOMPILESHADERARBPROC glad_glCompileShaderARB;
#define glCompileShaderARB glad_glCompileShaderARB
GLAPI PFNGLNORMALSTREAM3FVATIPROC glad_glNormalStream3fvATI;
#define glNormalStream3fvATI glad_glNormalStream3fvATI
GLAPI PFNGLUNIFORM4UI64ARBPROC glad_glUniform4ui64ARB;
#define glUniform4ui64ARB glad_glUniform4ui64ARB
GLAPI PFNGLGETFRAMEBUFFERPARAMETERIVPROC glad_glGetFramebufferParameteriv;
#define glGetFramebufferParameteriv glad_glGetFramebufferParameteriv
GLAPI PFNGLVERTEXSTREAM2FVATIPROC glad_glVertexStream2fvATI;
#define glVertexStream2fvATI glad_glVertexStream2fvATI
GLAPI PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC glad_glProgramUniformMatrix3dvEXT;
#define glProgramUniformMatrix3dvEXT glad_glProgramUniformMatrix3dvEXT
GLAPI PFNGLDELETEPROGRAMPIPELINESPROC glad_glDeleteProgramPipelines;
#define glDeleteProgramPipelines glad_glDeleteProgramPipelines
GLAPI PFNGLSTOPINSTRUMENTSSGIXPROC glad_glStopInstrumentsSGIX;
#define glStopInstrumentsSGIX glad_glStopInstrumentsSGIX
GLAPI PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform;
#define glGetActiveUniform glad_glGetActiveUniform
GLAPI PFNGLENABLEVERTEXATTRIBAPPLEPROC glad_glEnableVertexAttribAPPLE;
#define glEnableVertexAttribAPPLE glad_glEnableVertexAttribAPPLE
GLAPI PFNGLPROGRAMENVPARAMETERI4IVNVPROC glad_glProgramEnvParameterI4ivNV;
#define glProgramEnvParameterI4ivNV glad_glProgramEnvParameterI4ivNV
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glad_glNamedFramebufferTextureLayer;
#define glNamedFramebufferTextureLayer glad_glNamedFramebufferTextureLayer
GLAPI PFNGLGETVERTEXARRAYINTEGERVEXTPROC glad_glGetVertexArrayIntegervEXT;
#define glGetVertexArrayIntegervEXT glad_glGetVertexArrayIntegervEXT
GLAPI PFNGLVDPAUISSURFACENVPROC glad_glVDPAUIsSurfaceNV;
#define glVDPAUIsSurfaceNV glad_glVDPAUIsSurfaceNV
GLAPI PFNGLISCOMMANDLISTNVPROC glad_glIsCommandListNV;
#define glIsCommandListNV glad_glIsCommandListNV
GLAPI PFNGLCONVOLUTIONPARAMETERIEXTPROC glad_glConvolutionParameteriEXT;
#define glConvolutionParameteriEXT glad_glConvolutionParameteriEXT
GLAPI PFNGLPATHPARAMETERFVNVPROC glad_glPathParameterfvNV;
#define glPathParameterfvNV glad_glPathParameterfvNV
GLAPI PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC glad_glMatrixLoadTranspose3x3fNV;
#define glMatrixLoadTranspose3x3fNV glad_glMatrixLoadTranspose3x3fNV
GLAPI PFNGLBINDSAMPLERPROC glad_glBindSampler;
#define glBindSampler glad_glBindSampler
GLAPI PFNGLLINEWIDTHPROC glad_glLineWidth;
#define glLineWidth glad_glLineWidth
GLAPI PFNGLVERTEXARRAYRANGEAPPLEPROC glad_glVertexArrayRangeAPPLE;
#define glVertexArrayRangeAPPLE glad_glVertexArrayRangeAPPLE
GLAPI PFNGLCOLOR4HNVPROC glad_glColor4hNV;
#define glColor4hNV glad_glColor4hNV
GLAPI PFNGLWEIGHTFVARBPROC glad_glWeightfvARB;
#define glWeightfvARB glad_glWeightfvARB
GLAPI PFNGLVERTEXATTRIB2DARBPROC glad_glVertexAttrib2dARB;
#define glVertexAttrib2dARB glad_glVertexAttrib2dARB
GLAPI PFNGLGETTEXBUMPPARAMETERFVATIPROC glad_glGetTexBumpParameterfvATI;
#define glGetTexBumpParameterfvATI glad_glGetTexBumpParameterfvATI
GLAPI PFNGLBINDPROGRAMARBPROC glad_glBindProgramARB;
#define glBindProgramARB glad_glBindProgramARB
GLAPI PFNGLPROGRAMUNIFORM3UI64VARBPROC glad_glProgramUniform3ui64vARB;
#define glProgramUniform3ui64vARB glad_glProgramUniform3ui64vARB
GLAPI PFNGLSAMPLECOVERAGEARBPROC glad_glSampleCoverageARB;
#define glSampleCoverageARB glad_glSampleCoverageARB
GLAPI PFNGLPROGRAMUNIFORM2UI64VARBPROC glad_glProgramUniform2ui64vARB;
#define glProgramUniform2ui64vARB glad_glProgramUniform2ui64vARB
GLAPI PFNGLVERTEXSTREAM3SVATIPROC glad_glVertexStream3svATI;
#define glVertexStream3svATI glad_glVertexStream3svATI
GLAPI PFNGLSAMPLEMASKIPROC glad_glSampleMaski;
#define glSampleMaski glad_glSampleMaski
GLAPI PFNGLPOINTPARAMETERINVPROC glad_glPointParameteriNV;
#define glPointParameteriNV glad_glPointParameteriNV
GLAPI PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv;
#define glUniformMatrix3x2fv glad_glUniformMatrix3x2fv
GLAPI PFNGLNAMEDBUFFERSTORAGEEXTPROC glad_glNamedBufferStorageEXT;
#define glNamedBufferStorageEXT glad_glNamedBufferStorageEXT
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC glad_glNamedFramebufferTexture3DEXT;
#define glNamedFramebufferTexture3DEXT glad_glNamedFramebufferTexture3DEXT
GLAPI PFNGLVERTEXATTRIB2DVPROC glad_glVertexAttrib2dv;
#define glVertexAttrib2dv glad_glVertexAttrib2dv
GLAPI PFNGLTEXIMAGE4DSGISPROC glad_glTexImage4DSGIS;
#define glTexImage4DSGIS glad_glTexImage4DSGIS
GLAPI PFNGLENABLEVERTEXARRAYEXTPROC glad_glEnableVertexArrayEXT;
#define glEnableVertexArrayEXT glad_glEnableVertexArrayEXT
GLAPI PFNGLUNMAPBUFFERARBPROC glad_glUnmapBufferARB;
#define glUnmapBufferARB glad_glUnmapBufferARB
GLAPI PFNGLVERTEXATTRIBL3UI64VNVPROC glad_glVertexAttribL3ui64vNV;
#define glVertexAttribL3ui64vNV glad_glVertexAttribL3ui64vNV
GLAPI PFNGLDETACHOBJECTARBPROC glad_glDetachObjectARB;
#define glDetachObjectARB glad_glDetachObjectARB
GLAPI PFNGLDELETEPATHSNVPROC glad_glDeletePathsNV;
#define glDeletePathsNV glad_glDeletePathsNV
GLAPI PFNGLPRIMITIVERESTARTINDEXNVPROC glad_glPrimitiveRestartIndexNV;
#define glPrimitiveRestartIndexNV glad_glPrimitiveRestartIndexNV
GLAPI PFNGLTEXCOORDPOINTERLISTIBMPROC glad_glTexCoordPointerListIBM;
#define glTexCoordPointerListIBM glad_glTexCoordPointerListIBM
GLAPI PFNGLRECTXOESPROC glad_glRectxOES;
#define glRectxOES glad_glRectxOES
GLAPI PFNGLTEXTUREPARAMETERIVPROC glad_glTextureParameteriv;
#define glTextureParameteriv glad_glTextureParameteriv
GLAPI PFNGLMULTITEXCOORD3FVARBPROC glad_glMultiTexCoord3fvARB;
#define glMultiTexCoord3fvARB glad_glMultiTexCoord3fvARB
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glad_glNamedFramebufferTexture;
#define glNamedFramebufferTexture glad_glNamedFramebufferTexture
GLAPI PFNGLFOGCOORDFVEXTPROC glad_glFogCoordfvEXT;
#define glFogCoordfvEXT glad_glFogCoordfvEXT
GLAPI PFNGLUNIFORM4UI64VNVPROC glad_glUniform4ui64vNV;
#define glUniform4ui64vNV glad_glUniform4ui64vNV
GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv;
#define glGetFramebufferAttachmentParameteriv glad_glGetFramebufferAttachmentParameteriv
GLAPI PFNGLVERTEXATTRIBL1UI64ARBPROC glad_glVertexAttribL1ui64ARB;
#define glVertexAttribL1ui64ARB glad_glVertexAttribL1ui64ARB
GLAPI PFNGLBLENDEQUATIONIARBPROC glad_glBlendEquationiARB;
#define glBlendEquationiARB glad_glBlendEquationiARB
GLAPI PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv;
#define glTexParameteriv glad_glTexParameteriv
GLAPI PFNGLMATRIXORTHOEXTPROC glad_glMatrixOrthoEXT;
#define glMatrixOrthoEXT glad_glMatrixOrthoEXT
GLAPI PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC glad_glProgramLocalParametersI4ivNV;
#define glProgramLocalParametersI4ivNV glad_glProgramLocalParametersI4ivNV
GLAPI PFNGLPROGRAMUNIFORM4UI64VNVPROC glad_glProgramUniform4ui64vNV;
#define glProgramUniform4ui64vNV glad_glProgramUniform4ui64vNV
GLAPI PFNGLCOMPILESHADERPROC glad_glCompileShader;
#define glCompileShader glad_glCompileShader
GLAPI PFNGLGETDETAILTEXFUNCSGISPROC glad_glGetDetailTexFuncSGIS;
#define glGetDetailTexFuncSGIS glad_glGetDetailTexFuncSGIS
GLAPI PFNGLMULTITEXGENFVEXTPROC glad_glMultiTexGenfvEXT;
#define glMultiTexGenfvEXT glad_glMultiTexGenfvEXT
GLAPI PFNGLSTENCILFUNCSEPARATEATIPROC glad_glStencilFuncSeparateATI;
#define glStencilFuncSeparateATI glad_glStencilFuncSeparateATI
GLAPI PFNGLPROGRAMUNIFORM2IVPROC glad_glProgramUniform2iv;
#define glProgramUniform2iv glad_glProgramUniform2iv
GLAPI PFNGLLISTPARAMETERIVSGIXPROC glad_glListParameterivSGIX;
#define glListParameterivSGIX glad_glListParameterivSGIX
GLAPI PFNGLFRAGMENTLIGHTMODELIVSGIXPROC glad_glFragmentLightModelivSGIX;
#define glFragmentLightModelivSGIX glad_glFragmentLightModelivSGIX
GLAPI PFNGLPROGRAMUNIFORM3I64NVPROC glad_glProgramUniform3i64NV;
#define glProgramUniform3i64NV glad_glProgramUniform3i64NV
GLAPI PFNGLGETTEXTUREHANDLEARBPROC glad_glGetTextureHandleARB;
#define glGetTextureHandleARB glad_glGetTextureHandleARB
GLAPI PFNGLCOVERAGEMODULATIONTABLENVPROC glad_glCoverageModulationTableNV;
#define glCoverageModulationTableNV glad_glCoverageModulationTableNV
GLAPI PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv;
#define glPointParameteriv glad_glPointParameteriv
GLAPI PFNGLMULTITEXCOORD4SVARBPROC glad_glMultiTexCoord4svARB;
#define glMultiTexCoord4svARB glad_glMultiTexCoord4svARB
GLAPI PFNGLNORMAL3XVOESPROC glad_glNormal3xvOES;
#define glNormal3xvOES glad_glNormal3xvOES
GLAPI PFNGLGETACTIVEVARYINGNVPROC glad_glGetActiveVaryingNV;
#define glGetActiveVaryingNV glad_glGetActiveVaryingNV
GLAPI PFNGLTEXTUREBUFFERRANGEPROC glad_glTextureBufferRange;
#define glTextureBufferRange glad_glTextureBufferRange
GLAPI PFNGLPROGRAMUNIFORM4UI64VARBPROC glad_glProgramUniform4ui64vARB;
#define glProgramUniform4ui64vARB glad_glProgramUniform4ui64vARB
GLAPI PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC glad_glGetPixelTransformParameterivEXT;
#define glGetPixelTransformParameterivEXT glad_glGetPixelTransformParameterivEXT
GLAPI PFNGLTEXCOORD4XVOESPROC glad_glTexCoord4xvOES;
#define glTexCoord4xvOES glad_glTexCoord4xvOES
GLAPI PFNGLGETVARIANTBOOLEANVEXTPROC glad_glGetVariantBooleanvEXT;
#define glGetVariantBooleanvEXT glad_glGetVariantBooleanvEXT
GLAPI PFNGLGETVERTEXATTRIBDVARBPROC glad_glGetVertexAttribdvARB;
#define glGetVertexAttribdvARB glad_glGetVertexAttribdvARB
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC glad_glMultiDrawArraysIndirectBindlessNV;
#define glMultiDrawArraysIndirectBindlessNV glad_glMultiDrawArraysIndirectBindlessNV
GLAPI PFNGLSPRITEPARAMETERFVSGIXPROC glad_glSpriteParameterfvSGIX;
#define glSpriteParameterfvSGIX glad_glSpriteParameterfvSGIX
GLAPI PFNGLSHADERSOURCEARBPROC glad_glShaderSourceARB;
#define glShaderSourceARB glad_glShaderSourceARB
GLAPI PFNGLSHADEROP3EXTPROC glad_glShaderOp3EXT;
#define glShaderOp3EXT glad_glShaderOp3EXT
GLAPI PFNGLPROVOKINGVERTEXEXTPROC glad_glProvokingVertexEXT;
#define glProvokingVertexEXT glad_glProvokingVertexEXT
GLAPI PFNGLVARIANTUBVEXTPROC glad_glVariantubvEXT;
#define glVariantubvEXT glad_glVariantubvEXT
GLAPI PFNGLFLUSHPROC glad_glFlush;
#define glFlush glad_glFlush
GLAPI PFNGLGETCOLORTABLEPARAMETERIVEXTPROC glad_glGetColorTableParameterivEXT;
#define glGetColorTableParameterivEXT glad_glGetColorTableParameterivEXT
GLAPI PFNGLPRESENTFRAMEDUALFILLNVPROC glad_glPresentFrameDualFillNV;
#define glPresentFrameDualFillNV glad_glPresentFrameDualFillNV
GLAPI PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC glad_glProgramUniformHandleui64vARB;
#define glProgramUniformHandleui64vARB glad_glProgramUniformHandleui64vARB
GLAPI PFNGLDEPTHRANGEFOESPROC glad_glDepthRangefOES;
#define glDepthRangefOES glad_glDepthRangefOES
GLAPI PFNGLGETVARIANTPOINTERVEXTPROC glad_glGetVariantPointervEXT;
#define glGetVariantPointervEXT glad_glGetVariantPointervEXT
GLAPI PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv;
#define glGetTexLevelParameteriv glad_glGetTexLevelParameteriv
GLAPI PFNGLMULTITEXCOORD3XVOESPROC glad_glMultiTexCoord3xvOES;
#define glMultiTexCoord3xvOES glad_glMultiTexCoord3xvOES
GLAPI PFNGLWINDOWPOS3FVMESAPROC glad_glWindowPos3fvMESA;
#define glWindowPos3fvMESA glad_glWindowPos3fvMESA
GLAPI PFNGLSTENCILOPVALUEAMDPROC glad_glStencilOpValueAMD;
#define glStencilOpValueAMD glad_glStencilOpValueAMD
GLAPI PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC glad_glGetTexParameterPointervAPPLE;
#define glGetTexParameterPointervAPPLE glad_glGetTexParameterPointervAPPLE
GLAPI PFNGLCLAMPCOLORPROC glad_glClampColor;
#define glClampColor glad_glClampColor
GLAPI PFNGLMAKETEXTUREHANDLERESIDENTNVPROC glad_glMakeTextureHandleResidentNV;
#define glMakeTextureHandleResidentNV glad_glMakeTextureHandleResidentNV
GLAPI PFNGLMULTITEXCOORD2HNVPROC glad_glMultiTexCoord2hNV;
#define glMultiTexCoord2hNV glad_glMultiTexCoord2hNV
GLAPI PFNGLISFENCEAPPLEPROC glad_glIsFenceAPPLE;
#define glIsFenceAPPLE glad_glIsFenceAPPLE
GLAPI PFNGLCOMBINERINPUTNVPROC glad_glCombinerInputNV;
#define glCombinerInputNV glad_glCombinerInputNV
GLAPI PFNGLMAPVERTEXATTRIB2DAPPLEPROC glad_glMapVertexAttrib2dAPPLE;
#define glMapVertexAttrib2dAPPLE glad_glMapVertexAttrib2dAPPLE
GLAPI PFNGLCOPYTEXTUREIMAGE2DEXTPROC glad_glCopyTextureImage2DEXT;
#define glCopyTextureImage2DEXT glad_glCopyTextureImage2DEXT
GLAPI PFNGLMULTITEXCOORD4FARBPROC glad_glMultiTexCoord4fARB;
#define glMultiTexCoord4fARB glad_glMultiTexCoord4fARB
GLAPI PFNGLGETPROGRAMIVPROC glad_glGetProgramiv;
#define glGetProgramiv glad_glGetProgramiv
GLAPI PFNGLPROGRAMUNIFORM4FVPROC glad_glProgramUniform4fv;
#define glProgramUniform4fv glad_glProgramUniform4fv
GLAPI PFNGLVERTEXATTRIBI3UIEXTPROC glad_glVertexAttribI3uiEXT;
#define glVertexAttribI3uiEXT glad_glVertexAttribI3uiEXT
GLAPI PFNGLLINEWIDTHXOESPROC glad_glLineWidthxOES;
#define glLineWidthxOES glad_glLineWidthxOES
GLAPI PFNGLPIXELTEXGENPARAMETERIVSGISPROC glad_glPixelTexGenParameterivSGIS;
#define glPixelTexGenParameterivSGIS glad_glPixelTexGenParameterivSGIS
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC glad_glCompressedTextureSubImage1DEXT;
#define glCompressedTextureSubImage1DEXT glad_glCompressedTextureSubImage1DEXT
GLAPI PFNGLGETNUNIFORMIVARBPROC glad_glGetnUniformivARB;
#define glGetnUniformivARB glad_glGetnUniformivARB
GLAPI PFNGLUNIFORM2I64ARBPROC glad_glUniform2i64ARB;
#define glUniform2i64ARB glad_glUniform2i64ARB
GLAPI PFNGLDELETESAMPLERSPROC glad_glDeleteSamplers;
#define glDeleteSamplers glad_glDeleteSamplers
GLAPI PFNGLGETLIGHTXOESPROC glad_glGetLightxOES;
#define glGetLightxOES glad_glGetLightxOES
GLAPI PFNGLVERTEXARRAYNORMALOFFSETEXTPROC glad_glVertexArrayNormalOffsetEXT;
#define glVertexArrayNormalOffsetEXT glad_glVertexArrayNormalOffsetEXT
GLAPI PFNGLDRAWMESHARRAYSSUNPROC glad_glDrawMeshArraysSUN;
#define glDrawMeshArraysSUN glad_glDrawMeshArraysSUN
GLAPI PFNGLGETPATHCOMMANDSNVPROC glad_glGetPathCommandsNV;
#define glGetPathCommandsNV glad_glGetPathCommandsNV
GLAPI PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC glad_glVertexArrayTexCoordOffsetEXT;
#define glVertexArrayTexCoordOffsetEXT glad_glVertexArrayTexCoordOffsetEXT
GLAPI PFNGLUNIFORMMATRIX4DVPROC glad_glUniformMatrix4dv;
#define glUniformMatrix4dv glad_glUniformMatrix4dv
GLAPI PFNGLBINDTEXTURESPROC glad_glBindTextures;
#define glBindTextures glad_glBindTextures
GLAPI PFNGLGETPERFQUERYINFOINTELPROC glad_glGetPerfQueryInfoINTEL;
#define glGetPerfQueryInfoINTEL glad_glGetPerfQueryInfoINTEL
GLAPI PFNGLUNIFORM2FARBPROC glad_glUniform2fARB;
#define glUniform2fARB glad_glUniform2fARB
GLAPI PFNGLBINDBUFFERRANGEEXTPROC glad_glBindBufferRangeEXT;
#define glBindBufferRangeEXT glad_glBindBufferRangeEXT
GLAPI PFNGLGETPROGRAMSTRINGARBPROC glad_glGetProgramStringARB;
#define glGetProgramStringARB glad_glGetProgramStringARB
GLAPI PFNGLGETSHADERSOURCEARBPROC glad_glGetShaderSourceARB;
#define glGetShaderSourceARB glad_glGetShaderSourceARB
GLAPI PFNGLVERTEXATTRIB3DVARBPROC glad_glVertexAttrib3dvARB;
#define glVertexAttrib3dvARB glad_glVertexAttrib3dvARB
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glad_glCompressedTextureSubImage1D;
#define glCompressedTextureSubImage1D glad_glCompressedTextureSubImage1D
GLAPI PFNGLUNIFORM3FVPROC glad_glUniform3fv;
#define glUniform3fv glad_glUniform3fv
GLAPI PFNGLCLEARTEXIMAGEPROC glad_glClearTexImage;
#define glClearTexImage glad_glClearTexImage
GLAPI PFNGLCLEARNAMEDBUFFERDATAEXTPROC glad_glClearNamedBufferDataEXT;
#define glClearNamedBufferDataEXT glad_glClearNamedBufferDataEXT
GLAPI PFNGLWINDOWPOS3FMESAPROC glad_glWindowPos3fMESA;
#define glWindowPos3fMESA glad_glWindowPos3fMESA
GLAPI PFNGLCONVOLUTIONPARAMETERXOESPROC glad_glConvolutionParameterxOES;
#define glConvolutionParameterxOES glad_glConvolutionParameterxOES
GLAPI PFNGLGETQUERYBUFFEROBJECTUIVPROC glad_glGetQueryBufferObjectuiv;
#define glGetQueryBufferObjectuiv glad_glGetQueryBufferObjectuiv
GLAPI PFNGLTEXSUBIMAGE1DEXTPROC glad_glTexSubImage1DEXT;
#define glTexSubImage1DEXT glad_glTexSubImage1DEXT
GLAPI PFNGLNORMALSTREAM3DATIPROC glad_glNormalStream3dATI;
#define glNormalStream3dATI glad_glNormalStream3dATI
GLAPI PFNGLVERTEXATTRIBL4I64VNVPROC glad_glVertexAttribL4i64vNV;
#define glVertexAttribL4i64vNV glad_glVertexAttribL4i64vNV
GLAPI PFNGLUNIFORM2I64VARBPROC glad_glUniform2i64vARB;
#define glUniform2i64vARB glad_glUniform2i64vARB
GLAPI PFNGLMULTITEXCOORD4DVARBPROC glad_glMultiTexCoord4dvARB;
#define glMultiTexCoord4dvARB glad_glMultiTexCoord4dvARB
GLAPI PFNGLMAPBUFFERPROC glad_glMapBuffer;
#define glMapBuffer glad_glMapBuffer
GLAPI PFNGLTEXCOORD1HNVPROC glad_glTexCoord1hNV;
#define glTexCoord1hNV glad_glTexCoord1hNV
GLAPI PFNGLMULTITEXCOORD1HVNVPROC glad_glMultiTexCoord1hvNV;
#define glMultiTexCoord1hvNV glad_glMultiTexCoord1hvNV
GLAPI PFNGLWEIGHTBVARBPROC glad_glWeightbvARB;
#define glWeightbvARB glad_glWeightbvARB
GLAPI PFNGLUNIFORM2UIVPROC glad_glUniform2uiv;
#define glUniform2uiv glad_glUniform2uiv
GLAPI PFNGLRECTXVOESPROC glad_glRectxvOES;
#define glRectxvOES glad_glRectxvOES
GLAPI PFNGLFINISHPROC glad_glFinish;
#define glFinish glad_glFinish
GLAPI PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC glad_glVertexArrayVertexOffsetEXT;
#define glVertexArrayVertexOffsetEXT glad_glVertexArrayVertexOffsetEXT
GLAPI PFNGLVIEWPORTPOSITIONWSCALENVPROC glad_glViewportPositionWScaleNV;
#define glViewportPositionWScaleNV glad_glViewportPositionWScaleNV
GLAPI PFNGLUNIFORM1UIVPROC glad_glUniform1uiv;
#define glUniform1uiv glad_glUniform1uiv
GLAPI PFNGLUNIFORMMATRIX2DVPROC glad_glUniformMatrix2dv;
#define glUniformMatrix2dv glad_glUniformMatrix2dv
GLAPI PFNGLSECONDARYCOLOR3IVEXTPROC glad_glSecondaryColor3ivEXT;
#define glSecondaryColor3ivEXT glad_glSecondaryColor3ivEXT
GLAPI PFNGLGETPROGRAMPARAMETERFVNVPROC glad_glGetProgramParameterfvNV;
#define glGetProgramParameterfvNV glad_glGetProgramParameterfvNV
GLAPI PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glad_glCompressedTexImage3DARB;
#define glCompressedTexImage3DARB glad_glCompressedTexImage3DARB
GLAPI PFNGLWEIGHTIVARBPROC glad_glWeightivARB;
#define glWeightivARB glad_glWeightivARB
GLAPI PFNGLINSERTCOMPONENTEXTPROC glad_glInsertComponentEXT;
#define glInsertComponentEXT glad_glInsertComponentEXT
GLAPI PFNGLCREATETEXTURESPROC glad_glCreateTextures;
#define glCreateTextures glad_glCreateTextures
GLAPI PFNGLMULTITEXCOORD2XVOESPROC glad_glMultiTexCoord2xvOES;
#define glMultiTexCoord2xvOES glad_glMultiTexCoord2xvOES
GLAPI PFNGLTEXGENXVOESPROC glad_glTexGenxvOES;
#define glTexGenxvOES glad_glTexGenxvOES
GLAPI PFNGLMULTTRANSPOSEMATRIXFARBPROC glad_glMultTransposeMatrixfARB;
#define glMultTransposeMatrixfARB glad_glMultTransposeMatrixfARB
GLAPI PFNGLBEGINTRANSFORMFEEDBACKEXTPROC glad_glBeginTransformFeedbackEXT;
#define glBeginTransformFeedbackEXT glad_glBeginTransformFeedbackEXT
GLAPI PFNGLMULTITEXPARAMETERIEXTPROC glad_glMultiTexParameteriEXT;
#define glMultiTexParameteriEXT glad_glMultiTexParameteriEXT
GLAPI PFNGLBLENDFUNCSEPARATEEXTPROC glad_glBlendFuncSeparateEXT;
#define glBlendFuncSeparateEXT glad_glBlendFuncSeparateEXT
GLAPI PFNGLCONVOLUTIONPARAMETERIVEXTPROC glad_glConvolutionParameterivEXT;
#define glConvolutionParameterivEXT glad_glConvolutionParameterivEXT
GLAPI PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC glad_glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
#define glReplacementCodeuiColor4fNormal3fVertex3fvSUN glad_glReplacementCodeuiColor4fNormal3fVertex3fvSUN
GLAPI PFNGLSECONDARYCOLOR3DEXTPROC glad_glSecondaryColor3dEXT;
#define glSecondaryColor3dEXT glad_glSecondaryColor3dEXT
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glad_glClearNamedFramebufferuiv;
#define glClearNamedFramebufferuiv glad_glClearNamedFramebufferuiv
GLAPI PFNGLPROGRAMUNIFORM1UI64NVPROC glad_glProgramUniform1ui64NV;
#define glProgramUniform1ui64NV glad_glProgramUniform1ui64NV
GLAPI PFNGLDISPATCHCOMPUTEPROC glad_glDispatchCompute;
#define glDispatchCompute glad_glDispatchCompute
GLAPI PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib;
#define glGetActiveAttrib glad_glGetActiveAttrib
GLAPI PFNGLFRAGMENTCOLORMATERIALSGIXPROC glad_glFragmentColorMaterialSGIX;
#define glFragmentColorMaterialSGIX glad_glFragmentColorMaterialSGIX
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glad_glProgramUniformMatrix3x4fv;
#define glProgramUniformMatrix3x4fv glad_glProgramUniformMatrix3x4fv
GLAPI PFNGLGETTEXTUREPARAMETERIUIVPROC glad_glGetTextureParameterIuiv;
#define glGetTextureParameterIuiv glad_glGetTextureParameterIuiv
GLAPI PFNGLFRAMEBUFFERTEXTURE1DEXTPROC glad_glFramebufferTexture1DEXT;
#define glFramebufferTexture1DEXT glad_glFramebufferTexture1DEXT
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC glad_glNamedProgramLocalParametersI4ivEXT;
#define glNamedProgramLocalParametersI4ivEXT glad_glNamedProgramLocalParametersI4ivEXT
GLAPI PFNGLRASTERPOS4XVOESPROC glad_glRasterPos4xvOES;
#define glRasterPos4xvOES glad_glRasterPos4xvOES
GLAPI PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glad_glDrawTransformFeedbackStream;
#define glDrawTransformFeedbackStream glad_glDrawTransformFeedbackStream
GLAPI PFNGLSTENCILSTROKEPATHNVPROC glad_glStencilStrokePathNV;
#define glStencilStrokePathNV glad_glStencilStrokePathNV
GLAPI PFNGLCREATESTATESNVPROC glad_glCreateStatesNV;
#define glCreateStatesNV glad_glCreateStatesNV
GLAPI PFNGLCLEARDEPTHDNVPROC glad_glClearDepthdNV;
#define glClearDepthdNV glad_glClearDepthdNV
GLAPI PFNGLBINDMULTITEXTUREEXTPROC glad_glBindMultiTextureEXT;
#define glBindMultiTextureEXT glad_glBindMultiTextureEXT
GLAPI PFNGLPROGRAMUNIFORM4IVPROC glad_glProgramUniform4iv;
#define glProgramUniform4iv glad_glProgramUniform4iv
GLAPI PFNGLPROGRAMUNIFORM3UI64NVPROC glad_glProgramUniform3ui64NV;
#define glProgramUniform3ui64NV glad_glProgramUniform3ui64NV
GLAPI PFNGLMULTITEXPARAMETERIIVEXTPROC glad_glMultiTexParameterIivEXT;
#define glMultiTexParameterIivEXT glad_glMultiTexParameterIivEXT
GLAPI PFNGLVERTEXATTRIB1DVARBPROC glad_glVertexAttrib1dvARB;
#define glVertexAttrib1dvARB glad_glVertexAttrib1dvARB
GLAPI PFNGLUNIFORM1IVPROC glad_glUniform1iv;
#define glUniform1iv glad_glUniform1iv
GLAPI PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glad_glVertexAttribArrayObjectATI;
#define glVertexAttribArrayObjectATI glad_glVertexAttribArrayObjectATI
GLAPI PFNGLSAMPLERPARAMETERIVPROC glad_glSamplerParameteriv;
#define glSamplerParameteriv glad_glSamplerParameteriv
GLAPI PFNGLPROGRAMPARAMETERIARBPROC glad_glProgramParameteriARB;
#define glProgramParameteriARB glad_glProgramParameteriARB
GLAPI PFNGLDISABLEVERTEXATTRIBAPPLEPROC glad_glDisableVertexAttribAPPLE;
#define glDisableVertexAttribAPPLE glad_glDisableVertexAttribAPPLE
GLAPI PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer;
#define glBindRenderbuffer glad_glBindRenderbuffer
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC glad_glMultiDrawElementsIndirectAMD;
#define glMultiDrawElementsIndirectAMD glad_glMultiDrawElementsIndirectAMD
GLAPI PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glad_glGetLocalConstantBooleanvEXT;
#define glGetLocalConstantBooleanvEXT glad_glGetLocalConstantBooleanvEXT
GLAPI PFNGLUNIFORMMATRIX3X2DVPROC glad_glUniformMatrix3x2dv;
#define glUniformMatrix3x2dv glad_glUniformMatrix3x2dv
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glad_glProgramUniformMatrix2x3dv;
#define glProgramUniformMatrix2x3dv glad_glProgramUniformMatrix2x3dv
GLAPI PFNGLSECONDARYCOLORPOINTERLISTIBMPROC glad_glSecondaryColorPointerListIBM;
#define glSecondaryColorPointerListIBM glad_glSecondaryColorPointerListIBM
GLAPI PFNGLVERTEXATTRIBS3FVNVPROC glad_glVertexAttribs3fvNV;
#define glVertexAttribs3fvNV glad_glVertexAttribs3fvNV
GLAPI PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv;
#define glVertexAttrib2fv glad_glVertexAttrib2fv
GLAPI PFNGLUNIFORM3UI64NVPROC glad_glUniform3ui64NV;
#define glUniform3ui64NV glad_glUniform3ui64NV
GLAPI PFNGLCOMBINERPARAMETERFVNVPROC glad_glCombinerParameterfvNV;
#define glCombinerParameterfvNV glad_glCombinerParameterfvNV
GLAPI PFNGLBEGINCONDITIONALRENDERNVPROC glad_glBeginConditionalRenderNV;
#define glBeginConditionalRenderNV glad_glBeginConditionalRenderNV
GLAPI PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC glad_glPixelTransformParameterivEXT;
#define glPixelTransformParameterivEXT glad_glPixelTransformParameterivEXT
GLAPI PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glad_glGetLocalConstantIntegervEXT;
#define glGetLocalConstantIntegervEXT glad_glGetLocalConstantIntegervEXT
GLAPI PFNGLPROGRAMUNIFORM3IPROC glad_glProgramUniform3i;
#define glProgramUniform3i glad_glProgramUniform3i
GLAPI PFNGLGETBUFFERPOINTERVARBPROC glad_glGetBufferPointervARB;
#define glGetBufferPointervARB glad_glGetBufferPointervARB
GLAPI PFNGLMULTMATRIXXOESPROC glad_glMultMatrixxOES;
#define glMultMatrixxOES glad_glMultMatrixxOES
GLAPI PFNGLCOLORPOINTERLISTIBMPROC glad_glColorPointerListIBM;
#define glColorPointerListIBM glad_glColorPointerListIBM
GLAPI PFNGLPROGRAMUNIFORM3DPROC glad_glProgramUniform3d;
#define glProgramUniform3d glad_glProgramUniform3d
GLAPI PFNGLMAPVERTEXATTRIB1DAPPLEPROC glad_glMapVertexAttrib1dAPPLE;
#define glMapVertexAttrib1dAPPLE glad_glMapVertexAttrib1dAPPLE
GLAPI PFNGLFOGFUNCSGISPROC glad_glFogFuncSGIS;
#define glFogFuncSGIS glad_glFogFuncSGIS
GLAPI PFNGLGETUNIFORMIVARBPROC glad_glGetUniformivARB;
#define glGetUniformivARB glad_glGetUniformivARB
GLAPI PFNGLENDCONDITIONALRENDERNVPROC glad_glEndConditionalRenderNV;
#define glEndConditionalRenderNV glad_glEndConditionalRenderNV
GLAPI PFNGLMULTITEXCOORD2BVOESPROC glad_glMultiTexCoord2bvOES;
#define glMultiTexCoord2bvOES glad_glMultiTexCoord2bvOES
GLAPI PFNGLVERTEXATTRIBFORMATNVPROC glad_glVertexAttribFormatNV;
#define glVertexAttribFormatNV glad_glVertexAttribFormatNV
GLAPI PFNGLUNIFORM3I64VARBPROC glad_glUniform3i64vARB;
#define glUniform3i64vARB glad_glUniform3i64vARB
GLAPI PFNGLVERTEXATTRIBI1UIPROC glad_glVertexAttribI1ui;
#define glVertexAttribI1ui glad_glVertexAttribI1ui
GLAPI PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC glad_glGetNamedRenderbufferParameterivEXT;
#define glGetNamedRenderbufferParameterivEXT glad_glGetNamedRenderbufferParameterivEXT
GLAPI PFNGLUNIFORM1UIEXTPROC glad_glUniform1uiEXT;
#define glUniform1uiEXT glad_glUniform1uiEXT
GLAPI PFNGLVERTEXARRAYRANGENVPROC glad_glVertexArrayRangeNV;
#define glVertexArrayRangeNV glad_glVertexArrayRangeNV
GLAPI PFNGLISTEXTUREHANDLERESIDENTNVPROC glad_glIsTextureHandleResidentNV;
#define glIsTextureHandleResidentNV glad_glIsTextureHandleResidentNV
GLAPI PFNGLISNAMEDSTRINGARBPROC glad_glIsNamedStringARB;
#define glIsNamedStringARB glad_glIsNamedStringARB
GLAPI PFNGLPIXELTRANSFERXOESPROC glad_glPixelTransferxOES;
#define glPixelTransferxOES glad_glPixelTransferxOES
GLAPI PFNGLINVALIDATETEXSUBIMAGEPROC glad_glInvalidateTexSubImage;
#define glInvalidateTexSubImage glad_glInvalidateTexSubImage
GLAPI PFNGLCOLOR4UBVERTEX3FSUNPROC glad_glColor4ubVertex3fSUN;
#define glColor4ubVertex3fSUN glad_glColor4ubVertex3fSUN
GLAPI PFNGLGETPROGRAMENVPARAMETERFVARBPROC glad_glGetProgramEnvParameterfvARB;
#define glGetProgramEnvParameterfvARB glad_glGetProgramEnvParameterfvARB
GLAPI PFNGLGETHANDLEARBPROC glad_glGetHandleARB;
#define glGetHandleARB glad_glGetHandleARB
GLAPI PFNGLPIXELMAPXPROC glad_glPixelMapx;
#define glPixelMapx glad_glPixelMapx
GLAPI PFNGLEVALCOORD2XVOESPROC glad_glEvalCoord2xvOES;
#define glEvalCoord2xvOES glad_glEvalCoord2xvOES
GLAPI PFNGLCLEARBUFFERIVPROC glad_glClearBufferiv;
#define glClearBufferiv glad_glClearBufferiv
GLAPI PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC glad_glBindVideoCaptureStreamBufferNV;
#define glBindVideoCaptureStreamBufferNV glad_glBindVideoCaptureStreamBufferNV
GLAPI PFNGLNAMEDSTRINGARBPROC glad_glNamedStringARB;
#define glNamedStringARB glad_glNamedStringARB
GLAPI PFNGLGETNAMEDPROGRAMSTRINGEXTPROC glad_glGetNamedProgramStringEXT;
#define glGetNamedProgramStringEXT glad_glGetNamedProgramStringEXT
GLAPI PFNGLCURRENTPALETTEMATRIXARBPROC glad_glCurrentPaletteMatrixARB;
#define glCurrentPaletteMatrixARB glad_glCurrentPaletteMatrixARB
GLAPI PFNGLGETSAMPLERPARAMETERIUIVPROC glad_glGetSamplerParameterIuiv;
#define glGetSamplerParameterIuiv glad_glGetSamplerParameterIuiv
GLAPI PFNGLVERTEXATTRIBLPOINTEREXTPROC glad_glVertexAttribLPointerEXT;
#define glVertexAttribLPointerEXT glad_glVertexAttribLPointerEXT
GLAPI PFNGLFOGXVOESPROC glad_glFogxvOES;
#define glFogxvOES glad_glFogxvOES
GLAPI PFNGLVERTEXATTRIBS2SVNVPROC glad_glVertexAttribs2svNV;
#define glVertexAttribs2svNV glad_glVertexAttribs2svNV
GLAPI PFNGLFINALCOMBINERINPUTNVPROC glad_glFinalCombinerInputNV;
#define glFinalCombinerInputNV glad_glFinalCombinerInputNV
GLAPI PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glad_glInvalidateNamedFramebufferData;
#define glInvalidateNamedFramebufferData glad_glInvalidateNamedFramebufferData
GLAPI PFNGLISENABLEDINDEXEDEXTPROC glad_glIsEnabledIndexedEXT;
#define glIsEnabledIndexedEXT glad_glIsEnabledIndexedEXT
GLAPI PFNGLVERTEXPOINTERLISTIBMPROC glad_glVertexPointerListIBM;
#define glVertexPointerListIBM glad_glVertexPointerListIBM
GLAPI PFNGLVERTEXATTRIBL3UI64NVPROC glad_glVertexAttribL3ui64NV;
#define glVertexAttribL3ui64NV glad_glVertexAttribL3ui64NV
GLAPI PFNGLVERTEXATTRIB2SARBPROC glad_glVertexAttrib2sARB;
#define glVertexAttrib2sARB glad_glVertexAttrib2sARB
GLAPI PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glad_glCompressedTexImage2DARB;
#define glCompressedTexImage2DARB glad_glCompressedTexImage2DARB
GLAPI PFNGLMULTITEXCOORD1IVARBPROC glad_glMultiTexCoord1ivARB;
#define glMultiTexCoord1ivARB glad_glMultiTexCoord1ivARB
GLAPI PFNGLCOLORMASKPROC glad_glColorMask;
#define glColorMask glad_glColorMask
GLAPI PFNGLGETQUERYOBJECTUI64VEXTPROC glad_glGetQueryObjectui64vEXT;
#define glGetQueryObjectui64vEXT glad_glGetQueryObjectui64vEXT
GLAPI PFNGLVERTEXATTRIBI4UIVEXTPROC glad_glVertexAttribI4uivEXT;
#define glVertexAttribI4uivEXT glad_glVertexAttribI4uivEXT
GLAPI PFNGLVERTEXSTREAM4IVATIPROC glad_glVertexStream4ivATI;
#define glVertexStream4ivATI glad_glVertexStream4ivATI
GLAPI PFNGLGETPROGRAMIVNVPROC glad_glGetProgramivNV;
#define glGetProgramivNV glad_glGetProgramivNV
GLAPI PFNGLPROGRAMUNIFORM2IVEXTPROC glad_glProgramUniform2ivEXT;
#define glProgramUniform2ivEXT glad_glProgramUniform2ivEXT
GLAPI PFNGLVERTEXATTRIB1DVPROC glad_glVertexAttrib1dv;
#define glVertexAttrib1dv glad_glVertexAttrib1dv
GLAPI PFNGLMATRIXLOADIDENTITYEXTPROC glad_glMatrixLoadIdentityEXT;
#define glMatrixLoadIdentityEXT glad_glMatrixLoadIdentityEXT
GLAPI PFNGLBUFFERSUBDATAPROC glad_glBufferSubData;
#define glBufferSubData glad_glBufferSubData
GLAPI PFNGLGETBOOLEANINDEXEDVEXTPROC glad_glGetBooleanIndexedvEXT;
#define glGetBooleanIndexedvEXT glad_glGetBooleanIndexedvEXT
GLAPI PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC glad_glApplyFramebufferAttachmentCMAAINTEL;
#define glApplyFramebufferAttachmentCMAAINTEL glad_glApplyFramebufferAttachmentCMAAINTEL
GLAPI PFNGLGETVERTEXATTRIBLI64VNVPROC glad_glGetVertexAttribLi64vNV;
#define glGetVertexAttribLi64vNV glad_glGetVertexAttribLi64vNV
GLAPI PFNGLWEIGHTUIVARBPROC glad_glWeightuivARB;
#define glWeightuivARB glad_glWeightuivARB
GLAPI PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glad_glGetProgramLocalParameterdvARB;
#define glGetProgramLocalParameterdvARB glad_glGetProgramLocalParameterdvARB
GLAPI PFNGLGETUNIFORMUI64VARBPROC glad_glGetUniformui64vARB;
#define glGetUniformui64vARB glad_glGetUniformui64vARB
GLAPI PFNGLGETSYNCIVPROC glad_glGetSynciv;
#define glGetSynciv glad_glGetSynciv
GLAPI PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC glad_glGetProgramNamedParameterfvNV;
#define glGetProgramNamedParameterfvNV glad_glGetProgramNamedParameterfvNV
GLAPI PFNGLPROGRAMUNIFORM2DPROC glad_glProgramUniform2d;
#define glProgramUniform2d glad_glProgramUniform2d
GLAPI PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC glad_glProgramLocalParametersI4uivNV;
#define glProgramLocalParametersI4uivNV glad_glProgramLocalParametersI4uivNV
GLAPI PFNGLBEGINTRANSFORMFEEDBACKNVPROC glad_glBeginTransformFeedbackNV;
#define glBeginTransformFeedbackNV glad_glBeginTransformFeedbackNV
GLAPI PFNGLGETPROGRAMBINARYPROC glad_glGetProgramBinary;
#define glGetProgramBinary glad_glGetProgramBinary
GLAPI PFNGLBINORMAL3IEXTPROC glad_glBinormal3iEXT;
#define glBinormal3iEXT glad_glBinormal3iEXT
GLAPI PFNGLGLOBALALPHAFACTORBSUNPROC glad_glGlobalAlphaFactorbSUN;
#define glGlobalAlphaFactorbSUN glad_glGlobalAlphaFactorbSUN
GLAPI PFNGLCREATETRANSFORMFEEDBACKSPROC glad_glCreateTransformFeedbacks;
#define glCreateTransformFeedbacks glad_glCreateTransformFeedbacks
GLAPI PFNGLTEXTUREPAGECOMMITMENTEXTPROC glad_glTexturePageCommitmentEXT;
#define glTexturePageCommitmentEXT glad_glTexturePageCommitmentEXT
GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC glad_glTransformFeedbackVaryingsNV;
#define glTransformFeedbackVaryingsNV glad_glTransformFeedbackVaryingsNV
GLAPI PFNGLBLITFRAMEBUFFEREXTPROC glad_glBlitFramebufferEXT;
#define glBlitFramebufferEXT glad_glBlitFramebufferEXT
GLAPI PFNGLVERTEXATTRIBI4IVPROC glad_glVertexAttribI4iv;
#define glVertexAttribI4iv glad_glVertexAttribI4iv
GLAPI PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC glad_glGetMultiTexLevelParameterivEXT;
#define glGetMultiTexLevelParameterivEXT glad_glGetMultiTexLevelParameterivEXT
GLAPI PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC glad_glGetProgramEnvParameterIuivNV;
#define glGetProgramEnvParameterIuivNV glad_glGetProgramEnvParameterIuivNV
GLAPI PFNGLVERTEXATTRIB4SVPROC glad_glVertexAttrib4sv;
#define glVertexAttrib4sv glad_glVertexAttrib4sv
GLAPI PFNGLVERTEXATTRIB4FVARBPROC glad_glVertexAttrib4fvARB;
#define glVertexAttrib4fvARB glad_glVertexAttrib4fvARB
GLAPI PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC glad_glGetNamedProgramLocalParameterIivEXT;
#define glGetNamedProgramLocalParameterIivEXT glad_glGetNamedProgramLocalParameterIivEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC glad_glProgramUniformMatrix4x2dvEXT;
#define glProgramUniformMatrix4x2dvEXT glad_glProgramUniformMatrix4x2dvEXT
GLAPI PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv;
#define glTexParameterfv glad_glTexParameterfv
GLAPI PFNGLVARIANTDVEXTPROC glad_glVariantdvEXT;
#define glVariantdvEXT glad_glVariantdvEXT
GLAPI PFNGLUNIFORM3DVPROC glad_glUniform3dv;
#define glUniform3dv glad_glUniform3dv
GLAPI PFNGLFOGCOORDHNVPROC glad_glFogCoordhNV;
#define glFogCoordhNV glad_glFogCoordhNV
GLAPI PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glad_glCompressedTexImage1DARB;
#define glCompressedTexImage1DARB glad_glCompressedTexImage1DARB
GLAPI PFNGLGETQUERYOBJECTUI64VPROC glad_glGetQueryObjectui64v;
#define glGetQueryObjectui64v glad_glGetQueryObjectui64v
GLAPI PFNGLVERTEXATTRIBL4UI64VNVPROC glad_glVertexAttribL4ui64vNV;
#define glVertexAttribL4ui64vNV glad_glVertexAttribL4ui64vNV
GLAPI PFNGLGETVIDEOIVNVPROC glad_glGetVideoivNV;
#define glGetVideoivNV glad_glGetVideoivNV
GLAPI PFNGLGETTEXTUREIMAGEPROC glad_glGetTextureImage;
#define glGetTextureImage glad_glGetTextureImage
GLAPI PFNGLPROGRAMUNIFORM1FVPROC glad_glProgramUniform1fv;
#define glProgramUniform1fv glad_glProgramUniform1fv
GLAPI PFNGLMULTIDRAWARRAYSEXTPROC glad_glMultiDrawArraysEXT;
#define glMultiDrawArraysEXT glad_glMultiDrawArraysEXT
GLAPI PFNGLACTIVESHADERPROGRAMPROC glad_glActiveShaderProgram;
#define glActiveShaderProgram glad_glActiveShaderProgram
GLAPI PFNGLPATHPARAMETERINVPROC glad_glPathParameteriNV;
#define glPathParameteriNV glad_glPathParameteriNV
GLAPI PFNGLCREATECOMMANDLISTSNVPROC glad_glCreateCommandListsNV;
#define glCreateCommandListsNV glad_glCreateCommandListsNV
GLAPI PFNGLCOPYCOLORSUBTABLEEXTPROC glad_glCopyColorSubTableEXT;
#define glCopyColorSubTableEXT glad_glCopyColorSubTableEXT
GLAPI PFNGLVARIANTSVEXTPROC glad_glVariantsvEXT;
#define glVariantsvEXT glad_glVariantsvEXT
GLAPI PFNGLGENPROGRAMPIPELINESPROC glad_glGenProgramPipelines;
#define glGenProgramPipelines glad_glGenProgramPipelines
GLAPI PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC glad_glVertexArrayEdgeFlagOffsetEXT;
#define glVertexArrayEdgeFlagOffsetEXT glad_glVertexArrayEdgeFlagOffsetEXT
GLAPI PFNGLUNIFORM4UIVEXTPROC glad_glUniform4uivEXT;
#define glUniform4uivEXT glad_glUniform4uivEXT
GLAPI PFNGLORTHOXOESPROC glad_glOrthoxOES;
#define glOrthoxOES glad_glOrthoxOES
GLAPI PFNGLUNIFORMSUBROUTINESUIVPROC glad_glUniformSubroutinesuiv;
#define glUniformSubroutinesuiv glad_glUniformSubroutinesuiv
GLAPI PFNGLVERTEXATTRIBI4UIEXTPROC glad_glVertexAttribI4uiEXT;
#define glVertexAttribI4uiEXT glad_glVertexAttribI4uiEXT
GLAPI PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC glad_glCompressedMultiTexSubImage1DEXT;
#define glCompressedMultiTexSubImage1DEXT glad_glCompressedMultiTexSubImage1DEXT
GLAPI PFNGLVERTEXATTRIB4NBVARBPROC glad_glVertexAttrib4NbvARB;
#define glVertexAttrib4NbvARB glad_glVertexAttrib4NbvARB
GLAPI PFNGLUNIFORM1UIVEXTPROC glad_glUniform1uivEXT;
#define glUniform1uivEXT glad_glUniform1uivEXT
GLAPI PFNGLMATRIXTRANSLATEFEXTPROC glad_glMatrixTranslatefEXT;
#define glMatrixTranslatefEXT glad_glMatrixTranslatefEXT
GLAPI PFNGLGETUNIFORMUIVEXTPROC glad_glGetUniformuivEXT;
#define glGetUniformuivEXT glad_glGetUniformuivEXT
GLAPI PFNGLFRAMEBUFFERTEXTUREEXTPROC glad_glFramebufferTextureEXT;
#define glFramebufferTextureEXT glad_glFramebufferTextureEXT
GLAPI PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC glad_glGetNamedProgramLocalParameterfvEXT;
#define glGetNamedProgramLocalParameterfvEXT glad_glGetNamedProgramLocalParameterfvEXT
GLAPI PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC glad_glColor4fNormal3fVertex3fvSUN;
#define glColor4fNormal3fVertex3fvSUN glad_glColor4fNormal3fVertex3fvSUN
GLAPI PFNGLSEPARABLEFILTER2DEXTPROC glad_glSeparableFilter2DEXT;
#define glSeparableFilter2DEXT glad_glSeparableFilter2DEXT
GLAPI PFNGLCLEARACCUMXOESPROC glad_glClearAccumxOES;
#define glClearAccumxOES glad_glClearAccumxOES
GLAPI PFNGLVERTEXATTRIBP1UIVPROC glad_glVertexAttribP1uiv;
#define glVertexAttribP1uiv glad_glVertexAttribP1uiv
GLAPI PFNGLINVALIDATEFRAMEBUFFERPROC glad_glInvalidateFramebuffer;
#define glInvalidateFramebuffer glad_glInvalidateFramebuffer
GLAPI PFNGLWEIGHTUBVARBPROC glad_glWeightubvARB;
#define glWeightubvARB glad_glWeightubvARB
GLAPI PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D;
#define glCompressedTexImage2D glad_glCompressedTexImage2D
GLAPI PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f;
#define glVertexAttrib1f glad_glVertexAttrib1f
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glad_glClearNamedFramebufferfi;
#define glClearNamedFramebufferfi glad_glClearNamedFramebufferfi
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glad_glClearNamedFramebufferfv;
#define glClearNamedFramebufferfv glad_glClearNamedFramebufferfv
GLAPI PFNGLVERTEXATTRIB1SPROC glad_glVertexAttrib1s;
#define glVertexAttrib1s glad_glVertexAttrib1s
GLAPI PFNGLNORMAL3HNVPROC glad_glNormal3hNV;
#define glNormal3hNV glad_glNormal3hNV
GLAPI PFNGLVARIANTUSVEXTPROC glad_glVariantusvEXT;
#define glVariantusvEXT glad_glVariantusvEXT
GLAPI PFNGLPROGRAMPARAMETER4DNVPROC glad_glProgramParameter4dNV;
#define glProgramParameter4dNV glad_glProgramParameter4dNV
GLAPI PFNGLCLEARBUFFERFVPROC glad_glClearBufferfv;
#define glClearBufferfv glad_glClearBufferfv
GLAPI PFNGLREPLACEMENTCODEUIVSUNPROC glad_glReplacementCodeuivSUN;
#define glReplacementCodeuivSUN glad_glReplacementCodeuivSUN
GLAPI PFNGLDELETEASYNCMARKERSSGIXPROC glad_glDeleteAsyncMarkersSGIX;
#define glDeleteAsyncMarkersSGIX glad_glDeleteAsyncMarkersSGIX
GLAPI PFNGLGETSHARPENTEXFUNCSGISPROC glad_glGetSharpenTexFuncSGIS;
#define glGetSharpenTexFuncSGIS glad_glGetSharpenTexFuncSGIS
GLAPI PFNGLIGLOOINTERFACESGIXPROC glad_glIglooInterfaceSGIX;
#define glIglooInterfaceSGIX glad_glIglooInterfaceSGIX
GLAPI PFNGLWINDOWPOS2DVARBPROC glad_glWindowPos2dvARB;
#define glWindowPos2dvARB glad_glWindowPos2dvARB
GLAPI PFNGLCLEARBUFFERFIPROC glad_glClearBufferfi;
#define glClearBufferfi glad_glClearBufferfi
GLAPI PFNGLENABLEVERTEXARRAYATTRIBPROC glad_glEnableVertexArrayAttrib;
#define glEnableVertexArrayAttrib glad_glEnableVertexArrayAttrib
GLAPI PFNGLGETSAMPLERPARAMETERIIVPROC glad_glGetSamplerParameterIiv;
#define glGetSamplerParameterIiv glad_glGetSamplerParameterIiv
GLAPI PFNGLGETQUERYBUFFEROBJECTI64VPROC glad_glGetQueryBufferObjecti64v;
#define glGetQueryBufferObjecti64v glad_glGetQueryBufferObjecti64v
GLAPI PFNGLFRAMETERMINATORGREMEDYPROC glad_glFrameTerminatorGREMEDY;
#define glFrameTerminatorGREMEDY glad_glFrameTerminatorGREMEDY
GLAPI PFNGLBLENDBARRIERKHRPROC glad_glBlendBarrierKHR;
#define glBlendBarrierKHR glad_glBlendBarrierKHR
GLAPI PFNGLUNIFORM1I64VNVPROC glad_glUniform1i64vNV;
#define glUniform1i64vNV glad_glUniform1i64vNV
GLAPI PFNGLVERTEXATTRIB2FVARBPROC glad_glVertexAttrib2fvARB;
#define glVertexAttrib2fvARB glad_glVertexAttrib2fvARB
GLAPI PFNGLPROGRAMUNIFORM2UIVPROC glad_glProgramUniform2uiv;
#define glProgramUniform2uiv glad_glProgramUniform2uiv
GLAPI PFNGLVERTEXATTRIBI4SVEXTPROC glad_glVertexAttribI4svEXT;
#define glVertexAttribI4svEXT glad_glVertexAttribI4svEXT
GLAPI PFNGLGETVARIANTARRAYOBJECTFVATIPROC glad_glGetVariantArrayObjectfvATI;
#define glGetVariantArrayObjectfvATI glad_glGetVariantArrayObjectfvATI
GLAPI PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv;
#define glGetQueryObjectuiv glad_glGetQueryObjectuiv
GLAPI PFNGLGETFRAGDATALOCATIONPROC glad_glGetFragDataLocation;
#define glGetFragDataLocation glad_glGetFragDataLocation
GLAPI PFNGLMULTITEXCOORD1SVARBPROC glad_glMultiTexCoord1svARB;
#define glMultiTexCoord1svARB glad_glMultiTexCoord1svARB
GLAPI PFNGLGETMAPXVOESPROC glad_glGetMapxvOES;
#define glGetMapxvOES glad_glGetMapxvOES
GLAPI PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC glad_glTextureStorage2DMultisampleEXT;
#define glTextureStorage2DMultisampleEXT glad_glTextureStorage2DMultisampleEXT
GLAPI PFNGLCOLORPOINTEREXTPROC glad_glColorPointerEXT;
#define glColorPointerEXT glad_glColorPointerEXT
GLAPI PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC glad_glCompressedTextureImage3DEXT;
#define glCompressedTextureImage3DEXT glad_glCompressedTextureImage3DEXT
GLAPI PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC glad_glGetVertexArrayIntegeri_vEXT;
#define glGetVertexArrayIntegeri_vEXT glad_glGetVertexArrayIntegeri_vEXT
GLAPI PFNGLGETMINMAXPARAMETERFVEXTPROC glad_glGetMinmaxParameterfvEXT;
#define glGetMinmaxParameterfvEXT glad_glGetMinmaxParameterfvEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glad_glProgramUniformMatrix2x3fv;
#define glProgramUniformMatrix2x3fv glad_glProgramUniformMatrix2x3fv
GLAPI PFNGLEDGEFLAGPOINTERLISTIBMPROC glad_glEdgeFlagPointerListIBM;
#define glEdgeFlagPointerListIBM glad_glEdgeFlagPointerListIBM
GLAPI PFNGLUSEPROGRAMOBJECTARBPROC glad_glUseProgramObjectARB;
#define glUseProgramObjectARB glad_glUseProgramObjectARB
GLAPI PFNGLGETTEXTUREPARAMETERIVPROC glad_glGetTextureParameteriv;
#define glGetTextureParameteriv glad_glGetTextureParameteriv
GLAPI PFNGLSHADEROP2EXTPROC glad_glShaderOp2EXT;
#define glShaderOp2EXT glad_glShaderOp2EXT
GLAPI PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glad_glNamedFramebufferParameteri;
#define glNamedFramebufferParameteri glad_glNamedFramebufferParameteri
GLAPI PFNGLBINORMAL3DEXTPROC glad_glBinormal3dEXT;
#define glBinormal3dEXT glad_glBinormal3dEXT
GLAPI PFNGLPROGRAMUNIFORM3UIPROC glad_glProgramUniform3ui;
#define glProgramUniform3ui glad_glProgramUniform3ui
GLAPI PFNGLMATRIXSCALEDEXTPROC glad_glMatrixScaledEXT;
#define glMatrixScaledEXT glad_glMatrixScaledEXT
GLAPI PFNGLUNMAPTEXTURE2DINTELPROC glad_glUnmapTexture2DINTEL;
#define glUnmapTexture2DINTEL glad_glUnmapTexture2DINTEL
GLAPI PFNGLGETVERTEXATTRIBIVARBPROC glad_glGetVertexAttribivARB;
#define glGetVertexAttribivARB glad_glGetVertexAttribivARB
GLAPI PFNGLGENERATEMIPMAPEXTPROC glad_glGenerateMipmapEXT;
#define glGenerateMipmapEXT glad_glGenerateMipmapEXT
GLAPI PFNGLVERTEXATTRIBI2UIVEXTPROC glad_glVertexAttribI2uivEXT;
#define glVertexAttribI2uivEXT glad_glVertexAttribI2uivEXT
GLAPI PFNGLPATHCOORDSNVPROC glad_glPathCoordsNV;
#define glPathCoordsNV glad_glPathCoordsNV
GLAPI PFNGLPROGRAMUNIFORM1IPROC glad_glProgramUniform1i;
#define glProgramUniform1i glad_glProgramUniform1i
GLAPI PFNGLPROGRAMUNIFORM1DPROC glad_glProgramUniform1d;
#define glProgramUniform1d glad_glProgramUniform1d
GLAPI PFNGLPROGRAMUNIFORM1FPROC glad_glProgramUniform1f;
#define glProgramUniform1f glad_glProgramUniform1f
GLAPI PFNGLPROGRAMPARAMETERIEXTPROC glad_glProgramParameteriEXT;
#define glProgramParameteriEXT glad_glProgramParameteriEXT
GLAPI PFNGLPROGRAMUNIFORM3IVPROC glad_glProgramUniform3iv;
#define glProgramUniform3iv glad_glProgramUniform3iv
GLAPI PFNGLMULTITEXCOORD4XVOESPROC glad_glMultiTexCoord4xvOES;
#define glMultiTexCoord4xvOES glad_glMultiTexCoord4xvOES
GLAPI PFNGLFRAMEBUFFERREADBUFFEREXTPROC glad_glFramebufferReadBufferEXT;
#define glFramebufferReadBufferEXT glad_glFramebufferReadBufferEXT
GLAPI PFNGLGENBUFFERSARBPROC glad_glGenBuffersARB;
#define glGenBuffersARB glad_glGenBuffersARB
GLAPI PFNGLFOGCOORDDEXTPROC glad_glFogCoorddEXT;
#define glFogCoorddEXT glad_glFogCoorddEXT
GLAPI PFNGLVERTEXATTRIB4FVNVPROC glad_glVertexAttrib4fvNV;
#define glVertexAttrib4fvNV glad_glVertexAttrib4fvNV
GLAPI PFNGLSECONDARYCOLORPOINTEREXTPROC glad_glSecondaryColorPointerEXT;
#define glSecondaryColorPointerEXT glad_glSecondaryColorPointerEXT
GLAPI PFNGLGETBUFFERSUBDATAARBPROC glad_glGetBufferSubDataARB;
#define glGetBufferSubDataARB glad_glGetBufferSubDataARB
GLAPI PFNGLGETPATHPARAMETERIVNVPROC glad_glGetPathParameterivNV;
#define glGetPathParameterivNV glad_glGetPathParameterivNV
GLAPI PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation;
#define glGetAttribLocation glad_glGetAttribLocation
GLAPI PFNGLDISABLEVERTEXARRAYATTRIBPROC glad_glDisableVertexArrayAttrib;
#define glDisableVertexArrayAttrib glad_glDisableVertexArrayAttrib
GLAPI PFNGLELEMENTPOINTERATIPROC glad_glElementPointerATI;
#define glElementPointerATI glad_glElementPointerATI
GLAPI PFNGLGETQUERYOBJECTUIVARBPROC glad_glGetQueryObjectuivARB;
#define glGetQueryObjectuivARB glad_glGetQueryObjectuivARB
GLAPI PFNGLVARIANTBVEXTPROC glad_glVariantbvEXT;
#define glVariantbvEXT glad_glVariantbvEXT
GLAPI PFNGLFOGXOESPROC glad_glFogxOES;
#define glFogxOES glad_glFogxOES
GLAPI PFNGLGETTEXIMAGEPROC glad_glGetTexImage;
#define glGetTexImage glad_glGetTexImage
GLAPI PFNGLCLEARDEPTHFOESPROC glad_glClearDepthfOES;
#define glClearDepthfOES glad_glClearDepthfOES
GLAPI PFNGLVERTEX4HNVPROC glad_glVertex4hNV;
#define glVertex4hNV glad_glVertex4hNV
GLAPI PFNGLPATHSUBCOORDSNVPROC glad_glPathSubCoordsNV;
#define glPathSubCoordsNV glad_glPathSubCoordsNV
GLAPI PFNGLPROGRAMSTRINGARBPROC glad_glProgramStringARB;
#define glProgramStringARB glad_glProgramStringARB
GLAPI PFNGLMATRIXINDEXUSVARBPROC glad_glMatrixIndexusvARB;
#define glMatrixIndexusvARB glad_glMatrixIndexusvARB
GLAPI PFNGLTEXPARAMETERIIVEXTPROC glad_glTexParameterIivEXT;
#define glTexParameterIivEXT glad_glTexParameterIivEXT
GLAPI PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC glad_glDispatchComputeGroupSizeARB;
#define glDispatchComputeGroupSizeARB glad_glDispatchComputeGroupSizeARB
GLAPI PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer;
#define glVertexAttribPointer glad_glVertexAttribPointer
GLAPI PFNGLDRAWBUFFERSATIPROC glad_glDrawBuffersATI;
#define glDrawBuffersATI glad_glDrawBuffersATI
GLAPI PFNGLAPPLYTEXTUREEXTPROC glad_glApplyTextureEXT;
#define glApplyTextureEXT glad_glApplyTextureEXT
GLAPI PFNGLGETFIXEDVOESPROC glad_glGetFixedvOES;
#define glGetFixedvOES glad_glGetFixedvOES
GLAPI PFNGLSAMPLEPATTERNEXTPROC glad_glSamplePatternEXT;
#define glSamplePatternEXT glad_glSamplePatternEXT
GLAPI PFNGLFOGCOORDDVEXTPROC glad_glFogCoorddvEXT;
#define glFogCoorddvEXT glad_glFogCoorddvEXT
GLAPI PFNGLPROGRAMUNIFORM1IVEXTPROC glad_glProgramUniform1ivEXT;
#define glProgramUniform1ivEXT glad_glProgramUniform1ivEXT
GLAPI PFNGLPROGRAMUNIFORM4UI64NVPROC glad_glProgramUniform4ui64NV;
#define glProgramUniform4ui64NV glad_glProgramUniform4ui64NV
GLAPI PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC glad_glNamedFramebufferParameteriEXT;
#define glNamedFramebufferParameteriEXT glad_glNamedFramebufferParameteriEXT
GLAPI PFNGLVERTEXATTRIBP1UIPROC glad_glVertexAttribP1ui;
#define glVertexAttribP1ui glad_glVertexAttribP1ui
GLAPI PFNGLPROGRAMUNIFORM4DVEXTPROC glad_glProgramUniform4dvEXT;
#define glProgramUniform4dvEXT glad_glProgramUniform4dvEXT
GLAPI PFNGLENDTRANSFORMFEEDBACKEXTPROC glad_glEndTransformFeedbackEXT;
#define glEndTransformFeedbackEXT glad_glEndTransformFeedbackEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glad_glProgramUniformMatrix3x4dv;
#define glProgramUniformMatrix3x4dv glad_glProgramUniformMatrix3x4dv
GLAPI PFNGLREPLACEMENTCODEUBSUNPROC glad_glReplacementCodeubSUN;
#define glReplacementCodeubSUN glad_glReplacementCodeubSUN
GLAPI PFNGLBINDBUFFERSRANGEPROC glad_glBindBuffersRange;
#define glBindBuffersRange glad_glBindBuffersRange
GLAPI PFNGLFINISHASYNCSGIXPROC glad_glFinishAsyncSGIX;
#define glFinishAsyncSGIX glad_glFinishAsyncSGIX
GLAPI PFNGLUNIFORM2IVPROC glad_glUniform2iv;
#define glUniform2iv glad_glUniform2iv
GLAPI PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC glad_glGetNamedBufferParameterivEXT;
#define glGetNamedBufferParameterivEXT glad_glGetNamedBufferParameterivEXT
GLAPI PFNGLGETPERFMONITORCOUNTERSAMDPROC glad_glGetPerfMonitorCountersAMD;
#define glGetPerfMonitorCountersAMD glad_glGetPerfMonitorCountersAMD
GLAPI PFNGLGENQUERIESARBPROC glad_glGenQueriesARB;
#define glGenQueriesARB glad_glGenQueriesARB
GLAPI PFNGLPROGRAMUNIFORM2UI64NVPROC glad_glProgramUniform2ui64NV;
#define glProgramUniform2ui64NV glad_glProgramUniform2ui64NV
GLAPI PFNGLACTIVESTENCILFACEEXTPROC glad_glActiveStencilFaceEXT;
#define glActiveStencilFaceEXT glad_glActiveStencilFaceEXT
GLAPI PFNGLMULTITEXCOORD3BOESPROC glad_glMultiTexCoord3bOES;
#define glMultiTexCoord3bOES glad_glMultiTexCoord3bOES
GLAPI PFNGLUNIFORM1DVPROC glad_glUniform1dv;
#define glUniform1dv glad_glUniform1dv
GLAPI PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv;
#define glVertexAttrib1fv glad_glVertexAttrib1fv
GLAPI PFNGLPROGRAMENVPARAMETERI4UIVNVPROC glad_glProgramEnvParameterI4uivNV;
#define glProgramEnvParameterI4uivNV glad_glProgramEnvParameterI4uivNV
GLAPI PFNGLWINDOWPOS4DMESAPROC glad_glWindowPos4dMESA;
#define glWindowPos4dMESA glad_glWindowPos4dMESA
GLAPI PFNGLDEBUGMESSAGECONTROLARBPROC glad_glDebugMessageControlARB;
#define glDebugMessageControlARB glad_glDebugMessageControlARB
GLAPI PFNGLGETFRAGMENTLIGHTIVSGIXPROC glad_glGetFragmentLightivSGIX;
#define glGetFragmentLightivSGIX glad_glGetFragmentLightivSGIX
GLAPI PFNGLISTEXTUREEXTPROC glad_glIsTextureEXT;
#define glIsTextureEXT glad_glIsTextureEXT
GLAPI PFNGLLINKPROGRAMARBPROC glad_glLinkProgramARB;
#define glLinkProgramARB glad_glLinkProgramARB
GLAPI PFNGLFINISHFENCEAPPLEPROC glad_glFinishFenceAPPLE;
#define glFinishFenceAPPLE glad_glFinishFenceAPPLE
GLAPI PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D;
#define glCompressedTexImage3D glad_glCompressedTexImage3D
GLAPI PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC glad_glGetProgramLocalParameterIuivNV;
#define glGetProgramLocalParameterIuivNV glad_glGetProgramLocalParameterIuivNV
GLAPI PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv;
#define glGetVertexAttribiv glad_glGetVertexAttribiv
GLAPI PFNGLGETPOINTERINDEXEDVEXTPROC glad_glGetPointerIndexedvEXT;
#define glGetPointerIndexedvEXT glad_glGetPointerIndexedvEXT
GLAPI PFNGLVERTEXATTRIB2SVNVPROC glad_glVertexAttrib2svNV;
#define glVertexAttrib2svNV glad_glVertexAttrib2svNV
GLAPI PFNGLWINDOWPOS4SMESAPROC glad_glWindowPos4sMESA;
#define glWindowPos4sMESA glad_glWindowPos4sMESA
GLAPI PFNGLVDPAUMAPSURFACESNVPROC glad_glVDPAUMapSurfacesNV;
#define glVDPAUMapSurfacesNV glad_glVDPAUMapSurfacesNV
GLAPI PFNGLGETVERTEXATTRIBPOINTERVNVPROC glad_glGetVertexAttribPointervNV;
#define glGetVertexAttribPointervNV glad_glGetVertexAttribPointervNV
GLAPI PFNGLBINDPARAMETEREXTPROC glad_glBindParameterEXT;
#define glBindParameterEXT glad_glBindParameterEXT
GLAPI PFNGLUNIFORM4FVARBPROC glad_glUniform4fvARB;
#define glUniform4fvARB glad_glUniform4fvARB
GLAPI PFNGLGETTRACKMATRIXIVNVPROC glad_glGetTrackMatrixivNV;
#define glGetTrackMatrixivNV glad_glGetTrackMatrixivNV
GLAPI PFNGLISNAMEDBUFFERRESIDENTNVPROC glad_glIsNamedBufferResidentNV;
#define glIsNamedBufferResidentNV glad_glIsNamedBufferResidentNV
GLAPI PFNGLCOVERFILLPATHNVPROC glad_glCoverFillPathNV;
#define glCoverFillPathNV glad_glCoverFillPathNV
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC glad_glNamedProgramLocalParameterI4uivEXT;
#define glNamedProgramLocalParameterI4uivEXT glad_glNamedProgramLocalParameterI4uivEXT
GLAPI PFNGLMEMORYBARRIEREXTPROC glad_glMemoryBarrierEXT;
#define glMemoryBarrierEXT glad_glMemoryBarrierEXT
GLAPI PFNGLGETNAMEDBUFFERSUBDATAPROC glad_glGetNamedBufferSubData;
#define glGetNamedBufferSubData glad_glGetNamedBufferSubData
GLAPI PFNGLSETFENCENVPROC glad_glSetFenceNV;
#define glSetFenceNV glad_glSetFenceNV
GLAPI PFNGLINVALIDATETEXIMAGEPROC glad_glInvalidateTexImage;
#define glInvalidateTexImage glad_glInvalidateTexImage
GLAPI PFNGLVERTEXATTRIBI4USVEXTPROC glad_glVertexAttribI4usvEXT;
#define glVertexAttribI4usvEXT glad_glVertexAttribI4usvEXT
GLAPI PFNGLISPATHNVPROC glad_glIsPathNV;
#define glIsPathNV glad_glIsPathNV
GLAPI PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC glad_glCompressedMultiTexSubImage2DEXT;
#define glCompressedMultiTexSubImage2DEXT glad_glCompressedMultiTexSubImage2DEXT
GLAPI PFNGLDEBUGMESSAGECALLBACKPROC glad_glDebugMessageCallback;
#define glDebugMessageCallback glad_glDebugMessageCallback
GLAPI PFNGLTANGENT3SVEXTPROC glad_glTangent3svEXT;
#define glTangent3svEXT glad_glTangent3svEXT
GLAPI PFNGLVERTEXATTRIBPARAMETERIAMDPROC glad_glVertexAttribParameteriAMD;
#define glVertexAttribParameteriAMD glad_glVertexAttribParameteriAMD
GLAPI PFNGLUNIFORMHANDLEUI64ARBPROC glad_glUniformHandleui64ARB;
#define glUniformHandleui64ARB glad_glUniformHandleui64ARB
GLAPI PFNGLGETPATHMETRICSNVPROC glad_glGetPathMetricsNV;
#define glGetPathMetricsNV glad_glGetPathMetricsNV
GLAPI PFNGLGETBOOLEANI_VPROC glad_glGetBooleani_v;
#define glGetBooleani_v glad_glGetBooleani_v
GLAPI PFNGLVERTEXSTREAM3DVATIPROC glad_glVertexStream3dvATI;
#define glVertexStream3dvATI glad_glVertexStream3dvATI
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC glad_glVertexArrayVertexAttribIFormatEXT;
#define glVertexArrayVertexAttribIFormatEXT glad_glVertexArrayVertexAttribIFormatEXT
GLAPI PFNGLHINTPROC glad_glHint;
#define glHint glad_glHint
GLAPI PFNGLPOINTALONGPATHNVPROC glad_glPointAlongPathNV;
#define glPointAlongPathNV glad_glPointAlongPathNV
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTPROC glad_glMultiDrawArraysIndirect;
#define glMultiDrawArraysIndirect glad_glMultiDrawArraysIndirect
GLAPI PFNGLVERTEXATTRIBP2UIVPROC glad_glVertexAttribP2uiv;
#define glVertexAttribP2uiv glad_glVertexAttribP2uiv
GLAPI PFNGLFRAMEBUFFERTEXTUREARBPROC glad_glFramebufferTextureARB;
#define glFramebufferTextureARB glad_glFramebufferTextureARB
GLAPI PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC glad_glPushClientAttribDefaultEXT;
#define glPushClientAttribDefaultEXT glad_glPushClientAttribDefaultEXT
GLAPI PFNGLGETPROGRAMRESOURCENAMEPROC glad_glGetProgramResourceName;
#define glGetProgramResourceName glad_glGetProgramResourceName
GLAPI PFNGLCOVERFILLPATHINSTANCEDNVPROC glad_glCoverFillPathInstancedNV;
#define glCoverFillPathInstancedNV glad_glCoverFillPathInstancedNV
GLAPI PFNGLMULTITEXPARAMETERIVEXTPROC glad_glMultiTexParameterivEXT;
#define glMultiTexParameterivEXT glad_glMultiTexParameterivEXT
GLAPI PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glad_glGetActiveAtomicCounterBufferiv;
#define glGetActiveAtomicCounterBufferiv glad_glGetActiveAtomicCounterBufferiv
GLAPI PFNGLGETCOLORTABLEPARAMETERIVSGIPROC glad_glGetColorTableParameterivSGI;
#define glGetColorTableParameterivSGI glad_glGetColorTableParameterivSGI
GLAPI PFNGLPROGRAMPARAMETERS4DVNVPROC glad_glProgramParameters4dvNV;
#define glProgramParameters4dvNV glad_glProgramParameters4dvNV
GLAPI PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv;
#define glGetTexParameteriv glad_glGetTexParameteriv
GLAPI PFNGLGETUNIFORMOFFSETEXTPROC glad_glGetUniformOffsetEXT;
#define glGetUniformOffsetEXT glad_glGetUniformOffsetEXT
GLAPI PFNGLPROGRAMUNIFORM1DVPROC glad_glProgramUniform1dv;
#define glProgramUniform1dv glad_glProgramUniform1dv
GLAPI PFNGLPROGRAMUNIFORM3I64VNVPROC glad_glProgramUniform3i64vNV;
#define glProgramUniform3i64vNV glad_glProgramUniform3i64vNV
GLAPI PFNGLTANGENT3FEXTPROC glad_glTangent3fEXT;
#define glTangent3fEXT glad_glTangent3fEXT
GLAPI PFNGLGETPATHMETRICRANGENVPROC glad_glGetPathMetricRangeNV;
#define glGetPathMetricRangeNV glad_glGetPathMetricRangeNV
GLAPI PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC glad_glReplacementCodeuiVertex3fSUN;
#define glReplacementCodeuiVertex3fSUN glad_glReplacementCodeuiVertex3fSUN
GLAPI PFNGLWINDOWPOS3FARBPROC glad_glWindowPos3fARB;
#define glWindowPos3fARB glad_glWindowPos3fARB
GLAPI PFNGLMAPNAMEDBUFFEREXTPROC glad_glMapNamedBufferEXT;
#define glMapNamedBufferEXT glad_glMapNamedBufferEXT
GLAPI PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glad_glFramebufferRenderbufferEXT;
#define glFramebufferRenderbufferEXT glad_glFramebufferRenderbufferEXT
GLAPI PFNGLBINORMAL3SVEXTPROC glad_glBinormal3svEXT;
#define glBinormal3svEXT glad_glBinormal3svEXT
GLAPI PFNGLCOPYTEXTURESUBIMAGE2DPROC glad_glCopyTextureSubImage2D;
#define glCopyTextureSubImage2D glad_glCopyTextureSubImage2D
GLAPI PFNGLGETPROGRAMRESOURCEFVNVPROC glad_glGetProgramResourcefvNV;
#define glGetProgramResourcefvNV glad_glGetProgramResourcefvNV
GLAPI PFNGLBINORMALPOINTEREXTPROC glad_glBinormalPointerEXT;
#define glBinormalPointerEXT glad_glBinormalPointerEXT
GLAPI PFNGLEXTRACTCOMPONENTEXTPROC glad_glExtractComponentEXT;
#define glExtractComponentEXT glad_glExtractComponentEXT
GLAPI PFNGLUNIFORM2IVARBPROC glad_glUniform2ivARB;
#define glUniform2ivARB glad_glUniform2ivARB
GLAPI PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glad_glGetVertexAttribArrayObjectfvATI;
#define glGetVertexAttribArrayObjectfvATI glad_glGetVertexAttribArrayObjectfvATI
GLAPI PFNGLOBJECTPURGEABLEAPPLEPROC glad_glObjectPurgeableAPPLE;
#define glObjectPurgeableAPPLE glad_glObjectPurgeableAPPLE
GLAPI PFNGLCOLORTABLESGIPROC glad_glColorTableSGI;
#define glColorTableSGI glad_glColorTableSGI
GLAPI PFNGLPROGRAMUNIFORM1FEXTPROC glad_glProgramUniform1fEXT;
#define glProgramUniform1fEXT glad_glProgramUniform1fEXT
GLAPI PFNGLWINDOWPOS2FVMESAPROC glad_glWindowPos2fvMESA;
#define glWindowPos2fvMESA glad_glWindowPos2fvMESA
GLAPI PFNGLPOLYGONOFFSETXOESPROC glad_glPolygonOffsetxOES;
#define glPolygonOffsetxOES glad_glPolygonOffsetxOES
GLAPI PFNGLUNIFORMHANDLEUI64VARBPROC glad_glUniformHandleui64vARB;
#define glUniformHandleui64vARB glad_glUniformHandleui64vARB
GLAPI PFNGLFRAGMENTLIGHTMODELFVSGIXPROC glad_glFragmentLightModelfvSGIX;
#define glFragmentLightModelfvSGIX glad_glFragmentLightModelfvSGIX
GLAPI PFNGLBINDFRAGMENTSHADERATIPROC glad_glBindFragmentShaderATI;
#define glBindFragmentShaderATI glad_glBindFragmentShaderATI
GLAPI PFNGLLISTPARAMETERFVSGIXPROC glad_glListParameterfvSGIX;
#define glListParameterfvSGIX glad_glListParameterfvSGIX
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glNamedRenderbufferStorageMultisample;
#define glNamedRenderbufferStorageMultisample glad_glNamedRenderbufferStorageMultisample
GLAPI PFNGLCOLOR3XOESPROC glad_glColor3xOES;
#define glColor3xOES glad_glColor3xOES
GLAPI PFNGLSTENCILFILLPATHINSTANCEDNVPROC glad_glStencilFillPathInstancedNV;
#define glStencilFillPathInstancedNV glad_glStencilFillPathInstancedNV
GLAPI PFNGLISQUERYPROC glad_glIsQuery;
#define glIsQuery glad_glIsQuery
GLAPI PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC glad_glProgramUniformMatrix4fvEXT;
#define glProgramUniformMatrix4fvEXT glad_glProgramUniformMatrix4fvEXT
GLAPI PFNGLVERTEXATTRIB3HNVPROC glad_glVertexAttrib3hNV;
#define glVertexAttrib3hNV glad_glVertexAttrib3hNV
GLAPI PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glad_glFlushMappedNamedBufferRange;
#define glFlushMappedNamedBufferRange glad_glFlushMappedNamedBufferRange
GLAPI PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f;
#define glVertexAttrib3f glad_glVertexAttrib3f
GLAPI PFNGLVERTEXATTRIB3DPROC glad_glVertexAttrib3d;
#define glVertexAttrib3d glad_glVertexAttrib3d
GLAPI PFNGLBLENDCOLORPROC glad_glBlendColor;
#define glBlendColor glad_glBlendColor
GLAPI PFNGLSAMPLERPARAMETERIUIVPROC glad_glSamplerParameterIuiv;
#define glSamplerParameterIuiv glad_glSamplerParameterIuiv
GLAPI PFNGLVERTEXATTRIB3SPROC glad_glVertexAttrib3s;
#define glVertexAttrib3s glad_glVertexAttrib3s
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC glad_glNamedProgramLocalParameterI4iEXT;
#define glNamedProgramLocalParameterI4iEXT glad_glNamedProgramLocalParameterI4iEXT
GLAPI PFNGLGETMATERIALXOESPROC glad_glGetMaterialxOES;
#define glGetMaterialxOES glad_glGetMaterialxOES
GLAPI PFNGLTANGENT3BEXTPROC glad_glTangent3bEXT;
#define glTangent3bEXT glad_glTangent3bEXT
GLAPI PFNGLGETGRAPHICSRESETSTATUSARBPROC glad_glGetGraphicsResetStatusARB;
#define glGetGraphicsResetStatusARB glad_glGetGraphicsResetStatusARB
GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray;
#define glEnableVertexAttribArray glad_glEnableVertexAttribArray
GLAPI PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC glad_glProgramUniformHandleui64NV;
#define glProgramUniformHandleui64NV glad_glProgramUniformHandleui64NV
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex;
#define glDrawElementsInstancedBaseVertex glad_glDrawElementsInstancedBaseVertex
GLAPI PFNGLDRAWTRANSFORMFEEDBACKNVPROC glad_glDrawTransformFeedbackNV;
#define glDrawTransformFeedbackNV glad_glDrawTransformFeedbackNV
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC glad_glNamedRenderbufferStorageMultisampleCoverageEXT;
#define glNamedRenderbufferStorageMultisampleCoverageEXT glad_glNamedRenderbufferStorageMultisampleCoverageEXT
GLAPI PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding;
#define glUniformBlockBinding glad_glUniformBlockBinding
GLAPI PFNGLWINDOWPOS2SVMESAPROC glad_glWindowPos2svMESA;
#define glWindowPos2svMESA glad_glWindowPos2svMESA
GLAPI PFNGLFRAMEBUFFERTEXTURE3DEXTPROC glad_glFramebufferTexture3DEXT;
#define glFramebufferTexture3DEXT glad_glFramebufferTexture3DEXT
GLAPI PFNGLLOADTRANSPOSEMATRIXXOESPROC glad_glLoadTransposeMatrixxOES;
#define glLoadTransposeMatrixxOES glad_glLoadTransposeMatrixxOES
GLAPI PFNGLDELETETRANSFORMFEEDBACKSNVPROC glad_glDeleteTransformFeedbacksNV;
#define glDeleteTransformFeedbacksNV glad_glDeleteTransformFeedbacksNV
GLAPI PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glad_glFramebufferTexture2DEXT;
#define glFramebufferTexture2DEXT glad_glFramebufferTexture2DEXT
GLAPI PFNGLENDTRANSFORMFEEDBACKNVPROC glad_glEndTransformFeedbackNV;
#define glEndTransformFeedbackNV glad_glEndTransformFeedbackNV
GLAPI PFNGLNAMEDBUFFERSUBDATAEXTPROC glad_glNamedBufferSubDataEXT;
#define glNamedBufferSubDataEXT glad_glNamedBufferSubDataEXT
GLAPI PFNGLFLUSHRASTERSGIXPROC glad_glFlushRasterSGIX;
#define glFlushRasterSGIX glad_glFlushRasterSGIX
GLAPI PFNGLCREATEPROGRAMPROC glad_glCreateProgram;
#define glCreateProgram glad_glCreateProgram
GLAPI PFNGLBLENDEQUATIONSEPARATEEXTPROC glad_glBlendEquationSeparateEXT;
#define glBlendEquationSeparateEXT glad_glBlendEquationSeparateEXT
GLAPI PFNGLPRIMITIVERESTARTINDEXPROC glad_glPrimitiveRestartIndex;
#define glPrimitiveRestartIndex glad_glPrimitiveRestartIndex
GLAPI PFNGLNORMALSTREAM3FATIPROC glad_glNormalStream3fATI;
#define glNormalStream3fATI glad_glNormalStream3fATI
GLAPI PFNGLUNIFORM1I64NVPROC glad_glUniform1i64NV;
#define glUniform1i64NV glad_glUniform1i64NV
GLAPI PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC glad_glGetProgramNamedParameterdvNV;
#define glGetProgramNamedParameterdvNV glad_glGetProgramNamedParameterdvNV
GLAPI PFNGLUNIFORM3UIVPROC glad_glUniform3uiv;
#define glUniform3uiv glad_glUniform3uiv
GLAPI PFNGLCOLOR3FVERTEX3FVSUNPROC glad_glColor3fVertex3fvSUN;
#define glColor3fVertex3fvSUN glad_glColor3fVertex3fvSUN
GLAPI PFNGLTANGENT3DEXTPROC glad_glTangent3dEXT;
#define glTangent3dEXT glad_glTangent3dEXT
GLAPI PFNGLGETQUERYOBJECTIVARBPROC glad_glGetQueryObjectivARB;
#define glGetQueryObjectivARB glad_glGetQueryObjectivARB
GLAPI PFNGLUSESHADERPROGRAMEXTPROC glad_glUseShaderProgramEXT;
#define glUseShaderProgramEXT glad_glUseShaderProgramEXT
GLAPI PFNGLBINDRENDERBUFFEREXTPROC glad_glBindRenderbufferEXT;
#define glBindRenderbufferEXT glad_glBindRenderbufferEXT
GLAPI PFNGLGETNUNIFORMIVPROC glad_glGetnUniformiv;
#define glGetnUniformiv glad_glGetnUniformiv
GLAPI PFNGLGETPERFMONITORGROUPSTRINGAMDPROC glad_glGetPerfMonitorGroupStringAMD;
#define glGetPerfMonitorGroupStringAMD glad_glGetPerfMonitorGroupStringAMD
GLAPI PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC glad_glGetNamedProgramLocalParameterdvEXT;
#define glGetNamedProgramLocalParameterdvEXT glad_glGetNamedProgramLocalParameterdvEXT
GLAPI PFNGLMULTITEXCOORD3XOESPROC glad_glMultiTexCoord3xOES;
#define glMultiTexCoord3xOES glad_glMultiTexCoord3xOES
GLAPI PFNGLDRAWELEMENTSINDIRECTPROC glad_glDrawElementsIndirect;
#define glDrawElementsIndirect glad_glDrawElementsIndirect
GLAPI PFNGLGETVARIANTARRAYOBJECTIVATIPROC glad_glGetVariantArrayObjectivATI;
#define glGetVariantArrayObjectivATI glad_glGetVariantArrayObjectivATI
GLAPI PFNGLVERTEXATTRIB1DARBPROC glad_glVertexAttrib1dARB;
#define glVertexAttrib1dARB glad_glVertexAttrib1dARB
GLAPI PFNGLGETNAMEDBUFFERPOINTERVPROC glad_glGetNamedBufferPointerv;
#define glGetNamedBufferPointerv glad_glGetNamedBufferPointerv
GLAPI PFNGLVERTEXATTRIB1DPROC glad_glVertexAttrib1d;
#define glVertexAttrib1d glad_glVertexAttrib1d
GLAPI PFNGLGENASYNCMARKERSSGIXPROC glad_glGenAsyncMarkersSGIX;
#define glGenAsyncMarkersSGIX glad_glGenAsyncMarkersSGIX
GLAPI PFNGLGETQUERYBUFFEROBJECTUI64VPROC glad_glGetQueryBufferObjectui64v;
#define glGetQueryBufferObjectui64v glad_glGetQueryBufferObjectui64v
GLAPI PFNGLSETMULTISAMPLEFVAMDPROC glad_glSetMultisamplefvAMD;
#define glSetMultisamplefvAMD glad_glSetMultisamplefvAMD
GLAPI PFNGLGENTRANSFORMFEEDBACKSPROC glad_glGenTransformFeedbacks;
#define glGenTransformFeedbacks glad_glGenTransformFeedbacks
GLAPI PFNGLPIXELTRANSFORMPARAMETERFEXTPROC glad_glPixelTransformParameterfEXT;
#define glPixelTransformParameterfEXT glad_glPixelTransformParameterfEXT
GLAPI PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC glad_glVertexArraySecondaryColorOffsetEXT;
#define glVertexArraySecondaryColorOffsetEXT glad_glVertexArraySecondaryColorOffsetEXT
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D;
#define glCompressedTexSubImage2D glad_glCompressedTexSubImage2D
GLAPI PFNGLPROGRAMBINARYPROC glad_glProgramBinary;
#define glProgramBinary glad_glProgramBinary
GLAPI PFNGLVERTEXATTRIBI4BVPROC glad_glVertexAttribI4bv;
#define glVertexAttribI4bv glad_glVertexAttribI4bv
GLAPI PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glad_glTextureStorage2DMultisample;
#define glTextureStorage2DMultisample glad_glTextureStorage2DMultisample
GLAPI PFNGLINDEXXVOESPROC glad_glIndexxvOES;
#define glIndexxvOES glad_glIndexxvOES
GLAPI PFNGLSECONDARYCOLOR3USEXTPROC glad_glSecondaryColor3usEXT;
#define glSecondaryColor3usEXT glad_glSecondaryColor3usEXT
GLAPI PFNGLGETPOINTERVEXTPROC glad_glGetPointervEXT;
#define glGetPointervEXT glad_glGetPointervEXT
GLAPI PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC glad_glDrawCommandsStatesAddressNV;
#define glDrawCommandsStatesAddressNV glad_glDrawCommandsStatesAddressNV
GLAPI PFNGLUNIFORM4UI64NVPROC glad_glUniform4ui64NV;
#define glUniform4ui64NV glad_glUniform4ui64NV
GLAPI PFNGLVERTEXATTRIB4USVPROC glad_glVertexAttrib4usv;
#define glVertexAttrib4usv glad_glVertexAttrib4usv
GLAPI PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC glad_glBlendFuncSeparateIndexedAMD;
#define glBlendFuncSeparateIndexedAMD glad_glBlendFuncSeparateIndexedAMD
GLAPI PFNGLVERTEXATTRIBI1IVPROC glad_glVertexAttribI1iv;
#define glVertexAttribI1iv glad_glVertexAttribI1iv
GLAPI PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glad_glGetFinalCombinerInputParameterfvNV;
#define glGetFinalCombinerInputParameterfvNV glad_glGetFinalCombinerInputParameterfvNV
GLAPI PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glad_glGetCompressedTextureImage;
#define glGetCompressedTextureImage glad_glGetCompressedTextureImage
GLAPI PFNGLTEXTUREIMAGE2DEXTPROC glad_glTextureImage2DEXT;
#define glTextureImage2DEXT glad_glTextureImage2DEXT
GLAPI PFNGLVERTEXATTRIBI1UIVPROC glad_glVertexAttribI1uiv;
#define glVertexAttribI1uiv glad_glVertexAttribI1uiv
GLAPI PFNGLTEXCOORD4XOESPROC glad_glTexCoord4xOES;
#define glTexCoord4xOES glad_glTexCoord4xOES
GLAPI PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv;
#define glUniformMatrix4x2fv glad_glUniformMatrix4x2fv
GLAPI PFNGLMAPBUFFERRANGEPROC glad_glMapBufferRange;
#define glMapBufferRange glad_glMapBufferRange
GLAPI PFNGLGETTEXTUREPARAMETERIIVEXTPROC glad_glGetTextureParameterIivEXT;
#define glGetTextureParameterIivEXT glad_glGetTextureParameterIivEXT
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC glad_glNamedProgramLocalParametersI4uivEXT;
#define glNamedProgramLocalParametersI4uivEXT glad_glNamedProgramLocalParametersI4uivEXT
GLAPI PFNGLVERTEXATTRIBI2IVPROC glad_glVertexAttribI2iv;
#define glVertexAttribI2iv glad_glVertexAttribI2iv
GLAPI PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC glad_glTexImage3DMultisampleCoverageNV;
#define glTexImage3DMultisampleCoverageNV glad_glTexImage3DMultisampleCoverageNV
GLAPI PFNGLTEXSUBIMAGE4DSGISPROC glad_glTexSubImage4DSGIS;
#define glTexSubImage4DSGIS glad_glTexSubImage4DSGIS
GLAPI PFNGLTEXTUREVIEWPROC glad_glTextureView;
#define glTextureView glad_glTextureView
GLAPI PFNGLEVALMAPSNVPROC glad_glEvalMapsNV;
#define glEvalMapsNV glad_glEvalMapsNV
GLAPI PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC glad_glGetCompressedMultiTexImageEXT;
#define glGetCompressedMultiTexImageEXT glad_glGetCompressedMultiTexImageEXT
GLAPI PFNGLDRAWBUFFERSARBPROC glad_glDrawBuffersARB;
#define glDrawBuffersARB glad_glDrawBuffersARB
GLAPI PFNGLSHADERSOURCEPROC glad_glShaderSource;
#define glShaderSource glad_glShaderSource
GLAPI PFNGLTEXTUREPARAMETERIIVEXTPROC glad_glTextureParameterIivEXT;
#define glTextureParameterIivEXT glad_glTextureParameterIivEXT
GLAPI PFNGLMULTITEXPARAMETERFVEXTPROC glad_glMultiTexParameterfvEXT;
#define glMultiTexParameterfvEXT glad_glMultiTexParameterfvEXT
GLAPI PFNGLNEWOBJECTBUFFERATIPROC glad_glNewObjectBufferATI;
#define glNewObjectBufferATI glad_glNewObjectBufferATI
GLAPI PFNGLVIEWPORTSWIZZLENVPROC glad_glViewportSwizzleNV;
#define glViewportSwizzleNV glad_glViewportSwizzleNV
GLAPI PFNGLROTATEXOESPROC glad_glRotatexOES;
#define glRotatexOES glad_glRotatexOES
GLAPI PFNGLTEXTUREIMAGE1DEXTPROC glad_glTextureImage1DEXT;
#define glTextureImage1DEXT glad_glTextureImage1DEXT
GLAPI PFNGLATTACHOBJECTARBPROC glad_glAttachObjectARB;
#define glAttachObjectARB glad_glAttachObjectARB
GLAPI PFNGLCOPYTEXSUBIMAGE1DEXTPROC glad_glCopyTexSubImage1DEXT;
#define glCopyTexSubImage1DEXT glad_glCopyTexSubImage1DEXT
GLAPI PFNGLUNIFORMMATRIX3FVARBPROC glad_glUniformMatrix3fvARB;
#define glUniformMatrix3fvARB glad_glUniformMatrix3fvARB
GLAPI PFNGLPOINTPARAMETERFVEXTPROC glad_glPointParameterfvEXT;
#define glPointParameterfvEXT glad_glPointParameterfvEXT
GLAPI PFNGLUNIFORM4FARBPROC glad_glUniform4fARB;
#define glUniform4fARB glad_glUniform4fARB
GLAPI PFNGLCOPYTEXTURESUBIMAGE3DPROC glad_glCopyTextureSubImage3D;
#define glCopyTextureSubImage3D glad_glCopyTextureSubImage3D
GLAPI PFNGLMULTITEXENVFVEXTPROC glad_glMultiTexEnvfvEXT;
#define glMultiTexEnvfvEXT glad_glMultiTexEnvfvEXT
GLAPI PFNGLVERTEXATTRIB4SNVPROC glad_glVertexAttrib4sNV;
#define glVertexAttrib4sNV glad_glVertexAttrib4sNV
GLAPI PFNGLVERTEXATTRIBI1IPROC glad_glVertexAttribI1i;
#define glVertexAttribI1i glad_glVertexAttribI1i
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC glad_glNamedProgramLocalParameters4fvEXT;
#define glNamedProgramLocalParameters4fvEXT glad_glNamedProgramLocalParameters4fvEXT
GLAPI PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC glad_glCopyConvolutionFilter2DEXT;
#define glCopyConvolutionFilter2DEXT glad_glCopyConvolutionFilter2DEXT
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC glad_glCompressedTextureSubImage2DEXT;
#define glCompressedTextureSubImage2DEXT glad_glCompressedTextureSubImage2DEXT
GLAPI PFNGLSAMPLERPARAMETERFVPROC glad_glSamplerParameterfv;
#define glSamplerParameterfv glad_glSamplerParameterfv
GLAPI PFNGLBINDBUFFERARBPROC glad_glBindBufferARB;
#define glBindBufferARB glad_glBindBufferARB
GLAPI PFNGLVERTEXATTRIB1SNVPROC glad_glVertexAttrib1sNV;
#define glVertexAttrib1sNV glad_glVertexAttrib1sNV
GLAPI PFNGLUNIFORM1FVPROC glad_glUniform1fv;
#define glUniform1fv glad_glUniform1fv
GLAPI PFNGLDEPTHRANGEDNVPROC glad_glDepthRangedNV;
#define glDepthRangedNV glad_glDepthRangedNV
GLAPI PFNGLNORMALPOINTERVINTELPROC glad_glNormalPointervINTEL;
#define glNormalPointervINTEL glad_glNormalPointervINTEL
GLAPI PFNGLGETOBJECTPARAMETERIVAPPLEPROC glad_glGetObjectParameterivAPPLE;
#define glGetObjectParameterivAPPLE glad_glGetObjectParameterivAPPLE
GLAPI PFNGLGETUNIFORMBUFFERSIZEEXTPROC glad_glGetUniformBufferSizeEXT;
#define glGetUniformBufferSizeEXT glad_glGetUniformBufferSizeEXT
GLAPI PFNGLPROGRAMUNIFORM3I64ARBPROC glad_glProgramUniform3i64ARB;
#define glProgramUniform3i64ARB glad_glProgramUniform3i64ARB
GLAPI PFNGLVERTEXATTRIB2DPROC glad_glVertexAttrib2d;
#define glVertexAttrib2d glad_glVertexAttrib2d
GLAPI PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f;
#define glVertexAttrib2f glad_glVertexAttrib2f
GLAPI PFNGLMULTIDRAWELEMENTSEXTPROC glad_glMultiDrawElementsEXT;
#define glMultiDrawElementsEXT glad_glMultiDrawElementsEXT
GLAPI PFNGLUNIFORM1FARBPROC glad_glUniform1fARB;
#define glUniform1fARB glad_glUniform1fARB
GLAPI PFNGLVERTEXATTRIB2SPROC glad_glVertexAttrib2s;
#define glVertexAttrib2s glad_glVertexAttrib2s
GLAPI PFNGLEVALCOORD1XOESPROC glad_glEvalCoord1xOES;
#define glEvalCoord1xOES glad_glEvalCoord1xOES
GLAPI PFNGLTEXTUREPARAMETERFVPROC glad_glTextureParameterfv;
#define glTextureParameterfv glad_glTextureParameterfv
GLAPI PFNGLGETLISTPARAMETERIVSGIXPROC glad_glGetListParameterivSGIX;
#define glGetListParameterivSGIX glad_glGetListParameterivSGIX
GLAPI PFNGLVERTEXARRAYELEMENTBUFFERPROC glad_glVertexArrayElementBuffer;
#define glVertexArrayElementBuffer glad_glVertexArrayElementBuffer
GLAPI PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate;
#define glStencilMaskSeparate glad_glStencilMaskSeparate
GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glad_glGetFramebufferAttachmentParameterivEXT;
#define glGetFramebufferAttachmentParameterivEXT glad_glGetFramebufferAttachmentParameterivEXT
GLAPI PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glad_glTextureStorage3DMultisample;
#define glTextureStorage3DMultisample glad_glTextureStorage3DMultisample
GLAPI PFNGLUNIFORM2UI64NVPROC glad_glUniform2ui64NV;
#define glUniform2ui64NV glad_glUniform2ui64NV
GLAPI PFNGLTANGENT3SEXTPROC glad_glTangent3sEXT;
#define glTangent3sEXT glad_glTangent3sEXT
GLAPI PFNGLFRUSTUMXOESPROC glad_glFrustumxOES;
#define glFrustumxOES glad_glFrustumxOES
GLAPI PFNGLINSTRUMENTSBUFFERSGIXPROC glad_glInstrumentsBufferSGIX;
#define glInstrumentsBufferSGIX glad_glInstrumentsBufferSGIX
GLAPI PFNGLCOPYTEXTUREIMAGE1DEXTPROC glad_glCopyTextureImage1DEXT;
#define glCopyTextureImage1DEXT glad_glCopyTextureImage1DEXT
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D;
#define glCompressedTexSubImage3D glad_glCompressedTexSubImage3D
GLAPI PFNGLSECONDARYCOLOR3HVNVPROC glad_glSecondaryColor3hvNV;
#define glSecondaryColor3hvNV glad_glSecondaryColor3hvNV
GLAPI PFNGLTEXTURESTORAGE3DEXTPROC glad_glTextureStorage3DEXT;
#define glTextureStorage3DEXT glad_glTextureStorage3DEXT
GLAPI PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glad_glGetSubroutineUniformLocation;
#define glGetSubroutineUniformLocation glad_glGetSubroutineUniformLocation
GLAPI PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC glad_glVertexArrayBindVertexBufferEXT;
#define glVertexArrayBindVertexBufferEXT glad_glVertexArrayBindVertexBufferEXT
GLAPI PFNGLUNIFORM3UIEXTPROC glad_glUniform3uiEXT;
#define glUniform3uiEXT glad_glUniform3uiEXT
GLAPI PFNGLMULTTRANSPOSEMATRIXDARBPROC glad_glMultTransposeMatrixdARB;
#define glMultTransposeMatrixdARB glad_glMultTransposeMatrixdARB
GLAPI PFNGLVERTEXATTRIBL4DEXTPROC glad_glVertexAttribL4dEXT;
#define glVertexAttribL4dEXT glad_glVertexAttribL4dEXT
GLAPI PFNGLCOVERSTROKEPATHINSTANCEDNVPROC glad_glCoverStrokePathInstancedNV;
#define glCoverStrokePathInstancedNV glad_glCoverStrokePathInstancedNV
GLAPI PFNGLDEFORMSGIXPROC glad_glDeformSGIX;
#define glDeformSGIX glad_glDeformSGIX
GLAPI PFNGLCOPYPATHNVPROC glad_glCopyPathNV;
#define glCopyPathNV glad_glCopyPathNV
GLAPI PFNGLVERTEXATTRIBL2DPROC glad_glVertexAttribL2d;
#define glVertexAttribL2d glad_glVertexAttribL2d
GLAPI PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC glad_glCompressedMultiTexSubImage3DEXT;
#define glCompressedMultiTexSubImage3DEXT glad_glCompressedMultiTexSubImage3DEXT
GLAPI PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC glad_glVDPAURegisterOutputSurfaceNV;
#define glVDPAURegisterOutputSurfaceNV glad_glVDPAURegisterOutputSurfaceNV
GLAPI PFNGLCOVERSTROKEPATHNVPROC glad_glCoverStrokePathNV;
#define glCoverStrokePathNV glad_glCoverStrokePathNV
GLAPI PFNGLVERTEX3BOESPROC glad_glVertex3bOES;
#define glVertex3bOES glad_glVertex3bOES
GLAPI PFNGLTESSELLATIONFACTORAMDPROC glad_glTessellationFactorAMD;
#define glTessellationFactorAMD glad_glTessellationFactorAMD
GLAPI PFNGLDEBUGMESSAGECONTROLPROC glad_glDebugMessageControl;
#define glDebugMessageControl glad_glDebugMessageControl
GLAPI PFNGLISOBJECTBUFFERATIPROC glad_glIsObjectBufferATI;
#define glIsObjectBufferATI glad_glIsObjectBufferATI
GLAPI PFNGLPROGRAMUNIFORM4IEXTPROC glad_glProgramUniform4iEXT;
#define glProgramUniform4iEXT glad_glProgramUniform4iEXT
GLAPI PFNGLVERTEXATTRIB2SVARBPROC glad_glVertexAttrib2svARB;
#define glVertexAttrib2svARB glad_glVertexAttrib2svARB
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC glad_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN glad_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
GLAPI PFNGLGETUNIFORMLOCATIONARBPROC glad_glGetUniformLocationARB;
#define glGetUniformLocationARB glad_glGetUniformLocationARB
GLAPI PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv;
#define glGetBufferParameteriv glad_glGetBufferParameteriv
GLAPI PFNGLMULTITEXCOORD3HVNVPROC glad_glMultiTexCoord3hvNV;
#define glMultiTexCoord3hvNV glad_glMultiTexCoord3hvNV
GLAPI PFNGLMATRIXPUSHEXTPROC glad_glMatrixPushEXT;
#define glMatrixPushEXT glad_glMatrixPushEXT
GLAPI PFNGLVIEWPORTPROC glad_glViewport;
#define glViewport glad_glViewport
GLAPI PFNGLGETVERTEXATTRIBLDVEXTPROC glad_glGetVertexAttribLdvEXT;
#define glGetVertexAttribLdvEXT glad_glGetVertexAttribLdvEXT
GLAPI PFNGLRESUMETRANSFORMFEEDBACKPROC glad_glResumeTransformFeedback;
#define glResumeTransformFeedback glad_glResumeTransformFeedback
GLAPI PFNGLTESSELLATIONMODEAMDPROC glad_glTessellationModeAMD;
#define glTessellationModeAMD glad_glTessellationModeAMD
GLAPI PFNGLGETPERFMONITORCOUNTERDATAAMDPROC glad_glGetPerfMonitorCounterDataAMD;
#define glGetPerfMonitorCounterDataAMD glad_glGetPerfMonitorCounterDataAMD
GLAPI PFNGLGETMULTITEXPARAMETERIVEXTPROC glad_glGetMultiTexParameterivEXT;
#define glGetMultiTexParameterivEXT glad_glGetMultiTexParameterivEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC glad_glProgramUniformMatrix3x4fvEXT;
#define glProgramUniformMatrix3x4fvEXT glad_glProgramUniformMatrix3x4fvEXT
GLAPI PFNGLVERTEXATTRIBI2IPROC glad_glVertexAttribI2i;
#define glVertexAttribI2i glad_glVertexAttribI2i
GLAPI PFNGLLOADPROGRAMNVPROC glad_glLoadProgramNV;
#define glLoadProgramNV glad_glLoadProgramNV
GLAPI PFNGLWRITEMASKEXTPROC glad_glWriteMaskEXT;
#define glWriteMaskEXT glad_glWriteMaskEXT
GLAPI PFNGLGETGRAPHICSRESETSTATUSPROC glad_glGetGraphicsResetStatus;
#define glGetGraphicsResetStatus glad_glGetGraphicsResetStatus
GLAPI PFNGLMAPNAMEDBUFFERRANGEPROC glad_glMapNamedBufferRange;
#define glMapNamedBufferRange glad_glMapNamedBufferRange
GLAPI PFNGLINDEXPOINTEREXTPROC glad_glIndexPointerEXT;
#define glIndexPointerEXT glad_glIndexPointerEXT
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glad_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN glad_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
GLAPI PFNGLREPLACEMENTCODEUBVSUNPROC glad_glReplacementCodeubvSUN;
#define glReplacementCodeubvSUN glad_glReplacementCodeubvSUN
GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_glGetTransformFeedbackVarying;
#define glGetTransformFeedbackVarying glad_glGetTransformFeedbackVarying
GLAPI PFNGLGETDEBUGMESSAGELOGAMDPROC glad_glGetDebugMessageLogAMD;
#define glGetDebugMessageLogAMD glad_glGetDebugMessageLogAMD
GLAPI PFNGLVERTEXATTRIBS4DVNVPROC glad_glVertexAttribs4dvNV;
#define glVertexAttribs4dvNV glad_glVertexAttribs4dvNV
GLAPI PFNGLVERTEXATTRIBL1I64NVPROC glad_glVertexAttribL1i64NV;
#define glVertexAttribL1i64NV glad_glVertexAttribL1i64NV
GLAPI PFNGLORTHOFOESPROC glad_glOrthofOES;
#define glOrthofOES glad_glOrthofOES
GLAPI PFNGLVIEWPORTARRAYVPROC glad_glViewportArrayv;
#define glViewportArrayv glad_glViewportArrayv
GLAPI PFNGLDRAWELEMENTARRAYATIPROC glad_glDrawElementArrayATI;
#define glDrawElementArrayATI glad_glDrawElementArrayATI
GLAPI PFNGLUNIFORM3UI64ARBPROC glad_glUniform3ui64ARB;
#define glUniform3ui64ARB glad_glUniform3ui64ARB
GLAPI PFNGLDEBUGMESSAGEINSERTARBPROC glad_glDebugMessageInsertARB;
#define glDebugMessageInsertARB glad_glDebugMessageInsertARB
GLAPI PFNGLMATRIXROTATEDEXTPROC glad_glMatrixRotatedEXT;
#define glMatrixRotatedEXT glad_glMatrixRotatedEXT
GLAPI PFNGLISPROGRAMNVPROC glad_glIsProgramNV;
#define glIsProgramNV glad_glIsProgramNV
GLAPI PFNGLGETTRANSFORMFEEDBACKI_VPROC glad_glGetTransformFeedbacki_v;
#define glGetTransformFeedbacki_v glad_glGetTransformFeedbacki_v
GLAPI PFNGLDEPTHBOUNDSEXTPROC glad_glDepthBoundsEXT;
#define glDepthBoundsEXT glad_glDepthBoundsEXT
GLAPI PFNGLCOLORTABLEPARAMETERIVSGIPROC glad_glColorTableParameterivSGI;
#define glColorTableParameterivSGI glad_glColorTableParameterivSGI
GLAPI PFNGLGETSHADERIVPROC glad_glGetShaderiv;
#define glGetShaderiv glad_glGetShaderiv
GLAPI PFNGLVERTEXBINDINGDIVISORPROC glad_glVertexBindingDivisor;
#define glVertexBindingDivisor glad_glVertexBindingDivisor
GLAPI PFNGLGETDOUBLEVPROC glad_glGetDoublev;
#define glGetDoublev glad_glGetDoublev
GLAPI PFNGLGETUNIFORMUIVPROC glad_glGetUniformuiv;
#define glGetUniformuiv glad_glGetUniformuiv
GLAPI PFNGLGETNUNIFORMFVARBPROC glad_glGetnUniformfvARB;
#define glGetnUniformfvARB glad_glGetnUniformfvARB
GLAPI PFNGLCLEARCOLORXOESPROC glad_glClearColorxOES;
#define glClearColorxOES glad_glClearColorxOES
GLAPI PFNGLVERTEXSTREAM4SVATIPROC glad_glVertexStream4svATI;
#define glVertexStream4svATI glad_glVertexStream4svATI
GLAPI PFNGLMULTITEXCOORD4IARBPROC glad_glMultiTexCoord4iARB;
#define glMultiTexCoord4iARB glad_glMultiTexCoord4iARB
GLAPI PFNGLVARIANTFVEXTPROC glad_glVariantfvEXT;
#define glVariantfvEXT glad_glVariantfvEXT
GLAPI PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC glad_glLoadIdentityDeformationMapSGIX;
#define glLoadIdentityDeformationMapSGIX glad_glLoadIdentityDeformationMapSGIX
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEPROC glad_glNamedRenderbufferStorage;
#define glNamedRenderbufferStorage glad_glNamedRenderbufferStorage
GLAPI PFNGLFOGCOORDPOINTERLISTIBMPROC glad_glFogCoordPointerListIBM;
#define glFogCoordPointerListIBM glad_glFogCoordPointerListIBM
GLAPI PFNGLGETVERTEXATTRIBIIVEXTPROC glad_glGetVertexAttribIivEXT;
#define glGetVertexAttribIivEXT glad_glGetVertexAttribIivEXT
GLAPI PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC glad_glFramebufferDrawBuffersEXT;
#define glFramebufferDrawBuffersEXT glad_glFramebufferDrawBuffersEXT
GLAPI PFNGLVERTEXATTRIB3SVPROC glad_glVertexAttrib3sv;
#define glVertexAttrib3sv glad_glVertexAttrib3sv
GLAPI PFNGLVDPAUSURFACEACCESSNVPROC glad_glVDPAUSurfaceAccessNV;
#define glVDPAUSurfaceAccessNV glad_glVDPAUSurfaceAccessNV
GLAPI PFNGLTEXPAGECOMMITMENTARBPROC glad_glTexPageCommitmentARB;
#define glTexPageCommitmentARB glad_glTexPageCommitmentARB
GLAPI PFNGLWINDOWPOS3DVARBPROC glad_glWindowPos3dvARB;
#define glWindowPos3dvARB glad_glWindowPos3dvARB
GLAPI PFNGLGENSAMPLERSPROC glad_glGenSamplers;
#define glGenSamplers glad_glGenSamplers
GLAPI PFNGLENABLEIPROC glad_glEnablei;
#define glEnablei glad_glEnablei
GLAPI PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC glad_glStencilThenCoverStrokePathNV;
#define glStencilThenCoverStrokePathNV glad_glStencilThenCoverStrokePathNV
GLAPI PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC glad_glGetNamedBufferParameterui64vNV;
#define glGetNamedBufferParameterui64vNV glad_glGetNamedBufferParameterui64vNV
GLAPI PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC glad_glMakeNamedBufferNonResidentNV;
#define glMakeNamedBufferNonResidentNV glad_glMakeNamedBufferNonResidentNV
GLAPI PFNGLBLENDCOLORXOESPROC glad_glBlendColorxOES;
#define glBlendColorxOES glad_glBlendColorxOES
GLAPI PFNGLTEXTUREPARAMETERIPROC glad_glTextureParameteri;
#define glTextureParameteri glad_glTextureParameteri
GLAPI PFNGLTEXTUREPARAMETERFPROC glad_glTextureParameterf;
#define glTextureParameterf glad_glTextureParameterf
GLAPI PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC glad_glFramebufferDrawBufferEXT;
#define glFramebufferDrawBufferEXT glad_glFramebufferDrawBufferEXT
GLAPI PFNGLFRAGMENTMATERIALFVSGIXPROC glad_glFragmentMaterialfvSGIX;
#define glFragmentMaterialfvSGIX glad_glFragmentMaterialfvSGIX
GLAPI PFNGLDELETENAMESAMDPROC glad_glDeleteNamesAMD;
#define glDeleteNamesAMD glad_glDeleteNamesAMD
GLAPI PFNGLDRAWRANGEELEMENTSEXTPROC glad_glDrawRangeElementsEXT;
#define glDrawRangeElementsEXT glad_glDrawRangeElementsEXT
GLAPI PFNGLDELETEBUFFERSARBPROC glad_glDeleteBuffersARB;
#define glDeleteBuffersARB glad_glDeleteBuffersARB
GLAPI PFNGLVERTEXATTRIBL1DVPROC glad_glVertexAttribL1dv;
#define glVertexAttribL1dv glad_glVertexAttribL1dv
GLAPI PFNGLPROGRAMUNIFORMMATRIX2DVPROC glad_glProgramUniformMatrix2dv;
#define glProgramUniformMatrix2dv glad_glProgramUniformMatrix2dv
GLAPI PFNGLNORMALSTREAM3SVATIPROC glad_glNormalStream3svATI;
#define glNormalStream3svATI glad_glNormalStream3svATI
GLAPI PFNGLPATHSTENCILFUNCNVPROC glad_glPathStencilFuncNV;
#define glPathStencilFuncNV glad_glPathStencilFuncNV
GLAPI PFNGLSETINVARIANTEXTPROC glad_glSetInvariantEXT;
#define glSetInvariantEXT glad_glSetInvariantEXT
GLAPI PFNGLENDOCCLUSIONQUERYNVPROC glad_glEndOcclusionQueryNV;
#define glEndOcclusionQueryNV glad_glEndOcclusionQueryNV
GLAPI PFNGLSCISSORARRAYVPROC glad_glScissorArrayv;
#define glScissorArrayv glad_glScissorArrayv
GLAPI PFNGLMULTITEXCOORD2HVNVPROC glad_glMultiTexCoord2hvNV;
#define glMultiTexCoord2hvNV glad_glMultiTexCoord2hvNV
GLAPI PFNGLMAPTEXTURE2DINTELPROC glad_glMapTexture2DINTEL;
#define glMapTexture2DINTEL glad_glMapTexture2DINTEL
GLAPI PFNGLGETMULTITEXENVFVEXTPROC glad_glGetMultiTexEnvfvEXT;
#define glGetMultiTexEnvfvEXT glad_glGetMultiTexEnvfvEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC glad_glProgramUniformMatrix4dvEXT;
#define glProgramUniformMatrix4dvEXT glad_glProgramUniformMatrix4dvEXT
GLAPI PFNGLVERTEXATTRIBL2DVEXTPROC glad_glVertexAttribL2dvEXT;
#define glVertexAttribL2dvEXT glad_glVertexAttribL2dvEXT
GLAPI PFNGLINVALIDATESUBFRAMEBUFFERPROC glad_glInvalidateSubFramebuffer;
#define glInvalidateSubFramebuffer glad_glInvalidateSubFramebuffer
GLAPI PFNGLVERTEXATTRIBLFORMATPROC glad_glVertexAttribLFormat;
#define glVertexAttribLFormat glad_glVertexAttribLFormat
GLAPI PFNGLCOVERAGEMODULATIONNVPROC glad_glCoverageModulationNV;
#define glCoverageModulationNV glad_glCoverageModulationNV
GLAPI PFNGLUNIFORM3IVPROC glad_glUniform3iv;
#define glUniform3iv glad_glUniform3iv
GLAPI PFNGLPOLYGONMODEPROC glad_glPolygonMode;
#define glPolygonMode glad_glPolygonMode
GLAPI PFNGLBEGINPERFQUERYINTELPROC glad_glBeginPerfQueryINTEL;
#define glBeginPerfQueryINTEL glad_glBeginPerfQueryINTEL
GLAPI PFNGLTEXTURESUBIMAGE2DEXTPROC glad_glTextureSubImage2DEXT;
#define glTextureSubImage2DEXT glad_glTextureSubImage2DEXT
GLAPI PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog;
#define glGetProgramInfoLog glad_glGetProgramInfoLog
GLAPI PFNGLTEXCOORD3HVNVPROC glad_glTexCoord3hvNV;
#define glTexCoord3hvNV glad_glTexCoord3hvNV
GLAPI PFNGLIMAGETRANSFORMPARAMETERIVHPPROC glad_glImageTransformParameterivHP;
#define glImageTransformParameterivHP glad_glImageTransformParameterivHP
GLAPI PFNGLUNIFORM3FVARBPROC glad_glUniform3fvARB;
#define glUniform3fvARB glad_glUniform3fvARB
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC glad_glProgramUniformMatrix3x2fvEXT;
#define glProgramUniformMatrix3x2fvEXT glad_glProgramUniformMatrix3x2fvEXT
GLAPI PFNGLDELETEOBJECTARBPROC glad_glDeleteObjectARB;
#define glDeleteObjectARB glad_glDeleteObjectARB
GLAPI PFNGLMULTITEXCOORD3DARBPROC glad_glMultiTexCoord3dARB;
#define glMultiTexCoord3dARB glad_glMultiTexCoord3dARB
GLAPI PFNGLSCISSORPROC glad_glScissor;
#define glScissor glad_glScissor
GLAPI PFNGLCALLCOMMANDLISTNVPROC glad_glCallCommandListNV;
#define glCallCommandListNV glad_glCallCommandListNV
GLAPI PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC glad_glTexImage2DMultisampleCoverageNV;
#define glTexImage2DMultisampleCoverageNV glad_glTexImage2DMultisampleCoverageNV
GLAPI PFNGLGETATTRIBLOCATIONARBPROC glad_glGetAttribLocationARB;
#define glGetAttribLocationARB glad_glGetAttribLocationARB
GLAPI PFNGLVERTEXATTRIB1FARBPROC glad_glVertexAttrib1fARB;
#define glVertexAttrib1fARB glad_glVertexAttrib1fARB
GLAPI PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC glad_glTexCoord2fColor4ubVertex3fSUN;
#define glTexCoord2fColor4ubVertex3fSUN glad_glTexCoord2fColor4ubVertex3fSUN
GLAPI PFNGLCOPYTEXTURESUBIMAGE1DPROC glad_glCopyTextureSubImage1D;
#define glCopyTextureSubImage1D glad_glCopyTextureSubImage1D
GLAPI PFNGLTEXTUREPARAMETERIEXTPROC glad_glTextureParameteriEXT;
#define glTextureParameteriEXT glad_glTextureParameteriEXT
GLAPI PFNGLMAPPARAMETERFVNVPROC glad_glMapParameterfvNV;
#define glMapParameterfvNV glad_glMapParameterfvNV
GLAPI PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC glad_glTransformFeedbackAttribsNV;
#define glTransformFeedbackAttribsNV glad_glTransformFeedbackAttribsNV
GLAPI PFNGLGETVIDEOI64VNVPROC glad_glGetVideoi64vNV;
#define glGetVideoi64vNV glad_glGetVideoi64vNV
GLAPI PFNGLVERTEXATTRIB4UIVPROC glad_glVertexAttrib4uiv;
#define glVertexAttrib4uiv glad_glVertexAttrib4uiv
GLAPI PFNGLSWIZZLEEXTPROC glad_glSwizzleEXT;
#define glSwizzleEXT glad_glSwizzleEXT
GLAPI PFNGLUNIFORM2UIPROC glad_glUniform2ui;
#define glUniform2ui glad_glUniform2ui
GLAPI PFNGLVERTEXATTRIBI3IPROC glad_glVertexAttribI3i;
#define glVertexAttribI3i glad_glVertexAttribI3i
GLAPI PFNGLVERTEXATTRIBBINDINGPROC glad_glVertexAttribBinding;
#define glVertexAttribBinding glad_glVertexAttribBinding
GLAPI PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource;
#define glGetShaderSource glad_glGetShaderSource
GLAPI PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC glad_glFramebufferSampleLocationsfvNV;
#define glFramebufferSampleLocationsfvNV glad_glFramebufferSampleLocationsfvNV
GLAPI PFNGLGETNEXTPERFQUERYIDINTELPROC glad_glGetNextPerfQueryIdINTEL;
#define glGetNextPerfQueryIdINTEL glad_glGetNextPerfQueryIdINTEL
GLAPI PFNGLISNAMEAMDPROC glad_glIsNameAMD;
#define glIsNameAMD glad_glIsNameAMD
GLAPI PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv;
#define glVertexAttrib3fv glad_glVertexAttrib3fv
GLAPI PFNGLTEXSTORAGESPARSEAMDPROC glad_glTexStorageSparseAMD;
#define glTexStorageSparseAMD glad_glTexStorageSparseAMD
GLAPI PFNGLGETNAMEDBUFFERPARAMETERIVPROC glad_glGetNamedBufferParameteriv;
#define glGetNamedBufferParameteriv glad_glGetNamedBufferParameteriv
GLAPI PFNGLVERTEXPOINTEREXTPROC glad_glVertexPointerEXT;
#define glVertexPointerEXT glad_glVertexPointerEXT
GLAPI PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC glad_glTexCoord4fColor4fNormal3fVertex4fSUN;
#define glTexCoord4fColor4fNormal3fVertex4fSUN glad_glTexCoord4fColor4fNormal3fVertex4fSUN
GLAPI PFNGLGETSTRINGPROC glad_glGetString;
#define glGetString glad_glGetString
GLAPI PFNGLFRAMEBUFFERPARAMETERIPROC glad_glFramebufferParameteri;
#define glFramebufferParameteri glad_glFramebufferParameteri
GLAPI PFNGLTEXCOORD3HNVPROC glad_glTexCoord3hNV;
#define glTexCoord3hNV glad_glTexCoord3hNV
GLAPI PFNGLMULTIMODEDRAWELEMENTSIBMPROC glad_glMultiModeDrawElementsIBM;
#define glMultiModeDrawElementsIBM glad_glMultiModeDrawElementsIBM
GLAPI PFNGLUNIFORM2IARBPROC glad_glUniform2iARB;
#define glUniform2iARB glad_glUniform2iARB
GLAPI PFNGLCOLORPOINTERVINTELPROC glad_glColorPointervINTEL;
#define glColorPointervINTEL glad_glColorPointervINTEL
GLAPI PFNGLDELETETEXTURESPROC glad_glDeleteTextures;
#define glDeleteTextures glad_glDeleteTextures
GLAPI PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f;
#define glVertexAttrib4f glad_glVertexAttrib4f
GLAPI PFNGLVERTEXATTRIB4DPROC glad_glVertexAttrib4d;
#define glVertexAttrib4d glad_glVertexAttrib4d
GLAPI PFNGLTEXCOORD2FVERTEX3FVSUNPROC glad_glTexCoord2fVertex3fvSUN;
#define glTexCoord2fVertex3fvSUN glad_glTexCoord2fVertex3fvSUN
GLAPI PFNGLREPLACEMENTCODEUSSUNPROC glad_glReplacementCodeusSUN;
#define glReplacementCodeusSUN glad_glReplacementCodeusSUN
GLAPI PFNGLCREATEVERTEXARRAYSPROC glad_glCreateVertexArrays;
#define glCreateVertexArrays glad_glCreateVertexArrays
GLAPI PFNGLGETARRAYOBJECTFVATIPROC glad_glGetArrayObjectfvATI;
#define glGetArrayObjectfvATI glad_glGetArrayObjectfvATI
GLAPI PFNGLGETVERTEXATTRIBIVNVPROC glad_glGetVertexAttribivNV;
#define glGetVertexAttribivNV glad_glGetVertexAttribivNV
GLAPI PFNGLSHADEROP1EXTPROC glad_glShaderOp1EXT;
#define glShaderOp1EXT glad_glShaderOp1EXT
GLAPI PFNGLCLEARCOLORIIEXTPROC glad_glClearColorIiEXT;
#define glClearColorIiEXT glad_glClearColorIiEXT
GLAPI PFNGLCOMBINEROUTPUTNVPROC glad_glCombinerOutputNV;
#define glCombinerOutputNV glad_glCombinerOutputNV
GLAPI PFNGLCULLFACEPROC glad_glCullFace;
#define glCullFace glad_glCullFace
GLAPI PFNGLPROGRAMUNIFORM4IPROC glad_glProgramUniform4i;
#define glProgramUniform4i glad_glProgramUniform4i
GLAPI PFNGLPROGRAMUNIFORM4FPROC glad_glProgramUniform4f;
#define glProgramUniform4f glad_glProgramUniform4f
GLAPI PFNGLVIEWPORTINDEXEDFPROC glad_glViewportIndexedf;
#define glViewportIndexedf glad_glViewportIndexedf
GLAPI PFNGLPROGRAMUNIFORM4DPROC glad_glProgramUniform4d;
#define glProgramUniform4d glad_glProgramUniform4d
GLAPI PFNGLTEXCOORD1XOESPROC glad_glTexCoord1xOES;
#define glTexCoord1xOES glad_glTexCoord1xOES
GLAPI PFNGLMULTIMODEDRAWARRAYSIBMPROC glad_glMultiModeDrawArraysIBM;
#define glMultiModeDrawArraysIBM glad_glMultiModeDrawArraysIBM
GLAPI PFNGLVERTEXATTRIB2HNVPROC glad_glVertexAttrib2hNV;
#define glVertexAttrib2hNV glad_glVertexAttrib2hNV
GLAPI PFNGLRESUMETRANSFORMFEEDBACKNVPROC glad_glResumeTransformFeedbackNV;
#define glResumeTransformFeedbackNV glad_glResumeTransformFeedbackNV
GLAPI PFNGLGETFENCEIVNVPROC glad_glGetFenceivNV;
#define glGetFenceivNV glad_glGetFenceivNV
GLAPI PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC glad_glTexCoord2fColor4ubVertex3fvSUN;
#define glTexCoord2fColor4ubVertex3fvSUN glad_glTexCoord2fColor4ubVertex3fvSUN
GLAPI PFNGLUNMAPNAMEDBUFFERPROC glad_glUnmapNamedBuffer;
#define glUnmapNamedBuffer glad_glUnmapNamedBuffer
GLAPI PFNGLRASTERPOS2XOESPROC glad_glRasterPos2xOES;
#define glRasterPos2xOES glad_glRasterPos2xOES
GLAPI PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glad_glDrawTransformFeedbackStreamInstanced;
#define glDrawTransformFeedbackStreamInstanced glad_glDrawTransformFeedbackStreamInstanced
GLAPI PFNGLMULTITEXCOORD4IVARBPROC glad_glMultiTexCoord4ivARB;
#define glMultiTexCoord4ivARB glad_glMultiTexCoord4ivARB
GLAPI PFNGLSPRITEPARAMETERFSGIXPROC glad_glSpriteParameterfSGIX;
#define glSpriteParameterfSGIX glad_glSpriteParameterfSGIX
GLAPI PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC glad_glBindVideoCaptureStreamTextureNV;
#define glBindVideoCaptureStreamTextureNV glad_glBindVideoCaptureStreamTextureNV
GLAPI PFNGLTEXPARAMETERIUIVPROC glad_glTexParameterIuiv;
#define glTexParameterIuiv glad_glTexParameterIuiv
GLAPI PFNGLUNIFORMMATRIX4X2DVPROC glad_glUniformMatrix4x2dv;
#define glUniformMatrix4x2dv glad_glUniformMatrix4x2dv
GLAPI PFNGLMAP2XOESPROC glad_glMap2xOES;
#define glMap2xOES glad_glMap2xOES
GLAPI PFNGLVERTEXWEIGHTHNVPROC glad_glVertexWeighthNV;
#define glVertexWeighthNV glad_glVertexWeighthNV
GLAPI PFNGLCOLORFRAGMENTOP1ATIPROC glad_glColorFragmentOp1ATI;
#define glColorFragmentOp1ATI glad_glColorFragmentOp1ATI
GLAPI PFNGLVERTEXATTRIBI4UBVEXTPROC glad_glVertexAttribI4ubvEXT;
#define glVertexAttribI4ubvEXT glad_glVertexAttribI4ubvEXT
GLAPI PFNGLVERTEXATTRIB1DNVPROC glad_glVertexAttrib1dNV;
#define glVertexAttrib1dNV glad_glVertexAttrib1dNV
GLAPI PFNGLVERTEXATTRIBS3DVNVPROC glad_glVertexAttribs3dvNV;
#define glVertexAttribs3dvNV glad_glVertexAttribs3dvNV
GLAPI PFNGLMULTITEXCOORD1HNVPROC glad_glMultiTexCoord1hNV;
#define glMultiTexCoord1hNV glad_glMultiTexCoord1hNV
GLAPI PFNGLTEXTURESTORAGE3DPROC glad_glTextureStorage3D;
#define glTextureStorage3D glad_glTextureStorage3D
GLAPI PFNGLGETCONVOLUTIONPARAMETERXVOESPROC glad_glGetConvolutionParameterxvOES;
#define glGetConvolutionParameterxvOES glad_glGetConvolutionParameterxvOES
GLAPI PFNGLSTRINGMARKERGREMEDYPROC glad_glStringMarkerGREMEDY;
#define glStringMarkerGREMEDY glad_glStringMarkerGREMEDY
GLAPI PFNGLGETOBJECTLABELEXTPROC glad_glGetObjectLabelEXT;
#define glGetObjectLabelEXT glad_glGetObjectLabelEXT
GLAPI PFNGLUNIFORMHANDLEUI64VNVPROC glad_glUniformHandleui64vNV;
#define glUniformHandleui64vNV glad_glUniformHandleui64vNV
GLAPI PFNGLISPROGRAMPIPELINEPROC glad_glIsProgramPipeline;
#define glIsProgramPipeline glad_glIsProgramPipeline
GLAPI PFNGLMULTITEXCOORD2DVARBPROC glad_glMultiTexCoord2dvARB;
#define glMultiTexCoord2dvARB glad_glMultiTexCoord2dvARB
GLAPI PFNGLTEXTUREPARAMETERFVEXTPROC glad_glTextureParameterfvEXT;
#define glTextureParameterfvEXT glad_glTextureParameterfvEXT
GLAPI PFNGLGETMINMAXEXTPROC glad_glGetMinmaxEXT;
#define glGetMinmaxEXT glad_glGetMinmaxEXT
GLAPI PFNGLVERTEXATTRIBL2DVPROC glad_glVertexAttribL2dv;
#define glVertexAttribL2dv glad_glVertexAttribL2dv
GLAPI PFNGLVERTEXWEIGHTPOINTEREXTPROC glad_glVertexWeightPointerEXT;
#define glVertexWeightPointerEXT glad_glVertexWeightPointerEXT
GLAPI PFNGLTEXRENDERBUFFERNVPROC glad_glTexRenderbufferNV;
#define glTexRenderbufferNV glad_glTexRenderbufferNV
GLAPI PFNGLGETNAMEDSTRINGARBPROC glad_glGetNamedStringARB;
#define glGetNamedStringARB glad_glGetNamedStringARB
GLAPI PFNGLTBUFFERMASK3DFXPROC glad_glTbufferMask3DFX;
#define glTbufferMask3DFX glad_glTbufferMask3DFX
GLAPI PFNGLTEXGENXOESPROC glad_glTexGenxOES;
#define glTexGenxOES glad_glTexGenxOES
GLAPI PFNGLMATRIXFRUSTUMEXTPROC glad_glMatrixFrustumEXT;
#define glMatrixFrustumEXT glad_glMatrixFrustumEXT
GLAPI PFNGLGETPROGRAMPIPELINEIVPROC glad_glGetProgramPipelineiv;
#define glGetProgramPipelineiv glad_glGetProgramPipelineiv
GLAPI PFNGLVERTEXATTRIBI4IPROC glad_glVertexAttribI4i;
#define glVertexAttribI4i glad_glVertexAttribI4i
GLAPI PFNGLGENERATETEXTUREMIPMAPPROC glad_glGenerateTextureMipmap;
#define glGenerateTextureMipmap glad_glGenerateTextureMipmap
GLAPI PFNGLDRAWELEMENTSINSTANCEDARBPROC glad_glDrawElementsInstancedARB;
#define glDrawElementsInstancedARB glad_glDrawElementsInstancedARB
GLAPI PFNGLGETSUBROUTINEINDEXPROC glad_glGetSubroutineIndex;
#define glGetSubroutineIndex glad_glGetSubroutineIndex
GLAPI PFNGLVERTEXATTRIB2SVPROC glad_glVertexAttrib2sv;
#define glVertexAttrib2sv glad_glVertexAttrib2sv
GLAPI PFNGLSAMPLEPATTERNSGISPROC glad_glSamplePatternSGIS;
#define glSamplePatternSGIS glad_glSamplePatternSGIS
GLAPI PFNGLRASTERPOS3XVOESPROC glad_glRasterPos3xvOES;
#define glRasterPos3xvOES glad_glRasterPos3xvOES
GLAPI PFNGLVERTEXATTRIBL3DVPROC glad_glVertexAttribL3dv;
#define glVertexAttribL3dv glad_glVertexAttribL3dv
GLAPI PFNGLVERTEXATTRIBL1DEXTPROC glad_glVertexAttribL1dEXT;
#define glVertexAttribL1dEXT glad_glVertexAttribL1dEXT
GLAPI PFNGLGETNUNIFORMDVARBPROC glad_glGetnUniformdvARB;
#define glGetnUniformdvARB glad_glGetnUniformdvARB
GLAPI PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC glad_glProgramSubroutineParametersuivNV;
#define glProgramSubroutineParametersuivNV glad_glProgramSubroutineParametersuivNV
GLAPI PFNGLSECONDARYCOLOR3BEXTPROC glad_glSecondaryColor3bEXT;
#define glSecondaryColor3bEXT glad_glSecondaryColor3bEXT
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC glad_glVertexArrayVertexAttribLFormatEXT;
#define glVertexArrayVertexAttribLFormatEXT glad_glVertexArrayVertexAttribLFormatEXT
GLAPI PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC glad_glCopyTextureSubImage3DEXT;
#define glCopyTextureSubImage3DEXT glad_glCopyTextureSubImage3DEXT
GLAPI PFNGLBINDPROGRAMPIPELINEPROC glad_glBindProgramPipeline;
#define glBindProgramPipeline glad_glBindProgramPipeline
GLAPI PFNGLGETBOOLEANVPROC glad_glGetBooleanv;
#define glGetBooleanv glad_glGetBooleanv
GLAPI PFNGLWINDOWPOS4FVMESAPROC glad_glWindowPos4fvMESA;
#define glWindowPos4fvMESA glad_glWindowPos4fvMESA
GLAPI PFNGLVERTEXATTRIBIPOINTEREXTPROC glad_glVertexAttribIPointerEXT;
#define glVertexAttribIPointerEXT glad_glVertexAttribIPointerEXT
GLAPI PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC glad_glProgramBufferParametersfvNV;
#define glProgramBufferParametersfvNV glad_glProgramBufferParametersfvNV
GLAPI PFNGLPROGRAMUNIFORM4UIVEXTPROC glad_glProgramUniform4uivEXT;
#define glProgramUniform4uivEXT glad_glProgramUniform4uivEXT
GLAPI PFNGLGETTEXTURELEVELPARAMETERIVPROC glad_glGetTextureLevelParameteriv;
#define glGetTextureLevelParameteriv glad_glGetTextureLevelParameteriv
GLAPI PFNGLMAPVERTEXATTRIB1FAPPLEPROC glad_glMapVertexAttrib1fAPPLE;
#define glMapVertexAttrib1fAPPLE glad_glMapVertexAttrib1fAPPLE
GLAPI PFNGLVERTEXATTRIB4NSVARBPROC glad_glVertexAttrib4NsvARB;
#define glVertexAttrib4NsvARB glad_glVertexAttrib4NsvARB
GLAPI PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv;
#define glPointParameterfv glad_glPointParameterfv
GLAPI PFNGLFOGCOORDFORMATNVPROC glad_glFogCoordFormatNV;
#define glFogCoordFormatNV glad_glFogCoordFormatNV
GLAPI PFNGLGETMULTITEXGENFVEXTPROC glad_glGetMultiTexGenfvEXT;
#define glGetMultiTexGenfvEXT glad_glGetMultiTexGenfvEXT
GLAPI PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glad_glInvalidateNamedFramebufferSubData;
#define glInvalidateNamedFramebufferSubData glad_glInvalidateNamedFramebufferSubData
GLAPI PFNGLPROGRAMENVPARAMETER4DARBPROC glad_glProgramEnvParameter4dARB;
#define glProgramEnvParameter4dARB glad_glProgramEnvParameter4dARB
GLAPI PFNGLPROGRAMUNIFORM1UIEXTPROC glad_glProgramUniform1uiEXT;
#define glProgramUniform1uiEXT glad_glProgramUniform1uiEXT
GLAPI PFNGLBINDBUFFERRANGEPROC glad_glBindBufferRange;
#define glBindBufferRange glad_glBindBufferRange
GLAPI PFNGLGETUNIFORMI64VNVPROC glad_glGetUniformi64vNV;
#define glGetUniformi64vNV glad_glGetUniformi64vNV
GLAPI PFNGLISIMAGEHANDLERESIDENTARBPROC glad_glIsImageHandleResidentARB;
#define glIsImageHandleResidentARB glad_glIsImageHandleResidentARB
GLAPI PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC glad_glGetMultiTexLevelParameterfvEXT;
#define glGetMultiTexLevelParameterfvEXT glad_glGetMultiTexLevelParameterfvEXT
GLAPI PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv;
#define glUniformMatrix2x3fv glad_glUniformMatrix2x3fv
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glad_glProgramUniformMatrix4x3fv;
#define glProgramUniformMatrix4x3fv glad_glProgramUniformMatrix4x3fv
GLAPI PFNGLGETVERTEXARRAYPOINTERVEXTPROC glad_glGetVertexArrayPointervEXT;
#define glGetVertexArrayPointervEXT glad_glGetVertexArrayPointervEXT
GLAPI PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync;
#define glClientWaitSync glad_glClientWaitSync
GLAPI PFNGLQUERYOBJECTPARAMETERUIAMDPROC glad_glQueryObjectParameteruiAMD;
#define glQueryObjectParameteruiAMD glad_glQueryObjectParameteruiAMD
GLAPI PFNGLVARIANTPOINTEREXTPROC glad_glVariantPointerEXT;
#define glVariantPointerEXT glad_glVariantPointerEXT
GLAPI PFNGLVERTEXATTRIB4NSVPROC glad_glVertexAttrib4Nsv;
#define glVertexAttrib4Nsv glad_glVertexAttrib4Nsv
GLAPI PFNGLPATHGLYPHINDEXARRAYNVPROC glad_glPathGlyphIndexArrayNV;
#define glPathGlyphIndexArrayNV glad_glPathGlyphIndexArrayNV
GLAPI PFNGLBINDVERTEXBUFFERPROC glad_glBindVertexBuffer;
#define glBindVertexBuffer glad_glBindVertexBuffer
GLAPI PFNGLMULTITEXCOORD1IARBPROC glad_glMultiTexCoord1iARB;
#define glMultiTexCoord1iARB glad_glMultiTexCoord1iARB
GLAPI PFNGLISSAMPLERPROC glad_glIsSampler;
#define glIsSampler glad_glIsSampler
GLAPI PFNGLCONSERVATIVERASTERPARAMETERFNVPROC glad_glConservativeRasterParameterfNV;
#define glConservativeRasterParameterfNV glad_glConservativeRasterParameterfNV
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC glad_glNamedFramebufferTexture2DEXT;
#define glNamedFramebufferTexture2DEXT glad_glNamedFramebufferTexture2DEXT
GLAPI PFNGLCOPYTEXSUBIMAGE1DPROC glad_glCopyTexSubImage1D;
#define glCopyTexSubImage1D glad_glCopyTexSubImage1D
GLAPI PFNGLFRAGMENTLIGHTIVSGIXPROC glad_glFragmentLightivSGIX;
#define glFragmentLightivSGIX glad_glFragmentLightivSGIX
GLAPI PFNGLMULTITEXCOORDPOINTEREXTPROC glad_glMultiTexCoordPointerEXT;
#define glMultiTexCoordPointerEXT glad_glMultiTexCoordPointerEXT
GLAPI PFNGLSAMPLERPARAMETERIIVPROC glad_glSamplerParameterIiv;
#define glSamplerParameterIiv glad_glSamplerParameterIiv
GLAPI PFNGLSAMPLEMAPATIPROC glad_glSampleMapATI;
#define glSampleMapATI glad_glSampleMapATI
GLAPI PFNGLVERTEXATTRIB4BVARBPROC glad_glVertexAttrib4bvARB;
#define glVertexAttrib4bvARB glad_glVertexAttrib4bvARB
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC glad_glMultiDrawArraysIndirectCountARB;
#define glMultiDrawArraysIndirectCountARB glad_glMultiDrawArraysIndirectCountARB
GLAPI PFNGLUNIFORMBUFFEREXTPROC glad_glUniformBufferEXT;
#define glUniformBufferEXT glad_glUniformBufferEXT
GLAPI PFNGLWINDOWPOS2IVMESAPROC glad_glWindowPos2ivMESA;
#define glWindowPos2ivMESA glad_glWindowPos2ivMESA
GLAPI PFNGLMULTITEXSUBIMAGE1DEXTPROC glad_glMultiTexSubImage1DEXT;
#define glMultiTexSubImage1DEXT glad_glMultiTexSubImage1DEXT
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC glad_glNamedProgramLocalParameter4dEXT;
#define glNamedProgramLocalParameter4dEXT glad_glNamedProgramLocalParameter4dEXT
GLAPI PFNGLCREATEFRAMEBUFFERSPROC glad_glCreateFramebuffers;
#define glCreateFramebuffers glad_glCreateFramebuffers
GLAPI PFNGLUNIFORM3I64VNVPROC glad_glUniform3i64vNV;
#define glUniform3i64vNV glad_glUniform3i64vNV
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTPROC glad_glMultiDrawElementsIndirect;
#define glMultiDrawElementsIndirect glad_glMultiDrawElementsIndirect
GLAPI PFNGLWINDOWPOS4DVMESAPROC glad_glWindowPos4dvMESA;
#define glWindowPos4dvMESA glad_glWindowPos4dvMESA
GLAPI PFNGLMAKEIMAGEHANDLERESIDENTNVPROC glad_glMakeImageHandleResidentNV;
#define glMakeImageHandleResidentNV glad_glMakeImageHandleResidentNV
GLAPI PFNGLVERTEXATTRIB4NUSVARBPROC glad_glVertexAttrib4NusvARB;
#define glVertexAttrib4NusvARB glad_glVertexAttrib4NusvARB
GLAPI PFNGLGETVERTEXATTRIBIUIVEXTPROC glad_glGetVertexAttribIuivEXT;
#define glGetVertexAttribIuivEXT glad_glGetVertexAttribIuivEXT
GLAPI PFNGLCONVOLUTIONPARAMETERFEXTPROC glad_glConvolutionParameterfEXT;
#define glConvolutionParameterfEXT glad_glConvolutionParameterfEXT
GLAPI PFNGLACTIVEVARYINGNVPROC glad_glActiveVaryingNV;
#define glActiveVaryingNV glad_glActiveVaryingNV
GLAPI PFNGLVERTEXATTRIBI3IVEXTPROC glad_glVertexAttribI3ivEXT;
#define glVertexAttribI3ivEXT glad_glVertexAttribI3ivEXT
GLAPI PFNGLCREATESYNCFROMCLEVENTARBPROC glad_glCreateSyncFromCLeventARB;
#define glCreateSyncFromCLeventARB glad_glCreateSyncFromCLeventARB
GLAPI PFNGLVERTEXSTREAM4DATIPROC glad_glVertexStream4dATI;
#define glVertexStream4dATI glad_glVertexStream4dATI
GLAPI PFNGLGETNUNIFORMUI64VARBPROC glad_glGetnUniformui64vARB;
#define glGetnUniformui64vARB glad_glGetnUniformui64vARB
GLAPI PFNGLVERTEXATTRIBI1UIEXTPROC glad_glVertexAttribI1uiEXT;
#define glVertexAttribI1uiEXT glad_glVertexAttribI1uiEXT
GLAPI PFNGLPROGRAMUNIFORM3I64VARBPROC glad_glProgramUniform3i64vARB;
#define glProgramUniform3i64vARB glad_glProgramUniform3i64vARB
GLAPI PFNGLPROGRAMUNIFORM2UIPROC glad_glProgramUniform2ui;
#define glProgramUniform2ui glad_glProgramUniform2ui
GLAPI PFNGLPROGRAMUNIFORM4UIPROC glad_glProgramUniform4ui;
#define glProgramUniform4ui glad_glProgramUniform4ui
GLAPI PFNGLSTENCILMASKPROC glad_glStencilMask;
#define glStencilMask glad_glStencilMask
GLAPI PFNGLRESETHISTOGRAMEXTPROC glad_glResetHistogramEXT;
#define glResetHistogramEXT glad_glResetHistogramEXT
GLAPI PFNGLLIGHTXOESPROC glad_glLightxOES;
#define glLightxOES glad_glLightxOES
GLAPI PFNGLCLEARNAMEDBUFFERSUBDATAPROC glad_glClearNamedBufferSubData;
#define glClearNamedBufferSubData glad_glClearNamedBufferSubData
GLAPI PFNGLGETOBJECTPARAMETERFVARBPROC glad_glGetObjectParameterfvARB;
#define glGetObjectParameterfvARB glad_glGetObjectParameterfvARB
GLAPI PFNGLGETOBJECTBUFFERIVATIPROC glad_glGetObjectBufferivATI;
#define glGetObjectBufferivATI glad_glGetObjectBufferivATI
GLAPI PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC glad_glReplacementCodeuiColor4ubVertex3fvSUN;
#define glReplacementCodeuiColor4ubVertex3fvSUN glad_glReplacementCodeuiColor4ubVertex3fvSUN
GLAPI PFNGLBLENDFUNCSEPARATEINGRPROC glad_glBlendFuncSeparateINGR;
#define glBlendFuncSeparateINGR glad_glBlendFuncSeparateINGR
GLAPI PFNGLTEXTURESUBIMAGE1DEXTPROC glad_glTextureSubImage1DEXT;
#define glTextureSubImage1DEXT glad_glTextureSubImage1DEXT
GLAPI PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glad_glGetCompressedTextureSubImage;
#define glGetCompressedTextureSubImage glad_glGetCompressedTextureSubImage
GLAPI PFNGLDRAWBUFFERSPROC glad_glDrawBuffers;
#define glDrawBuffers glad_glDrawBuffers
GLAPI PFNGLVERTEXSTREAM1IATIPROC glad_glVertexStream1iATI;
#define glVertexStream1iATI glad_glVertexStream1iATI
GLAPI PFNGLPATCHPARAMETERFVPROC glad_glPatchParameterfv;
#define glPatchParameterfv glad_glPatchParameterfv
GLAPI PFNGLTEXTURESTORAGE2DPROC glad_glTextureStorage2D;
#define glTextureStorage2D glad_glTextureStorage2D
GLAPI PFNGLTEXTURESUBIMAGE3DEXTPROC glad_glTextureSubImage3DEXT;
#define glTextureSubImage3DEXT glad_glTextureSubImage3DEXT
GLAPI PFNGLUNIFORM2I64NVPROC glad_glUniform2i64NV;
#define glUniform2i64NV glad_glUniform2i64NV
GLAPI PFNGLVERTEXATTRIB3SNVPROC glad_glVertexAttrib3sNV;
#define glVertexAttrib3sNV glad_glVertexAttrib3sNV
GLAPI PFNGLVERTEXATTRIB4NIVARBPROC glad_glVertexAttrib4NivARB;
#define glVertexAttrib4NivARB glad_glVertexAttrib4NivARB
GLAPI PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC glad_glBlendEquationSeparateIndexedAMD;
#define glBlendEquationSeparateIndexedAMD glad_glBlendEquationSeparateIndexedAMD
GLAPI PFNGLUNIFORM1UI64NVPROC glad_glUniform1ui64NV;
#define glUniform1ui64NV glad_glUniform1ui64NV
GLAPI PFNGLGETTEXPARAMETERIUIVEXTPROC glad_glGetTexParameterIuivEXT;
#define glGetTexParameterIuivEXT glad_glGetTexParameterIuivEXT
GLAPI PFNGLPROGRAMUNIFORM2I64VNVPROC glad_glProgramUniform2i64vNV;
#define glProgramUniform2i64vNV glad_glProgramUniform2i64vNV
GLAPI PFNGLARRAYOBJECTATIPROC glad_glArrayObjectATI;
#define glArrayObjectATI glad_glArrayObjectATI
GLAPI PFNGLGETINTEGERUI64VNVPROC glad_glGetIntegerui64vNV;
#define glGetIntegerui64vNV glad_glGetIntegerui64vNV
GLAPI PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC glad_glGetImageTransformParameterfvHP;
#define glGetImageTransformParameterfvHP glad_glGetImageTransformParameterfvHP
GLAPI PFNGLWEIGHTPOINTERARBPROC glad_glWeightPointerARB;
#define glWeightPointerARB glad_glWeightPointerARB
GLAPI PFNGLFINISHFENCENVPROC glad_glFinishFenceNV;
#define glFinishFenceNV glad_glFinishFenceNV
GLAPI PFNGLDEPTHRANGEXOESPROC glad_glDepthRangexOES;
#define glDepthRangexOES glad_glDepthRangexOES
GLAPI PFNGLPROGRAMUNIFORM2UIVEXTPROC glad_glProgramUniform2uivEXT;
#define glProgramUniform2uivEXT glad_glProgramUniform2uivEXT
GLAPI PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glad_glTransformFeedbackBufferBase;
#define glTransformFeedbackBufferBase glad_glTransformFeedbackBufferBase
GLAPI PFNGLVERTEXATTRIBL1UI64VNVPROC glad_glVertexAttribL1ui64vNV;
#define glVertexAttribL1ui64vNV glad_glVertexAttribL1ui64vNV
GLAPI PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC glad_glCopyConvolutionFilter1DEXT;
#define glCopyConvolutionFilter1DEXT glad_glCopyConvolutionFilter1DEXT
GLAPI PFNGLGETCOLORTABLEPARAMETERFVEXTPROC glad_glGetColorTableParameterfvEXT;
#define glGetColorTableParameterfvEXT glad_glGetColorTableParameterfvEXT
GLAPI PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers;
#define glGenRenderbuffers glad_glGenRenderbuffers
GLAPI PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D;
#define glCopyTexSubImage2D glad_glCopyTexSubImage2D
GLAPI PFNGLVERTEXATTRIBS1SVNVPROC glad_glVertexAttribs1svNV;
#define glVertexAttribs1svNV glad_glVertexAttribs1svNV
GLAPI PFNGLUNIFORM1FVARBPROC glad_glUniform1fvARB;
#define glUniform1fvARB glad_glUniform1fvARB
GLAPI PFNGLGETVARIANTFLOATVEXTPROC glad_glGetVariantFloatvEXT;
#define glGetVariantFloatvEXT glad_glGetVariantFloatvEXT
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glad_glCompressedTexSubImage1DARB;
#define glCompressedTexSubImage1DARB glad_glCompressedTexSubImage1DARB
GLAPI PFNGLVERTEXSTREAM2SVATIPROC glad_glVertexStream2svATI;
#define glVertexStream2svATI glad_glVertexStream2svATI
GLAPI PFNGLPOINTSIZEPROC glad_glPointSize;
#define glPointSize glad_glPointSize
GLAPI PFNGLVERTEXATTRIB4NUIVPROC glad_glVertexAttrib4Nuiv;
#define glVertexAttrib4Nuiv glad_glVertexAttrib4Nuiv
GLAPI PFNGLGETUNIFORMFVARBPROC glad_glGetUniformfvARB;
#define glGetUniformfvARB glad_glGetUniformfvARB
GLAPI PFNGLPROGRAMLOCALPARAMETER4FARBPROC glad_glProgramLocalParameter4fARB;
#define glProgramLocalParameter4fARB glad_glProgramLocalParameter4fARB
GLAPI PFNGLTEXTUREPARAMETERIVEXTPROC glad_glTextureParameterivEXT;
#define glTextureParameterivEXT glad_glTextureParameterivEXT
GLAPI PFNGLACTIVEPROGRAMEXTPROC glad_glActiveProgramEXT;
#define glActiveProgramEXT glad_glActiveProgramEXT
GLAPI PFNGLPROGRAMUNIFORM1I64VARBPROC glad_glProgramUniform1i64vARB;
#define glProgramUniform1i64vARB glad_glProgramUniform1i64vARB
GLAPI PFNGLWEIGHTUSVARBPROC glad_glWeightusvARB;
#define glWeightusvARB glad_glWeightusvARB
GLAPI PFNGLMULTITEXCOORD2XOESPROC glad_glMultiTexCoord2xOES;
#define glMultiTexCoord2xOES glad_glMultiTexCoord2xOES
GLAPI PFNGLTEXCOORD2FVERTEX3FSUNPROC glad_glTexCoord2fVertex3fSUN;
#define glTexCoord2fVertex3fSUN glad_glTexCoord2fVertex3fSUN
GLAPI PFNGLPOLYGONOFFSETEXTPROC glad_glPolygonOffsetEXT;
#define glPolygonOffsetEXT glad_glPolygonOffsetEXT
GLAPI PFNGLCOMBINERSTAGEPARAMETERFVNVPROC glad_glCombinerStageParameterfvNV;
#define glCombinerStageParameterfvNV glad_glCombinerStageParameterfvNV
GLAPI PFNGLCOPYTEXIMAGE1DEXTPROC glad_glCopyTexImage1DEXT;
#define glCopyTexImage1DEXT glad_glCopyTexImage1DEXT
GLAPI PFNGLMATRIXMULTFEXTPROC glad_glMatrixMultfEXT;
#define glMatrixMultfEXT glad_glMatrixMultfEXT
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC glad_glCompressedTextureSubImage3DEXT;
#define glCompressedTextureSubImage3DEXT glad_glCompressedTextureSubImage3DEXT
GLAPI PFNGLVERTEXATTRIBL3DVEXTPROC glad_glVertexAttribL3dvEXT;
#define glVertexAttribL3dvEXT glad_glVertexAttribL3dvEXT
GLAPI PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC glad_glGetTextureLevelParameterivEXT;
#define glGetTextureLevelParameterivEXT glad_glGetTextureLevelParameterivEXT
GLAPI PFNGLDRAWARRAYSPROC glad_glDrawArrays;
#define glDrawArrays glad_glDrawArrays
GLAPI PFNGLGETNTEXIMAGEARBPROC glad_glGetnTexImageARB;
#define glGetnTexImageARB glad_glGetnTexImageARB
GLAPI PFNGLCLEARPROC glad_glClear;
#define glClear glad_glClear
GLAPI PFNGLWINDOWPOS2IARBPROC glad_glWindowPos2iARB;
#define glWindowPos2iARB glad_glWindowPos2iARB
GLAPI PFNGLCREATEQUERIESPROC glad_glCreateQueries;
#define glCreateQueries glad_glCreateQueries
GLAPI PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements;
#define glDrawRangeElements glad_glDrawRangeElements
GLAPI PFNGLVERTEXATTRIBP2UIPROC glad_glVertexAttribP2ui;
#define glVertexAttribP2ui glad_glVertexAttribP2ui
GLAPI PFNGLSECONDARYCOLOR3HNVPROC glad_glSecondaryColor3hNV;
#define glSecondaryColor3hNV glad_glSecondaryColor3hNV
GLAPI PFNGLPROGRAMUNIFORM3IEXTPROC glad_glProgramUniform3iEXT;
#define glProgramUniform3iEXT glad_glProgramUniform3iEXT
GLAPI PFNGLTEXIMAGE1DPROC glad_glTexImage1D;
#define glTexImage1D glad_glTexImage1D
GLAPI PFNGLISRENDERBUFFEREXTPROC glad_glIsRenderbufferEXT;
#define glIsRenderbufferEXT glad_glIsRenderbufferEXT
GLAPI PFNGLGETINVARIANTFLOATVEXTPROC glad_glGetInvariantFloatvEXT;
#define glGetInvariantFloatvEXT glad_glGetInvariantFloatvEXT
GLAPI PFNGLUNIFORM4IARBPROC glad_glUniform4iARB;
#define glUniform4iARB glad_glUniform4iARB
GLAPI PFNGLPATHSUBCOMMANDSNVPROC glad_glPathSubCommandsNV;
#define glPathSubCommandsNV glad_glPathSubCommandsNV
GLAPI PFNGLFRUSTUMFOESPROC glad_glFrustumfOES;
#define glFrustumfOES glad_glFrustumfOES
GLAPI PFNGLCREATESAMPLERSPROC glad_glCreateSamplers;
#define glCreateSamplers glad_glCreateSamplers
GLAPI PFNGLISVERTEXARRAYPROC glad_glIsVertexArray;
#define glIsVertexArray glad_glIsVertexArray
GLAPI PFNGLWINDOWPOS3IVARBPROC glad_glWindowPos3ivARB;
#define glWindowPos3ivARB glad_glWindowPos3ivARB
GLAPI PFNGLCOMBINERPARAMETERFNVPROC glad_glCombinerParameterfNV;
#define glCombinerParameterfNV glad_glCombinerParameterfNV
GLAPI PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC glad_glCheckNamedFramebufferStatusEXT;
#define glCheckNamedFramebufferStatusEXT glad_glCheckNamedFramebufferStatusEXT
GLAPI PFNGLGLOBALALPHAFACTORISUNPROC glad_glGlobalAlphaFactoriSUN;
#define glGlobalAlphaFactoriSUN glad_glGlobalAlphaFactoriSUN
GLAPI PFNGLTEXTURESTORAGE1DPROC glad_glTextureStorage1D;
#define glTextureStorage1D glad_glTextureStorage1D
GLAPI PFNGLBINORMAL3SEXTPROC glad_glBinormal3sEXT;
#define glBinormal3sEXT glad_glBinormal3sEXT
GLAPI PFNGLSHARPENTEXFUNCSGISPROC glad_glSharpenTexFuncSGIS;
#define glSharpenTexFuncSGIS glad_glSharpenTexFuncSGIS
GLAPI PFNGLTEXCOORDPOINTEREXTPROC glad_glTexCoordPointerEXT;
#define glTexCoordPointerEXT glad_glTexCoordPointerEXT
GLAPI PFNGLVERTEXATTRIB2FNVPROC glad_glVertexAttrib2fNV;
#define glVertexAttrib2fNV glad_glVertexAttrib2fNV
GLAPI PFNGLMAPNAMEDBUFFERPROC glad_glMapNamedBuffer;
#define glMapNamedBuffer glad_glMapNamedBuffer
GLAPI PFNGLENDCONDITIONALRENDERNVXPROC glad_glEndConditionalRenderNVX;
#define glEndConditionalRenderNVX glad_glEndConditionalRenderNVX
GLAPI PFNGLSECONDARYCOLOR3UBEXTPROC glad_glSecondaryColor3ubEXT;
#define glSecondaryColor3ubEXT glad_glSecondaryColor3ubEXT
GLAPI PFNGLBINORMAL3FEXTPROC glad_glBinormal3fEXT;
#define glBinormal3fEXT glad_glBinormal3fEXT
GLAPI PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC glad_glProgramBufferParametersIivNV;
#define glProgramBufferParametersIivNV glad_glProgramBufferParametersIivNV
GLAPI PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset;
#define glPolygonOffset glad_glPolygonOffset
GLAPI PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC glad_glFlushMappedNamedBufferRangeEXT;
#define glFlushMappedNamedBufferRangeEXT glad_glFlushMappedNamedBufferRangeEXT
GLAPI PFNGLGETVERTEXATTRIBIIVPROC glad_glGetVertexAttribIiv;
#define glGetVertexAttribIiv glad_glGetVertexAttribIiv
GLAPI PFNGLGETTEXFILTERFUNCSGISPROC glad_glGetTexFilterFuncSGIS;
#define glGetTexFilterFuncSGIS glad_glGetTexFilterFuncSGIS
GLAPI PFNGLMULTITEXCOORD3SVARBPROC glad_glMultiTexCoord3svARB;
#define glMultiTexCoord3svARB glad_glMultiTexCoord3svARB
GLAPI PFNGLBINDPROGRAMNVPROC glad_glBindProgramNV;
#define glBindProgramNV glad_glBindProgramNV
GLAPI PFNGLVERTEXATTRIB4FNVPROC glad_glVertexAttrib4fNV;
#define glVertexAttrib4fNV glad_glVertexAttrib4fNV
GLAPI PFNGLGETHISTOGRAMPARAMETERFVEXTPROC glad_glGetHistogramParameterfvEXT;
#define glGetHistogramParameterfvEXT glad_glGetHistogramParameterfvEXT
GLAPI PFNGLMULTITEXGENIEXTPROC glad_glMultiTexGeniEXT;
#define glMultiTexGeniEXT glad_glMultiTexGeniEXT
GLAPI PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC glad_glVertexArrayFogCoordOffsetEXT;
#define glVertexArrayFogCoordOffsetEXT glad_glVertexArrayFogCoordOffsetEXT
GLAPI PFNGLGENOCCLUSIONQUERIESNVPROC glad_glGenOcclusionQueriesNV;
#define glGenOcclusionQueriesNV glad_glGenOcclusionQueriesNV
GLAPI PFNGLPROGRAMUNIFORM2I64ARBPROC glad_glProgramUniform2i64ARB;
#define glProgramUniform2i64ARB glad_glProgramUniform2i64ARB
GLAPI PFNGLVERTEXATTRIBIFORMATNVPROC glad_glVertexAttribIFormatNV;
#define glVertexAttribIFormatNV glad_glVertexAttribIFormatNV
GLAPI PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate;
#define glStencilFuncSeparate glad_glStencilFuncSeparate
GLAPI PFNGLGETVERTEXATTRIBFVARBPROC glad_glGetVertexAttribfvARB;
#define glGetVertexAttribfvARB glad_glGetVertexAttribfvARB
GLAPI PFNGLBINORMAL3IVEXTPROC glad_glBinormal3ivEXT;
#define glBinormal3ivEXT glad_glBinormal3ivEXT
GLAPI PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC glad_glClientActiveVertexStreamATI;
#define glClientActiveVertexStreamATI glad_glClientActiveVertexStreamATI
GLAPI PFNGLRASTERPOS3XOESPROC glad_glRasterPos3xOES;
#define glRasterPos3xOES glad_glRasterPos3xOES
GLAPI PFNGLGETMAPPARAMETERIVNVPROC glad_glGetMapParameterivNV;
#define glGetMapParameterivNV glad_glGetMapParameterivNV
GLAPI PFNGLGETFIRSTPERFQUERYIDINTELPROC glad_glGetFirstPerfQueryIdINTEL;
#define glGetFirstPerfQueryIdINTEL glad_glGetFirstPerfQueryIdINTEL
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC glad_glRenderbufferStorageMultisampleCoverageNV;
#define glRenderbufferStorageMultisampleCoverageNV glad_glRenderbufferStorageMultisampleCoverageNV
GLAPI PFNGLBINDATTRIBLOCATIONARBPROC glad_glBindAttribLocationARB;
#define glBindAttribLocationARB glad_glBindAttribLocationARB
GLAPI PFNGLBUFFERADDRESSRANGENVPROC glad_glBufferAddressRangeNV;
#define glBufferAddressRangeNV glad_glBufferAddressRangeNV
GLAPI PFNGLMULTITEXENVIVEXTPROC glad_glMultiTexEnvivEXT;
#define glMultiTexEnvivEXT glad_glMultiTexEnvivEXT
GLAPI PFNGLPROGRAMUNIFORM1UI64VNVPROC glad_glProgramUniform1ui64vNV;
#define glProgramUniform1ui64vNV glad_glProgramUniform1ui64vNV
GLAPI PFNGLSECONDARYCOLOR3UIEXTPROC glad_glSecondaryColor3uiEXT;
#define glSecondaryColor3uiEXT glad_glSecondaryColor3uiEXT
GLAPI PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC glad_glCompressedTextureImage2DEXT;
#define glCompressedTextureImage2DEXT glad_glCompressedTextureImage2DEXT
GLAPI PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC glad_glFramebufferTextureFaceEXT;
#define glFramebufferTextureFaceEXT glad_glFramebufferTextureFaceEXT
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_glFramebufferTextureLayer;
#define glFramebufferTextureLayer glad_glFramebufferTextureLayer
GLAPI PFNGLMULTITEXCOORD4BVOESPROC glad_glMultiTexCoord4bvOES;
#define glMultiTexCoord4bvOES glad_glMultiTexCoord4bvOES
GLAPI PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC glad_glGetVertexArrayPointeri_vEXT;
#define glGetVertexArrayPointeri_vEXT glad_glGetVertexArrayPointeri_vEXT
GLAPI PFNGLGETINSTRUMENTSSGIXPROC glad_glGetInstrumentsSGIX;
#define glGetInstrumentsSGIX glad_glGetInstrumentsSGIX
GLAPI PFNGLBINORMAL3BEXTPROC glad_glBinormal3bEXT;
#define glBinormal3bEXT glad_glBinormal3bEXT
GLAPI PFNGLPROGRAMUNIFORM2FVPROC glad_glProgramUniform2fv;
#define glProgramUniform2fv glad_glProgramUniform2fv
GLAPI PFNGLINTERPOLATEPATHSNVPROC glad_glInterpolatePathsNV;
#define glInterpolatePathsNV glad_glInterpolatePathsNV
GLAPI PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC glad_glCopyMultiTexSubImage3DEXT;
#define glCopyMultiTexSubImage3DEXT glad_glCopyMultiTexSubImage3DEXT
GLAPI PFNGLPROGRAMLOCALPARAMETERI4INVPROC glad_glProgramLocalParameterI4iNV;
#define glProgramLocalParameterI4iNV glad_glProgramLocalParameterI4iNV
GLAPI PFNGLGETQUERYIVARBPROC glad_glGetQueryivARB;
#define glGetQueryivARB glad_glGetQueryivARB
GLAPI PFNGLDRAWARRAYSEXTPROC glad_glDrawArraysEXT;
#define glDrawArraysEXT glad_glDrawArraysEXT
GLAPI PFNGLBLENDEQUATIONEXTPROC glad_glBlendEquationEXT;
#define glBlendEquationEXT glad_glBlendEquationEXT
GLAPI PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC glad_glCopyTextureSubImage2DEXT;
#define glCopyTextureSubImage2DEXT glad_glCopyTextureSubImage2DEXT
GLAPI PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v;
#define glGetInteger64i_v glad_glGetInteger64i_v
GLAPI PFNGLBLENDFUNCINDEXEDAMDPROC glad_glBlendFuncIndexedAMD;
#define glBlendFuncIndexedAMD glad_glBlendFuncIndexedAMD
GLAPI PFNGLMATRIXTRANSLATEDEXTPROC glad_glMatrixTranslatedEXT;
#define glMatrixTranslatedEXT glad_glMatrixTranslatedEXT
GLAPI PFNGLUNIFORM1UI64VARBPROC glad_glUniform1ui64vARB;
#define glUniform1ui64vARB glad_glUniform1ui64vARB
GLAPI PFNGLIMPORTSYNCEXTPROC glad_glImportSyncEXT;
#define glImportSyncEXT glad_glImportSyncEXT
GLAPI PFNGLMULTITEXCOORD1BVOESPROC glad_glMultiTexCoord1bvOES;
#define glMultiTexCoord1bvOES glad_glMultiTexCoord1bvOES
GLAPI PFNGLGETLISTPARAMETERFVSGIXPROC glad_glGetListParameterfvSGIX;
#define glGetListParameterfvSGIX glad_glGetListParameterfvSGIX
GLAPI PFNGLPROGRAMUNIFORMMATRIX3FVPROC glad_glProgramUniformMatrix3fv;
#define glProgramUniformMatrix3fv glad_glProgramUniformMatrix3fv
GLAPI PFNGLOBJECTPTRLABELPROC glad_glObjectPtrLabel;
#define glObjectPtrLabel glad_glObjectPtrLabel
GLAPI PFNGLGETDEBUGMESSAGELOGPROC glad_glGetDebugMessageLog;
#define glGetDebugMessageLog glad_glGetDebugMessageLog
GLAPI PFNGLTANGENT3IVEXTPROC glad_glTangent3ivEXT;
#define glTangent3ivEXT glad_glTangent3ivEXT
GLAPI PFNGLVERTEXATTRIBS4UBVNVPROC glad_glVertexAttribs4ubvNV;
#define glVertexAttribs4ubvNV glad_glVertexAttribs4ubvNV
GLAPI PFNGLFOGCOORDHVNVPROC glad_glFogCoordhvNV;
#define glFogCoordhvNV glad_glFogCoordhvNV
GLAPI PFNGLUNIFORM2I64VNVPROC glad_glUniform2i64vNV;
#define glUniform2i64vNV glad_glUniform2i64vNV
GLAPI PFNGLTEXCOORD3XVOESPROC glad_glTexCoord3xvOES;
#define glTexCoord3xvOES glad_glTexCoord3xvOES
GLAPI PFNGLMULTITEXSUBIMAGE2DEXTPROC glad_glMultiTexSubImage2DEXT;
#define glMultiTexSubImage2DEXT glad_glMultiTexSubImage2DEXT
GLAPI PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC glad_glReplacementCodeuiColor3fVertex3fSUN;
#define glReplacementCodeuiColor3fVertex3fSUN glad_glReplacementCodeuiColor3fVertex3fSUN
GLAPI PFNGLTANGENT3DVEXTPROC glad_glTangent3dvEXT;
#define glTangent3dvEXT glad_glTangent3dvEXT
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERARBPROC glad_glFramebufferTextureLayerARB;
#define glFramebufferTextureLayerARB glad_glFramebufferTextureLayerARB
GLAPI PFNGLMULTITEXCOORD1XVOESPROC glad_glMultiTexCoord1xvOES;
#define glMultiTexCoord1xvOES glad_glMultiTexCoord1xvOES
GLAPI PFNGLPROGRAMNAMEDPARAMETER4DNVPROC glad_glProgramNamedParameter4dNV;
#define glProgramNamedParameter4dNV glad_glProgramNamedParameter4dNV
GLAPI PFNGLPROGRAMUNIFORM1DEXTPROC glad_glProgramUniform1dEXT;
#define glProgramUniform1dEXT glad_glProgramUniform1dEXT
GLAPI PFNGLNORMAL3HVNVPROC glad_glNormal3hvNV;
#define glNormal3hvNV glad_glNormal3hvNV
GLAPI PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glad_glGetCombinerOutputParameterfvNV;
#define glGetCombinerOutputParameterfvNV glad_glGetCombinerOutputParameterfvNV
GLAPI PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D;
#define glCopyTexSubImage3D glad_glCopyTexSubImage3D
GLAPI PFNGLCOLOR4UBVERTEX3FVSUNPROC glad_glColor4ubVertex3fvSUN;
#define glColor4ubVertex3fvSUN glad_glColor4ubVertex3fvSUN
GLAPI PFNGLGETCOMMANDHEADERNVPROC glad_glGetCommandHeaderNV;
#define glGetCommandHeaderNV glad_glGetCommandHeaderNV
GLAPI PFNGLGETPERFMONITORCOUNTERINFOAMDPROC glad_glGetPerfMonitorCounterInfoAMD;
#define glGetPerfMonitorCounterInfoAMD glad_glGetPerfMonitorCounterInfoAMD
GLAPI PFNGLVERTEXATTRIB1SVARBPROC glad_glVertexAttrib1svARB;
#define glVertexAttrib1svARB glad_glVertexAttrib1svARB
GLAPI PFNGLPROGRAMUNIFORM4UIVPROC glad_glProgramUniform4uiv;
#define glProgramUniform4uiv glad_glProgramUniform4uiv
GLAPI PFNGLPROGRAMUNIFORM4UIEXTPROC glad_glProgramUniform4uiEXT;
#define glProgramUniform4uiEXT glad_glProgramUniform4uiEXT
GLAPI PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv;
#define glGetActiveUniformBlockiv glad_glGetActiveUniformBlockiv
GLAPI PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC glad_glDisableClientStateIndexedEXT;
#define glDisableClientStateIndexedEXT glad_glDisableClientStateIndexedEXT
GLAPI PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC glad_glGetConvolutionParameterfvEXT;
#define glGetConvolutionParameterfvEXT glad_glGetConvolutionParameterfvEXT
GLAPI PFNGLVERTEXATTRIBI4IEXTPROC glad_glVertexAttribI4iEXT;
#define glVertexAttribI4iEXT glad_glVertexAttribI4iEXT
GLAPI PFNGLCOLORFRAGMENTOP3ATIPROC glad_glColorFragmentOp3ATI;
#define glColorFragmentOp3ATI glad_glColorFragmentOp3ATI
GLAPI PFNGLRESIZEBUFFERSMESAPROC glad_glResizeBuffersMESA;
#define glResizeBuffersMESA glad_glResizeBuffersMESA
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC glad_glProgramUniformMatrix2x3dvEXT;
#define glProgramUniformMatrix2x3dvEXT glad_glProgramUniformMatrix2x3dvEXT
GLAPI PFNGLDEBUGMESSAGEINSERTAMDPROC glad_glDebugMessageInsertAMD;
#define glDebugMessageInsertAMD glad_glDebugMessageInsertAMD
GLAPI PFNGLNAMEDBUFFERSUBDATAPROC glad_glNamedBufferSubData;
#define glNamedBufferSubData glad_glNamedBufferSubData
GLAPI PFNGLOBJECTUNPURGEABLEAPPLEPROC glad_glObjectUnpurgeableAPPLE;
#define glObjectUnpurgeableAPPLE glad_glObjectUnpurgeableAPPLE
GLAPI PFNGLGETMAPPARAMETERFVNVPROC glad_glGetMapParameterfvNV;
#define glGetMapParameterfvNV glad_glGetMapParameterfvNV
GLAPI PFNGLPROGRAMUNIFORM4IVEXTPROC glad_glProgramUniform4ivEXT;
#define glProgramUniform4ivEXT glad_glProgramUniform4ivEXT
GLAPI PFNGLPROGRAMUNIFORM3UI64VNVPROC glad_glProgramUniform3ui64vNV;
#define glProgramUniform3ui64vNV glad_glProgramUniform3ui64vNV
GLAPI PFNGLGETINTERNALFORMATI64VPROC glad_glGetInternalformati64v;
#define glGetInternalformati64v glad_glGetInternalformati64v
GLAPI PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glad_glGetProgramResourceLocationIndex;
#define glGetProgramResourceLocationIndex glad_glGetProgramResourceLocationIndex
GLAPI PFNGLGETINVARIANTBOOLEANVEXTPROC glad_glGetInvariantBooleanvEXT;
#define glGetInvariantBooleanvEXT glad_glGetInvariantBooleanvEXT
GLAPI PFNGLTEXSTORAGE2DMULTISAMPLEPROC glad_glTexStorage2DMultisample;
#define glTexStorage2DMultisample glad_glTexStorage2DMultisample
GLAPI PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram;
#define glValidateProgram glad_glValidateProgram
GLAPI PFNGLPATHCOVERDEPTHFUNCNVPROC glad_glPathCoverDepthFuncNV;
#define glPathCoverDepthFuncNV glad_glPathCoverDepthFuncNV
GLAPI PFNGLDRAWCOMMANDSSTATESNVPROC glad_glDrawCommandsStatesNV;
#define glDrawCommandsStatesNV glad_glDrawCommandsStatesNV
GLAPI PFNGLMAP1XOESPROC glad_glMap1xOES;
#define glMap1xOES glad_glMap1xOES
GLAPI PFNGLVERTEXATTRIB3FVNVPROC glad_glVertexAttrib3fvNV;
#define glVertexAttrib3fvNV glad_glVertexAttrib3fvNV
GLAPI PFNGLGETMULTITEXGENDVEXTPROC glad_glGetMultiTexGendvEXT;
#define glGetMultiTexGendvEXT glad_glGetMultiTexGendvEXT
GLAPI PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glad_glGetCombinerInputParameterfvNV;
#define glGetCombinerInputParameterfvNV glad_glGetCombinerInputParameterfvNV
GLAPI PFNGLTEXCOORD1BOESPROC glad_glTexCoord1bOES;
#define glTexCoord1bOES glad_glTexCoord1bOES
GLAPI PFNGLGETTEXTURESAMPLERHANDLENVPROC glad_glGetTextureSamplerHandleNV;
#define glGetTextureSamplerHandleNV glad_glGetTextureSamplerHandleNV
GLAPI PFNGLFINISHTEXTURESUNXPROC glad_glFinishTextureSUNX;
#define glFinishTextureSUNX glad_glFinishTextureSUNX
GLAPI PFNGLUNIFORMMATRIX3X4DVPROC glad_glUniformMatrix3x4dv;
#define glUniformMatrix3x4dv glad_glUniformMatrix3x4dv
GLAPI PFNGLVERTEXATTRIBS4SVNVPROC glad_glVertexAttribs4svNV;
#define glVertexAttribs4svNV glad_glVertexAttribs4svNV
GLAPI PFNGLVERTEXATTRIB4FARBPROC glad_glVertexAttrib4fARB;
#define glVertexAttrib4fARB glad_glVertexAttrib4fARB
GLAPI PFNGLGETPROGRAMRESOURCELOCATIONPROC glad_glGetProgramResourceLocation;
#define glGetProgramResourceLocation glad_glGetProgramResourceLocation
GLAPI PFNGLMATRIXLOADTRANSPOSEFEXTPROC glad_glMatrixLoadTransposefEXT;
#define glMatrixLoadTransposefEXT glad_glMatrixLoadTransposefEXT
GLAPI PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC glad_glNamedCopyBufferSubDataEXT;
#define glNamedCopyBufferSubDataEXT glad_glNamedCopyBufferSubDataEXT
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC glad_glVertexArrayVertexAttribOffsetEXT;
#define glVertexArrayVertexAttribOffsetEXT glad_glVertexArrayVertexAttribOffsetEXT
GLAPI PFNGLINDEXFORMATNVPROC glad_glIndexFormatNV;
#define glIndexFormatNV glad_glIndexFormatNV
GLAPI PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC glad_glReplacementCodeuiVertex3fvSUN;
#define glReplacementCodeuiVertex3fvSUN glad_glReplacementCodeuiVertex3fvSUN
GLAPI PFNGLBINDBUFFERSBASEPROC glad_glBindBuffersBase;
#define glBindBuffersBase glad_glBindBuffersBase
GLAPI PFNGLWINDOWPOS3SVMESAPROC glad_glWindowPos3svMESA;
#define glWindowPos3svMESA glad_glWindowPos3svMESA
GLAPI PFNGLSTENCILOPSEPARATEATIPROC glad_glStencilOpSeparateATI;
#define glStencilOpSeparateATI glad_glStencilOpSeparateATI
GLAPI PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex;
#define glDrawElementsBaseVertex glad_glDrawElementsBaseVertex
GLAPI PFNGLVERTEXATTRIB1FNVPROC glad_glVertexAttrib1fNV;
#define glVertexAttrib1fNV glad_glVertexAttrib1fNV
GLAPI PFNGLMAPVERTEXATTRIB2FAPPLEPROC glad_glMapVertexAttrib2fAPPLE;
#define glMapVertexAttrib2fAPPLE glad_glMapVertexAttrib2fAPPLE
GLAPI PFNGLGENVERTEXSHADERSEXTPROC glad_glGenVertexShadersEXT;
#define glGenVertexShadersEXT glad_glGenVertexShadersEXT
GLAPI PFNGLCLEARBUFFERSUBDATAPROC glad_glClearBufferSubData;
#define glClearBufferSubData glad_glClearBufferSubData
GLAPI PFNGLTEXSTORAGE1DPROC glad_glTexStorage1D;
#define glTexStorage1D glad_glTexStorage1D
GLAPI PFNGLVERTEXATTRIBI3IEXTPROC glad_glVertexAttribI3iEXT;
#define glVertexAttribI3iEXT glad_glVertexAttribI3iEXT
GLAPI PFNGLUNIFORM4I64NVPROC glad_glUniform4i64NV;
#define glUniform4i64NV glad_glUniform4i64NV
GLAPI PFNGLVERTEXATTRIB3SVNVPROC glad_glVertexAttrib3svNV;
#define glVertexAttrib3svNV glad_glVertexAttrib3svNV
GLAPI PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC glad_glProgramUniformMatrix2dvEXT;
#define glProgramUniformMatrix2dvEXT glad_glProgramUniformMatrix2dvEXT
GLAPI PFNGLVERTEXATTRIBS2HVNVPROC glad_glVertexAttribs2hvNV;
#define glVertexAttribs2hvNV glad_glVertexAttribs2hvNV
GLAPI PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage;
#define glRenderbufferStorage glad_glRenderbufferStorage
GLAPI PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC glad_glDisableVertexArrayAttribEXT;
#define glDisableVertexArrayAttribEXT glad_glDisableVertexArrayAttribEXT
GLAPI PFNGLVALIDATEPROGRAMARBPROC glad_glValidateProgramARB;
#define glValidateProgramARB glad_glValidateProgramARB
GLAPI PFNGLMULTITEXCOORD3FARBPROC glad_glMultiTexCoord3fARB;
#define glMultiTexCoord3fARB glad_glMultiTexCoord3fARB
GLAPI PFNGLDELETEFRAMEBUFFERSEXTPROC glad_glDeleteFramebuffersEXT;
#define glDeleteFramebuffersEXT glad_glDeleteFramebuffersEXT
GLAPI PFNGLRESETMINMAXEXTPROC glad_glResetMinmaxEXT;
#define glResetMinmaxEXT glad_glResetMinmaxEXT
GLAPI PFNGLVERTEXATTRIB1FVNVPROC glad_glVertexAttrib1fvNV;
#define glVertexAttrib1fvNV glad_glVertexAttrib1fvNV
GLAPI PFNGLISQUERYARBPROC glad_glIsQueryARB;
#define glIsQueryARB glad_glIsQueryARB
GLAPI PFNGLSCISSORINDEXEDPROC glad_glScissorIndexed;
#define glScissorIndexed glad_glScissorIndexed
GLAPI PFNGLGETINVARIANTINTEGERVEXTPROC glad_glGetInvariantIntegervEXT;
#define glGetInvariantIntegervEXT glad_glGetInvariantIntegervEXT
GLAPI PFNGLGENFRAMEBUFFERSEXTPROC glad_glGenFramebuffersEXT;
#define glGenFramebuffersEXT glad_glGenFramebuffersEXT
GLAPI PFNGLVERTEXARRAYCOLOROFFSETEXTPROC glad_glVertexArrayColorOffsetEXT;
#define glVertexArrayColorOffsetEXT glad_glVertexArrayColorOffsetEXT
GLAPI PFNGLMULTITEXCOORD3IVARBPROC glad_glMultiTexCoord3ivARB;
#define glMultiTexCoord3ivARB glad_glMultiTexCoord3ivARB
GLAPI PFNGLVERTEXWEIGHTFEXTPROC glad_glVertexWeightfEXT;
#define glVertexWeightfEXT glad_glVertexWeightfEXT
GLAPI PFNGLWINDOWPOS4IVMESAPROC glad_glWindowPos4ivMESA;
#define glWindowPos4ivMESA glad_glWindowPos4ivMESA
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glad_glDrawElementsInstancedBaseVertexBaseInstance;
#define glDrawElementsInstancedBaseVertexBaseInstance glad_glDrawElementsInstancedBaseVertexBaseInstance
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC glad_glNamedProgramLocalParameterI4uiEXT;
#define glNamedProgramLocalParameterI4uiEXT glad_glNamedProgramLocalParameterI4uiEXT
GLAPI PFNGLMAPNAMEDBUFFERRANGEEXTPROC glad_glMapNamedBufferRangeEXT;
#define glMapNamedBufferRangeEXT glad_glMapNamedBufferRangeEXT
GLAPI PFNGLCREATESHADERPROGRAMVPROC glad_glCreateShaderProgramv;
#define glCreateShaderProgramv glad_glCreateShaderProgramv
GLAPI PFNGLGETQUERYOBJECTIVPROC glad_glGetQueryObjectiv;
#define glGetQueryObjectiv glad_glGetQueryObjectiv
GLAPI PFNGLGLOBALALPHAFACTORUSSUNPROC glad_glGlobalAlphaFactorusSUN;
#define glGlobalAlphaFactorusSUN glad_glGlobalAlphaFactorusSUN
GLAPI PFNGLVERTEXATTRIB3DVNVPROC glad_glVertexAttrib3dvNV;
#define glVertexAttrib3dvNV glad_glVertexAttrib3dvNV
GLAPI PFNGLMULTITEXCOORD3SARBPROC glad_glMultiTexCoord3sARB;
#define glMultiTexCoord3sARB glad_glMultiTexCoord3sARB
GLAPI PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap;
#define glGenerateMipmap glad_glGenerateMipmap
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glad_glNamedRenderbufferStorageMultisampleEXT;
#define glNamedRenderbufferStorageMultisampleEXT glad_glNamedRenderbufferStorageMultisampleEXT
GLAPI PFNGLSAMPLEMASKEXTPROC glad_glSampleMaskEXT;
#define glSampleMaskEXT glad_glSampleMaskEXT
GLAPI PFNGLPROGRAMUNIFORM2FVEXTPROC glad_glProgramUniform2fvEXT;
#define glProgramUniform2fvEXT glad_glProgramUniform2fvEXT
GLAPI PFNGLTEXCOORD1XVOESPROC glad_glTexCoord1xvOES;
#define glTexCoord1xvOES glad_glTexCoord1xvOES
GLAPI PFNGLTEXTUREPARAMETERIUIVEXTPROC glad_glTextureParameterIuivEXT;
#define glTextureParameterIuivEXT glad_glTextureParameterIuivEXT
GLAPI PFNGLDELETERENDERBUFFERSEXTPROC glad_glDeleteRenderbuffersEXT;
#define glDeleteRenderbuffersEXT glad_glDeleteRenderbuffersEXT
GLAPI PFNGLVERTEXATTRIBP4UIVPROC glad_glVertexAttribP4uiv;
#define glVertexAttribP4uiv glad_glVertexAttribP4uiv
GLAPI PFNGLPROGRAMUNIFORM2UI64VNVPROC glad_glProgramUniform2ui64vNV;
#define glProgramUniform2ui64vNV glad_glProgramUniform2ui64vNV
GLAPI PFNGLTEXCOORD3BVOESPROC glad_glTexCoord3bvOES;
#define glTexCoord3bvOES glad_glTexCoord3bvOES
GLAPI PFNGLREADPIXELSPROC glad_glReadPixels;
#define glReadPixels glad_glReadPixels
GLAPI PFNGLVERTEXATTRIBI3IVPROC glad_glVertexAttribI3iv;
#define glVertexAttribI3iv glad_glVertexAttribI3iv
GLAPI PFNGLBUFFERPAGECOMMITMENTARBPROC glad_glBufferPageCommitmentARB;
#define glBufferPageCommitmentARB glad_glBufferPageCommitmentARB
GLAPI PFNGLCONSERVATIVERASTERPARAMETERINVPROC glad_glConservativeRasterParameteriNV;
#define glConservativeRasterParameteriNV glad_glConservativeRasterParameteriNV
GLAPI PFNGLGETDOUBLEI_VEXTPROC glad_glGetDoublei_vEXT;
#define glGetDoublei_vEXT glad_glGetDoublei_vEXT
GLAPI PFNGLFOGCOORDFEXTPROC glad_glFogCoordfEXT;
#define glFogCoordfEXT glad_glFogCoordfEXT
GLAPI PFNGLMULTITEXCOORD4DARBPROC glad_glMultiTexCoord4dARB;
#define glMultiTexCoord4dARB glad_glMultiTexCoord4dARB
GLAPI PFNGLBLENDEQUATIONSEPARATEIARBPROC glad_glBlendEquationSeparateiARB;
#define glBlendEquationSeparateiARB glad_glBlendEquationSeparateiARB
GLAPI PFNGLUNIFORM3I64ARBPROC glad_glUniform3i64ARB;
#define glUniform3i64ARB glad_glUniform3i64ARB
GLAPI PFNGLPROGRAMUNIFORM2DEXTPROC glad_glProgramUniform2dEXT;
#define glProgramUniform2dEXT glad_glProgramUniform2dEXT
GLAPI PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC glad_glMultiDrawElementArrayAPPLE;
#define glMultiDrawElementArrayAPPLE glad_glMultiDrawElementArrayAPPLE
GLAPI PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC glad_glProgramUniformHandleui64ARB;
#define glProgramUniformHandleui64ARB glad_glProgramUniformHandleui64ARB
GLAPI PFNGLGETVERTEXATTRIBLDVPROC glad_glGetVertexAttribLdv;
#define glGetVertexAttribLdv glad_glGetVertexAttribLdv
GLAPI PFNGLTEXSTORAGE3DMULTISAMPLEPROC glad_glTexStorage3DMultisample;
#define glTexStorage3DMultisample glad_glTexStorage3DMultisample
GLAPI PFNGLGETUNIFORMUI64VNVPROC glad_glGetUniformui64vNV;
#define glGetUniformui64vNV glad_glGetUniformui64vNV
GLAPI PFNGLVERTEXATTRIB3DNVPROC glad_glVertexAttrib3dNV;
#define glVertexAttrib3dNV glad_glVertexAttrib3dNV
GLAPI PFNGLTEXTURESTORAGE1DEXTPROC glad_glTextureStorage1DEXT;
#define glTextureStorage1DEXT glad_glTextureStorage1DEXT
GLAPI PFNGLPIXELTEXGENPARAMETERISGISPROC glad_glPixelTexGenParameteriSGIS;
#define glPixelTexGenParameteriSGIS glad_glPixelTexGenParameteriSGIS
GLAPI PFNGLCOLORTABLEEXTPROC glad_glColorTableEXT;
#define glColorTableEXT glad_glColorTableEXT
GLAPI PFNGLEXECUTEPROGRAMNVPROC glad_glExecuteProgramNV;
#define glExecuteProgramNV glad_glExecuteProgramNV
GLAPI PFNGLCOLOR3XVOESPROC glad_glColor3xvOES;
#define glColor3xvOES glad_glColor3xvOES
GLAPI PFNGLTEXIMAGE3DPROC glad_glTexImage3D;
#define glTexImage3D glad_glTexImage3D
GLAPI PFNGLMATRIXPOPEXTPROC glad_glMatrixPopEXT;
#define glMatrixPopEXT glad_glMatrixPopEXT
GLAPI PFNGLVERTEXSTREAM1SATIPROC glad_glVertexStream1sATI;
#define glVertexStream1sATI glad_glVertexStream1sATI
GLAPI PFNGLVERTEXATTRIBI2IEXTPROC glad_glVertexAttribI2iEXT;
#define glVertexAttribI2iEXT glad_glVertexAttribI2iEXT
GLAPI PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC glad_glNamedFramebufferSampleLocationsfvNV;
#define glNamedFramebufferSampleLocationsfvNV glad_glNamedFramebufferSampleLocationsfvNV
GLAPI PFNGLFRAGMENTCOVERAGECOLORNVPROC glad_glFragmentCoverageColorNV;
#define glFragmentCoverageColorNV glad_glFragmentCoverageColorNV
GLAPI PFNGLGETPERFMONITORGROUPSAMDPROC glad_glGetPerfMonitorGroupsAMD;
#define glGetPerfMonitorGroupsAMD glad_glGetPerfMonitorGroupsAMD
GLAPI PFNGLMULTITEXIMAGE2DEXTPROC glad_glMultiTexImage2DEXT;
#define glMultiTexImage2DEXT glad_glMultiTexImage2DEXT
GLAPI PFNGLEDGEFLAGPOINTEREXTPROC glad_glEdgeFlagPointerEXT;
#define glEdgeFlagPointerEXT glad_glEdgeFlagPointerEXT
GLAPI PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC glad_glVideoCaptureStreamParameterivNV;
#define glVideoCaptureStreamParameterivNV glad_glVideoCaptureStreamParameterivNV
GLAPI PFNGLVERTEXSTREAM4IATIPROC glad_glVertexStream4iATI;
#define glVertexStream4iATI glad_glVertexStream4iATI
GLAPI PFNGLMULTITEXCOORD2FVARBPROC glad_glMultiTexCoord2fvARB;
#define glMultiTexCoord2fvARB glad_glMultiTexCoord2fvARB
GLAPI PFNGLVARIANTUIVEXTPROC glad_glVariantuivEXT;
#define glVariantuivEXT glad_glVariantuivEXT
GLAPI PFNGLCOPYTEXSUBIMAGE3DEXTPROC glad_glCopyTexSubImage3DEXT;
#define glCopyTexSubImage3DEXT glad_glCopyTexSubImage3DEXT
GLAPI PFNGLSPRITEPARAMETERISGIXPROC glad_glSpriteParameteriSGIX;
#define glSpriteParameteriSGIX glad_glSpriteParameteriSGIX
GLAPI PFNGLUNIFORM4I64ARBPROC glad_glUniform4i64ARB;
#define glUniform4i64ARB glad_glUniform4i64ARB
GLAPI PFNGLTEXTURENORMALEXTPROC glad_glTextureNormalEXT;
#define glTextureNormalEXT glad_glTextureNormalEXT
GLAPI PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC glad_glCompressedMultiTexImage3DEXT;
#define glCompressedMultiTexImage3DEXT glad_glCompressedMultiTexImage3DEXT
GLAPI PFNGLMULTITEXCOORD2IVARBPROC glad_glMultiTexCoord2ivARB;
#define glMultiTexCoord2ivARB glad_glMultiTexCoord2ivARB
GLAPI PFNGLCREATERENDERBUFFERSPROC glad_glCreateRenderbuffers;
#define glCreateRenderbuffers glad_glCreateRenderbuffers
GLAPI PFNGLVERTEXATTRIB4NUSVPROC glad_glVertexAttrib4Nusv;
#define glVertexAttrib4Nusv glad_glVertexAttrib4Nusv
GLAPI PFNGLDEPTHFUNCPROC glad_glDepthFunc;
#define glDepthFunc glad_glDepthFunc
GLAPI PFNGLWINDOWPOS4FMESAPROC glad_glWindowPos4fMESA;
#define glWindowPos4fMESA glad_glWindowPos4fMESA
GLAPI PFNGLENABLECLIENTSTATEINDEXEDEXTPROC glad_glEnableClientStateIndexedEXT;
#define glEnableClientStateIndexedEXT glad_glEnableClientStateIndexedEXT
GLAPI PFNGLPROGRAMUNIFORM4I64ARBPROC glad_glProgramUniform4i64ARB;
#define glProgramUniform4i64ARB glad_glProgramUniform4i64ARB
GLAPI PFNGLRESOLVEDEPTHVALUESNVPROC glad_glResolveDepthValuesNV;
#define glResolveDepthValuesNV glad_glResolveDepthValuesNV
GLAPI PFNGLCREATESHADERPROGRAMEXTPROC glad_glCreateShaderProgramEXT;
#define glCreateShaderProgramEXT glad_glCreateShaderProgramEXT
GLAPI PFNGLBUFFERSTORAGEPROC glad_glBufferStorage;
#define glBufferStorage glad_glBufferStorage
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glad_glRenderbufferStorageMultisampleEXT;
#define glRenderbufferStorageMultisampleEXT glad_glRenderbufferStorageMultisampleEXT
GLAPI PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC glad_glListDrawCommandsStatesClientNV;
#define glListDrawCommandsStatesClientNV glad_glListDrawCommandsStatesClientNV
GLAPI PFNGLUNIFORM2UI64ARBPROC glad_glUniform2ui64ARB;
#define glUniform2ui64ARB glad_glUniform2ui64ARB
GLAPI PFNGLPROGRAMUNIFORM4FEXTPROC glad_glProgramUniform4fEXT;
#define glProgramUniform4fEXT glad_glProgramUniform4fEXT
GLAPI PFNGLBINDVERTEXSHADEREXTPROC glad_glBindVertexShaderEXT;
#define glBindVertexShaderEXT glad_glBindVertexShaderEXT
GLAPI PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation;
#define glGetUniformLocation glad_glGetUniformLocation
GLAPI PFNGLVERTEXSTREAM3FATIPROC glad_glVertexStream3fATI;
#define glVertexStream3fATI glad_glVertexStream3fATI
GLAPI PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glad_glNamedFramebufferDrawBuffers;
#define glNamedFramebufferDrawBuffers glad_glNamedFramebufferDrawBuffers
GLAPI PFNGLUNIFORM2UI64VNVPROC glad_glUniform2ui64vNV;
#define glUniform2ui64vNV glad_glUniform2ui64vNV
GLAPI PFNGLTEXCOORDPOINTERVINTELPROC glad_glTexCoordPointervINTEL;
#define glTexCoordPointervINTEL glad_glTexCoordPointervINTEL
GLAPI PFNGLUNIFORM4FVPROC glad_glUniform4fv;
#define glUniform4fv glad_glUniform4fv
GLAPI PFNGLNORMALPOINTEREXTPROC glad_glNormalPointerEXT;
#define glNormalPointerEXT glad_glNormalPointerEXT
GLAPI PFNGLTEXTURESTORAGESPARSEAMDPROC glad_glTextureStorageSparseAMD;
#define glTextureStorageSparseAMD glad_glTextureStorageSparseAMD
GLAPI PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC glad_glGetConvolutionParameterivEXT;
#define glGetConvolutionParameterivEXT glad_glGetConvolutionParameterivEXT
GLAPI PFNGLENDPERFQUERYINTELPROC glad_glEndPerfQueryINTEL;
#define glEndPerfQueryINTEL glad_glEndPerfQueryINTEL
GLAPI PFNGLVERTEX3BVOESPROC glad_glVertex3bvOES;
#define glVertex3bvOES glad_glVertex3bvOES
GLAPI PFNGLENDCONDITIONALRENDERPROC glad_glEndConditionalRender;
#define glEndConditionalRender glad_glEndConditionalRender
GLAPI PFNGLTEXSUBIMAGE2DEXTPROC glad_glTexSubImage2DEXT;
#define glTexSubImage2DEXT glad_glTexSubImage2DEXT
GLAPI PFNGLVERTEXATTRIB4IVPROC glad_glVertexAttrib4iv;
#define glVertexAttrib4iv glad_glVertexAttrib4iv
GLAPI PFNGLLABELOBJECTEXTPROC glad_glLabelObjectEXT;
#define glLabelObjectEXT glad_glLabelObjectEXT
GLAPI PFNGLPROGRAMUNIFORM1UIVPROC glad_glProgramUniform1uiv;
#define glProgramUniform1uiv glad_glProgramUniform1uiv
GLAPI PFNGLCOPYIMAGESUBDATANVPROC glad_glCopyImageSubDataNV;
#define glCopyImageSubDataNV glad_glCopyImageSubDataNV
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC glad_glNamedProgramLocalParameter4fvEXT;
#define glNamedProgramLocalParameter4fvEXT glad_glNamedProgramLocalParameter4fvEXT
GLAPI PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC glad_glGetPixelTransformParameterfvEXT;
#define glGetPixelTransformParameterfvEXT glad_glGetPixelTransformParameterfvEXT
GLAPI PFNGLAREPROGRAMSRESIDENTNVPROC glad_glAreProgramsResidentNV;
#define glAreProgramsResidentNV glad_glAreProgramsResidentNV
GLAPI PFNGLBEGINQUERYINDEXEDPROC glad_glBeginQueryIndexed;
#define glBeginQueryIndexed glad_glBeginQueryIndexed
GLAPI PFNGLGETIMAGEHANDLENVPROC glad_glGetImageHandleNV;
#define glGetImageHandleNV glad_glGetImageHandleNV
GLAPI PFNGLDELETEFENCESNVPROC glad_glDeleteFencesNV;
#define glDeleteFencesNV glad_glDeleteFencesNV
GLAPI PFNGLVERTEXSTREAM2SATIPROC glad_glVertexStream2sATI;
#define glVertexStream2sATI glad_glVertexStream2sATI
GLAPI PFNGLPROGRAMUNIFORM2DVPROC glad_glProgramUniform2dv;
#define glProgramUniform2dv glad_glProgramUniform2dv
GLAPI PFNGLACTIVETEXTUREPROC glad_glActiveTexture;
#define glActiveTexture glad_glActiveTexture
GLAPI PFNGLPROGRAMUNIFORM4DEXTPROC glad_glProgramUniform4dEXT;
#define glProgramUniform4dEXT glad_glProgramUniform4dEXT
GLAPI PFNGLPOINTSIZEXOESPROC glad_glPointSizexOES;
#define glPointSizexOES glad_glPointSizexOES
GLAPI PFNGLGETFLOATVPROC glad_glGetFloatv;
#define glGetFloatv glad_glGetFloatv
GLAPI PFNGLWEIGHTDVARBPROC glad_glWeightdvARB;
#define glWeightdvARB glad_glWeightdvARB
GLAPI PFNGLVERTEXATTRIBDIVISORARBPROC glad_glVertexAttribDivisorARB;
#define glVertexAttribDivisorARB glad_glVertexAttribDivisorARB
GLAPI PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC glad_glGetnCompressedTexImageARB;
#define glGetnCompressedTexImageARB glad_glGetnCompressedTexImageARB
GLAPI PFNGLMATRIXLOADDEXTPROC glad_glMatrixLoaddEXT;
#define glMatrixLoaddEXT glad_glMatrixLoaddEXT
GLAPI PFNGLGETPATHLENGTHNVPROC glad_glGetPathLengthNV;
#define glGetPathLengthNV glad_glGetPathLengthNV
GLAPI PFNGLPROGRAMUNIFORMMATRIX3DVPROC glad_glProgramUniformMatrix3dv;
#define glProgramUniformMatrix3dv glad_glProgramUniformMatrix3dv
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glRenderbufferStorageMultisample;
#define glRenderbufferStorageMultisample glad_glRenderbufferStorageMultisample
GLAPI PFNGLVERTEXATTRIB4NUIVARBPROC glad_glVertexAttrib4NuivARB;
#define glVertexAttrib4NuivARB glad_glVertexAttrib4NuivARB
GLAPI PFNGLMAPGRID2XOESPROC glad_glMapGrid2xOES;
#define glMapGrid2xOES glad_glMapGrid2xOES
GLAPI PFNGLTEXIMAGE2DPROC glad_glTexImage2D;
#define glTexImage2D glad_glTexImage2D
GLAPI PFNGLGETVIDEOUI64VNVPROC glad_glGetVideoui64vNV;
#define glGetVideoui64vNV glad_glGetVideoui64vNV
GLAPI PFNGLUNIFORM2UIEXTPROC glad_glUniform2uiEXT;
#define glUniform2uiEXT glad_glUniform2uiEXT
GLAPI PFNGLISTEXTUREPROC glad_glIsTexture;
#define glIsTexture glad_glIsTexture
GLAPI PFNGLPROGRAMUNIFORM3FEXTPROC glad_glProgramUniform3fEXT;
#define glProgramUniform3fEXT glad_glProgramUniform3fEXT
GLAPI PFNGLVERTEXATTRIBS1HVNVPROC glad_glVertexAttribs1hvNV;
#define glVertexAttribs1hvNV glad_glVertexAttribs1hvNV
GLAPI PFNGLTEXTURERENDERBUFFEREXTPROC glad_glTextureRenderbufferEXT;
#define glTextureRenderbufferEXT glad_glTextureRenderbufferEXT
GLAPI PFNGLGETSAMPLERPARAMETERIVPROC glad_glGetSamplerParameteriv;
#define glGetSamplerParameteriv glad_glGetSamplerParameteriv
GLAPI PFNGLVERTEXATTRIBL4DVEXTPROC glad_glVertexAttribL4dvEXT;
#define glVertexAttribL4dvEXT glad_glVertexAttribL4dvEXT
GLAPI PFNGLUNIFORM2UI64VARBPROC glad_glUniform2ui64vARB;
#define glUniform2ui64vARB glad_glUniform2ui64vARB
GLAPI PFNGLMAKENAMEDBUFFERRESIDENTNVPROC glad_glMakeNamedBufferResidentNV;
#define glMakeNamedBufferResidentNV glad_glMakeNamedBufferResidentNV
GLAPI PFNGLPATHGLYPHINDEXRANGENVPROC glad_glPathGlyphIndexRangeNV;
#define glPathGlyphIndexRangeNV glad_glPathGlyphIndexRangeNV
GLAPI PFNGLMULTITEXPARAMETERFEXTPROC glad_glMultiTexParameterfEXT;
#define glMultiTexParameterfEXT glad_glMultiTexParameterfEXT
GLAPI PFNGLVERTEXATTRIB3DARBPROC glad_glVertexAttrib3dARB;
#define glVertexAttrib3dARB glad_glVertexAttrib3dARB
GLAPI PFNGLISASYNCMARKERSGIXPROC glad_glIsAsyncMarkerSGIX;
#define glIsAsyncMarkerSGIX glad_glIsAsyncMarkerSGIX
GLAPI PFNGLTEXPARAMETERIUIVEXTPROC glad_glTexParameterIuivEXT;
#define glTexParameterIuivEXT glad_glTexParameterIuivEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX4FVPROC glad_glProgramUniformMatrix4fv;
#define glProgramUniformMatrix4fv glad_glProgramUniformMatrix4fv
GLAPI PFNGLGETTEXTUREPARAMETERIUIVEXTPROC glad_glGetTextureParameterIuivEXT;
#define glGetTextureParameterIuivEXT glad_glGetTextureParameterIuivEXT
GLAPI PFNGLVERTEXATTRIBL3DEXTPROC glad_glVertexAttribL3dEXT;
#define glVertexAttribL3dEXT glad_glVertexAttribL3dEXT
GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer;
#define glFramebufferRenderbuffer glad_glFramebufferRenderbuffer
GLAPI PFNGLGETDOUBLEI_VPROC glad_glGetDoublei_v;
#define glGetDoublei_v glad_glGetDoublei_v
GLAPI PFNGLVERTEXATTRIB1SVPROC glad_glVertexAttrib1sv;
#define glVertexAttrib1sv glad_glVertexAttrib1sv
GLAPI PFNGLIMAGETRANSFORMPARAMETERFVHPPROC glad_glImageTransformParameterfvHP;
#define glImageTransformParameterfvHP glad_glImageTransformParameterfvHP
GLAPI PFNGLBINDBUFFEROFFSETEXTPROC glad_glBindBufferOffsetEXT;
#define glBindBufferOffsetEXT glad_glBindBufferOffsetEXT
GLAPI PFNGLGETINTEGERI_VPROC glad_glGetIntegeri_v;
#define glGetIntegeri_v glad_glGetIntegeri_v
GLAPI PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glad_glProgramLocalParameter4fvARB;
#define glProgramLocalParameter4fvARB glad_glProgramLocalParameter4fvARB
GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC glad_glGetTransformFeedbackVaryingNV;
#define glGetTransformFeedbackVaryingNV glad_glGetTransformFeedbackVaryingNV
GLAPI PFNGLVERTEXSTREAM1DATIPROC glad_glVertexStream1dATI;
#define glVertexStream1dATI glad_glVertexStream1dATI
GLAPI PFNGLCOLORFRAGMENTOP2ATIPROC glad_glColorFragmentOp2ATI;
#define glColorFragmentOp2ATI glad_glColorFragmentOp2ATI
GLAPI PFNGLGETTEXTUREHANDLENVPROC glad_glGetTextureHandleNV;
#define glGetTextureHandleNV glad_glGetTextureHandleNV
GLAPI PFNGLDEPTHRANGEFPROC glad_glDepthRangef;
#define glDepthRangef glad_glDepthRangef
GLAPI PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC glad_glVideoCaptureStreamParameterfvNV;
#define glVideoCaptureStreamParameterfvNV glad_glVideoCaptureStreamParameterfvNV
GLAPI PFNGLDELETEPROGRAMSARBPROC glad_glDeleteProgramsARB;
#define glDeleteProgramsARB glad_glDeleteProgramsARB
GLAPI PFNGLFEEDBACKBUFFERXOESPROC glad_glFeedbackBufferxOES;
#define glFeedbackBufferxOES glad_glFeedbackBufferxOES
GLAPI PFNGLBLENDCOLOREXTPROC glad_glBlendColorEXT;
#define glBlendColorEXT glad_glBlendColorEXT
GLAPI PFNGLDELETEPROGRAMSNVPROC glad_glDeleteProgramsNV;
#define glDeleteProgramsNV glad_glDeleteProgramsNV
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC glad_glNamedRenderbufferStorageEXT;
#define glNamedRenderbufferStorageEXT glad_glNamedRenderbufferStorageEXT
GLAPI PFNGLVERTEXBLENDARBPROC glad_glVertexBlendARB;
#define glVertexBlendARB glad_glVertexBlendARB
GLAPI PFNGLPIXELDATARANGENVPROC glad_glPixelDataRangeNV;
#define glPixelDataRangeNV glad_glPixelDataRangeNV
GLAPI PFNGLPOLLINSTRUMENTSSGIXPROC glad_glPollInstrumentsSGIX;
#define glPollInstrumentsSGIX glad_glPollInstrumentsSGIX
GLAPI PFNGLINDEXFUNCEXTPROC glad_glIndexFuncEXT;
#define glIndexFuncEXT glad_glIndexFuncEXT
GLAPI PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC glad_glGetFramebufferParameterivEXT;
#define glGetFramebufferParameterivEXT glad_glGetFramebufferParameterivEXT
GLAPI PFNGLSTENCILTHENCOVERFILLPATHNVPROC glad_glStencilThenCoverFillPathNV;
#define glStencilThenCoverFillPathNV glad_glStencilThenCoverFillPathNV
GLAPI PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glad_glGetCombinerOutputParameterivNV;
#define glGetCombinerOutputParameterivNV glad_glGetCombinerOutputParameterivNV
GLAPI PFNGLTEXSTORAGE2DPROC glad_glTexStorage2D;
#define glTexStorage2D glad_glTexStorage2D
GLAPI PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv;
#define glUniformMatrix3x4fv glad_glUniformMatrix3x4fv
GLAPI PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC glad_glProgramUniformMatrix3fvEXT;
#define glProgramUniformMatrix3fvEXT glad_glProgramUniformMatrix3fvEXT
GLAPI PFNGLCOLORTABLEPARAMETERFVSGIPROC glad_glColorTableParameterfvSGI;
#define glColorTableParameterfvSGI glad_glColorTableParameterfvSGI
GLAPI PFNGLMULTITEXRENDERBUFFEREXTPROC glad_glMultiTexRenderbufferEXT;
#define glMultiTexRenderbufferEXT glad_glMultiTexRenderbufferEXT
GLAPI PFNGLPRIMITIVEBOUNDINGBOXARBPROC glad_glPrimitiveBoundingBoxARB;
#define glPrimitiveBoundingBoxARB glad_glPrimitiveBoundingBoxARB
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC glad_glNamedProgramLocalParameter4dvEXT;
#define glNamedProgramLocalParameter4dvEXT glad_glNamedProgramLocalParameter4dvEXT
GLAPI PFNGLCOLORMASKIPROC glad_glColorMaski;
#define glColorMaski glad_glColorMaski
GLAPI PFNGLVERTEXSTREAM2IVATIPROC glad_glVertexStream2ivATI;
#define glVertexStream2ivATI glad_glVertexStream2ivATI
GLAPI PFNGLCOPYNAMEDBUFFERSUBDATAPROC glad_glCopyNamedBufferSubData;
#define glCopyNamedBufferSubData glad_glCopyNamedBufferSubData
GLAPI PFNGLGENPROGRAMSNVPROC glad_glGenProgramsNV;
#define glGenProgramsNV glad_glGenProgramsNV
GLAPI PFNGLFRAGMENTLIGHTFSGIXPROC glad_glFragmentLightfSGIX;
#define glFragmentLightfSGIX glad_glFragmentLightfSGIX
GLAPI PFNGLTEXSTORAGE3DPROC glad_glTexStorage3D;
#define glTexStorage3D glad_glTexStorage3D
GLAPI PFNGLNAMEDBUFFERDATAEXTPROC glad_glNamedBufferDataEXT;
#define glNamedBufferDataEXT glad_glNamedBufferDataEXT
GLAPI PFNGLSUBPIXELPRECISIONBIASNVPROC glad_glSubpixelPrecisionBiasNV;
#define glSubpixelPrecisionBiasNV glad_glSubpixelPrecisionBiasNV
GLAPI PFNGLATTACHSHADERPROC glad_glAttachShader;
#define glAttachShader glad_glAttachShader
GLAPI PFNGLTANGENT3FVEXTPROC glad_glTangent3fvEXT;
#define glTangent3fvEXT glad_glTangent3fvEXT
GLAPI PFNGLVERTEXATTRIB4DNVPROC glad_glVertexAttrib4dNV;
#define glVertexAttrib4dNV glad_glVertexAttrib4dNV
GLAPI PFNGLVERTEXARRAYVERTEXBUFFERSPROC glad_glVertexArrayVertexBuffers;
#define glVertexArrayVertexBuffers glad_glVertexArrayVertexBuffers
GLAPI PFNGLVERTEXATTRIBL3I64NVPROC glad_glVertexAttribL3i64NV;
#define glVertexAttribL3i64NV glad_glVertexAttribL3i64NV
GLAPI PFNGLSTENCILCLEARTAGEXTPROC glad_glStencilClearTagEXT;
#define glStencilClearTagEXT glad_glStencilClearTagEXT
GLAPI PFNGLPROGRAMPARAMETERIPROC glad_glProgramParameteri;
#define glProgramParameteri glad_glProgramParameteri
GLAPI PFNGLGETACTIVEUNIFORMNAMEPROC glad_glGetActiveUniformName;
#define glGetActiveUniformName glad_glGetActiveUniformName
GLAPI PFNGLPROGRAMUNIFORM2I64VARBPROC glad_glProgramUniform2i64vARB;
#define glProgramUniform2i64vARB glad_glProgramUniform2i64vARB
GLAPI PFNGLDEBUGMESSAGEENABLEAMDPROC glad_glDebugMessageEnableAMD;
#define glDebugMessageEnableAMD glad_glDebugMessageEnableAMD
GLAPI PFNGLCOPYTEXSUBIMAGE2DEXTPROC glad_glCopyTexSubImage2DEXT;
#define glCopyTexSubImage2DEXT glad_glCopyTexSubImage2DEXT
GLAPI PFNGLGENRENDERBUFFERSEXTPROC glad_glGenRenderbuffersEXT;
#define glGenRenderbuffersEXT glad_glGenRenderbuffersEXT
GLAPI PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC glad_glNamedProgramLocalParameterI4ivEXT;
#define glNamedProgramLocalParameterI4ivEXT glad_glNamedProgramLocalParameterI4ivEXT
GLAPI PFNGLGETMULTITEXPARAMETERIUIVEXTPROC glad_glGetMultiTexParameterIuivEXT;
#define glGetMultiTexParameterIuivEXT glad_glGetMultiTexParameterIuivEXT
GLAPI PFNGLWINDOWPOS3FVARBPROC glad_glWindowPos3fvARB;
#define glWindowPos3fvARB glad_glWindowPos3fvARB
GLAPI PFNGLUNIFORM4IVARBPROC glad_glUniform4ivARB;
#define glUniform4ivARB glad_glUniform4ivARB
GLAPI PFNGLVERTEXARRAYVERTEXBUFFERPROC glad_glVertexArrayVertexBuffer;
#define glVertexArrayVertexBuffer glad_glVertexArrayVertexBuffer
GLAPI PFNGLGETNAMEDSTRINGIVARBPROC glad_glGetNamedStringivARB;
#define glGetNamedStringivARB glad_glGetNamedStringivARB
GLAPI PFNGLVERTEXATTRIBL1I64VNVPROC glad_glVertexAttribL1i64vNV;
#define glVertexAttribL1i64vNV glad_glVertexAttribL1i64vNV
GLAPI PFNGLPOINTPARAMETERIVNVPROC glad_glPointParameterivNV;
#define glPointParameterivNV glad_glPointParameterivNV
GLAPI PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC glad_glReplacementCodeuiColor3fVertex3fvSUN;
#define glReplacementCodeuiColor3fVertex3fvSUN glad_glReplacementCodeuiColor3fVertex3fvSUN
GLAPI PFNGLNORMALSTREAM3DVATIPROC glad_glNormalStream3dvATI;
#define glNormalStream3dvATI glad_glNormalStream3dvATI
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC glad_glNamedFramebufferTextureLayerEXT;
#define glNamedFramebufferTextureLayerEXT glad_glNamedFramebufferTextureLayerEXT
GLAPI PFNGLPATHSTENCILDEPTHOFFSETNVPROC glad_glPathStencilDepthOffsetNV;
#define glPathStencilDepthOffsetNV glad_glPathStencilDepthOffsetNV
GLAPI PFNGLGETQUERYIVPROC glad_glGetQueryiv;
#define glGetQueryiv glad_glGetQueryiv
GLAPI PFNGLGETTRANSFORMFEEDBACKIVPROC glad_glGetTransformFeedbackiv;
#define glGetTransformFeedbackiv glad_glGetTransformFeedbackiv
GLAPI PFNGLGETSAMPLERPARAMETERFVPROC glad_glGetSamplerParameterfv;
#define glGetSamplerParameterfv glad_glGetSamplerParameterfv
GLAPI PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices;
#define glGetUniformIndices glad_glGetUniformIndices
GLAPI PFNGLMULTITEXIMAGE3DEXTPROC glad_glMultiTexImage3DEXT;
#define glMultiTexImage3DEXT glad_glMultiTexImage3DEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC glad_glProgramUniformMatrix3x4dvEXT;
#define glProgramUniformMatrix3x4dvEXT glad_glProgramUniformMatrix3x4dvEXT
GLAPI PFNGLLOADTRANSPOSEMATRIXFARBPROC glad_glLoadTransposeMatrixfARB;
#define glLoadTransposeMatrixfARB glad_glLoadTransposeMatrixfARB
GLAPI PFNGLISSTATENVPROC glad_glIsStateNV;
#define glIsStateNV glad_glIsStateNV
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC glad_glProgramUniformMatrix4x3dvEXT;
#define glProgramUniformMatrix4x3dvEXT glad_glProgramUniformMatrix4x3dvEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC glad_glProgramUniformMatrix4x2fvEXT;
#define glProgramUniformMatrix4x2fvEXT glad_glProgramUniformMatrix4x2fvEXT
GLAPI PFNGLUNIFORM1I64VARBPROC glad_glUniform1i64vARB;
#define glUniform1i64vARB glad_glUniform1i64vARB
GLAPI PFNGLVERTEXATTRIBP3UIPROC glad_glVertexAttribP3ui;
#define glVertexAttribP3ui glad_glVertexAttribP3ui
GLAPI PFNGLCOLOR3FVERTEX3FSUNPROC glad_glColor3fVertex3fSUN;
#define glColor3fVertex3fSUN glad_glColor3fVertex3fSUN
GLAPI PFNGLVERTEXATTRIBL2DEXTPROC glad_glVertexAttribL2dEXT;
#define glVertexAttribL2dEXT glad_glVertexAttribL2dEXT
GLAPI PFNGLDEPTHRANGEPROC glad_glDepthRange;
#define glDepthRange glad_glDepthRange
GLAPI PFNGLPROGRAMUNIFORM4I64VNVPROC glad_glProgramUniform4i64vNV;
#define glProgramUniform4i64vNV glad_glProgramUniform4i64vNV
GLAPI PFNGLCOLOR3HVNVPROC glad_glColor3hvNV;
#define glColor3hvNV glad_glColor3hvNV
GLAPI PFNGLDRAWARRAYSINSTANCEDEXTPROC glad_glDrawArraysInstancedEXT;
#define glDrawArraysInstancedEXT glad_glDrawArraysInstancedEXT
GLAPI PFNGLDRAWBUFFERPROC glad_glDrawBuffer;
#define glDrawBuffer glad_glDrawBuffer
GLAPI PFNGLCLEARBUFFERUIVPROC glad_glClearBufferuiv;
#define glClearBufferuiv glad_glClearBufferuiv
GLAPI PFNGLWINDOWPOS2DVMESAPROC glad_glWindowPos2dvMESA;
#define glWindowPos2dvMESA glad_glWindowPos2dvMESA
GLAPI PFNGLNORMALSTREAM3BVATIPROC glad_glNormalStream3bvATI;
#define glNormalStream3bvATI glad_glNormalStream3bvATI
GLAPI PFNGLGETOBJECTLABELPROC glad_glGetObjectLabel;
#define glGetObjectLabel glad_glGetObjectLabel
GLAPI PFNGLPUSHDEBUGGROUPPROC glad_glPushDebugGroup;
#define glPushDebugGroup glad_glPushDebugGroup
GLAPI PFNGLSTENCILFILLPATHNVPROC glad_glStencilFillPathNV;
#define glStencilFillPathNV glad_glStencilFillPathNV
GLAPI PFNGLWINDOWPOS3IARBPROC glad_glWindowPos3iARB;
#define glWindowPos3iARB glad_glWindowPos3iARB
GLAPI PFNGLVERTEX4XVOESPROC glad_glVertex4xvOES;
#define glVertex4xvOES glad_glVertex4xvOES
GLAPI PFNGLPROGRAMVERTEXLIMITNVPROC glad_glProgramVertexLimitNV;
#define glProgramVertexLimitNV glad_glProgramVertexLimitNV
GLAPI PFNGLENABLEVERTEXARRAYATTRIBEXTPROC glad_glEnableVertexArrayAttribEXT;
#define glEnableVertexArrayAttribEXT glad_glEnableVertexArrayAttribEXT
GLAPI PFNGLUNIFORM3I64NVPROC glad_glUniform3i64NV;
#define glUniform3i64NV glad_glUniform3i64NV
GLAPI PFNGLTEXTUREPARAMETERFEXTPROC glad_glTextureParameterfEXT;
#define glTextureParameterfEXT glad_glTextureParameterfEXT
GLAPI PFNGLPROGRAMUNIFORM3UIVEXTPROC glad_glProgramUniform3uivEXT;
#define glProgramUniform3uivEXT glad_glProgramUniform3uivEXT
GLAPI PFNGLCLEARSTENCILPROC glad_glClearStencil;
#define glClearStencil glad_glClearStencil
GLAPI PFNGLVERTEXATTRIBS3SVNVPROC glad_glVertexAttribs3svNV;
#define glVertexAttribs3svNV glad_glVertexAttribs3svNV
GLAPI PFNGLVERTEXBLENDENVFATIPROC glad_glVertexBlendEnvfATI;
#define glVertexBlendEnvfATI glad_glVertexBlendEnvfATI
GLAPI PFNGLGETBUFFERPARAMETERUI64VNVPROC glad_glGetBufferParameterui64vNV;
#define glGetBufferParameterui64vNV glad_glGetBufferParameterui64vNV
GLAPI PFNGLVERTEXATTRIBI4BVEXTPROC glad_glVertexAttribI4bvEXT;
#define glVertexAttribI4bvEXT glad_glVertexAttribI4bvEXT
GLAPI PFNGLBLENDFUNCPROC glad_glBlendFunc;
#define glBlendFunc glad_glBlendFunc
GLAPI PFNGLVERTEXATTRIB3DVPROC glad_glVertexAttrib3dv;
#define glVertexAttrib3dv glad_glVertexAttrib3dv
GLAPI PFNGLSECONDARYCOLOR3BVEXTPROC glad_glSecondaryColor3bvEXT;
#define glSecondaryColor3bvEXT glad_glSecondaryColor3bvEXT
GLAPI PFNGLTANGENT3BVEXTPROC glad_glTangent3bvEXT;
#define glTangent3bvEXT glad_glTangent3bvEXT
GLAPI PFNGLMATRIXINDEXUBVARBPROC glad_glMatrixIndexubvARB;
#define glMatrixIndexubvARB glad_glMatrixIndexubvARB
GLAPI PFNGLGETVERTEXATTRIBLUI64VNVPROC glad_glGetVertexAttribLui64vNV;
#define glGetVertexAttribLui64vNV glad_glGetVertexAttribLui64vNV
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_glFlushMappedBufferRange;
#define glFlushMappedBufferRange glad_glFlushMappedBufferRange
GLAPI PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC glad_glProgramUniformMatrix2fvEXT;
#define glProgramUniformMatrix2fvEXT glad_glProgramUniformMatrix2fvEXT
GLAPI PFNGLVERTEXATTRIB1DVNVPROC glad_glVertexAttrib1dvNV;
#define glVertexAttrib1dvNV glad_glVertexAttrib1dvNV
GLAPI PFNGLGETMULTITEXENVIVEXTPROC glad_glGetMultiTexEnvivEXT;
#define glGetMultiTexEnvivEXT glad_glGetMultiTexEnvivEXT
GLAPI PFNGLGENQUERIESPROC glad_glGenQueries;
#define glGenQueries glad_glGenQueries
GLAPI PFNGLGETMAPATTRIBPARAMETERIVNVPROC glad_glGetMapAttribParameterivNV;
#define glGetMapAttribParameterivNV glad_glGetMapAttribParameterivNV
GLAPI PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D;
#define glTexSubImage3D glad_glTexSubImage3D
GLAPI PFNGLGETBUFFERPARAMETERIVARBPROC glad_glGetBufferParameterivARB;
#define glGetBufferParameterivARB glad_glGetBufferParameterivARB
GLAPI PFNGLGETTEXTUREPARAMETERFVPROC glad_glGetTextureParameterfv;
#define glGetTextureParameterfv glad_glGetTextureParameterfv
GLAPI PFNGLGETMULTISAMPLEFVNVPROC glad_glGetMultisamplefvNV;
#define glGetMultisamplefvNV glad_glGetMultisamplefvNV
GLAPI PFNGLMAPOBJECTBUFFERATIPROC glad_glMapObjectBufferATI;
#define glMapObjectBufferATI glad_glMapObjectBufferATI
GLAPI PFNGLPROGRAMUNIFORMUI64NVPROC glad_glProgramUniformui64NV;
#define glProgramUniformui64NV glad_glProgramUniformui64NV
GLAPI PFNGLLOADMATRIXXOESPROC glad_glLoadMatrixxOES;
#define glLoadMatrixxOES glad_glLoadMatrixxOES
GLAPI PFNGLVERTEXATTRIBL2I64NVPROC glad_glVertexAttribL2i64NV;
#define glVertexAttribL2i64NV glad_glVertexAttribL2i64NV
GLAPI PFNGLMATRIXROTATEFEXTPROC glad_glMatrixRotatefEXT;
#define glMatrixRotatefEXT glad_glMatrixRotatefEXT
GLAPI PFNGLGETCLIPPLANEXOESPROC glad_glGetClipPlanexOES;
#define glGetClipPlanexOES glad_glGetClipPlanexOES
GLAPI PFNGLSECONDARYCOLOR3UIVEXTPROC glad_glSecondaryColor3uivEXT;
#define glSecondaryColor3uivEXT glad_glSecondaryColor3uivEXT
GLAPI PFNGLMAPBUFFERARBPROC glad_glMapBufferARB;
#define glMapBufferARB glad_glMapBufferARB
GLAPI PFNGLGETPATHSPACINGNVPROC glad_glGetPathSpacingNV;
#define glGetPathSpacingNV glad_glGetPathSpacingNV
GLAPI PFNGLUNIFORM4DVPROC glad_glUniform4dv;
#define glUniform4dv glad_glUniform4dv
GLAPI PFNGLGLOBALALPHAFACTORDSUNPROC glad_glGlobalAlphaFactordSUN;
#define glGlobalAlphaFactordSUN glad_glGlobalAlphaFactordSUN
GLAPI PFNGLPROGRAMUNIFORM3DVPROC glad_glProgramUniform3dv;
#define glProgramUniform3dv glad_glProgramUniform3dv
GLAPI PFNGLINVALIDATEBUFFERDATAPROC glad_glInvalidateBufferData;
#define glInvalidateBufferData glad_glInvalidateBufferData
GLAPI PFNGLMATRIXLOAD3X2FNVPROC glad_glMatrixLoad3x2fNV;
#define glMatrixLoad3x2fNV glad_glMatrixLoad3x2fNV
GLAPI PFNGLGENTEXTURESEXTPROC glad_glGenTexturesEXT;
#define glGenTexturesEXT glad_glGenTexturesEXT
GLAPI PFNGLTANGENT3IEXTPROC glad_glTangent3iEXT;
#define glTangent3iEXT glad_glTangent3iEXT
GLAPI PFNGLGETTRANSFORMFEEDBACKI64_VPROC glad_glGetTransformFeedbacki64_v;
#define glGetTransformFeedbacki64_v glad_glGetTransformFeedbacki64_v
GLAPI PFNGLDISABLEINDEXEDEXTPROC glad_glDisableIndexedEXT;
#define glDisableIndexedEXT glad_glDisableIndexedEXT
GLAPI PFNGLGETHISTOGRAMPARAMETERXVOESPROC glad_glGetHistogramParameterxvOES;
#define glGetHistogramParameterxvOES glad_glGetHistogramParameterxvOES
GLAPI PFNGLDELETEFRAGMENTSHADERATIPROC glad_glDeleteFragmentShaderATI;
#define glDeleteFragmentShaderATI glad_glDeleteFragmentShaderATI
GLAPI PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC glad_glCopyTextureSubImage1DEXT;
#define glCopyTextureSubImage1DEXT glad_glCopyTextureSubImage1DEXT
GLAPI PFNGLWINDOWRECTANGLESEXTPROC glad_glWindowRectanglesEXT;
#define glWindowRectanglesEXT glad_glWindowRectanglesEXT
GLAPI PFNGLBEGINQUERYARBPROC glad_glBeginQueryARB;
#define glBeginQueryARB glad_glBeginQueryARB
GLAPI PFNGLVERTEX4BVOESPROC glad_glVertex4bvOES;
#define glVertex4bvOES glad_glVertex4bvOES
GLAPI PFNGLTESTFENCENVPROC glad_glTestFenceNV;
#define glTestFenceNV glad_glTestFenceNV
GLAPI PFNGLBINDTRANSFORMFEEDBACKPROC glad_glBindTransformFeedback;
#define glBindTransformFeedback glad_glBindTransformFeedback
GLAPI PFNGLBINORMAL3BVEXTPROC glad_glBinormal3bvEXT;
#define glBinormal3bvEXT glad_glBinormal3bvEXT
GLAPI PFNGLCLIPPLANEXOESPROC glad_glClipPlanexOES;
#define glClipPlanexOES glad_glClipPlanexOES
GLAPI PFNGLGENFENCESNVPROC glad_glGenFencesNV;
#define glGenFencesNV glad_glGenFencesNV
GLAPI PFNGLVERTEXATTRIBL2UI64NVPROC glad_glVertexAttribL2ui64NV;
#define glVertexAttribL2ui64NV glad_glVertexAttribL2ui64NV
GLAPI PFNGLBEGINCONDITIONALRENDERNVXPROC glad_glBeginConditionalRenderNVX;
#define glBeginConditionalRenderNVX glad_glBeginConditionalRenderNVX
GLAPI PFNGLFINISHOBJECTAPPLEPROC glad_glFinishObjectAPPLE;
#define glFinishObjectAPPLE glad_glFinishObjectAPPLE
GLAPI PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC glad_glReplacementCodeuiTexCoord2fVertex3fvSUN;
#define glReplacementCodeuiTexCoord2fVertex3fvSUN glad_glReplacementCodeuiTexCoord2fVertex3fvSUN
GLAPI PFNGLCLEARDEPTHPROC glad_glClearDepth;
#define glClearDepth glad_glClearDepth
GLAPI PFNGLVERTEXWEIGHTFVEXTPROC glad_glVertexWeightfvEXT;
#define glVertexWeightfvEXT glad_glVertexWeightfvEXT
GLAPI PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC glad_glGetTextureLevelParameterfvEXT;
#define glGetTextureLevelParameterfvEXT glad_glGetTextureLevelParameterfvEXT
GLAPI PFNGLCREATEBUFFERSPROC glad_glCreateBuffers;
#define glCreateBuffers glad_glCreateBuffers
GLAPI PFNGLGETCOLORTABLESGIPROC glad_glGetColorTableSGI;
#define glGetColorTableSGI glad_glGetColorTableSGI
GLAPI PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements;
#define glMultiDrawElements glad_glMultiDrawElements
GLAPI PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC glad_glTexCoord2fColor3fVertex3fSUN;
#define glTexCoord2fColor3fVertex3fSUN glad_glTexCoord2fColor3fVertex3fSUN
GLAPI PFNGLFREEOBJECTBUFFERATIPROC glad_glFreeObjectBufferATI;
#define glFreeObjectBufferATI glad_glFreeObjectBufferATI
GLAPI PFNGLBLENDBARRIERNVPROC glad_glBlendBarrierNV;
#define glBlendBarrierNV glad_glBlendBarrierNV
GLAPI PFNGLUNIFORM4I64VNVPROC glad_glUniform4i64vNV;
#define glUniform4i64vNV glad_glUniform4i64vNV
GLAPI PFNGLGETNUNIFORMUIVARBPROC glad_glGetnUniformuivARB;
#define glGetnUniformuivARB glad_glGetnUniformuivARB
GLAPI PFNGLPROGRAMENVPARAMETERS4FVEXTPROC glad_glProgramEnvParameters4fvEXT;
#define glProgramEnvParameters4fvEXT glad_glProgramEnvParameters4fvEXT
GLAPI PFNGLPROGRAMUNIFORM4I64VARBPROC glad_glProgramUniform4i64vARB;
#define glProgramUniform4i64vARB glad_glProgramUniform4i64vARB
GLAPI PFNGLUNIFORMMATRIX4X3DVPROC glad_glUniformMatrix4x3dv;
#define glUniformMatrix4x3dv glad_glUniformMatrix4x3dv
GLAPI PFNGLGETVIDEOCAPTURESTREAMIVNVPROC glad_glGetVideoCaptureStreamivNV;
#define glGetVideoCaptureStreamivNV glad_glGetVideoCaptureStreamivNV
GLAPI PFNGLUNIFORM1I64ARBPROC glad_glUniform1i64ARB;
#define glUniform1i64ARB glad_glUniform1i64ARB
GLAPI PFNGLDELETEQUERIESPROC glad_glDeleteQueries;
#define glDeleteQueries glad_glDeleteQueries
GLAPI PFNGLWAITSYNCPROC glad_glWaitSync;
#define glWaitSync glad_glWaitSync
GLAPI PFNGLARRAYELEMENTEXTPROC glad_glArrayElementEXT;
#define glArrayElementEXT glad_glArrayElementEXT
GLAPI PFNGLUNIFORM3UIVEXTPROC glad_glUniform3uivEXT;
#define glUniform3uivEXT glad_glUniform3uivEXT
GLAPI PFNGLPOPGROUPMARKEREXTPROC glad_glPopGroupMarkerEXT;
#define glPopGroupMarkerEXT glad_glPopGroupMarkerEXT
GLAPI PFNGLSETLOCALCONSTANTEXTPROC glad_glSetLocalConstantEXT;
#define glSetLocalConstantEXT glad_glSetLocalConstantEXT
GLAPI PFNGLCOLOR4HVNVPROC glad_glColor4hvNV;
#define glColor4hvNV glad_glColor4hvNV
GLAPI PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv;
#define glGetVertexAttribfv glad_glGetVertexAttribfv
GLAPI PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D;
#define glTexSubImage2D glad_glTexSubImage2D
GLAPI PFNGLLOGICOPPROC glad_glLogicOp;
#define glLogicOp glad_glLogicOp
GLAPI PFNGLWINDOWPOS4IMESAPROC glad_glWindowPos4iMESA;
#define glWindowPos4iMESA glad_glWindowPos4iMESA
GLAPI PFNGLPOLLASYNCSGIXPROC glad_glPollAsyncSGIX;
#define glPollAsyncSGIX glad_glPollAsyncSGIX
GLAPI PFNGLMULTITEXCOORD1XOESPROC glad_glMultiTexCoord1xOES;
#define glMultiTexCoord1xOES glad_glMultiTexCoord1xOES
GLAPI PFNGLPROGRAMUNIFORMMATRIX4DVPROC glad_glProgramUniformMatrix4dv;
#define glProgramUniformMatrix4dv glad_glProgramUniformMatrix4dv
GLAPI PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glad_glNamedFramebufferReadBuffer;
#define glNamedFramebufferReadBuffer glad_glNamedFramebufferReadBuffer
GLAPI PFNGLVERTEXPOINTERVINTELPROC glad_glVertexPointervINTEL;
#define glVertexPointervINTEL glad_glVertexPointervINTEL
GLAPI PFNGLTEXTUREPARAMETERIIVPROC glad_glTextureParameterIiv;
#define glTextureParameterIiv glad_glTextureParameterIiv
GLAPI PFNGLVERTEXATTRIBI1UIVEXTPROC glad_glVertexAttribI1uivEXT;
#define glVertexAttribI1uivEXT glad_glVertexAttribI1uivEXT
GLAPI PFNGLGETSEPARABLEFILTEREXTPROC glad_glGetSeparableFilterEXT;
#define glGetSeparableFilterEXT glad_glGetSeparableFilterEXT
GLAPI PFNGLMULTITEXCOORD3IARBPROC glad_glMultiTexCoord3iARB;
#define glMultiTexCoord3iARB glad_glMultiTexCoord3iARB
GLAPI PFNGLVERTEX3HVNVPROC glad_glVertex3hvNV;
#define glVertex3hvNV glad_glVertex3hvNV
GLAPI PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC glad_glVertexArrayMultiTexCoordOffsetEXT;
#define glVertexArrayMultiTexCoordOffsetEXT glad_glVertexArrayMultiTexCoordOffsetEXT
GLAPI PFNGLPROVOKINGVERTEXPROC glad_glProvokingVertex;
#define glProvokingVertex glad_glProvokingVertex
GLAPI PFNGLGETMULTITEXGENIVEXTPROC glad_glGetMultiTexGenivEXT;
#define glGetMultiTexGenivEXT glad_glGetMultiTexGenivEXT
GLAPI PFNGLGETFLOATINDEXEDVEXTPROC glad_glGetFloatIndexedvEXT;
#define glGetFloatIndexedvEXT glad_glGetFloatIndexedvEXT
GLAPI PFNGLTRANSFORMPATHNVPROC glad_glTransformPathNV;
#define glTransformPathNV glad_glTransformPathNV
GLAPI PFNGLVDPAUUNMAPSURFACESNVPROC glad_glVDPAUUnmapSurfacesNV;
#define glVDPAUUnmapSurfacesNV glad_glVDPAUUnmapSurfacesNV
GLAPI PFNGLDRAWELEMENTSPROC glad_glDrawElements;
#define glDrawElements glad_glDrawElements
GLAPI PFNGLFLUSHPIXELDATARANGENVPROC glad_glFlushPixelDataRangeNV;
#define glFlushPixelDataRangeNV glad_glFlushPixelDataRangeNV
GLAPI PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced;
#define glDrawArraysInstanced glad_glDrawArraysInstanced
GLAPI PFNGLUNIFORM3UI64VARBPROC glad_glUniform3ui64vARB;
#define glUniform3ui64vARB glad_glUniform3ui64vARB
GLAPI PFNGLVERTEXATTRIB2SNVPROC glad_glVertexAttrib2sNV;
#define glVertexAttrib2sNV glad_glVertexAttrib2sNV
GLAPI PFNGLVERTEXSTREAM2FATIPROC glad_glVertexStream2fATI;
#define glVertexStream2fATI glad_glVertexStream2fATI
GLAPI PFNGLPROGRAMUNIFORMMATRIX2FVPROC glad_glProgramUniformMatrix2fv;
#define glProgramUniformMatrix2fv glad_glProgramUniformMatrix2fv
GLAPI PFNGLMULTITEXCOORD2DARBPROC glad_glMultiTexCoord2dARB;
#define glMultiTexCoord2dARB glad_glMultiTexCoord2dARB
GLAPI PFNGLENDQUERYINDEXEDPROC glad_glEndQueryIndexed;
#define glEndQueryIndexed glad_glEndQueryIndexed
GLAPI PFNGLNORMALSTREAM3SATIPROC glad_glNormalStream3sATI;
#define glNormalStream3sATI glad_glNormalStream3sATI
GLAPI PFNGLTEXENVXOESPROC glad_glTexEnvxOES;
#define glTexEnvxOES glad_glTexEnvxOES
GLAPI PFNGLISPROGRAMPROC glad_glIsProgram;
#define glIsProgram glad_glIsProgram
GLAPI PFNGLVERTEXATTRIB4UBNVPROC glad_glVertexAttrib4ubNV;
#define glVertexAttrib4ubNV glad_glVertexAttrib4ubNV
GLAPI PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv;
#define glVertexAttrib4fv glad_glVertexAttrib4fv
GLAPI PFNGLMULTITEXCOORD4XOESPROC glad_glMultiTexCoord4xOES;
#define glMultiTexCoord4xOES glad_glMultiTexCoord4xOES
GLAPI PFNGLVERTEXSTREAM3FVATIPROC glad_glVertexStream3fvATI;
#define glVertexStream3fvATI glad_glVertexStream3fvATI
GLAPI PFNGLCULLPARAMETERFVEXTPROC glad_glCullParameterfvEXT;
#define glCullParameterfvEXT glad_glCullParameterfvEXT
GLAPI PFNGLVERTEXARRAYINDEXOFFSETEXTPROC glad_glVertexArrayIndexOffsetEXT;
#define glVertexArrayIndexOffsetEXT glad_glVertexArrayIndexOffsetEXT
GLAPI PFNGLEDGEFLAGFORMATNVPROC glad_glEdgeFlagFormatNV;
#define glEdgeFlagFormatNV glad_glEdgeFlagFormatNV
GLAPI PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC glad_glCopyMultiTexSubImage1DEXT;
#define glCopyMultiTexSubImage1DEXT glad_glCopyMultiTexSubImage1DEXT
GLAPI PFNGLTEXBUFFERARBPROC glad_glTexBufferARB;
#define glTexBufferARB glad_glTexBufferARB
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC glad_glMultiDrawElementsIndirectBindlessCountNV;
#define glMultiDrawElementsIndirectBindlessCountNV glad_glMultiDrawElementsIndirectBindlessCountNV
GLAPI PFNGLMULTITEXPARAMETERIUIVEXTPROC glad_glMultiTexParameterIuivEXT;
#define glMultiTexParameterIuivEXT glad_glMultiTexParameterIuivEXT
GLAPI PFNGLVERTEXATTRIBPOINTERNVPROC glad_glVertexAttribPointerNV;
#define glVertexAttribPointerNV glad_glVertexAttribPointerNV
GLAPI PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC glad_glProgramLocalParameters4fvEXT;
#define glProgramLocalParameters4fvEXT glad_glProgramLocalParameters4fvEXT
GLAPI PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate;
#define glStencilOpSeparate glad_glStencilOpSeparate
GLAPI PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC glad_glProgramNamedParameter4dvNV;
#define glProgramNamedParameter4dvNV glad_glProgramNamedParameter4dvNV
GLAPI PFNGLCOMPILECOMMANDLISTNVPROC glad_glCompileCommandListNV;
#define glCompileCommandListNV glad_glCompileCommandListNV
GLAPI PFNGLBINDFRAGDATALOCATIONPROC glad_glBindFragDataLocation;
#define glBindFragDataLocation glad_glBindFragDataLocation
GLAPI PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC glad_glGetRenderbufferParameterivEXT;
#define glGetRenderbufferParameterivEXT glad_glGetRenderbufferParameterivEXT
GLAPI PFNGLISBUFFERRESIDENTNVPROC glad_glIsBufferResidentNV;
#define glIsBufferResidentNV glad_glIsBufferResidentNV
GLAPI PFNGLTEXCOORD2XVOESPROC glad_glTexCoord2xvOES;
#define glTexCoord2xvOES glad_glTexCoord2xvOES
GLAPI PFNGLMULTITEXGENDVEXTPROC glad_glMultiTexGendvEXT;
#define glMultiTexGendvEXT glad_glMultiTexGendvEXT
GLAPI PFNGLTAGSAMPLEBUFFERSGIXPROC glad_glTagSampleBufferSGIX;
#define glTagSampleBufferSGIX glad_glTagSampleBufferSGIX
GLAPI PFNGLVDPAUUNREGISTERSURFACENVPROC glad_glVDPAUUnregisterSurfaceNV;
#define glVDPAUUnregisterSurfaceNV glad_glVDPAUUnregisterSurfaceNV
GLAPI PFNGLGETPERFQUERYIDBYNAMEINTELPROC glad_glGetPerfQueryIdByNameINTEL;
#define glGetPerfQueryIdByNameINTEL glad_glGetPerfQueryIdByNameINTEL
GLAPI PFNGLGETINTEGER64VPROC glad_glGetInteger64v;
#define glGetInteger64v glad_glGetInteger64v
GLAPI PFNGLVERTEX2BOESPROC glad_glVertex2bOES;
#define glVertex2bOES glad_glVertex2bOES
GLAPI PFNGLVERTEXATTRIB4USVARBPROC glad_glVertexAttrib4usvARB;
#define glVertexAttrib4usvARB glad_glVertexAttrib4usvARB
GLAPI PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glad_glNamedFramebufferRenderbuffer;
#define glNamedFramebufferRenderbuffer glad_glNamedFramebufferRenderbuffer
GLAPI PFNGLMULTITEXCOORD2IARBPROC glad_glMultiTexCoord2iARB;
#define glMultiTexCoord2iARB glad_glMultiTexCoord2iARB
GLAPI PFNGLTESTFENCEAPPLEPROC glad_glTestFenceAPPLE;
#define glTestFenceAPPLE glad_glTestFenceAPPLE
GLAPI PFNGLVERTEXATTRIB4NIVPROC glad_glVertexAttrib4Niv;
#define glVertexAttrib4Niv glad_glVertexAttrib4Niv
GLAPI PFNGLVERTEXATTRIBL2I64VNVPROC glad_glVertexAttribL2i64vNV;
#define glVertexAttribL2i64vNV glad_glVertexAttribL2i64vNV
GLAPI PFNGLVERTEXATTRIB4IVARBPROC glad_glVertexAttrib4ivARB;
#define glVertexAttrib4ivARB glad_glVertexAttrib4ivARB
GLAPI PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC glad_glTexCoord2fNormal3fVertex3fSUN;
#define glTexCoord2fNormal3fVertex3fSUN glad_glTexCoord2fNormal3fVertex3fSUN
GLAPI PFNGLMATRIXMULT3X2FNVPROC glad_glMatrixMult3x2fNV;
#define glMatrixMult3x2fNV glad_glMatrixMult3x2fNV
GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glad_glGetActiveSubroutineUniformName;
#define glGetActiveSubroutineUniformName glad_glGetActiveSubroutineUniformName
GLAPI PFNGLGETTEXLEVELPARAMETERXVOESPROC glad_glGetTexLevelParameterxvOES;
#define glGetTexLevelParameterxvOES glad_glGetTexLevelParameterxvOES
GLAPI PFNGLVERTEXATTRIB4DVNVPROC glad_glVertexAttrib4dvNV;
#define glVertexAttrib4dvNV glad_glVertexAttrib4dvNV
GLAPI PFNGLGETTEXTURELEVELPARAMETERFVPROC glad_glGetTextureLevelParameterfv;
#define glGetTextureLevelParameterfv glad_glGetTextureLevelParameterfv
GLAPI PFNGLBITMAPXOESPROC glad_glBitmapxOES;
#define glBitmapxOES glad_glBitmapxOES
GLAPI PFNGLPROGRAMUNIFORM3FVPROC glad_glProgramUniform3fv;
#define glProgramUniform3fv glad_glProgramUniform3fv
GLAPI PFNGLTEXTURESUBIMAGE1DPROC glad_glTextureSubImage1D;
#define glTextureSubImage1D glad_glTextureSubImage1D
GLAPI PFNGLCLEARDEPTHFPROC glad_glClearDepthf;
#define glClearDepthf glad_glClearDepthf
GLAPI PFNGLGETVERTEXATTRIBIUIVPROC glad_glGetVertexAttribIuiv;
#define glGetVertexAttribIuiv glad_glGetVertexAttribIuiv
GLAPI PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC glad_glGetPerfMonitorCounterStringAMD;
#define glGetPerfMonitorCounterStringAMD glad_glGetPerfMonitorCounterStringAMD
GLAPI PFNGLGETNAMEDPROGRAMIVEXTPROC glad_glGetNamedProgramivEXT;
#define glGetNamedProgramivEXT glad_glGetNamedProgramivEXT
GLAPI PFNGLISFENCENVPROC glad_glIsFenceNV;
#define glIsFenceNV glad_glIsFenceNV
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glad_glProgramUniformMatrix4x3dv;
#define glProgramUniformMatrix4x3dv glad_glProgramUniformMatrix4x3dv
GLAPI PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC glad_glGetNamedProgramLocalParameterIuivEXT;
#define glGetNamedProgramLocalParameterIuivEXT glad_glGetNamedProgramLocalParameterIuivEXT
GLAPI PFNGLREADBUFFERPROC glad_glReadBuffer;
#define glReadBuffer glad_glReadBuffer
GLAPI PFNGLPROGRAMUNIFORM4FVEXTPROC glad_glProgramUniform4fvEXT;
#define glProgramUniform4fvEXT glad_glProgramUniform4fvEXT
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glad_glCheckFramebufferStatusEXT;
#define glCheckFramebufferStatusEXT glad_glCheckFramebufferStatusEXT
GLAPI PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glad_glDisableVertexAttribArrayARB;
#define glDisableVertexAttribArrayARB glad_glDisableVertexAttribArrayARB
GLAPI PFNGLCLEARNAMEDBUFFERDATAPROC glad_glClearNamedBufferData;
#define glClearNamedBufferData glad_glClearNamedBufferData
GLAPI PFNGLVERTEXATTRIBI4UIPROC glad_glVertexAttribI4ui;
#define glVertexAttribI4ui glad_glVertexAttribI4ui
GLAPI PFNGLDELETEOCCLUSIONQUERIESNVPROC glad_glDeleteOcclusionQueriesNV;
#define glDeleteOcclusionQueriesNV glad_glDeleteOcclusionQueriesNV
GLAPI PFNGLVERTEX4HVNVPROC glad_glVertex4hvNV;
#define glVertex4hvNV glad_glVertex4hvNV
GLAPI PFNGLPROGRAMLOCALPARAMETER4DARBPROC glad_glProgramLocalParameter4dARB;
#define glProgramLocalParameter4dARB glad_glProgramLocalParameter4dARB
GLAPI PFNGLBLENDEQUATIONPROC glad_glBlendEquation;
#define glBlendEquation glad_glBlendEquation
GLAPI PFNGLUNLOCKARRAYSEXTPROC glad_glUnlockArraysEXT;
#define glUnlockArraysEXT glad_glUnlockArraysEXT
GLAPI PFNGLGETPROGRAMRESOURCEIVPROC glad_glGetProgramResourceiv;
#define glGetProgramResourceiv glad_glGetProgramResourceiv
GLAPI PFNGLCLEARBUFFERDATAPROC glad_glClearBufferData;
#define glClearBufferData glad_glClearBufferData
GLAPI PFNGLBEGINTRANSFORMFEEDBACKPROC glad_glBeginTransformFeedback;
#define glBeginTransformFeedback glad_glBeginTransformFeedback
GLAPI PFNGLPRESENTFRAMEKEYEDNVPROC glad_glPresentFrameKeyedNV;
#define glPresentFrameKeyedNV glad_glPresentFrameKeyedNV
GLAPI PFNGLDELETETRANSFORMFEEDBACKSPROC glad_glDeleteTransformFeedbacks;
#define glDeleteTransformFeedbacks glad_glDeleteTransformFeedbacks
GLAPI PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex;
#define glDrawRangeElementsBaseVertex glad_glDrawRangeElementsBaseVertex
GLAPI PFNGLUNIFORM4I64VARBPROC glad_glUniform4i64vARB;
#define glUniform4i64vARB glad_glUniform4i64vARB
GLAPI PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC glad_glTextureStorage3DMultisampleEXT;
#define glTextureStorage3DMultisampleEXT glad_glTextureStorage3DMultisampleEXT
GLAPI PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation;
#define glBindAttribLocation glad_glBindAttribLocation
GLAPI PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC glad_glCompressedMultiTexImage1DEXT;
#define glCompressedMultiTexImage1DEXT glad_glCompressedMultiTexImage1DEXT
GLAPI PFNGLPUSHGROUPMARKEREXTPROC glad_glPushGroupMarkerEXT;
#define glPushGroupMarkerEXT glad_glPushGroupMarkerEXT
GLAPI PFNGLMULTTRANSPOSEMATRIXXOESPROC glad_glMultTransposeMatrixxOES;
#define glMultTransposeMatrixxOES glad_glMultTransposeMatrixxOES
GLAPI PFNGLGETPIXELMAPXVPROC glad_glGetPixelMapxv;
#define glGetPixelMapxv glad_glGetPixelMapxv
GLAPI PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC glad_glFramebufferSampleLocationsfvARB;
#define glFramebufferSampleLocationsfvARB glad_glFramebufferSampleLocationsfvARB
GLAPI PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC glad_glGetProgramSubroutineParameteruivNV;
#define glGetProgramSubroutineParameteruivNV glad_glGetProgramSubroutineParameteruivNV
GLAPI PFNGLVERTEXATTRIBI3UIVEXTPROC glad_glVertexAttribI3uivEXT;
#define glVertexAttribI3uivEXT glad_glVertexAttribI3uivEXT
GLAPI PFNGLVERTEXARRAYPARAMETERIAPPLEPROC glad_glVertexArrayParameteriAPPLE;
#define glVertexArrayParameteriAPPLE glad_glVertexArrayParameteriAPPLE
GLAPI PFNGLDISABLEIPROC glad_glDisablei;
#define glDisablei glad_glDisablei
GLAPI PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData;
#define glCopyBufferSubData glad_glCopyBufferSubData
GLAPI PFNGLSELECTPERFMONITORCOUNTERSAMDPROC glad_glSelectPerfMonitorCountersAMD;
#define glSelectPerfMonitorCountersAMD glad_glSelectPerfMonitorCountersAMD
GLAPI PFNGLGETVIDEOCAPTURESTREAMDVNVPROC glad_glGetVideoCaptureStreamdvNV;
#define glGetVideoCaptureStreamdvNV glad_glGetVideoCaptureStreamdvNV
GLAPI PFNGLVERTEXSTREAM4FVATIPROC glad_glVertexStream4fvATI;
#define glVertexStream4fvATI glad_glVertexStream4fvATI
GLAPI PFNGLMAKEIMAGEHANDLERESIDENTARBPROC glad_glMakeImageHandleResidentARB;
#define glMakeImageHandleResidentARB glad_glMakeImageHandleResidentARB
GLAPI PFNGLVERTEXATTRIBFORMATPROC glad_glVertexAttribFormat;
#define glVertexAttribFormat glad_glVertexAttribFormat
GLAPI PFNGLDEFORMATIONMAP3FSGIXPROC glad_glDeformationMap3fSGIX;
#define glDeformationMap3fSGIX glad_glDeformationMap3fSGIX
GLAPI PFNGLPROGRAMENVPARAMETER4FVARBPROC glad_glProgramEnvParameter4fvARB;
#define glProgramEnvParameter4fvARB glad_glProgramEnvParameter4fvARB
GLAPI PFNGLPAUSETRANSFORMFEEDBACKPROC glad_glPauseTransformFeedback;
#define glPauseTransformFeedback glad_glPauseTransformFeedback
GLAPI PFNGLWINDOWPOS2SMESAPROC glad_glWindowPos2sMESA;
#define glWindowPos2sMESA glad_glWindowPos2sMESA
GLAPI PFNGLTEXSUBIMAGE1DPROC glad_glTexSubImage1D;
#define glTexSubImage1D glad_glTexSubImage1D
GLAPI PFNGLCONVOLUTIONPARAMETERFVEXTPROC glad_glConvolutionParameterfvEXT;
#define glConvolutionParameterfvEXT glad_glConvolutionParameterfvEXT
GLAPI PFNGLUNIFORMMATRIX4FVARBPROC glad_glUniformMatrix4fvARB;
#define glUniformMatrix4fvARB glad_glUniformMatrix4fvARB
GLAPI PFNGLPROGRAMENVPARAMETER4DVARBPROC glad_glProgramEnvParameter4dvARB;
#define glProgramEnvParameter4dvARB glad_glProgramEnvParameter4dvARB
GLAPI PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC glad_glGetProgramLocalParameterIivNV;
#define glGetProgramLocalParameterIivNV glad_glGetProgramLocalParameterIivNV
GLAPI PFNGLISOCCLUSIONQUERYNVPROC glad_glIsOcclusionQueryNV;
#define glIsOcclusionQueryNV glad_glIsOcclusionQueryNV
GLAPI PFNGLGETVERTEXARRAYIVPROC glad_glGetVertexArrayiv;
#define glGetVertexArrayiv glad_glGetVertexArrayiv
GLAPI PFNGLPROGRAMUNIFORM3UIEXTPROC glad_glProgramUniform3uiEXT;
#define glProgramUniform3uiEXT glad_glProgramUniform3uiEXT
GLAPI PFNGLGETTEXPARAMETERIIVPROC glad_glGetTexParameterIiv;
#define glGetTexParameterIiv glad_glGetTexParameterIiv
GLAPI PFNGLTEXCOORD1HVNVPROC glad_glTexCoord1hvNV;
#define glTexCoord1hvNV glad_glTexCoord1hvNV
GLAPI PFNGLPIXELTEXGENPARAMETERFVSGISPROC glad_glPixelTexGenParameterfvSGIS;
#define glPixelTexGenParameterfvSGIS glad_glPixelTexGenParameterfvSGIS
GLAPI PFNGLVERTEXATTRIB4SARBPROC glad_glVertexAttrib4sARB;
#define glVertexAttrib4sARB glad_glVertexAttrib4sARB
GLAPI PFNGLISBUFFERARBPROC glad_glIsBufferARB;
#define glIsBufferARB glad_glIsBufferARB
GLAPI PFNGLMULTITEXCOORD1BOESPROC glad_glMultiTexCoord1bOES;
#define glMultiTexCoord1bOES glad_glMultiTexCoord1bOES
GLAPI PFNGLTEXCOORD4HNVPROC glad_glTexCoord4hNV;
#define glTexCoord4hNV glad_glTexCoord4hNV
GLAPI PFNGLGENSYMBOLSEXTPROC glad_glGenSymbolsEXT;
#define glGenSymbolsEXT glad_glGenSymbolsEXT
GLAPI PFNGLPROGRAMUNIFORM1FVEXTPROC glad_glProgramUniform1fvEXT;
#define glProgramUniform1fvEXT glad_glProgramUniform1fvEXT
GLAPI PFNGLTANGENTPOINTEREXTPROC glad_glTangentPointerEXT;
#define glTangentPointerEXT glad_glTangentPointerEXT
GLAPI PFNGLBINDSAMPLERSPROC glad_glBindSamplers;
#define glBindSamplers glad_glBindSamplers
GLAPI PFNGLGETPROGRAMENVPARAMETERIIVNVPROC glad_glGetProgramEnvParameterIivNV;
#define glGetProgramEnvParameterIivNV glad_glGetProgramEnvParameterIivNV
GLAPI PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;
#define glUniformMatrix4fv glad_glUniformMatrix4fv
GLAPI PFNGLBEGINFRAGMENTSHADERATIPROC glad_glBeginFragmentShaderATI;
#define glBeginFragmentShaderATI glad_glBeginFragmentShaderATI
GLAPI PFNGLGENNAMESAMDPROC glad_glGenNamesAMD;
#define glGenNamesAMD glad_glGenNamesAMD
GLAPI PFNGLSECONDARYCOLOR3IEXTPROC glad_glSecondaryColor3iEXT;
#define glSecondaryColor3iEXT glad_glSecondaryColor3iEXT
GLAPI PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC glad_glProgramEnvParametersI4uivNV;
#define glProgramEnvParametersI4uivNV glad_glProgramEnvParametersI4uivNV
GLAPI PFNGLDEBUGMESSAGECALLBACKARBPROC glad_glDebugMessageCallbackARB;
#define glDebugMessageCallbackARB glad_glDebugMessageCallbackARB
GLAPI PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC glad_glTexCoord2fColor3fVertex3fvSUN;
#define glTexCoord2fColor3fVertex3fvSUN glad_glTexCoord2fColor3fVertex3fvSUN
GLAPI PFNGLPROGRAMUNIFORM1I64VNVPROC glad_glProgramUniform1i64vNV;
#define glProgramUniform1i64vNV glad_glProgramUniform1i64vNV
GLAPI PFNGLMULTITEXGENDEXTPROC glad_glMultiTexGendEXT;
#define glMultiTexGendEXT glad_glMultiTexGendEXT
GLAPI PFNGLTEXCOORD2HNVPROC glad_glTexCoord2hNV;
#define glTexCoord2hNV glad_glTexCoord2hNV
GLAPI PFNGLREQUESTRESIDENTPROGRAMSNVPROC glad_glRequestResidentProgramsNV;
#define glRequestResidentProgramsNV glad_glRequestResidentProgramsNV
GLAPI PFNGLMATRIXLOADTRANSPOSEDEXTPROC glad_glMatrixLoadTransposedEXT;
#define glMatrixLoadTransposedEXT glad_glMatrixLoadTransposedEXT
GLAPI PFNGLVERTEXATTRIBIPOINTERPROC glad_glVertexAttribIPointer;
#define glVertexAttribIPointer glad_glVertexAttribIPointer
GLAPI PFNGLEVALUATEDEPTHVALUESARBPROC glad_glEvaluateDepthValuesARB;
#define glEvaluateDepthValuesARB glad_glEvaluateDepthValuesARB
GLAPI PFNGLWINDOWPOS2SARBPROC glad_glWindowPos2sARB;
#define glWindowPos2sARB glad_glWindowPos2sARB
GLAPI PFNGLTEXPARAMETERXOESPROC glad_glTexParameterxOES;
#define glTexParameterxOES glad_glTexParameterxOES
GLAPI PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC glad_glMakeImageHandleNonResidentNV;
#define glMakeImageHandleNonResidentNV glad_glMakeImageHandleNonResidentNV
GLAPI PFNGLENDVERTEXSHADEREXTPROC glad_glEndVertexShaderEXT;
#define glEndVertexShaderEXT glad_glEndVertexShaderEXT
GLAPI PFNGLUNIFORM1IARBPROC glad_glUniform1iARB;
#define glUniform1iARB glad_glUniform1iARB
GLAPI PFNGLUNIFORM1UI64VNVPROC glad_glUniform1ui64vNV;
#define glUniform1ui64vNV glad_glUniform1ui64vNV
GLAPI PFNGLGETCLIPPLANEFOESPROC glad_glGetClipPlanefOES;
#define glGetClipPlanefOES glad_glGetClipPlanefOES
GLAPI PFNGLPROGRAMUNIFORM3IVEXTPROC glad_glProgramUniform3ivEXT;
#define glProgramUniform3ivEXT glad_glProgramUniform3ivEXT
GLAPI PFNGLPROGRAMPARAMETER4FNVPROC glad_glProgramParameter4fNV;
#define glProgramParameter4fNV glad_glProgramParameter4fNV
GLAPI PFNGLMULTITEXCOORD4HVNVPROC glad_glMultiTexCoord4hvNV;
#define glMultiTexCoord4hvNV glad_glMultiTexCoord4hvNV
GLAPI PFNGLGETMINMAXPARAMETERIVEXTPROC glad_glGetMinmaxParameterivEXT;
#define glGetMinmaxParameterivEXT glad_glGetMinmaxParameterivEXT
GLAPI PFNGLDELETEPROGRAMPROC glad_glDeleteProgram;
#define glDeleteProgram glad_glDeleteProgram
GLAPI PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC glad_glNamedBufferPageCommitmentARB;
#define glNamedBufferPageCommitmentARB glad_glNamedBufferPageCommitmentARB
GLAPI PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv;
#define glUniformMatrix4x3fv glad_glUniformMatrix4x3fv
GLAPI PFNGLTEXTUREBARRIERPROC glad_glTextureBarrier;
#define glTextureBarrier glad_glTextureBarrier
GLAPI PFNGLGETNUNIFORMFVPROC glad_glGetnUniformfv;
#define glGetnUniformfv glad_glGetnUniformfv
GLAPI PFNGLGETINTERNALFORMATIVPROC glad_glGetInternalformativ;
#define glGetInternalformativ glad_glGetInternalformativ
GLAPI PFNGLTEXCOORD2BVOESPROC glad_glTexCoord2bvOES;
#define glTexCoord2bvOES glad_glTexCoord2bvOES
GLAPI PFNGLEVALCOORD2XOESPROC glad_glEvalCoord2xOES;
#define glEvalCoord2xOES glad_glEvalCoord2xOES
GLAPI PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC glad_glProgramUniformHandleui64vNV;
#define glProgramUniformHandleui64vNV glad_glProgramUniformHandleui64vNV
GLAPI PFNGLDRAWARRAYSINDIRECTPROC glad_glDrawArraysIndirect;
#define glDrawArraysIndirect glad_glDrawArraysIndirect
GLAPI PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays;
#define glGenVertexArrays glad_glGenVertexArrays
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glad_glProgramUniformMatrix3x2dv;
#define glProgramUniformMatrix3x2dv glad_glProgramUniformMatrix3x2dv
GLAPI PFNGLVERTEXSTREAM4FATIPROC glad_glVertexStream4fATI;
#define glVertexStream4fATI glad_glVertexStream4fATI
GLAPI PFNGLGETCOVERAGEMODULATIONTABLENVPROC glad_glGetCoverageModulationTableNV;
#define glGetCoverageModulationTableNV glad_glGetCoverageModulationTableNV
GLAPI PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC glad_glMultiDrawRangeElementArrayAPPLE;
#define glMultiDrawRangeElementArrayAPPLE glad_glMultiDrawRangeElementArrayAPPLE
GLAPI PFNGLGETVERTEXATTRIBDVPROC glad_glGetVertexAttribdv;
#define glGetVertexAttribdv glad_glGetVertexAttribdv
GLAPI PFNGLGETUNIFORMI64VARBPROC glad_glGetUniformi64vARB;
#define glGetUniformi64vARB glad_glGetUniformi64vARB
GLAPI PFNGLARETEXTURESRESIDENTEXTPROC glad_glAreTexturesResidentEXT;
#define glAreTexturesResidentEXT glad_glAreTexturesResidentEXT
GLAPI PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC glad_glVideoCaptureStreamParameterdvNV;
#define glVideoCaptureStreamParameterdvNV glad_glVideoCaptureStreamParameterdvNV
GLAPI PFNGLMAPPARAMETERIVNVPROC glad_glMapParameterivNV;
#define glMapParameterivNV glad_glMapParameterivNV
GLAPI PFNGLMULTITEXCOORD2SVARBPROC glad_glMultiTexCoord2svARB;
#define glMultiTexCoord2svARB glad_glMultiTexCoord2svARB
GLAPI PFNGLSECONDARYCOLOR3SEXTPROC glad_glSecondaryColor3sEXT;
#define glSecondaryColor3sEXT glad_glSecondaryColor3sEXT
GLAPI PFNGLGETTEXPARAMETERIIVEXTPROC glad_glGetTexParameterIivEXT;
#define glGetTexParameterIivEXT glad_glGetTexParameterIivEXT
GLAPI PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray;
#define glDisableVertexAttribArray glad_glDisableVertexAttribArray
GLAPI PFNGLVERTEXATTRIB4NUBARBPROC glad_glVertexAttrib4NubARB;
#define glVertexAttrib4NubARB glad_glVertexAttrib4NubARB
GLAPI PFNGLPRIMITIVERESTARTNVPROC glad_glPrimitiveRestartNV;
#define glPrimitiveRestartNV glad_glPrimitiveRestartNV
GLAPI PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC glad_glProgramNamedParameter4fvNV;
#define glProgramNamedParameter4fvNV glad_glProgramNamedParameter4fvNV
GLAPI PFNGLVERTEXATTRIBL1UI64VARBPROC glad_glVertexAttribL1ui64vARB;
#define glVertexAttribL1ui64vARB glad_glVertexAttribL1ui64vARB
GLAPI PFNGLPOINTPARAMETERFVARBPROC glad_glPointParameterfvARB;
#define glPointParameterfvARB glad_glPointParameterfvARB
GLAPI PFNGLUNIFORM1UIPROC glad_glUniform1ui;
#define glUniform1ui glad_glUniform1ui
GLAPI PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC glad_glTextureImage3DMultisampleCoverageNV;
#define glTextureImage3DMultisampleCoverageNV glad_glTextureImage3DMultisampleCoverageNV
GLAPI PFNGLMEMORYBARRIERPROC glad_glMemoryBarrier;
#define glMemoryBarrier glad_glMemoryBarrier
GLAPI PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC glad_glTexCoord4fColor4fNormal3fVertex4fvSUN;
#define glTexCoord4fColor4fNormal3fVertex4fvSUN glad_glTexCoord4fColor4fNormal3fVertex4fvSUN
GLAPI PFNGLISPROGRAMARBPROC glad_glIsProgramARB;
#define glIsProgramARB glad_glIsProgramARB
GLAPI PFNGLBINDIMAGETEXTUREEXTPROC glad_glBindImageTextureEXT;
#define glBindImageTextureEXT glad_glBindImageTextureEXT
GLAPI PFNGLBEGINQUERYPROC glad_glBeginQuery;
#define glBeginQuery glad_glBeginQuery
GLAPI PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC glad_glReplacementCodeuiColor4fNormal3fVertex3fSUN;
#define glReplacementCodeuiColor4fNormal3fVertex3fSUN glad_glReplacementCodeuiColor4fNormal3fVertex3fSUN
GLAPI PFNGLENABLECLIENTSTATEIEXTPROC glad_glEnableClientStateiEXT;
#define glEnableClientStateiEXT glad_glEnableClientStateiEXT
GLAPI PFNGLCLEARTEXSUBIMAGEPROC glad_glClearTexSubImage;
#define glClearTexSubImage glad_glClearTexSubImage
GLAPI PFNGLEVALCOORD1XVOESPROC glad_glEvalCoord1xvOES;
#define glEvalCoord1xvOES glad_glEvalCoord1xvOES
GLAPI PFNGLCOLORFORMATNVPROC glad_glColorFormatNV;
#define glColorFormatNV glad_glColorFormatNV
GLAPI PFNGLALPHAFRAGMENTOP1ATIPROC glad_glAlphaFragmentOp1ATI;
#define glAlphaFragmentOp1ATI glad_glAlphaFragmentOp1ATI
GLAPI PFNGLGETTEXTUREPARAMETERIIVPROC glad_glGetTextureParameterIiv;
#define glGetTextureParameterIiv glad_glGetTextureParameterIiv
GLAPI PFNGLMULTITEXCOORD1DARBPROC glad_glMultiTexCoord1dARB;
#define glMultiTexCoord1dARB glad_glMultiTexCoord1dARB
GLAPI PFNGLCREATEPERFQUERYINTELPROC glad_glCreatePerfQueryINTEL;
#define glCreatePerfQueryINTEL glad_glCreatePerfQueryINTEL
GLAPI PFNGLWINDOWPOS3IVMESAPROC glad_glWindowPos3ivMESA;
#define glWindowPos3ivMESA glad_glWindowPos3ivMESA
GLAPI PFNGLPIXELTEXGENPARAMETERFSGISPROC glad_glPixelTexGenParameterfSGIS;
#define glPixelTexGenParameterfSGIS glad_glPixelTexGenParameterfSGIS
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glad_glProgramUniformMatrix4x2dv;
#define glProgramUniformMatrix4x2dv glad_glProgramUniformMatrix4x2dv
GLAPI PFNGLUNIFORM3FARBPROC glad_glUniform3fARB;
#define glUniform3fARB glad_glUniform3fARB
GLAPI PFNGLISSHADERPROC glad_glIsShader;
#define glIsShader glad_glIsShader
GLAPI PFNGLVERTEX2HNVPROC glad_glVertex2hNV;
#define glVertex2hNV glad_glVertex2hNV
GLAPI PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC glad_glCopyMultiTexSubImage2DEXT;
#define glCopyMultiTexSubImage2DEXT glad_glCopyMultiTexSubImage2DEXT
GLAPI PFNGLENABLEVERTEXATTRIBARRAYARBPROC glad_glEnableVertexAttribArrayARB;
#define glEnableVertexAttribArrayARB glad_glEnableVertexAttribArrayARB
GLAPI PFNGLENABLEPROC glad_glEnable;
#define glEnable glad_glEnable
GLAPI PFNGLTEXCOORD4HVNVPROC glad_glTexCoord4hvNV;
#define glTexCoord4hvNV glad_glTexCoord4hvNV
GLAPI PFNGLVERTEXATTRIB4DVPROC glad_glVertexAttrib4dv;
#define glVertexAttrib4dv glad_glVertexAttrib4dv
GLAPI PFNGLUNIFORM3UI64VNVPROC glad_glUniform3ui64vNV;
#define glUniform3ui64vNV glad_glUniform3ui64vNV
GLAPI PFNGLGETVIDEOUIVNVPROC glad_glGetVideouivNV;
#define glGetVideouivNV glad_glGetVideouivNV
GLAPI PFNGLVERTEXATTRIB3SVARBPROC glad_glVertexAttrib3svARB;
#define glVertexAttrib3svARB glad_glVertexAttrib3svARB
GLAPI PFNGLBINORMAL3FVEXTPROC glad_glBinormal3fvEXT;
#define glBinormal3fvEXT glad_glBinormal3fvEXT
GLAPI PFNGLPROGRAMUNIFORM1UI64ARBPROC glad_glProgramUniform1ui64ARB;
#define glProgramUniform1ui64ARB glad_glProgramUniform1ui64ARB
GLAPI PFNGLWINDOWPOS2SVARBPROC glad_glWindowPos2svARB;
#define glWindowPos2svARB glad_glWindowPos2svARB
GLAPI PFNGLVERTEX4XOESPROC glad_glVertex4xOES;
#define glVertex4xOES glad_glVertex4xOES
GLAPI PFNGLWINDOWPOS2IVARBPROC glad_glWindowPos2ivARB;
#define glWindowPos2ivARB glad_glWindowPos2ivARB
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC glad_glProgramUniformMatrix2x4dvEXT;
#define glProgramUniformMatrix2x4dvEXT glad_glProgramUniformMatrix2x4dvEXT
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC glad_glVertexArrayVertexAttribDivisorEXT;
#define glVertexArrayVertexAttribDivisorEXT glad_glVertexArrayVertexAttribDivisorEXT
GLAPI PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC glad_glProgramLocalParameterI4ivNV;
#define glProgramLocalParameterI4ivNV glad_glProgramLocalParameterI4ivNV
GLAPI PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC glad_glCompressedMultiTexImage2DEXT;
#define glCompressedMultiTexImage2DEXT glad_glCompressedMultiTexImage2DEXT
GLAPI PFNGLBINDFRAGDATALOCATIONEXTPROC glad_glBindFragDataLocationEXT;
#define glBindFragDataLocationEXT glad_glBindFragDataLocationEXT
GLAPI PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glad_glTransformFeedbackBufferRange;
#define glTransformFeedbackBufferRange glad_glTransformFeedbackBufferRange
GLAPI PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv;
#define glGetVertexAttribPointerv glad_glGetVertexAttribPointerv
GLAPI PFNGLBINDLIGHTPARAMETEREXTPROC glad_glBindLightParameterEXT;
#define glBindLightParameterEXT glad_glBindLightParameterEXT
GLAPI PFNGLGETFOGFUNCSGISPROC glad_glGetFogFuncSGIS;
#define glGetFogFuncSGIS glad_glGetFogFuncSGIS
GLAPI PFNGLFRAGMENTLIGHTISGIXPROC glad_glFragmentLightiSGIX;
#define glFragmentLightiSGIX glad_glFragmentLightiSGIX
GLAPI PFNGLGETATTACHEDOBJECTSARBPROC glad_glGetAttachedObjectsARB;
#define glGetAttachedObjectsARB glad_glGetAttachedObjectsARB
GLAPI PFNGLINDEXXOESPROC glad_glIndexxOES;
#define glIndexxOES glad_glIndexxOES
GLAPI PFNGLUNIFORM4IVPROC glad_glUniform4iv;
#define glUniform4iv glad_glUniform4iv
GLAPI PFNGLMATRIXINDEXPOINTERARBPROC glad_glMatrixIndexPointerARB;
#define glMatrixIndexPointerARB glad_glMatrixIndexPointerARB
GLAPI PFNGLDELETECOMMANDLISTSNVPROC glad_glDeleteCommandListsNV;
#define glDeleteCommandListsNV glad_glDeleteCommandListsNV
GLAPI PFNGLSECONDARYCOLOR3DVEXTPROC glad_glSecondaryColor3dvEXT;
#define glSecondaryColor3dvEXT glad_glSecondaryColor3dvEXT
GLAPI PFNGLGENTEXTURESPROC glad_glGenTextures;
#define glGenTextures glad_glGenTextures
GLAPI PFNGLMAKEBUFFERRESIDENTNVPROC glad_glMakeBufferResidentNV;
#define glMakeBufferResidentNV glad_glMakeBufferResidentNV
GLAPI PFNGLACTIVETEXTUREARBPROC glad_glActiveTextureARB;
#define glActiveTextureARB glad_glActiveTextureARB
GLAPI PFNGLGETPERFQUERYDATAINTELPROC glad_glGetPerfQueryDataINTEL;
#define glGetPerfQueryDataINTEL glad_glGetPerfQueryDataINTEL
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC glad_glNamedFramebufferTexture1DEXT;
#define glNamedFramebufferTexture1DEXT glad_glNamedFramebufferTexture1DEXT
GLAPI PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers;
#define glDeleteRenderbuffers glad_glDeleteRenderbuffers
GLAPI PFNGLPATHPARAMETERFNVPROC glad_glPathParameterfNV;
#define glPathParameterfNV glad_glPathParameterfNV
GLAPI PFNGLVERTEXATTRIB2DVARBPROC glad_glVertexAttrib2dvARB;
#define glVertexAttrib2dvARB glad_glVertexAttrib2dvARB
GLAPI PFNGLDEPTHBOUNDSDNVPROC glad_glDepthBoundsdNV;
#define glDepthBoundsdNV glad_glDepthBoundsdNV
GLAPI PFNGLDELETETEXTURESEXTPROC glad_glDeleteTexturesEXT;
#define glDeleteTexturesEXT glad_glDeleteTexturesEXT
GLAPI PFNGLLIGHTMODELXVOESPROC glad_glLightModelxvOES;
#define glLightModelxvOES glad_glLightModelxvOES
GLAPI PFNGLGETFLOATI_VPROC glad_glGetFloati_v;
#define glGetFloati_v glad_glGetFloati_v
GLAPI PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC glad_glColor4fNormal3fVertex3fSUN;
#define glColor4fNormal3fVertex3fSUN glad_glColor4fNormal3fVertex3fSUN
GLAPI PFNGLFLUSHSTATICDATAIBMPROC glad_glFlushStaticDataIBM;
#define glFlushStaticDataIBM glad_glFlushStaticDataIBM
GLAPI PFNGLRASTERPOS4XOESPROC glad_glRasterPos4xOES;
#define glRasterPos4xOES glad_glRasterPos4xOES
GLAPI PFNGLVERTEXATTRIB4DVARBPROC glad_glVertexAttrib4dvARB;
#define glVertexAttrib4dvARB glad_glVertexAttrib4dvARB
GLAPI PFNGLLIGHTENVISGIXPROC glad_glLightEnviSGIX;
#define glLightEnviSGIX glad_glLightEnviSGIX
GLAPI PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glad_glGetNamedRenderbufferParameteriv;
#define glGetNamedRenderbufferParameteriv glad_glGetNamedRenderbufferParameteriv
GLAPI PFNGLDRAWCOMMANDSADDRESSNVPROC glad_glDrawCommandsAddressNV;
#define glDrawCommandsAddressNV glad_glDrawCommandsAddressNV
GLAPI PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glad_glBindFragDataLocationIndexed;
#define glBindFragDataLocationIndexed glad_glBindFragDataLocationIndexed
GLAPI PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC glad_glNamedFramebufferRenderbufferEXT;
#define glNamedFramebufferRenderbufferEXT glad_glNamedFramebufferRenderbufferEXT
GLAPI PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC glad_glFlushVertexArrayRangeAPPLE;
#define glFlushVertexArrayRangeAPPLE glad_glFlushVertexArrayRangeAPPLE
GLAPI PFNGLMULTITEXCOORD3DVARBPROC glad_glMultiTexCoord3dvARB;
#define glMultiTexCoord3dvARB glad_glMultiTexCoord3dvARB
GLAPI PFNGLTEXTURESUBIMAGE3DPROC glad_glTextureSubImage3D;
#define glTextureSubImage3D glad_glTextureSubImage3D
GLAPI PFNGLFRAMEBUFFERTEXTURE1DPROC glad_glFramebufferTexture1D;
#define glFramebufferTexture1D glad_glFramebufferTexture1D
GLAPI PFNGLFRAGMENTLIGHTMODELFSGIXPROC glad_glFragmentLightModelfSGIX;
#define glFragmentLightModelfSGIX glad_glFragmentLightModelfSGIX
GLAPI PFNGLGETPOINTERI_VEXTPROC glad_glGetPointeri_vEXT;
#define glGetPointeri_vEXT glad_glGetPointeri_vEXT
GLAPI PFNGLNAMEDBUFFERSTORAGEPROC glad_glNamedBufferStorage;
#define glNamedBufferStorage glad_glNamedBufferStorage
GLAPI PFNGLMAPGRID1XOESPROC glad_glMapGrid1xOES;
#define glMapGrid1xOES glad_glMapGrid1xOES
GLAPI PFNGLSECONDARYCOLOR3USVEXTPROC glad_glSecondaryColor3usvEXT;
#define glSecondaryColor3usvEXT glad_glSecondaryColor3usvEXT
GLAPI PFNGLFRAGMENTMATERIALIVSGIXPROC glad_glFragmentMaterialivSGIX;
#define glFragmentMaterialivSGIX glad_glFragmentMaterialivSGIX
GLAPI PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC glad_glVertexArrayVertexAttribBindingEXT;
#define glVertexArrayVertexAttribBindingEXT glad_glVertexArrayVertexAttribBindingEXT
GLAPI PFNGLVARIANTIVEXTPROC glad_glVariantivEXT;
#define glVariantivEXT glad_glVariantivEXT
GLAPI PFNGLTEXTUREMATERIALEXTPROC glad_glTextureMaterialEXT;
#define glTextureMaterialEXT glad_glTextureMaterialEXT
GLAPI PFNGLGETPATHCOORDSNVPROC glad_glGetPathCoordsNV;
#define glGetPathCoordsNV glad_glGetPathCoordsNV
GLAPI PFNGLCOLOR4XVOESPROC glad_glColor4xvOES;
#define glColor4xvOES glad_glColor4xvOES
GLAPI PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC glad_glStencilThenCoverFillPathInstancedNV;
#define glStencilThenCoverFillPathInstancedNV glad_glStencilThenCoverFillPathInstancedNV
GLAPI PFNGLCLAMPCOLORARBPROC glad_glClampColorARB;
#define glClampColorARB glad_glClampColorARB
GLAPI PFNGLVERTEX4BOESPROC glad_glVertex4bOES;
#define glVertex4bOES glad_glVertex4bOES
GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC glad_glTransformFeedbackVaryingsEXT;
#define glTransformFeedbackVaryingsEXT glad_glTransformFeedbackVaryingsEXT
GLAPI PFNGLVERTEXATTRIB4SVARBPROC glad_glVertexAttrib4svARB;
#define glVertexAttrib4svARB glad_glVertexAttrib4svARB
GLAPI PFNGLGETINFOLOGARBPROC glad_glGetInfoLogARB;
#define glGetInfoLogARB glad_glGetInfoLogARB
GLAPI PFNGLGLOBALALPHAFACTORSSUNPROC glad_glGlobalAlphaFactorsSUN;
#define glGlobalAlphaFactorsSUN glad_glGlobalAlphaFactorsSUN
GLAPI PFNGLMATRIXMULTDEXTPROC glad_glMatrixMultdEXT;
#define glMatrixMultdEXT glad_glMatrixMultdEXT
GLAPI PFNGLVERTEXATTRIB1FVARBPROC glad_glVertexAttrib1fvARB;
#define glVertexAttrib1fvARB glad_glVertexAttrib1fvARB
GLAPI PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glad_glMultiDrawElementsBaseVertex;
#define glMultiDrawElementsBaseVertex glad_glMultiDrawElementsBaseVertex
GLAPI PFNGLVERTEXSTREAM3IATIPROC glad_glVertexStream3iATI;
#define glVertexStream3iATI glad_glVertexStream3iATI
GLAPI PFNGLREADNPIXELSPROC glad_glReadnPixels;
#define glReadnPixels glad_glReadnPixels
GLAPI PFNGLTEXPARAMETERXVOESPROC glad_glTexParameterxvOES;
#define glTexParameterxvOES glad_glTexParameterxvOES
GLAPI PFNGLTEXTUREBUFFERPROC glad_glTextureBuffer;
#define glTextureBuffer glad_glTextureBuffer
GLAPI PFNGLTEXTUREBUFFERRANGEEXTPROC glad_glTextureBufferRangeEXT;
#define glTextureBufferRangeEXT glad_glTextureBufferRangeEXT
GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_glTransformFeedbackVaryings;
#define glTransformFeedbackVaryings glad_glTransformFeedbackVaryings
GLAPI PFNGLGETNUNIFORMI64VARBPROC glad_glGetnUniformi64vARB;
#define glGetnUniformi64vARB glad_glGetnUniformi64vARB
GLAPI PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC glad_glFramebufferTextureMultiviewOVR;
#define glFramebufferTextureMultiviewOVR glad_glFramebufferTextureMultiviewOVR
GLAPI PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC glad_glStencilThenCoverStrokePathInstancedNV;
#define glStencilThenCoverStrokePathInstancedNV glad_glStencilThenCoverStrokePathInstancedNV
GLAPI PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC glad_glTransformFeedbackStreamAttribsNV;
#define glTransformFeedbackStreamAttribsNV glad_glTransformFeedbackStreamAttribsNV
GLAPI PFNGLBUFFERSUBDATAARBPROC glad_glBufferSubDataARB;
#define glBufferSubDataARB glad_glBufferSubDataARB
GLAPI PFNGLGETVERTEXATTRIBLUI64VARBPROC glad_glGetVertexAttribLui64vARB;
#define glGetVertexAttribLui64vARB glad_glGetVertexAttribLui64vARB
GLAPI PFNGLVERTEXATTRIBL4UI64NVPROC glad_glVertexAttribL4ui64NV;
#define glVertexAttribL4ui64NV glad_glVertexAttribL4ui64NV
GLAPI PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC glad_glReplacementCodeuiColor4ubVertex3fSUN;
#define glReplacementCodeuiColor4ubVertex3fSUN glad_glReplacementCodeuiColor4ubVertex3fSUN
GLAPI PFNGLIMAGETRANSFORMPARAMETERFHPPROC glad_glImageTransformParameterfHP;
#define glImageTransformParameterfHP glad_glImageTransformParameterfHP
GLAPI PFNGLVERTEX2BVOESPROC glad_glVertex2bvOES;
#define glVertex2bvOES glad_glVertex2bvOES
GLAPI PFNGLGETMAPCONTROLPOINTSNVPROC glad_glGetMapControlPointsNV;
#define glGetMapControlPointsNV glad_glGetMapControlPointsNV
GLAPI PFNGLVERTEXATTRIBS4HVNVPROC glad_glVertexAttribs4hvNV;
#define glVertexAttribs4hvNV glad_glVertexAttribs4hvNV
GLAPI PFNGLBINDBUFFERRANGENVPROC glad_glBindBufferRangeNV;
#define glBindBufferRangeNV glad_glBindBufferRangeNV
GLAPI PFNGLNORMALPOINTERLISTIBMPROC glad_glNormalPointerListIBM;
#define glNormalPointerListIBM glad_glNormalPointerListIBM
GLAPI PFNGLPROGRAMUNIFORM2DVEXTPROC glad_glProgramUniform2dvEXT;
#define glProgramUniform2dvEXT glad_glProgramUniform2dvEXT
GLAPI PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glad_glGetNamedFramebufferAttachmentParameterivEXT;
#define glGetNamedFramebufferAttachmentParameterivEXT glad_glGetNamedFramebufferAttachmentParameterivEXT
GLAPI PFNGLGETTEXTUREIMAGEEXTPROC glad_glGetTextureImageEXT;
#define glGetTextureImageEXT glad_glGetTextureImageEXT
GLAPI PFNGLREPLACEMENTCODEUISUNPROC glad_glReplacementCodeuiSUN;
#define glReplacementCodeuiSUN glad_glReplacementCodeuiSUN
GLAPI PFNGLVERTEXATTRIB4SVNVPROC glad_glVertexAttrib4svNV;
#define glVertexAttrib4svNV glad_glVertexAttrib4svNV
GLAPI PFNGLDEPTHMASKPROC glad_glDepthMask;
#define glDepthMask glad_glDepthMask
GLAPI PFNGLDEPTHRANGEARRAYVPROC glad_glDepthRangeArrayv;
#define glDepthRangeArrayv glad_glDepthRangeArrayv
GLAPI PFNGLVERTEXARRAYATTRIBBINDINGPROC glad_glVertexArrayAttribBinding;
#define glVertexArrayAttribBinding glad_glVertexArrayAttribBinding
GLAPI PFNGLVERTEXATTRIBL4DVPROC glad_glVertexAttribL4dv;
#define glVertexAttribL4dv glad_glVertexAttribL4dv
GLAPI PFNGLVERTEXSTREAM3DATIPROC glad_glVertexStream3dATI;
#define glVertexStream3dATI glad_glVertexStream3dATI
GLAPI PFNGLLIGHTXVOESPROC glad_glLightxvOES;
#define glLightxvOES glad_glLightxvOES
GLAPI PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v;
#define glGetBufferParameteri64v glad_glGetBufferParameteri64v
GLAPI PFNGLDRAWARRAYSINSTANCEDARBPROC glad_glDrawArraysInstancedARB;
#define glDrawArraysInstancedARB glad_glDrawArraysInstancedARB
GLAPI PFNGLWINDOWPOS2IMESAPROC glad_glWindowPos2iMESA;
#define glWindowPos2iMESA glad_glWindowPos2iMESA
GLAPI PFNGLVERTEX2XVOESPROC glad_glVertex2xvOES;
#define glVertex2xvOES glad_glVertex2xvOES
GLAPI PFNGLDISABLEPROC glad_glDisable;
#define glDisable glad_glDisable
GLAPI PFNGLISPOINTINFILLPATHNVPROC glad_glIsPointInFillPathNV;
#define glIsPointInFillPathNV glad_glIsPointInFillPathNV
GLAPI PFNGLVERTEXATTRIBI2UIEXTPROC glad_glVertexAttribI2uiEXT;
#define glVertexAttribI2uiEXT glad_glVertexAttribI2uiEXT
GLAPI PFNGLGETFRAGMENTLIGHTFVSGIXPROC glad_glGetFragmentLightfvSGIX;
#define glGetFragmentLightfvSGIX glad_glGetFragmentLightfvSGIX
GLAPI PFNGLBINDBUFFEROFFSETNVPROC glad_glBindBufferOffsetNV;
#define glBindBufferOffsetNV glad_glBindBufferOffsetNV
GLAPI PFNGLVERTEXATTRIBI2UIVPROC glad_glVertexAttribI2uiv;
#define glVertexAttribI2uiv glad_glVertexAttribI2uiv
GLAPI PFNGLPASSTEXCOORDATIPROC glad_glPassTexCoordATI;
#define glPassTexCoordATI glad_glPassTexCoordATI
GLAPI PFNGLGETTEXGENXVOESPROC glad_glGetTexGenxvOES;
#define glGetTexGenxvOES glad_glGetTexGenxvOES
GLAPI PFNGLTEXTURESUBIMAGE2DPROC glad_glTextureSubImage2D;
#define glTextureSubImage2D glad_glTextureSubImage2D
GLAPI PFNGLVERTEXATTRIB4SPROC glad_glVertexAttrib4s;
#define glVertexAttrib4s glad_glVertexAttrib4s
GLAPI PFNGLACCUMXOESPROC glad_glAccumxOES;
#define glAccumxOES glad_glAccumxOES
GLAPI PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv;
#define glGetBufferPointerv glad_glGetBufferPointerv
GLAPI PFNGLCLIPPLANEFOESPROC glad_glClipPlanefOES;
#define glClipPlanefOES glad_glClipPlanefOES
GLAPI PFNGLSHADERBINARYPROC glad_glShaderBinary;
#define glShaderBinary glad_glShaderBinary
GLAPI PFNGLPOINTPARAMETERXVOESPROC glad_glPointParameterxvOES;
#define glPointParameterxvOES glad_glPointParameterxvOES
GLAPI PFNGLVERTEXATTRIBS3HVNVPROC glad_glVertexAttribs3hvNV;
#define glVertexAttribs3hvNV glad_glVertexAttribs3hvNV
GLAPI PFNGLVERTEXATTRIB4HNVPROC glad_glVertexAttrib4hNV;
#define glVertexAttrib4hNV glad_glVertexAttrib4hNV
GLAPI PFNGLVERTEXATTRIBI1IEXTPROC glad_glVertexAttribI1iEXT;
#define glVertexAttribI1iEXT glad_glVertexAttribI1iEXT
GLAPI PFNGLLIGHTMODELXOESPROC glad_glLightModelxOES;
#define glLightModelxOES glad_glLightModelxOES
GLAPI PFNGLPROGRAMUNIFORM4I64NVPROC glad_glProgramUniform4i64NV;
#define glProgramUniform4i64NV glad_glProgramUniform4i64NV
GLAPI PFNGLVERTEXSTREAM4DVATIPROC glad_glVertexStream4dvATI;
#define glVertexStream4dvATI glad_glVertexStream4dvATI
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D;
#define glCompressedTexSubImage1D glad_glCompressedTexSubImage1D
GLAPI PFNGLVERTEXBLENDENVIATIPROC glad_glVertexBlendEnviATI;
#define glVertexBlendEnviATI glad_glVertexBlendEnviATI
GLAPI PFNGLBINDTRANSFORMFEEDBACKNVPROC glad_glBindTransformFeedbackNV;
#define glBindTransformFeedbackNV glad_glBindTransformFeedbackNV
GLAPI PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC glad_glNamedBufferPageCommitmentEXT;
#define glNamedBufferPageCommitmentEXT glad_glNamedBufferPageCommitmentEXT
GLAPI PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glad_glCheckNamedFramebufferStatus;
#define glCheckNamedFramebufferStatus glad_glCheckNamedFramebufferStatus
GLAPI PFNGLGETOBJECTBUFFERFVATIPROC glad_glGetObjectBufferfvATI;
#define glGetObjectBufferfvATI glad_glGetObjectBufferfvATI
GLAPI PFNGLDRAWELEMENTSINSTANCEDEXTPROC glad_glDrawElementsInstancedEXT;
#define glDrawElementsInstancedEXT glad_glDrawElementsInstancedEXT
GLAPI PFNGLDISABLEVERTEXARRAYEXTPROC glad_glDisableVertexArrayEXT;
#define glDisableVertexArrayEXT glad_glDisableVertexArrayEXT
GLAPI PFNGLGETPROGRAMSTAGEIVPROC glad_glGetProgramStageiv;
#define glGetProgramStageiv glad_glGetProgramStageiv
GLAPI PFNGLENDVIDEOCAPTURENVPROC glad_glEndVideoCaptureNV;
#define glEndVideoCaptureNV glad_glEndVideoCaptureNV
GLAPI PFNGLUNIFORM4IPROC glad_glUniform4i;
#define glUniform4i glad_glUniform4i
GLAPI PFNGLTEXCOORD4FVERTEX4FVSUNPROC glad_glTexCoord4fVertex4fvSUN;
#define glTexCoord4fVertex4fvSUN glad_glTexCoord4fVertex4fvSUN
GLAPI PFNGLUNIFORM4DPROC glad_glUniform4d;
#define glUniform4d glad_glUniform4d
GLAPI PFNGLUNIFORM4FPROC glad_glUniform4f;
#define glUniform4f glad_glUniform4f
GLAPI PFNGLCREATEPROGRAMPIPELINESPROC glad_glCreateProgramPipelines;
#define glCreateProgramPipelines glad_glCreateProgramPipelines
GLAPI PFNGLGETFRAGMENTMATERIALIVSGIXPROC glad_glGetFragmentMaterialivSGIX;
#define glGetFragmentMaterialivSGIX glad_glGetFragmentMaterialivSGIX
GLAPI PFNGLWINDOWPOS3DMESAPROC glad_glWindowPos3dMESA;
#define glWindowPos3dMESA glad_glWindowPos3dMESA
GLAPI PFNGLVERTEXATTRIBLPOINTERPROC glad_glVertexAttribLPointer;
#define glVertexAttribLPointer glad_glVertexAttribLPointer
GLAPI PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC glad_glPixelTransformParameterfvEXT;
#define glPixelTransformParameterfvEXT glad_glPixelTransformParameterfvEXT
GLAPI PFNGLMULTITEXCOORD4HNVPROC glad_glMultiTexCoord4hNV;
#define glMultiTexCoord4hNV glad_glMultiTexCoord4hNV
GLAPI PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC glad_glTextureImage2DMultisampleCoverageNV;
#define glTextureImage2DMultisampleCoverageNV glad_glTextureImage2DMultisampleCoverageNV
GLAPI PFNGLGETACTIVESUBROUTINENAMEPROC glad_glGetActiveSubroutineName;
#define glGetActiveSubroutineName glad_glGetActiveSubroutineName
GLAPI PFNGLVERTEXATTRIBI1IVEXTPROC glad_glVertexAttribI1ivEXT;
#define glVertexAttribI1ivEXT glad_glVertexAttribI1ivEXT
GLAPI PFNGLPOPDEBUGGROUPPROC glad_glPopDebugGroup;
#define glPopDebugGroup glad_glPopDebugGroup
GLAPI PFNGLGENERATETEXTUREMIPMAPEXTPROC glad_glGenerateTextureMipmapEXT;
#define glGenerateTextureMipmapEXT glad_glGenerateTextureMipmapEXT
GLAPI PFNGLTEXCOORD3BOESPROC glad_glTexCoord3bOES;
#define glTexCoord3bOES glad_glTexCoord3bOES
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glad_glProgramUniformMatrix3x2fv;
#define glProgramUniformMatrix3x2fv glad_glProgramUniformMatrix3x2fv
GLAPI PFNGLUNIFORM2FVARBPROC glad_glUniform2fvARB;
#define glUniform2fvARB glad_glUniform2fvARB
GLAPI PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC glad_glProgramLocalParameterI4uivNV;
#define glProgramLocalParameterI4uivNV glad_glProgramLocalParameterI4uivNV
GLAPI PFNGLFLUSHVERTEXARRAYRANGENVPROC glad_glFlushVertexArrayRangeNV;
#define glFlushVertexArrayRangeNV glad_glFlushVertexArrayRangeNV
GLAPI PFNGLSECONDARYCOLOR3SVEXTPROC glad_glSecondaryColor3svEXT;
#define glSecondaryColor3svEXT glad_glSecondaryColor3svEXT
GLAPI PFNGLGETQUERYINDEXEDIVPROC glad_glGetQueryIndexediv;
#define glGetQueryIndexediv glad_glGetQueryIndexediv
GLAPI PFNGLOBJECTLABELPROC glad_glObjectLabel;
#define glObjectLabel glad_glObjectLabel
GLAPI PFNGLINDEXMATERIALEXTPROC glad_glIndexMaterialEXT;
#define glIndexMaterialEXT glad_glIndexMaterialEXT
GLAPI PFNGLTEXCOORD2HVNVPROC glad_glTexCoord2hvNV;
#define glTexCoord2hvNV glad_glTexCoord2hvNV
GLAPI PFNGLGLOBALALPHAFACTORUISUNPROC glad_glGlobalAlphaFactoruiSUN;
#define glGlobalAlphaFactoruiSUN glad_glGlobalAlphaFactoruiSUN
GLAPI PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glad_glEnableVariantClientStateEXT;
#define glEnableVariantClientStateEXT glad_glEnableVariantClientStateEXT
GLAPI PFNGLUNIFORM4UI64VARBPROC glad_glUniform4ui64vARB;
#define glUniform4ui64vARB glad_glUniform4ui64vARB
GLAPI PFNGLDEBUGMESSAGECALLBACKAMDPROC glad_glDebugMessageCallbackAMD;
#define glDebugMessageCallbackAMD glad_glDebugMessageCallbackAMD
GLAPI PFNGLVERTEXATTRIB2DNVPROC glad_glVertexAttrib2dNV;
#define glVertexAttrib2dNV glad_glVertexAttrib2dNV
GLAPI PFNGLWINDOWPOS4SVMESAPROC glad_glWindowPos4svMESA;
#define glWindowPos4svMESA glad_glWindowPos4svMESA
GLAPI PFNGLELEMENTPOINTERAPPLEPROC glad_glElementPointerAPPLE;
#define glElementPointerAPPLE glad_glElementPointerAPPLE
GLAPI PFNGLPATHSTRINGNVPROC glad_glPathStringNV;
#define glPathStringNV glad_glPathStringNV
GLAPI PFNGLGETMULTITEXPARAMETERIIVEXTPROC glad_glGetMultiTexParameterIivEXT;
#define glGetMultiTexParameterIivEXT glad_glGetMultiTexParameterIivEXT
GLAPI PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC glad_glGetNamedFramebufferParameterivEXT;
#define glGetNamedFramebufferParameterivEXT glad_glGetNamedFramebufferParameterivEXT
GLAPI PFNGLPATHDASHARRAYNVPROC glad_glPathDashArrayNV;
#define glPathDashArrayNV glad_glPathDashArrayNV
GLAPI PFNGLCLEARCOLORPROC glad_glClearColor;
#define glClearColor glad_glClearColor
GLAPI PFNGLGETIMAGEHANDLEARBPROC glad_glGetImageHandleARB;
#define glGetImageHandleARB glad_glGetImageHandleARB
GLAPI PFNGLPIXELTEXGENSGIXPROC glad_glPixelTexGenSGIX;
#define glPixelTexGenSGIX glad_glPixelTexGenSGIX
GLAPI PFNGLGETLOCALCONSTANTFLOATVEXTPROC glad_glGetLocalConstantFloatvEXT;
#define glGetLocalConstantFloatvEXT glad_glGetLocalConstantFloatvEXT
GLAPI PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glad_glGetNamedFramebufferParameteriv;
#define glGetNamedFramebufferParameteriv glad_glGetNamedFramebufferParameteriv
GLAPI PFNGLUNIFORM3UIPROC glad_glUniform3ui;
#define glUniform3ui glad_glUniform3ui
GLAPI PFNGLCLEARCOLORIUIEXTPROC glad_glClearColorIuiEXT;
#define glClearColorIuiEXT glad_glClearColorIuiEXT
GLAPI PFNGLVERTEXATTRIBI4UIVPROC glad_glVertexAttribI4uiv;
#define glVertexAttribI4uiv glad_glVertexAttribI4uiv
GLAPI PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC glad_glGetCompressedTextureImageEXT;
#define glGetCompressedTextureImageEXT glad_glGetCompressedTextureImageEXT
GLAPI PFNGLVERTEXATTRIB4BVPROC glad_glVertexAttrib4bv;
#define glVertexAttrib4bv glad_glVertexAttrib4bv
GLAPI PFNGLGETPROGRAMRESOURCEINDEXPROC glad_glGetProgramResourceIndex;
#define glGetProgramResourceIndex glad_glGetProgramResourceIndex
GLAPI PFNGLCONVOLUTIONFILTER2DEXTPROC glad_glConvolutionFilter2DEXT;
#define glConvolutionFilter2DEXT glad_glConvolutionFilter2DEXT
GLAPI PFNGLLOCKARRAYSEXTPROC glad_glLockArraysEXT;
#define glLockArraysEXT glad_glLockArraysEXT
GLAPI PFNGLGENFRAGMENTSHADERSATIPROC glad_glGenFragmentShadersATI;
#define glGenFragmentShadersATI glad_glGenFragmentShadersATI
GLAPI PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv;
#define glGetActiveUniformsiv glad_glGetActiveUniformsiv
GLAPI PFNGLBINDBUFFERBASEEXTPROC glad_glBindBufferBaseEXT;
#define glBindBufferBaseEXT glad_glBindBufferBaseEXT
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC glad_glProgramUniformMatrix2x3fvEXT;
#define glProgramUniformMatrix2x3fvEXT glad_glProgramUniformMatrix2x3fvEXT
GLAPI PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC glad_glNamedFramebufferSampleLocationsfvARB;
#define glNamedFramebufferSampleLocationsfvARB glad_glNamedFramebufferSampleLocationsfvARB
GLAPI PFNGLVERTEXATTRIB3SARBPROC glad_glVertexAttrib3sARB;
#define glVertexAttrib3sARB glad_glVertexAttrib3sARB
GLAPI PFNGLPROGRAMUNIFORM1IVPROC glad_glProgramUniform1iv;
#define glProgramUniform1iv glad_glProgramUniform1iv
GLAPI PFNGLVERTEX3XVOESPROC glad_glVertex3xvOES;
#define glVertex3xvOES glad_glVertex3xvOES
GLAPI PFNGLUPDATEOBJECTBUFFERATIPROC glad_glUpdateObjectBufferATI;
#define glUpdateObjectBufferATI glad_glUpdateObjectBufferATI
GLAPI PFNGLWINDOWPOS2FARBPROC glad_glWindowPos2fARB;
#define glWindowPos2fARB glad_glWindowPos2fARB
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glad_glCompressedTexSubImage3DARB;
#define glCompressedTexSubImage3DARB glad_glCompressedTexSubImage3DARB
GLAPI PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv;
#define glGetTexParameterfv glad_glGetTexParameterfv
GLAPI PFNGLCOPYCOLORTABLESGIPROC glad_glCopyColorTableSGI;
#define glCopyColorTableSGI glad_glCopyColorTableSGI
GLAPI PFNGLMULTITEXCOORD4SARBPROC glad_glMultiTexCoord4sARB;
#define glMultiTexCoord4sARB glad_glMultiTexCoord4sARB
GLAPI PFNGLGETVERTEXARRAYINDEXED64IVPROC glad_glGetVertexArrayIndexed64iv;
#define glGetVertexArrayIndexed64iv glad_glGetVertexArrayIndexed64iv
GLAPI PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC glad_glMatrixMultTranspose3x3fNV;
#define glMatrixMultTranspose3x3fNV glad_glMatrixMultTranspose3x3fNV
GLAPI PFNGLTEXPARAMETERIIVPROC glad_glTexParameterIiv;
#define glTexParameterIiv glad_glTexParameterIiv
GLAPI PFNGLVERTEXARRAYATTRIBFORMATPROC glad_glVertexArrayAttribFormat;
#define glVertexArrayAttribFormat glad_glVertexArrayAttribFormat
GLAPI PFNGLENDTRANSFORMFEEDBACKPROC glad_glEndTransformFeedback;
#define glEndTransformFeedback glad_glEndTransformFeedback
GLAPI PFNGLMULTITEXSUBIMAGE3DEXTPROC glad_glMultiTexSubImage3DEXT;
#define glMultiTexSubImage3DEXT glad_glMultiTexSubImage3DEXT
GLAPI PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample;
#define glTexImage2DMultisample glad_glTexImage2DMultisample
GLAPI PFNGLBINDTEXTUREEXTPROC glad_glBindTextureEXT;
#define glBindTextureEXT glad_glBindTextureEXT
GLAPI PFNGLVERTEXATTRIB1HNVPROC glad_glVertexAttrib1hNV;
#define glVertexAttrib1hNV glad_glVertexAttrib1hNV
GLAPI PFNGLMULTITEXCOORD3BVOESPROC glad_glMultiTexCoord3bvOES;
#define glMultiTexCoord3bvOES glad_glMultiTexCoord3bvOES
GLAPI PFNGLVERTEXATTRIBDIVISORPROC glad_glVertexAttribDivisor;
#define glVertexAttribDivisor glad_glVertexAttribDivisor
GLAPI PFNGLBINDTEXGENPARAMETEREXTPROC glad_glBindTexGenParameterEXT;
#define glBindTexGenParameterEXT glad_glBindTexGenParameterEXT
GLAPI PFNGLNORMALSTREAM3BATIPROC glad_glNormalStream3bATI;
#define glNormalStream3bATI glad_glNormalStream3bATI
GLAPI PFNGLSECONDARYCOLOR3FVEXTPROC glad_glSecondaryColor3fvEXT;
#define glSecondaryColor3fvEXT glad_glSecondaryColor3fvEXT
GLAPI PFNGLSTARTINSTRUMENTSSGIXPROC glad_glStartInstrumentsSGIX;
#define glStartInstrumentsSGIX glad_glStartInstrumentsSGIX
GLAPI PFNGLBINDVERTEXBUFFERSPROC glad_glBindVertexBuffers;
#define glBindVertexBuffers glad_glBindVertexBuffers
GLAPI PFNGLINVALIDATEBUFFERSUBDATAPROC glad_glInvalidateBufferSubData;
#define glInvalidateBufferSubData glad_glInvalidateBufferSubData
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC glad_glMultiDrawElementsIndirectCountARB;
#define glMultiDrawElementsIndirectCountARB glad_glMultiDrawElementsIndirectCountARB
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glad_glProgramUniformMatrix4x2fv;
#define glProgramUniformMatrix4x2fv glad_glProgramUniformMatrix4x2fv
GLAPI PFNGLMULTITEXCOORD3HNVPROC glad_glMultiTexCoord3hNV;
#define glMultiTexCoord3hNV glad_glMultiTexCoord3hNV
GLAPI PFNGLGETVIDEOCAPTUREIVNVPROC glad_glGetVideoCaptureivNV;
#define glGetVideoCaptureivNV glad_glGetVideoCaptureivNV
GLAPI PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glad_glTexCoord2fColor4fNormal3fVertex3fSUN;
#define glTexCoord2fColor4fNormal3fVertex3fSUN glad_glTexCoord2fColor4fNormal3fVertex3fSUN
GLAPI PFNGLGENTRANSFORMFEEDBACKSNVPROC glad_glGenTransformFeedbacksNV;
#define glGenTransformFeedbacksNV glad_glGenTransformFeedbacksNV
GLAPI PFNGLCOMBINERPARAMETERIVNVPROC glad_glCombinerParameterivNV;
#define glCombinerParameterivNV glad_glCombinerParameterivNV
GLAPI PFNGLCOPYMULTITEXIMAGE2DEXTPROC glad_glCopyMultiTexImage2DEXT;
#define glCopyMultiTexImage2DEXT glad_glCopyMultiTexImage2DEXT
GLAPI PFNGLTEXCOORD4BOESPROC glad_glTexCoord4bOES;
#define glTexCoord4bOES glad_glTexCoord4bOES
GLAPI PFNGLGETSHADERPRECISIONFORMATPROC glad_glGetShaderPrecisionFormat;
#define glGetShaderPrecisionFormat glad_glGetShaderPrecisionFormat
GLAPI PFNGLRASTERSAMPLESEXTPROC glad_glRasterSamplesEXT;
#define glRasterSamplesEXT glad_glRasterSamplesEXT
GLAPI PFNGLGETFRAGDATALOCATIONEXTPROC glad_glGetFragDataLocationEXT;
#define glGetFragDataLocationEXT glad_glGetFragDataLocationEXT
GLAPI PFNGLTEXCOORD3XOESPROC glad_glTexCoord3xOES;
#define glTexCoord3xOES glad_glTexCoord3xOES
GLAPI PFNGLCOPYTEXIMAGE2DEXTPROC glad_glCopyTexImage2DEXT;
#define glCopyTexImage2DEXT glad_glCopyTexImage2DEXT
GLAPI PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glad_glGetNamedBufferParameteri64v;
#define glGetNamedBufferParameteri64v glad_glGetNamedBufferParameteri64v
GLAPI PFNGLCOMMANDLISTSEGMENTSNVPROC glad_glCommandListSegmentsNV;
#define glCommandListSegmentsNV glad_glCommandListSegmentsNV
GLAPI PFNGLUNIFORM2DPROC glad_glUniform2d;
#define glUniform2d glad_glUniform2d
GLAPI PFNGLPROGRAMUNIFORM2UI64ARBPROC glad_glProgramUniform2ui64ARB;
#define glProgramUniform2ui64ARB glad_glProgramUniform2ui64ARB
GLAPI PFNGLBUFFERDATAPROC glad_glBufferData;
#define glBufferData glad_glBufferData
GLAPI PFNGLDRAWRANGEELEMENTARRAYATIPROC glad_glDrawRangeElementArrayATI;
#define glDrawRangeElementArrayATI glad_glDrawRangeElementArrayATI
GLAPI PFNGLGETDEBUGMESSAGELOGARBPROC glad_glGetDebugMessageLogARB;
#define glGetDebugMessageLogARB glad_glGetDebugMessageLogARB
GLAPI PFNGLFRAMEBUFFERTEXTURE3DPROC glad_glFramebufferTexture3D;
#define glFramebufferTexture3D glad_glFramebufferTexture3D
GLAPI PFNGLFRAGMENTMATERIALISGIXPROC glad_glFragmentMaterialiSGIX;
#define glFragmentMaterialiSGIX glad_glFragmentMaterialiSGIX
GLAPI PFNGLREADINSTRUMENTSSGIXPROC glad_glReadInstrumentsSGIX;
#define glReadInstrumentsSGIX glad_glReadInstrumentsSGIX
GLAPI PFNGLBEGINOCCLUSIONQUERYNVPROC glad_glBeginOcclusionQueryNV;
#define glBeginOcclusionQueryNV glad_glBeginOcclusionQueryNV
GLAPI PFNGLSCISSORINDEXEDVPROC glad_glScissorIndexedv;
#define glScissorIndexedv glad_glScissorIndexedv
GLAPI PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glad_glDisableVariantClientStateEXT;
#define glDisableVariantClientStateEXT glad_glDisableVariantClientStateEXT
GLAPI PFNGLMINMAXEXTPROC glad_glMinmaxEXT;
#define glMinmaxEXT glad_glMinmaxEXT
GLAPI PFNGLUNIFORM1IVARBPROC glad_glUniform1ivARB;
#define glUniform1ivARB glad_glUniform1ivARB
GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC glad_glGetTransformFeedbackVaryingEXT;
#define glGetTransformFeedbackVaryingEXT glad_glGetTransformFeedbackVaryingEXT
GLAPI PFNGLMULTITEXCOORD2BOESPROC glad_glMultiTexCoord2bOES;
#define glMultiTexCoord2bOES glad_glMultiTexCoord2bOES
GLAPI PFNGLTEXIMAGE3DMULTISAMPLEPROC glad_glTexImage3DMultisample;
#define glTexImage3DMultisample glad_glTexImage3DMultisample
GLAPI PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex;
#define glGetUniformBlockIndex glad_glGetUniformBlockIndex
GLAPI PFNGLFRONTFACEPROC glad_glFrontFace;
#define glFrontFace glad_glFrontFace
GLAPI PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glad_glDrawArraysInstancedBaseInstance;
#define glDrawArraysInstancedBaseInstance glad_glDrawArraysInstancedBaseInstance
GLAPI PFNGLISPOINTINSTROKEPATHNVPROC glad_glIsPointInStrokePathNV;
#define glIsPointInStrokePathNV glad_glIsPointInStrokePathNV



typedef void* (* GLADloadproc)(const char *name);
GLAPI int gladLoadGL(GLADloadproc);




#ifdef __cplusplus
}
#endif
#endif