<template>
    <n-layout style="height: 100vh;">
        <n-layout-header style="height: 30px;" bordered>
        </n-layout-header>
        <n-layout position="absolute" style="top: 30px;" has-sider>
            <Sider></Sider>
            <n-layout ref="container" content-style="display:flex;flex-direction: column;overflow:hidden;">
                <router-view name="Main" v-slot="{Component}">
                    <transition enter-active-class="animate__animated animate__bounceInDown"
                                leave-active-class="animate__animated animate__bounceOutDown" mode="out-in">
                        <!--                        <keep-alive exclude="Home,Main">-->
                        <component ref="c1" :is="Component"/>
                        <!--                        </keep-alive>-->
                    </transition>
                </router-view>
            </n-layout>
        </n-layout>
    </n-layout>
</template>

<script>
import {Sider} from "@/components/layout/components/Sider/index.ts";

export default {
    name: "Layout",
    components: {
        Sider
    }
}
</script>

<style scoped>

</style>
