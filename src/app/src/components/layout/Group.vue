<template>
    <n-layout position="absolute" has-sider>
        <Sider/>
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
</template>

<script>
import Sider from "@/components/layout/components/Main/Sider";

export default {
    name: "Group",
    components: {Sider}
}
</script>

<style scoped>

</style>
