<template>
    <n-layout-header style="height:100px;padding: 12px;" bordered>
        <n-loading-bar-provider>
            <n-message-provider>
                <n-notification-provider>
                    <n-dialog-provider>
                        <Header></Header>
                    </n-dialog-provider>
                </n-notification-provider>
            </n-message-provider>
        </n-loading-bar-provider>
    </n-layout-header>
    <n-layout position="absolute" :style="'height:${scrollerHeight}px'" style="top: 100px;padding-left: 20px;"
              :native-scrollbar="false">
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-h2>TEST</n-h2>
        <n-input
            type="textarea"
            placeholder="自动调整尺寸"
            :native-scrollbar="false"
            :autosize="{minRows: 3,maxRows: 5}"
        />
    </n-layout>
</template>

<script>
import {defineComponent} from 'vue'
import Header from "@/components/layout/components/Main/Header";

export default defineComponent({
    name: "Main",
    components: {Header}
})
</script>

<style scoped>

</style>