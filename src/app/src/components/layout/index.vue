<template>
    <n-layout style="height: 100vh;">
        <n-layout-header style="height: 30px;" bordered>
        </n-layout-header>
        <n-layout position="absolute" style="top: 30px;" has-sider>
            <Sider></Sider>
            <n-layout content-style="padding: 0px;">
                <router-view name="Main"></router-view>
            </n-layout>
            <n-layout-footer position="absolute" style="height: 64px; padding: 24px;" bordered>
            </n-layout-footer>
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